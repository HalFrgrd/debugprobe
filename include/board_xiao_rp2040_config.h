/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd.
 * Copyright (c) 2024 SlickBug Project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef BOARD_XIAO_RP2040_H_
#define BOARD_XIAO_RP2040_H_

// Direct GPIO connection (no external level-shifters)
#define PROBE_IO_RAW
#define PROBE_CDC_UART

// PIO config:
// D8 is GPIO 2 -> 33Ω R2 -> TARGET_SWCLK
// D10 is GPIO 3 -> 33Ω R1 -> TARGET_SWDIO
#define PROBE_SM 0
#define PROBE_PIN_OFFSET 2
#define PROBE_PIN_SWCLK (PROBE_PIN_OFFSET + 0) // GPIO 2
#define PROBE_PIN_SWDIO (PROBE_PIN_OFFSET + 1) // GPIO 3

// Target reset config:
// SlickBug uses a 4-pin pogo probe (GND, SWCLK, SWDIO, 3V3).
// No hardware reset pin is routed to the probe.
// PROBE_PIN_RESET is intentionally omitted.

// UART config (XIAO D6 = GPIO 0 / TX, D7 = GPIO 1 / RX)
#define PROBE_UART_TX 0
#define PROBE_UART_RX 1
#define PROBE_UART_INTERFACE uart0
#define PROBE_UART_BAUDRATE 115200

// LED config for Seeed Studio XIAO RP2040:
// Three onboard single-color LEDs are active-low (0 = ON, 1 = OFF).
#define PROBE_LEDS_ACTIVE_LOW 1
#define PROBE_USB_CONNECTED_LED 25  // Blue LED: USB status
#define PROBE_DAP_CONNECTED_LED 16  // Green LED: DAP connected
#define PROBE_DAP_RUNNING_LED 17    // Red LED: Target running

#define PROBE_PRODUCT_STRING "SlickBug XIAO Debug Probe (CMSIS-DAP)"

#endif
