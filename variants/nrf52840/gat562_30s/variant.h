/*
 * GAT562 30S Mesh KIT V1.1 pin definition
 *
 * Source schematic:
 *   "GAT562 30S Mesh KIT V1.1 SCH.pdf" (dated 2026-01-24)
 *
 * Key note from board author:
 *   GAT562 Mesh family IO is compatible with RAK4631.
 */

#ifndef _VARIANT_GAT562_30S_
#define _VARIANT_GAT562_30S_

// Keep RAK4630 behavior (power-rail handling, shared code paths).
#define RAK4630

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO // Board uses 32 kHz crystal for LF

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (6)
#define NUM_ANALOG_OUTPUTS (0)

// LEDs (via transistor stages, active HIGH)
#define PIN_LED1 (35) // P1.03, net LED1 (green)
#define LED_BLUE (36) // P1.04, net LED2 (blue)

#define LED_GREEN PIN_LED1
#define LED_NOTIFICATION LED_BLUE
#define LED_STATE_ON 1
// LoRa activity indication: RX flashes green, TX flashes second LED channel (red on this board revision).
#define LORA_RX_LED LED_GREEN
#define LORA_TX_LED LED_BLUE
#define LORA_ACTIVITY_LED_PULSE_MS 80
// Board has WS2812; use it for reliable LoRa RX/TX activity indication.
#define LORA_ACTIVITY_USE_NEOPIXEL
#define LORA_ACTIVITY_NEOPIXEL_BRIGHTNESS 64
#define LORA_TX_NEOPIXEL_RED 255
#define LORA_TX_NEOPIXEL_GREEN 0
#define LORA_TX_NEOPIXEL_BLUE 0
#define LORA_RX_NEOPIXEL_RED 0
#define LORA_RX_NEOPIXEL_GREEN 255
#define LORA_RX_NEOPIXEL_BLUE 0

// User key (S1)
#define PIN_BUTTON1 (9) // P0.09, net U_KEY
#define BUTTON_NEED_PULLUP

// 5-way switch (SW2), active LOW
#define HAS_TRACKBALL 1
#define TB_UP (28)    // P0.28, net UP
#define TB_DOWN (4)   // P0.04, net DOWN
#define TB_LEFT (30)  // P0.30, net LEFT
#define TB_RIGHT (31) // P0.31, net RIGHT
#define TB_PRESS (26) // P0.26, net SC (center/select)
#define TB_DIRECTION FALLING

// WS2812B
#define HAS_NEOPIXEL
#define NEOPIXEL_COUNT 1
#define NEOPIXEL_DATA 29                     // P0.29, net WS2812
#define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800)

// Analog pins
#define PIN_A0 (5)  // P0.05, net ADC_VBAT
#define PIN_A1 (31) // P0.31
#define PIN_A2 (28) // P0.28
#define PIN_A3 (29) // P0.29
#define PIN_A4 (30) // P0.30
#define PIN_A5 (31) // P0.31
#define PIN_A6 (0xff)
#define PIN_A7 (0xff)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define ADC_RESOLUTION 14

// Other pins
#define WB_I2C1_SDA (13) // P0.13
#define WB_I2C1_SCL (14) // P0.14

#define PIN_AREF (2)
#define PIN_NFC1 (9)
#define WB_IO5 PIN_NFC1
#define WB_IO4 (4)
#define PIN_NFC2 (10)

static const uint8_t AREF = PIN_AREF;

// Serial interfaces
// GPS is wired to RX2/TX2 (P0.15/P0.16) on the module.
#define PIN_SERIAL1_RX (15)
#define PIN_SERIAL1_TX (16)

// Auxiliary UART header/test pads are net-labeled UART1_RX/UART1_TX.
#define PIN_SERIAL2_RX (20)
#define PIN_SERIAL2_TX (19)

// SPI interfaces
// Only internal SPI to SX1262 is usable; external SPI1/QSPI pins are repurposed.
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO (45) // P1.13
#define PIN_SPI_MOSI (44) // P1.12
#define PIN_SPI_SCK (43)  // P1.11

static const uint8_t SS = 42;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

// Wire interface
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (WB_I2C1_SDA)
#define PIN_WIRE_SCL (WB_I2C1_SCL)

// SX1262 (same internal wiring as RAK4631)
#define USE_SX1262
#define SX126X_CS (42)
#define SX126X_DIO1 (47)
#define SX126X_BUSY (46)
#define SX126X_RESET (38)
// Force continuous RX to improve immediate ACK capture stability on this hardware.
#define SX126X_FORCE_CONTINUOUS_RX
// Broadcast reliability in Meshtastic uses implicit ACK (hearing rebroadcast).
// Increase sender retries to improve ACK hit rate in sparse/noisy meshes.
#define MESHTASTIC_NUM_RELIABLE_RETX 5
// #define SX126X_TXEN (39)
// #define SX126X_RXEN (37)
#define SX126X_POWER_EN (37)
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_DIO3_TCXO_VOLTAGE 1.8

// USB power detect through nRF APM
#define NRF_APM

// Switched 3V3 rail enable (IO2 = P1.02)
#define PIN_3V3_EN (34)
#define WB_IO2 PIN_3V3_EN

// GPS (L76K) settings
// Keep baud probing enabled (don't lock to one fixed speed) for better compatibility.
#define GPS_PROBETRIES 5
#define GPS_RX_PIN PIN_SERIAL1_RX
#define GPS_TX_PIN PIN_SERIAL1_TX
// L76K TIMEPULSE is routed via optional R23 (NC in this schematic revision), so PPS is not guaranteed present.
// #define PIN_GPS_PPS (17)
// Accept valid NMEA flow even if active command-based probe does not identify a model.
#define GPS_ALLOW_NMEA_FALLBACK
#define GPS_NMEA_FALLBACK_TIMEOUT_MS 3000

// Passive buzzer driver
#define PIN_BUZZER (33) // P1.01, net BEE_EN

// Battery monitor (R6=1M top, R7=1.5M bottom on ADC_VBAT)
#define BATTERY_PIN PIN_A0
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER 1.67

// nRF52 low-power comparator uses AIN3 (P0.05)
#define BATTERY_LPCOMP_INPUT NRF_LPCOMP_INPUT_3
#define BATTERY_LPCOMP_THRESHOLD NRF_LPCOMP_REF_SUPPLY_11_16

#ifdef __cplusplus
}
#endif

#endif // _VARIANT_GAT562_30S_
