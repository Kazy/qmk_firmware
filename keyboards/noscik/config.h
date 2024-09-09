// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

/* QMK */
#define TAPPING_TERM 150
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define DEBOUNCE_TYPE none
// #define DEBOUNCE 2

// #define COMBO_STRICT_TIMER
#define COMBO_TERM 35
#define COMBO_HOLD (TAPPING_TERM) // time to hold to trigger delayed combo

#define LINGER_TIME TAPPING_TERM * 1.2 // how long to hold before a time-depentant behavior begins

/* Miryoku */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_ALT
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 100 /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 50  /* ms */
// was 3000 before
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 75   /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)
#define BILATERAL_COMBINATIONS_IGNORE_ROW 3

#define ADAPTIVE_ENABLE
#define ADAPTIVE_TERM  90 // rolling threshold
#define ADAPT_VOWEL_H                    // eliminate vowel SFBs (AU/UA;EO/OE) using vH instead of v'
// #define FR_ADAPTIVES                     // eliminate 'h SFB for French

// #define UNICODE_KEY_LNX KC_RALT

// #define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO false
// #define COMBO_MUST_TAP_PER_COMBO false
