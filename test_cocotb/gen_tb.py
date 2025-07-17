import os
import sys
import re
from pathlib import Path

def parse_ports(verilog_path):
    with open(verilog_path, 'r') as f:
        code = f.read()

    ports = []

    port_block_match = re.search(r'module\s+\w+\s*\((.*?)\);\s*', code, re.DOTALL)
    if not port_block_match:
        print("❌ 포트 블록을 찾을 수 없습니다.")
        return ports

    port_lines = port_block_match.group(1).splitlines()

    current_dir = None
    current_width = None

    for line in port_lines:
        line = line.strip().rstrip(',').rstrip(';')
        if not line:
            continue

        match = re.match(r'(input|output|inout)\s*(\[[^\]]+\])?\s*(.*)', line)
        if match:
            current_dir = match.group(1)
            current_width = match.group(2)
            signals = match.group(3)
        else:
            signals = line

        for name in signals.split(','):
            name = name.strip()
            if name.startswith("io_"):
                ports.append((current_dir, name))

    return ports



def generate_testbench(module_name, ports):
    tb_filename = f"test_cocotb/tb_{module_name}.py"
    with open(tb_filename, 'w') as f:
        f.write("import cocotb\n")
        f.write("from cocotb.triggers import Timer\n\n")
        f.write(f"@cocotb.test()\n")
        f.write(f"async def test_{module_name.lower()}(dut):\n")

        for direction, name in ports:
            if direction == "input":
                f.write(f"    dut.{name}.value = 0  # TODO: Set proper test value\n")
        f.write("    await Timer(1.0, units=\"ns\")\n\n")
        for direction, name in ports:
            if direction == "output":
                f.write(f"    assert dut.{name}.value == 0, f\"{module_name} failed: {{dut.{name}.value}}\"\n")

    print(f"✅ Generated {tb_filename}")


def main():
    if len(sys.argv) != 2:
        print("Usage: python3 gen_tb.py <ModuleName>")
        sys.exit(1)

    module_name = sys.argv[1]
    verilog_path = Path(f"generated/verilog/{module_name}.sv")

    if not verilog_path.exists():
        print(f"❌ Verilog file not found: {verilog_path}")
        sys.exit(1)

    ports = parse_ports(verilog_path)
    generate_testbench(module_name, ports)


if __name__ == "__main__":
    main()
