// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "features/custom_shift_key.h"
#include "features/adaptive.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"


enum layers {
    _COLEMAK,  // default layer
    _VIB_P,
    _NAV,
    _NUM,
    _SYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬───────────┬───────────┬───────────┬───────────┬───────────────┐                             ┌───────────────┬───────────────┬───────────┬───────────┬───────────┬────────────┐
//    │ RALT(US_6) │     q     │     w     │     f     │     p     │       b       │                             │       j       │       l       │     u     │     y     │     '     │    del     │
//    ├────────────┼───────────┼───────────┼───────────┼───────────┼───────────────┤                             ├───────────────┼───────────────┼───────────┼───────────┼───────────┼────────────┤
//    │  RALT(`)   │ LALT_T(a) │ LGUI_T(r) │ LCTL_T(s) │ LSFT_T(t) │       g       │                             │       m       │   LSFT_T(n)   │ LCTL_T(e) │ LGUI_T(i) │ LALT_T(o) │    bspc    │
//    ├────────────┼───────────┼───────────┼───────────┼───────────┼───────────────┤                             ├───────────────┼───────────────┼───────────┼───────────┼───────────┼────────────┤
//    │    ___     │     z     │     x     │     c     │     d     │       v       │                             │       k       │       h       │     ,     │     .     │     ?     │ DF(_VIB_P) │
//    └────────────┴───────────┴───────────┴───────────┼───────────┼───────────────┼───────────────┐       ┌─────┼───────────────┼───────────────┼───────────┴───────────┴───────────┴────────────┘
//                                                     │   ralt    │ LT(_NAV, spc) │ OSM(MOD_LSFT) │       │ tab │ LT(_SYM, ent) │ LT(_NUM, esc) │
//                                                     └───────────┴───────────────┴───────────────┘       └─────┴───────────────┴───────────────┘
[_COLEMAK] = LAYOUT_split_3x6_3(
  RALT(US_6)     , KC_Q         , KC_W         , KC_F         , KC_P         , KC_B             ,                                  KC_J               , KC_L             , KC_U         , KC_Y         , KC_QUOTE     , KC_DEL    ,
  RALT(KC_GRAVE) , LALT_T(KC_A) , LGUI_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T) , KC_G             ,                                  KC_M               , LSFT_T(KC_N)     , LCTL_T(KC_E) , LGUI_T(KC_I) , LALT_T(KC_O) , KC_BSPC   ,
  ___            , KC_Z         , KC_X         , KC_C         , KC_D         , KC_V             ,                                  KC_K               , KC_H             , KC_COMM      , KC_DOT       , KC_QUESTION  , DF(_VIB_P),
                                                                KC_RALT      , LT(_NAV, KC_SPC) , OSM(MOD_LSFT) ,         KC_TAB , LT(_SYM, KC_ENTER) , LT(_NUM, KC_ESC)
),

