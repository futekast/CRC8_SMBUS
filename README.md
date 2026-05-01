# CRC8_SMBUS

Reusable C implementation of CRC-8/SMBus.

## Files

- `include/crc8_smbus.h`
- `src/crc8_smbus.c`
- `examples/main.c`

## CRC Parameters

| Parameter | Value |
|---|---:|
| Name | CRC-8/SMBus |
| Polynomial | 0x07 |
| Initial Value | 0x00 |
| Input Reflected | No |
| Output Reflected | No |
| Final XOR | 0x00 |

## Validation

ASCII Check: `"123456789"` -> `0xF4`

HEX Check: `0x12 0x34 0x56 0x78 0x09` -> `0x6B`

Both bitwise and table-based functions are validated against the same expected results.

