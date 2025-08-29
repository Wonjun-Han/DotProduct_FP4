#!/bin/bash

# ============================================================================
# Chisel Template + Cocotb 환경 설치 스크립트 (연구실 서버용)
# ============================================================================
# 작성자: wonjun.han
# 용도: sudo 권한 없이 사용자 디렉토리에 개발환경 구축
# 
# 사용법: 
#   1. 프로젝트를 원하는 디렉토리에 클론
#   2. ./install.sh 실행
#   3. 설치 완료 후 ./chisel_env.sh로 개발환경 진입
# ============================================================================

set -e  # 오류 발생 시 스크립트 중단

# 색상 정의
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 로그 함수들
log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[SUCCESS]${NC} $1"
}

log_warning() {
    echo -e "${YELLOW}[WARNING]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# 현재 디렉토리 저장
PROJECT_DIR=$(pwd)
PROJECT_NAME=$(basename "$PROJECT_DIR")

log_info "Chisel Template + Cocotb 환경 설치 시작"
log_info "프로젝트 디렉토리: $PROJECT_DIR"

# ============================================================================
# 1. Java 11+ 확인
# ============================================================================
log_info "Java 버전 확인 중..."
if java -version 2>&1 | grep -q "openjdk version \"1[1-9]"; then
    JAVA_VERSION=$(java -version 2>&1 | head -n1 | cut -d'"' -f2)
    log_success "Java $JAVA_VERSION 사용 가능"
else
    log_error "Java 11+ 필요. 관리자에게 설치 요청하세요."
    exit 1
fi

# ============================================================================
# 2. SBT 설치 (사용자 디렉토리)
# ============================================================================
if [ ! -f "$HOME/sbt/bin/sbt" ]; then
    log_info "SBT 다운로드 및 설치 중..."
    cd ~
    
    if [ ! -f "sbt-1.9.7.tgz" ]; then
        wget https://github.com/sbt/sbt/releases/download/v1.9.7/sbt-1.9.7.tgz
    fi
    
    tar -xzf sbt-1.9.7.tgz
    rm -f sbt-1.9.7.tgz
    
    # SBT PATH 추가
    export PATH=~/sbt/bin:$PATH
    
    log_success "SBT 설치 완료"
else
    log_success "SBT 이미 설치됨"
    export PATH=~/sbt/bin:$PATH
fi

# ============================================================================
# 3. libffi 설치 (Pyenv Python용, 선택사항)
# ============================================================================
if [ ! -f "$HOME/local/lib/libffi.so" ]; then
    log_info "libffi 설치 중 (Python _ctypes 지원용)..."
    cd ~
    
    if [ ! -d "libffi-3.4.4" ]; then
        wget https://github.com/libffi/libffi/releases/download/v3.4.4/libffi-3.4.4.tar.gz
        tar -xzf libffi-3.4.4.tar.gz
        rm -f libffi-3.4.4.tar.gz
    fi
    
    cd libffi-3.4.4
    ./configure --prefix=$HOME/local
    make -j$(nproc)
    make install
    
    log_success "libffi 설치 완료"
else
    log_success "libffi 이미 설치됨"
fi

# ============================================================================
# 4. Iverilog 설치 (gperf가 시스템에 설치되어 있어야 함)
# ============================================================================
if [ ! -f "$HOME/local/bin/iverilog" ]; then
    log_info "Iverilog 다운로드 및 설치 중..."
    
    # gperf 확인
    if ! command -v gperf &> /dev/null; then
        log_error "gperf가 시스템에 설치되어 있지 않습니다."
        log_error "관리자에게 다음 명령어 실행 요청: sudo yum install gperf"
        log_error "gperf 설치 후 다시 실행하세요."
        exit 1
    fi
    
    cd ~
    if [ ! -d "iverilog" ]; then
        git clone https://github.com/steveicarus/iverilog.git
    fi
    
    cd iverilog
    autoconf
    ./configure --prefix=$HOME/local
    make -j$(nproc)
    make install || true  # help2man 에러 무시
    
    export PATH=$HOME/local/bin:$PATH
    
    log_success "Iverilog 설치 완료"
else
    log_success "Iverilog 이미 설치됨"
    export PATH=$HOME/local/bin:$PATH
fi

# ============================================================================
# 5. Python 가상환경 및 Cocotb 설치
# ============================================================================
log_info "Python 가상환경 및 Cocotb 설치 중..."

cd "$PROJECT_DIR"

# 기존 가상환경 삭제 (pyenv 연결 문제 해결)
if [ -d "cocotb_env" ]; then
    log_warning "기존 가상환경 삭제 중..."
    rm -rf cocotb_env
fi

# 시스템 Python으로 가상환경 생성
/usr/bin/python3 -m venv cocotb_env

# 가상환경 활성화
source cocotb_env/bin/activate

# pip 업그레이드
pip install --upgrade pip

# Cocotb 설치
pip install "cocotb[bus]"

# 설치 확인
python3 -c "import cocotb; print(f'Cocotb {cocotb.__version__} 설치 성공')"

log_success "Python 가상환경 및 Cocotb 설치 완료"

# ============================================================================
# 6. Chisel 프로젝트 컴파일 테스트
# ============================================================================
log_info "Chisel 프로젝트 컴파일 테스트 중..."

cd "$PROJECT_DIR"
sbt compile

if [ $? -eq 0 ]; then
    log_success "Chisel 컴파일 테스트 성공"
else
    log_error "Chisel 컴파일 실패"
    exit 1
fi

# ============================================================================
# 7. 환경 설정 스크립트 생성
# ============================================================================
log_info "개발환경 진입 스크립트 생성 중..."

# chisel_env.sh 스크립트 생성
cat > "$PROJECT_DIR/chisel_env.sh" << EOF
#!/bin/bash

# Chisel 개발환경 설정 스크립트
# 사용법: ./chisel_env.sh

PROJECT_DIR="$PROJECT_DIR"

# 환경변수 설정
export PATH=~/sbt/bin:\$HOME/local/bin:\$PATH
export SIM=icarus

# Python 가상환경 활성화
source \$PROJECT_DIR/cocotb_env/bin/activate

# 프로젝트 디렉토리로 이동
cd \$PROJECT_DIR

# run 명령어 alias 설정
alias run="bash \$PROJECT_DIR/run.sh"

echo "🚀 Chisel 개발환경이 활성화되었습니다!"
echo "📁 프로젝트 디렉토리: \$PROJECT_DIR" 
echo "🐍 Python: \$(python --version)"
echo "☕ Java: \$(java -version 2>&1 | head -n1)"
echo "🔧 SBT: \$(sbt --version | head -n1)"
echo "🧪 Cocotb: \$(python -c 'import cocotb; print(cocotb.__version__)')"
echo "⚡ Iverilog: \$(iverilog -V | head -n1)"
echo ""
echo "사용 가능한 명령어:"
echo "  run build <ModuleName>  - Chisel을 Verilog로 변환"
echo "  run cotb <ModuleName>   - Cocotb 테스트 실행"
echo "  sbt compile            - Scala 코드 컴파일"
echo "  sbt test              - Scala 테스트 실행"
echo ""

# bash로 전환 (zsh 환경 문제 회피)
exec bash
EOF

chmod +x "$PROJECT_DIR/chisel_env.sh"

# ============================================================================
# 8. 환경설정 파일 업데이트
# ============================================================================
log_info "쉘 설정 파일 업데이트 중..."

# .bashrc에 필요한 설정 추가 (중복 방지)
if ! grep -q "# Chisel 개발환경" ~/.bashrc; then
    cat >> ~/.bashrc << 'EOF'

# Chisel 개발환경 설정
export PATH=~/sbt/bin:$HOME/local/bin:$PATH
export SIM=icarus
EOF
    log_success "~/.bashrc 업데이트 완료"
fi

# ============================================================================
# 9. 설치 완료 메시지
# ============================================================================
log_success "============================================"
log_success "🎉 설치 완료!"
log_success "============================================"
log_info ""
log_info "설치된 도구들:"
log_info "  ☕ Java $(java -version 2>&1 | head -n1 | cut -d'"' -f2)"
log_info "  🔧 SBT $(~/sbt/bin/sbt --version | head -n1 | cut -d' ' -f4)"
log_info "  ⚡ Iverilog $($HOME/local/bin/iverilog -V | head -n1 | cut -d' ' -f3-4)"
log_info "  🧪 Cocotb $(python3 -c 'import cocotb; print(cocotb.__version__)' 2>/dev/null || echo 'N/A')"
log_info ""
log_info "다음 단계:"
log_info "  1. 새 터미널을 열거나 'source ~/.bashrc' 실행"
log_info "  2. './chisel_env.sh' 실행해서 개발환경 진입"
log_info "  3. 'run build <ModuleName>' 명령어로 테스트"
log_info ""
log_info "개발환경 진입: ./chisel_env.sh"
log_info "프로젝트 디렉토리: $PROJECT_DIR"
log_success "============================================"