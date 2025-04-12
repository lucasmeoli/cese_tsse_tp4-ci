/************************************************************************************************
Copyright (c) 2025, Lucas Meoli <meolilucas@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

#ifndef LEDS_H
#define LEDS_H

/** @file leds.h
 ** @brief Declaration of functions for the LED control library
 **/

/* === Headers files inclusions ================================================================ */

#include <stdint.h>
#include <stdbool.h>

/* === C++ Header ============================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Function to initialize the LEDs library
 *
 * @note This function must be called before using any other function in the library
 *
 * @param port Pointer to the GPIO port address that controls the LEDs
 */
void LedsInit(uint16_t * port);

/**
 * @brief Function to turn on a single LED
 *
 * @param led The LED number to be turned on
 */
void LedsTurnOnSingle(uint8_t led);

/**
 * @brief Function to turn off a single LED
 *
 * @param led The LED number to be turned off
 */
void LedsTurnOffSingle(uint8_t led);

/**
 * @brief Function to turn off ALL LEDs
 */
void LedsTurnOffAll();

/**
 * @brief Function to check if a LED is on
 *
 * @param led The LED number to check (must be within valid range)
 *
 * @return bool True if the LED is on
 */
bool LedsIsTurnedOn(uint8_t led);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* LEDS_H */
