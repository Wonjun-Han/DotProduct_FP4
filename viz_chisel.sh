#!/bin/bash

MODULES=(
  Visualize_Adder_Dep1
  Visualize_Adder_Dep2
  Visualize_Adder_Dep3
  Visualize_Adder_Dep4
  Visualize_Adder_Dep5
  Visualize_Adder_ScaleEmax
  Visualize_Adder_ScaleSum
  Visualize_Expansion
  Visualize_FieldExtractor
  Visualize_Multiplier
  Visualize_MulConvert
  Visualize_Convert_Dep1
  Visualize_Convert_Dep2
  Visualize_Convert_Dep3
  Visualize_Convert_Dep4
  Visualize_Convert_Dep5
  Visualize_TOP_Til_Dep_All_V1
)

for MODULE in "${MODULES[@]}"; do
  echo "🔍 Running: $MODULE"
  sbt "runMain mxfp4.proposed.${MODULE}"
done
echo "✅ All visualizations completed."