
MODE=$1        # build, spec, test, emptb, cotb, all
TARGET=$2      # ModuleName 

CHISEL_DIR=$(pwd)
VENV_DIR=~/cocotb_env
COCOTB_DIR=$CHISEL_DIR/test_cocotb
VERILOG_DIR=$CHISEL_DIR/generated/verilog
VERILOG_FILE="$VERILOG_DIR/$TARGET.sv"
TEST_FILE="$COCOTB_DIR/tb_$TARGET.py"
MODULE_NAME="tb_$TARGET"

if [ -z "$MODE" ] || [ -z "$TARGET" ]; then
  echo "❌ Usage: run [build|emptb|test|cotb|all] <ModuleName>"
  exit 1
fi

source $VENV_DIR/bin/activate

run_build() {
  echo "🔧 [BUILD] sbt runMain build.build $TARGET"
  sbt "runMain build.build $TARGET" || {
    echo "❌ sbt runMain failed"; exit 1;
  }

  if [ ! -f "$VERILOG_FILE" ]; then
    echo "❌ Verilog 파일이 없습니다: $VERILOG_FILE"
    exit 1
  fi

}

run_emptb() {
  TEST_FILE="$COCOTB_DIR/tb_$TARGET.py"
  if [ -f "$TEST_FILE" ]; then
    echo "⚠️  이미 테스트벤치 파일이 존재합니다: $TEST_FILE"
  else
    echo "🛠️ [TB] gen_tb.py $TARGET 실행"
    python3 $COCOTB_DIR/gen_tb.py $TARGET || {
      echo "❌ tb 자동 생성 실패"; exit 1;
    }
  fi
}

run_cotb() {
  if [ ! -f "$TEST_FILE" ]; then
    echo "❌ cocotb 테스트 파일이 없습니다: $TEST_FILE"
    exit 1
  fi

  echo "🧪 [COTB] make MODULE=$MODULE_NAME TOPLEVEL=$TARGET"
  cd $COCOTB_DIR || exit 1
  make MODULE=$MODULE_NAME TOPLEVEL=$TARGET || {
    echo "❌ cocotb 테스트 실패"; exit 1;
  }
  cd $CHISEL_DIR
}

run_test() {
  if [ -z "$TARGET" ]; then
    echo "🧪 [SCALA TEST] sbt test"
    sbt test || {
      echo "❌ ScalaTest 실패"; exit 1;
    }
  else
    echo "🧪 [SCALA TEST] sbt \"testOnly *${TARGET}Spec\""
    sbt "testOnly *${TARGET}Spec" || {
      echo "❌ ScalaTest 실패"; exit 1;
    }
  fi
}


case "$MODE" in
  build) run_build ;;
  emptb) run_emptb ;; 
  cotb) run_cotb ;;
  test) run_test ;;
  all)
    run_build
    run_test
    run_cotb
    ;;
  *)
    echo "❌ Invalid mode: $MODE"
    exit 1
    ;;
esac
