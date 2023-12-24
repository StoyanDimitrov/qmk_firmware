// Copyright 2023 Harshit Goel (@harshitgoel96)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define CIRQUE_PINNACLE_ADDR 0x2A
#define CIRQUE_PINNACLE_POSITION_MODE CIRQUE_PINNACLE_ABSOLUTE_MODE 
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE 
#define POINTING_DEVICE_ROTATION_270
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X