//    ┌────────────┬───────────┬───────────┬───────────┬───────────┬───────────────┐                         ┌───────────────┬───────────────┬───────────┬───────────┬───────────┬──────────────┐
//    │ RALT(US_6) │     j     │     g     │     m     │     p     │       v       │                         │       q       │       .       │     /     │     "     │     '     │     del      │
//    ├────────────┼───────────┼───────────┼───────────┼───────────┼───────────────┤                         ├───────────────┼───────────────┼───────────┼───────────┼───────────┼──────────────┤
//    │    ___     │ LALT_T(c) │ LGUI_T(s) │ LCTL_T(n) │ LSFT_T(t) │       b       │                         │       ,       │   LSFT_T(a)   │ LCTL_T(e) │ LGUI_T(i) │ LALT_T(h) │     bspc     │
//    ├────────────┼───────────┼───────────┼───────────┼───────────┼───────────────┤                         ├───────────────┼───────────────┼───────────┼───────────┼───────────┼──────────────┤
//    │  RALT(`)   │     x     │     f     │     l     │     d     │       w       │                         │       -       │       u       │     o     │     y     │     k     │ DF(_COLEMAK) │
//    └────────────┴───────────┴───────────┴───────────┼───────────┼───────────────┼─────────────┐       ┌───┼───────────────┼───────────────┼───────────┴───────────┴───────────┴──────────────┘
//                                                     │   ralt    │ LT(_NAV, spc) │ LSFT_T(tab) │       │ r │ LT(_SYM, ent) │ LT(_NUM, esc) │
//                                                     └───────────┴───────────────┴─────────────┘       └───┴───────────────┴───────────────┘
[_VIB_P] = LAYOUT_split_3x6_3(
  RALT(US_6)     , KC_J         , KC_G         , KC_M         , KC_P         , KC_V               ,                                 KC_Q               , KC_DOT           , KC_SLASH     , KC_DQUO      , KC_QUOTE     , KC_DEL      ,
  ___            , LALT_T(KC_C) , LGUI_T(KC_S) , LCTL_T(KC_N) , LSFT_T(KC_T) , KC_B               ,                                 KC_COMMA           , LSFT_T(KC_A)     , LCTL_T(KC_E) , LGUI_T(KC_I) , LALT_T(KC_H) , KC_BSPC     ,
  RALT(KC_GRAVE) , KC_X         , KC_F         , KC_L         , KC_D         , KC_W               ,                                 KC_MINUS           , KC_U             , KC_O         , KC_Y         , KC_K         , DF(_COLEMAK),
                                                                KC_RALT      , LT(_NAV, KC_SPACE) , LSFT_T(KC_TAB) ,         KC_R , LT(_SYM, KC_ENTER) , LT(_NUM, KC_ESC)
),

//    ┌─────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┐                         ┌───────────────┬───────────────┬──────┬─────┬──────┬─────┐
//    │ ___ │      ___      │      ___      │      ___      │      ___      │      ___      │                         │      ___      │      ___      │ ___  │ ___ │ ___  │ ___ │
//    ├─────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤                         ├───────────────┼───────────────┼──────┼─────┼──────┼─────┤
//    │ ___ │ OSM(MOD_LALT) │ OSM(MOD_LGUI) │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │     pgup      │                         │     home      │     left      │ down │ up  │ rght │ ___ │
//    ├─────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤                         ├───────────────┼───────────────┼──────┼─────┼──────┼─────┤
//    │ ___ │      ___      │      ___      │   C(S(tab))   │    C(tab)     │     pgdn      │                         │      end      │       h       │  j   │  k  │  l   │ ___ │
//    └─────┴───────────────┴───────────────┴───────────────┼───────────────┼───────────────┼─────────────┐       ┌───┼───────────────┼───────────────┼──────┴─────┴──────┴─────┘
//                                                          │     ralt      │ LT(_NAV, spc) │ LSFT_T(tab) │       │ r │ LT(_SYM, ent) │ LT(_NUM, esc) │
//                                                          └───────────────┴───────────────┴─────────────┘       └───┴───────────────┴───────────────┘
[_NAV] = LAYOUT_split_3x6_3(
  ___ , ___           , ___           , ___           , ___           , ___                ,                                 ___                , ___              , ___     , ___   , ___      , ___,
  ___ , OSM(MOD_LALT) , OSM(MOD_LGUI) , OSM(MOD_LCTL) , OSM(MOD_LSFT) , KC_PGUP            ,                                 KC_HOME            , KC_LEFT          , KC_DOWN , KC_UP , KC_RIGHT , ___,
  ___ , ___           , ___           , C(S(KC_TAB))  , C(KC_TAB)     , KC_PGDN            ,                                 KC_END             , KC_H             , KC_J    , KC_K  , KC_L     , ___,
                                                        KC_RALT       , LT(_NAV, KC_SPACE) , LSFT_T(KC_TAB) ,         KC_R , LT(_SYM, KC_ENTER) , LT(_NUM, KC_ESC)
),

