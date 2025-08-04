#!/bin/bash

set -e

VERILOG_DIR="./generated/verilog"
SVG_DIR="./out_svgs"
mkdir -p $SVG_DIR

VERILOG_FILES=$(find "$VERILOG_DIR" -name "*.sv" | tr '\n' ' ')

MODULE_NAMES=(
  p_Expansion
  p_Multiplier
  p_MulConvert
  p_Convert_Dep_1
  p_Convert_Dep_2
  p_Convert_Dep_3
  p_Convert_Dep_4
  p_Convert_Dep_5
  p_TOP_Til_Dep_All_V1
)

# Mac 호환용 코어 수 추출
CORES=$(sysctl -n hw.ncpu)

generate_svg() {
  MODULE=$1
  echo "[`date +%H:%M:%S`] Generating SVG for $MODULE"
  yosys -q -p "
    read_verilog -sv $VERILOG_FILES
    hierarchy -top $MODULE
    proc; opt; techmap; write_json $SVG_DIR/${MODULE}.json
  "
  node --max-old-space-size=8192 $(which netlistsvg) $SVG_DIR/${MODULE}.json -o $SVG_DIR/${MODULE}.svg
}

export VERILOG_FILES SVG_DIR
export -f generate_svg

# 병렬 실행 (macOS-friendly)
printf "%s\n" "${MODULE_NAMES[@]}" | parallel -j$CORES --halt now,fail=1 generate_svg

echo "✅ All SVGs done in $SVG_DIR"
