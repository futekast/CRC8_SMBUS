#ifndef CRC8_SMBUS_H
#define CRC8_SMBUS_H

//------------------------------------------------------------------------------
// SPDX-License-Identifier: MIT
// Copyright (c) 2026 FUTEK Advanced Sensor Technology, Inc.
//
// This implementation is based on publicly documented CRC-8/SMBus mathematical
// definitions. No third-party proprietary source code was used.
//------------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

#define _CRC8_SMBUS_POLYNOMIAL()          (0x07u)
#define _CRC8_SMBUS_INITIAL_VALUE()       (0x00u)
#define _CRC8_SMBUS_FINAL_XOR_VALUE()     (0x00u)

//------------------------------------------------------------------------------
// Function Name: Initialize CRC8 SMBus
// Description: This function returns the initial CRC-8/SMBus value.
// Parameters: None
// Returns: Initial CRC-8/SMBus value
//------------------------------------------------------------------------------
uint8_t initializeCrc8Smbus(void);

//------------------------------------------------------------------------------
// Function Name: Update CRC8 SMBus Bitwise
// Description: This function updates a running CRC-8/SMBus value with one byte
//              using the bitwise calculation method.
// Parameters:
//  crcValue - Current CRC-8/SMBus value
//  dataByte - Input data byte
// Returns: Updated CRC-8/SMBus value
//------------------------------------------------------------------------------
uint8_t updateCrc8SmbusBitwise(uint8_t crcValue, uint8_t dataByte);

//------------------------------------------------------------------------------
// Function Name: Update CRC8 SMBus Table
// Description: This function updates a running CRC-8/SMBus value with one byte
//              using the lookup table calculation method.
// Parameters:
//  crcValue - Current CRC-8/SMBus value
//  dataByte - Input data byte
// Returns: Updated CRC-8/SMBus value
//------------------------------------------------------------------------------
uint8_t updateCrc8SmbusTable(uint8_t crcValue, uint8_t dataByte);

//------------------------------------------------------------------------------
// Function Name: Calculate CRC8 SMBus Bitwise
// Description: This function calculates CRC-8/SMBus over a data buffer using
//              the bitwise calculation method.
// Parameters:
//  pData - Pointer to input data buffer
//  dataLength - Number of bytes in the input data buffer
// Returns: Calculated CRC-8/SMBus value
//------------------------------------------------------------------------------
uint8_t calculateCrc8SmbusBitwise(const uint8_t *pData, size_t dataLength);

//------------------------------------------------------------------------------
// Function Name: Calculate CRC8 SMBus Table
// Description: This function calculates CRC-8/SMBus over a data buffer using
//              the lookup table calculation method.
// Parameters:
//  pData - Pointer to input data buffer
//  dataLength - Number of bytes in the input data buffer
// Returns: Calculated CRC-8/SMBus value
//------------------------------------------------------------------------------
uint8_t calculateCrc8SmbusTable(const uint8_t *pData, size_t dataLength);

#endif