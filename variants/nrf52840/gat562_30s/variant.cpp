/*
 * GAT562 30S Mesh KIT V1.1 — Variant Initialisation
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "variant.h"
#include "nrf.h"
#include "wiring_constants.h"
#include "wiring_digital.h"

/*
 * One-to-one mapping: Arduino pin N ↔ nRF52840 GPIO N.
 *   P0.00 – P0.31  →  index 0 – 31
 *   P1.00 – P1.15  →  index 32 – 47
 */
const uint32_t g_ADigitalPinMap[] = {
    // P0
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,

    // P1
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47};

void initVariant()
{
    // ── LEDs ──────────────────────────────────────────────
    pinMode(PIN_LED1, OUTPUT);
    ledOff(PIN_LED1);

    pinMode(LED_BLUE, OUTPUT);
    ledOff(LED_BLUE);

    // ── Switched 3V3 rail ─────────────────────────────────
    pinMode(PIN_3V3_EN, OUTPUT);
    digitalWrite(PIN_3V3_EN, HIGH);
}
