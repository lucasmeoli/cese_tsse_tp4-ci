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

/** @file leds.c
 ** @brief Definitions of functions for the LED control library
 **/

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

/** @brief Mask to turn off all LEDs */
#define ALL_LEDS_OFF 0x0000

/** @brief Difference between the LED number and the bit number */
#define LEDS_TO_BIT_OFFSET 1

/** @brief Constant with the first bit set to one to generate a mask */
#define FIRST_BIT 1

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/** @brief Private variable to store the output port address */
static uint16_t * port_address;

/* === Private function declarations =========================================================== */

/**
 * @brief Private function to convert an LED number into a bitmask.
 *
 * @param led LED number for which the mask should be generated
 * @return uint16_t Bitmask with 1 in the position corresponding to the LED
 */
static uint16_t LedToMask(uint8_t led);

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

uint16_t LedToMask(uint8_t led) {
    return (FIRST_BIT << (led - LEDS_TO_BIT_OFFSET));
}

/* === Public function implementation ========================================================== */

void LedsInit(uint16_t * port) {
    port_address = port;
    LedsTurnOffAll();
}

void LedsTurnOnSingle(uint8_t led) {
    *port_address |= LedToMask(led);
}

void LedsTurnOffSingle(uint8_t led) {
    *port_address &= ~LedToMask(led);
}

void LedsTurnOffAll() {
    *port_address = ALL_LEDS_OFF;
}

bool LedsIsTurnedOn(uint8_t led) {
    return (*port_address & LedToMask(led)) != 0;
}

/* === End of documentation ==================================================================== */