//    ┌─────┬─────┬───┬───┬──────┬───────────────┐                         ┌───────────────┬───────────────┬──────┬──────┬──────┬─────┐
//    │ ___ │ ___ │ 7 │ 8 │  9   │      ___      │                         │      ___      │      ___      │ ___  │ ___  │ ___  │ ___ │
//    ├─────┼─────┼───┼───┼──────┼───────────────┤                         ├───────────────┼───────────────┼──────┼──────┼──────┼─────┤
//    │ ___ │ ___ │ 1 │ 2 │  3   │       0       │                         │      ___      │     lsft      │ lctl │ lgui │ lalt │ ___ │
//    ├─────┼─────┼───┼───┼──────┼───────────────┤                         ├───────────────┼───────────────┼──────┼──────┼──────┼─────┤
//    │ ___ │ ___ │ 4 │ 5 │  6   │      ___      │                         │      ___      │       +       │  ,   │  .   │  -   │ ___ │
//    └─────┴─────┴───┴───┼──────┼───────────────┼─────────────┐       ┌───┼───────────────┼───────────────┼──────┴──────┴──────┴─────┘
//                        │ ralt │ LT(_NAV, spc) │ LSFT_T(tab) │       │ r │ LT(_SYM, ent) │ LT(_NUM, esc) │
//                        └──────┴───────────────┴─────────────┘       └───┴───────────────┴───────────────┘
[_NUM] = LAYOUT_split_3x6_3(
  ___ , ___ , KC_7 , KC_8 , KC_9    , ___                ,                                 ___                , ___              , ___      , ___     , ___      , ___,
  ___ , ___ , KC_1 , KC_2 , KC_3    , KC_0               ,                                 ___                , KC_LSFT          , KC_LCTL  , KC_LGUI , KC_LALT  , ___,
  ___ , ___ , KC_4 , KC_5 , KC_6    , ___                ,                                 ___                , KC_PLUS          , KC_COMMA , KC_DOT  , KC_MINUS , ___,
                            KC_RALT , LT(_NAV, KC_SPACE) , LSFT_T(KC_TAB) ,         KC_R , LT(_SYM, KC_ENTER) , LT(_NUM, KC_ESC)
),

//    ┌─────┬───┬───┬───┬──────┬───────────────┐                         ┌───────────────┬───────────────┬──────┬──────┬──────┬─────┐
//    │ ___ │ @ │ & │ ^ │  $   │       `       │                         │      ___      │      ___      │ ___  │ ___  │ ___  │ ___ │
//    ├─────┼───┼───┼───┼──────┼───────────────┤                         ├───────────────┼───────────────┼──────┼──────┼──────┼─────┤
//    │  \  │ + │ / │ _ │  =   │       -       │                         │      ___      │     lsft      │ lctl │ lgui │ lalt │ ___ │
//    ├─────┼───┼───┼───┼──────┼───────────────┤                         ├───────────────┼───────────────┼──────┼──────┼──────┼─────┤
//    │ ___ │ ~ │ | │ # │  %   │       *       │                         │      ___      │      ___      │ ___  │ ___  │ ___  │ ___ │
//    └─────┴───┴───┴───┼──────┼───────────────┼─────────────┐       ┌───┼───────────────┼───────────────┼──────┴──────┴──────┴─────┘
//                      │ ralt │ LT(_NAV, spc) │ LSFT_T(tab) │       │ r │ LT(_SYM, ent) │ LT(_NUM, esc) │
//                      └──────┴───────────────┴─────────────┘       └───┴───────────────┴───────────────┘
[_SYM] = LAYOUT_split_3x6_3(
  ___          , KC_AT    , KC_AMPERSAND , KC_CIRC       , KC_DOLLAR  , KC_GRAVE           ,                                 ___                , ___              , ___     , ___     , ___     , ___,
  KC_BACKSLASH , KC_PLUS  , KC_SLASH     , KC_UNDERSCORE , KC_EQUAL   , KC_MINUS           ,                                 ___                , KC_LSFT          , KC_LCTL , KC_LGUI , KC_LALT , ___,
  ___          , KC_TILDE , KC_PIPE      , KC_HASH       , KC_PERCENT , KC_ASTERISK        ,                                 ___                , ___              , ___     , ___     , ___     , ___,
                                                           KC_RALT    , LT(_NAV, KC_SPACE) , LSFT_T(KC_TAB) ,         KC_R , LT(_SYM, KC_ENTER) , LT(_NUM, KC_ESC)
)
};

