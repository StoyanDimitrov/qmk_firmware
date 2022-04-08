// Copyright 2022 harshitgoel96 (@harshitgoel96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x4847 //HG
#define PRODUCT_ID   0x4D4E //MN
#define DEVICE_VER   0x0001
#define MANUFACTURER Harshit Goel
#define PRODUCT      Mano42

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 5

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { C6, D7, E6, B5, B4 }
#define MATRIX_COL_PINS { F6, F7, B1, B3,  B2 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define USE_SERIAL
#define SOFT_SERIAL_PIN D3  // or D1, D2, D3, E6

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

//qmk-dfu
#define QMK_ESC_OUTPUT C6  // COL pin if COL2ROW
#define QMK_ESC_INPUT  F6  // ROW pin if COL2ROW

// for via
//#define DYNAMIC_KEYMAP_LAYER_COUNT 7
