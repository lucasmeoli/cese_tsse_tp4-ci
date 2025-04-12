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

/** @file test_leds.c
 ** @brief Unit tests for the LED control library
 **/

/**
 * @test Con la inicialización todos los LEDs quedan apagados.
 * @test Prender un LED individual.
 * @test Apagar un LED individual.
 * @test Prender y apagar múltiples LED’s.
 * @test Prender todos los LEDs de una vez.
 * @test Apagar todos los LEDs de una vez.
 * @test Consultar el estado de un LED que está encendido
 * @test Consultar el estado de un LED que est apagado
 * @test Revisar limites de los parametros.
 * @test Revisar parámetros fuera de los limites.
 */

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

static uint16_t virtual_leds = 0xFFFF;

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
void setUp(void) {
    LedsInit(&virtual_leds);
}

/** @test With initialization, all LEDs are off. */
void test_all_leds_start_off(void) {
    uint16_t leds_virtualss = 0xFFFF;

    LedsInit(&virtual_leds);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

/** @test Turn on an individual LED. */
void test_turn_on_single_led(void) {
    LedsTurnOnSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0008, virtual_leds);
}

/** @test Turn off an individual LED. */
void test_turn_off_single_led(void) {
    LedsTurnOnSingle(4);
    LedsTurnOffSingle(4);
    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

/** @test Turn on and turn off multiple LEDs. */
void test_turn_on_and_off_multiple_leds(void) {
    LedsTurnOnSingle(4);
    LedsTurnOnSingle(6);

    LedsTurnOffSingle(4);
    LedsTurnOffSingle(8);

    TEST_ASSERT_EQUAL_HEX16(0x0020, virtual_leds);
}

/** @test Turn off all LEDs at once. */
void test_turn_off_all_leds(void) {
    for (int i = 0; i < 16; i++) {
        LedsTurnOnSingle(i);
    }
    LedsTurnOffAll();

    TEST_ASSERT_EQUAL_HEX16(0x0000, virtual_leds);
}

/** @test Check the status of a LED that is on. */
void test_check_status_led_is_on(void) {
    LedsTurnOnSingle(4);

    TEST_ASSERT_TRUE(LedsIsTurnedOn(4));
}

/** @test Check the status of a LED that is off. */
void test_check_status_led_is_off(void) {
    LedsTurnOnSingle(4);
    LedsTurnOffSingle(4);

    TEST_ASSERT_FALSE(LedsIsTurnedOn(4));
}

/* === End of documentation ==================================================================== */