enum combos {
    // left combos
    // WR_AT,
    // FS_SHARP,
    // PT_DOLLAR,
    // BG_PERCENTAGE,
    LCURLY_BRACE,
    RCURLY_BRACE,
    // RX_BACKTICK,
    // SC_BACKSLASH,
    // TD_EQUAL,
    // GV_TIDLE,
    // right combos
    // JM_CARET,
    // LN_PLUS,
    // UE_STAR,
    // YI_AMPERSAND,
    LPAR,
    RPAR,
    LANGLE,
    RANGLE,
    // MK_UNDERSCORE,
    // NH_MINUS,
    // ECOMMA_SLASH,
    // IDOT_PIPE,
    LSQUARE_BRACKET,
    RSQUARE_BRACKET,
    // right combos but not next to each other
    E_AIGUE,
    A_GRAVE,
    E_GRAVE,
    // XD_C_CEDILLE,
    Q,
    Z,
    Z_2,

    // SHIFT_NE_L_ANGLE_BRACKET,
    // SHIFT_EI_R_ANGLE_BRACKET,

    // crossover
    CAPS_WORD,
    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

// const uint16_t PROGMEM wr_at_combo[] = {KC_W, LGUI_T(KC_R), COMBO_END};
// const uint16_t PROGMEM fs_sharp_combo[] = {KC_F, LCTL_T(KC_S), COMBO_END};
// const uint16_t PROGMEM pt_dollar_combo[] = {KC_P, LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM bg_percentage_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM lcurly_brace_combo[] = {LGUI_T(KC_S), LCTL_T(KC_N), COMBO_END};
const uint16_t PROGMEM rcurly_brace_combo[] = {LCTL_T(KC_N), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM rx_backtick_combo[] = {LGUI_T(KC_R), KC_X, COMBO_END};
// const uint16_t PROGMEM sc_backslash_combo[] = {LCTL_T(KC_S), KC_C, COMBO_END};
// const uint16_t PROGMEM td_equal_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END};
// const uint16_t PROGMEM gv_tidle_combo[] = {KC_G, KC_V, COMBO_END};
// const uint16_t PROGMEM jm_caret_combo[] = {KC_J, KC_M, COMBO_END};
// const uint16_t PROGMEM ln_plus_combo[] = {KC_L, LSFT_T(KC_N), COMBO_END};
// const uint16_t PROGMEM ue_star_combo[] = {KC_U, LCTL_T(KC_E), COMBO_END};
// const uint16_t PROGMEM yi_ampersand_combo[] = {KC_Y, LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM lpar_combo[] = {LSFT_T(KC_A), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM rpar_combo[] = {LCTL_T(KC_E), LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {KC_O, KC_Y, COMBO_END};
// const uint16_t PROGMEM mk_underscore_combo[] = {KC_M, KC_K, COMBO_END};
// const uint16_t PROGMEM nh_minus_combo[] = {LSFT_T(KC_N), KC_H, COMBO_END};
// const uint16_t PROGMEM ecomma_slash_combo[] = {LCTL_T(KC_E), KC_COMM, COMBO_END};
// const uint16_t PROGMEM idot_pipe_combo[] = {LGUI_T(KC_I), KC_DOT, COMBO_END};
const uint16_t PROGMEM lsquare_bracket_combo[] = {KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM rsquare_bracket_combo[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM caps_word_combo[] = {LSFT_T(KC_T), LSFT_T(KC_A), COMBO_END};
const uint16_t PROGMEM e_aigue_combo[] = {LSFT_T(KC_A), LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM a_grave_combo[] = {LGUI_T(KC_S), LSFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM e_grave_combo[] = {KC_U, KC_Y, COMBO_END};
// const uint16_t PROGMEM xd_c_cedille_combo[] = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_G, KC_P, COMBO_END};
// const uint16_t PROGMEM z_combo[] = {KC_J, KC_G, COMBO_END};
const uint16_t PROGMEM z_combo_2[] = {KC_G, KC_M, COMBO_END};

combo_t key_combos[] = {
    // [WR_AT] = COMBO(wr_at_combo, KC_AT),
    // [FS_SHARP] = COMBO(fs_sharp_combo, KC_HASH),
    // [PT_DOLLAR] = COMBO(pt_dollar_combo, KC_DOLLAR),
    // [BG_PERCENTAGE] = COMBO(bg_percentage_combo, KC_PERCENT),
    [LCURLY_BRACE] = COMBO(lcurly_brace_combo, KC_LCBR),
    [RCURLY_BRACE] = COMBO(rcurly_brace_combo, KC_RCBR),
    // [RX_BACKTICK] = COMBO(rx_backtick_combo, KC_GRAVE),
    // [SC_BACKSLASH] = COMBO(sc_backslash_combo, KC_BACKSLASH),
    // [TD_EQUAL] = COMBO(td_equal_combo, KC_EQUAL),
    // [GV_TIDLE] = COMBO(gv_tidle_combo, KC_TILDE),
    // [JM_CARET] = COMBO(jm_caret_combo, KC_CIRCUMFLEX),
    // [LN_PLUS] = COMBO(ln_plus_combo, KC_PLUS),
    // [UE_STAR] = COMBO(ue_star_combo, KC_ASTERISK),
    // [YI_AMPERSAND] = COMBO(yi_ampersand_combo, KC_AMPERSAND),
    [LPAR] = COMBO(lpar_combo, KC_LPRN),
    [RPAR] = COMBO(rpar_combo, KC_RPRN),
    [LANGLE] = COMBO(langle_combo, KC_LABK),
    [RANGLE] = COMBO(rangle_combo, KC_RABK),
    // [MK_UNDERSCORE] = COMBO(mk_underscore_combo, KC_UNDERSCORE),
    // [NH_MINUS] = COMBO(nh_minus_combo, KC_MINUS),
    // [ECOMMA_SLASH] = COMBO(ecomma_slash_combo, KC_SLASH),
    // [IDOT_PIPE] = COMBO(idot_pipe_combo, KC_PIPE),
    [LSQUARE_BRACKET] = COMBO(lsquare_bracket_combo, KC_LBRC),
    [RSQUARE_BRACKET] = COMBO(rsquare_bracket_combo, KC_RBRC),
    [Q] = COMBO_ACTION(q_combo),
    // [Z] = COMBO(z_combo, KC_Z),
    [Z] = COMBO_ACTION(z_combo_2),
    [CAPS_WORD] = COMBO(caps_word_combo, QK_CAPS_WORD_TOGGLE),
    [E_AIGUE] = COMBO(e_aigue_combo, RALT(KC_E)),
    [A_GRAVE] = COMBO_ACTION(a_grave_combo),
    [E_GRAVE] = COMBO_ACTION(e_grave_combo)
    // [XD_C_CEDILLE] = COMBO(xd_c_cedille_combo, RALT(KC_COMMA)),
};

const custom_shift_key_t custom_shift_keys[] = {
    {KC_SLASH, KC_ASTERISK},
    {KC_DOT, KC_COLON},
    {KC_DQUO, KC_EXCLAIM},
    {KC_QUOTE, KC_QUESTION},
    {KC_COMMA, KC_SEMICOLON},
    {KC_MINUS, KC_PLUS},
    // {KC_LPRN, KC_LABK},
    // {KC_RPRN, KC_RABK},

};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// const key_override_t dot_key_override =
//     ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);  // Shift . is ?
// const key_override_t comm_key_override =
//     ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SEMICOLON); // Shift , is !
// const key_override_t shifted_comm_key_override =
//     ko_make_basic(MOD_MASK_SA, KC_COMM, RALT(LSFT(KC_COMM)));
// const key_override_t question_key_override =
//     ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM); // Shift : is ;
//
// const key_override_t** key_overrides = (const key_override_t*[]){
//     &shifted_comm_key_override,
//     // &dot_key_override,
//     &comm_key_override,
//     &question_key_override,
//     NULL
// };

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    bool return_state = true;

  if (!process_custom_shift_keys(keycode, record)) { return false; }

    // Do we need to filter multi-function keys?
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (!record->tap.count) // if not tapped yet…
                return true; // let QMK do that first
            keycode &= QK_BASIC_MAX; // mods & taps have been handled.
    }

#ifdef ADAPTIVE_ENABLE
    if (!process_adaptive_key(keycode, record)) {
        return false; // took care of that key
    }
#endif

    return return_state;  // keep processing record

  return true;
}

uint8_t  combo_on = 0;           // for combo actions to hold before triggering
bool  combo_triggered = false;   // for one-shot-combo-actions
uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (pressed) {
      switch(combo_index) {
        case A_GRAVE:
          if (pressed) {
            tap_code16(RALT(KC_GRAVE));
            tap_code16(KC_A);
          }
          break;
        case E_GRAVE:
          if (pressed) {
            tap_code16(RALT(KC_GRAVE));
            tap_code16(KC_E);
          }
          break;
        case Q: //
            if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                break;
            tap_code16(KC_Q); //
            unregister_mods(MOD_MASK_SHIFT);  //
            tap_code16(KC_U); //
            combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
            break;
        case Z: //
            tap_code16(KC_Z); //
            combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
            break;
      }
        if (combo_on) linger_timer = timer_read(); // start timing for linger process
    } else {
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo
            switch (combo_index) {
                case Q: //
                    unregister_code16(KC_Q); //
                    linger_key = 0;
                    break;
            }
        }
        combo_on = combo_triggered = false;
    }
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user if combo_on

    // These combos are to be held for COMBO_HOLD term before triggering
    // to avoid accidental triggers while fast typing these common rolls (or on home row).
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi on qwerty), so maybe best to avoid them as
    // combos.
    // I've successfully added COMBO_HOLD Home Row combos without difficulty.
    // To use multiple home row mods, just put them down one at a time...works great.
    //
    if (!combo_triggered) {
        // do simple "on" on held actions and then turn on combo state in process_combo_event above,
        // then handle hold actions here,
        // before resolving in keyup event above.
        // if necessary (like releasing the underlying keys, or other cleanup)
        if ((timer_elapsed(linger_timer) > COMBO_HOLD) && combo_on) {
            saved_mods = get_mods();
            clear_mods();
            switch(combo_on) {  // combo_on is global, set in process_combo above
                // case HC_OE:
                case Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;
            } // switch
            set_mods(saved_mods); // Restore mods
            combo_triggered = true;
        } //  if (combo_on) {
    }
}


void matrix_scan_user(void) {

    // Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }


    //
    // prior register_linger_key(kc) needs to be handled here
    //
    if (linger_key) { // A linger key is being held down
        if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
            saved_mods = get_mods();
            clear_mods();
            unregister_mods(MOD_MASK_SHIFT);  // second char isn't shifted. CAPSLOCK UNAFFECTED.
            switch(linger_key) {
                case KC_Q: // already "Q" has been sent; if lingered, add "u"
                    tap_code(KC_U);
                    break;

                default:
                    break;
            }
            linger_timer = linger_key = 0; // done lingering
            set_mods(saved_mods); // Restore mods
        }
    }
}
