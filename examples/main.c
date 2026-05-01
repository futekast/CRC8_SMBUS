//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This file provides example validation for the CRC-8/SMBus implementation.
//------------------------------------------------------------------------------

#include <stdint.h>
#include <stdio.h>

#include "crc8_smbus.h"

#define _CRC8_SMBUS_ASCII_CHECK_INPUT()           ("123456789")
#define _CRC8_SMBUS_ASCII_CHECK_INPUT_LENGTH()    (9u)
#define _CRC8_SMBUS_ASCII_EXPECTED_RESULT()       (0xF4u)

#define _CRC8_SMBUS_HEX_CHECK_INPUT_LENGTH()      (5u)
#define _CRC8_SMBUS_HEX_EXPECTED_RESULT()         (0x6Bu)

static const uint8_t crc8SmbusHexCheckInput[] = {
    0x12u,
    0x34u,
    0x56u,
    0x78u,
    0x09u
};

//------------------------------------------------------------------------------
// Function Name: Main
// Description: This function validates the CRC-8/SMBus bitwise and table-based
//              calculation methods using known check values.
// Parameters: None
// Returns: 0 if all checks pass, otherwise 1
//------------------------------------------------------------------------------
int main(void) {
    uint8_t asciiBitwiseCrcValue;
    uint8_t asciiTableCrcValue;
    uint8_t hexBitwiseCrcValue;
    uint8_t hexTableCrcValue;
    uint8_t checkResult;

    asciiBitwiseCrcValue = calculateCrc8SmbusBitwise(
        (const uint8_t *)_CRC8_SMBUS_ASCII_CHECK_INPUT(),
        _CRC8_SMBUS_ASCII_CHECK_INPUT_LENGTH()
    );

    asciiTableCrcValue = calculateCrc8SmbusTable(
        (const uint8_t *)_CRC8_SMBUS_ASCII_CHECK_INPUT(),
        _CRC8_SMBUS_ASCII_CHECK_INPUT_LENGTH()
    );

    hexBitwiseCrcValue = calculateCrc8SmbusBitwise(
        crc8SmbusHexCheckInput,
        _CRC8_SMBUS_HEX_CHECK_INPUT_LENGTH()
    );

    hexTableCrcValue = calculateCrc8SmbusTable(
        crc8SmbusHexCheckInput,
        _CRC8_SMBUS_HEX_CHECK_INPUT_LENGTH()
    );

    if ((asciiBitwiseCrcValue == _CRC8_SMBUS_ASCII_EXPECTED_RESULT())
        && (asciiTableCrcValue == _CRC8_SMBUS_ASCII_EXPECTED_RESULT())
        && (hexBitwiseCrcValue == _CRC8_SMBUS_HEX_EXPECTED_RESULT())
        && (hexTableCrcValue == _CRC8_SMBUS_HEX_EXPECTED_RESULT())) {
        checkResult = 1u;
    } else {
        checkResult = 0u;
    }

    printf("CRC-8/SMBus ASCII Bitwise Result: 0x%02X Expected: 0x%02X\n",
           asciiBitwiseCrcValue,
           _CRC8_SMBUS_ASCII_EXPECTED_RESULT());

    printf("CRC-8/SMBus ASCII Table Result:   0x%02X Expected: 0x%02X\n",
           asciiTableCrcValue,
           _CRC8_SMBUS_ASCII_EXPECTED_RESULT());

    printf("CRC-8/SMBus HEX Bitwise Result:   0x%02X Expected: 0x%02X\n",
           hexBitwiseCrcValue,
           _CRC8_SMBUS_HEX_EXPECTED_RESULT());

    printf("CRC-8/SMBus HEX Table Result:     0x%02X Expected: 0x%02X\n",
           hexTableCrcValue,
           _CRC8_SMBUS_HEX_EXPECTED_RESULT());

    printf("CRC-8/SMBus Status: %s\n",
           (checkResult == 1u) ? "PASS" : "FAIL");

    return (checkResult == 1u) ? 0 : 1;
}