// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap.h"
#include "features/custom_shift_key.h"
#include "keymap_us_international.h"


enum layers {
    _COLEMAK,  // default layer
    _NAV,
    _NUM,
    _SYM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────────────┬───────────┬───────────┬───────────┬───────────────┬───────────────┐                                       ┌───────────────┬───────────┬───────────┬───────────┬───────────┬──────┐
//    │ RALT(US_6) │     q     │     w     │     f     │       p       │       b       │                                       │       j       │     l     │     u     │     y     │    "'"    │ ___  │
//    ├────────────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤                                       ├───────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │  RALT(`)   │ LALT_T(a) │ LGUI_T(r) │ LCTL_T(s) │   LSFT_T(t)   │       g       │                                       │       m       │ LSFT_T(n) │ LCTL_T(e) │ LGUI_T(i) │ LALT_T(o) │ bspc │
//    ├────────────┼───────────┼───────────┼───────────┼───────────────┼───────────────┤                                       ├───────────────┼───────────┼───────────┼───────────┼───────────┼──────┤
//    │    ___     │     z     │     x     │     c     │       d       │       v       │                                       │       k       │     h     │     ,     │     .     │     ?     │ ___  │
//    └────────────┴───────────┴───────────┴───────────┼───────────────┼───────────────┼───────────────┐       ┌───────────────┼───────────────┼───────────┼───────────┴───────────┴───────────┴──────┘
//                                                     │ OSM(MOD_RALT) │ LT(_NAV, spc) │ OSM(MOD_LSFT) │       │ LT(_NUM, tab) │ LT(_SYM, ent) │    esc    │
//                                                     └───────────────┴───────────────┴───────────────┘       └───────────────┴───────────────┴───────────┘
[_COLEMAK] = LAYOUT_split_3x6_3(
  RALT(US_6)     , KC_Q         , KC_W         , KC_F         , KC_P          , KC_B             ,                                            KC_J               , KC_L         , KC_U         , KC_Y         , KC_QUOTE     , ___    ,
  RALT(KC_GRAVE) , LALT_T(KC_A) , LGUI_T(KC_R) , LCTL_T(KC_S) , LSFT_T(KC_T)  , KC_G             ,                                            KC_M               , LSFT_T(KC_N) , LCTL_T(KC_E) , LGUI_T(KC_I) , LALT_T(KC_O) , KC_BSPC,
  ___            , KC_Z         , KC_X         , KC_C         , KC_D          , KC_V             ,                                            KC_K               , KC_H         , KC_COMM      , KC_DOT       , KC_QUESTION  , ___    ,
                                                                OSM(MOD_RALT) , LT(_NAV, KC_SPC) , OSM(MOD_LSFT) ,         LT(_NUM, KC_TAB) , LT(_SYM, KC_ENTER) , KC_ESC
),

//    ┌─────┬───────────────┬───────────────┬───────────────┬───────────────┬───────────────┐                                       ┌───────────────┬──────┬──────┬─────┬──────┬─────┐
//    │ ___ │      ___      │      ___      │      ___      │      ___      │      ___      │                                       │      ___      │ ___  │ ___  │ ___ │ ___  │ ___ │
//    ├─────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼─────┼──────┼─────┤
//    │ ___ │ OSM(MOD_LALT) │ OSM(MOD_LGUI) │ OSM(MOD_LCTL) │ OSM(MOD_LSFT) │      ___      │                                       │      ___      │ left │ down │ up  │ rght │ ___ │
//    ├─────┼───────────────┼───────────────┼───────────────┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼─────┼──────┼─────┤
//    │ ___ │      ___      │      ___      │   C(S(tab))   │    C(tab)     │      ___      │                                       │      ___      │  h   │  j   │  k  │  l   │ ___ │
//    └─────┴───────────────┴───────────────┴───────────────┼───────────────┼───────────────┼───────────────┐       ┌───────────────┼───────────────┼──────┼──────┴─────┴──────┴─────┘
//                                                          │ OSM(MOD_RALT) │ LT(_NAV, spc) │ OSM(MOD_LSFT) │       │ LT(_NUM, tab) │ LT(_SYM, ent) │ esc  │
//                                                          └───────────────┴───────────────┴───────────────┘       └───────────────┴───────────────┴──────┘
[_NAV] = LAYOUT_split_3x6_3(
  ___ , ___           , ___           , ___           , ___           , ___              ,                                            ___                , ___     , ___     , ___   , ___      , ___,
  ___ , OSM(MOD_LALT) , OSM(MOD_LGUI) , OSM(MOD_LCTL) , OSM(MOD_LSFT) , ___              ,                                            ___                , KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT , ___,
  ___ , ___           , ___           , C(S(KC_TAB))  , C(KC_TAB)     , ___              ,                                            ___                , KC_H    , KC_J    , KC_K  , KC_L     , ___,
                                                        OSM(MOD_RALT) , LT(_NAV, KC_SPC) , OSM(MOD_LSFT) ,         LT(_NUM, KC_TAB) , LT(_SYM, KC_ENTER) , KC_ESC
),

//    ┌─────┬─────┬───┬───┬───────────────┬───────────────┐                                       ┌───────────────┬──────┬──────┬──────┬──────┬─────┐
//    │ ___ │ ___ │ 7 │ 8 │       9       │      ___      │                                       │      ___      │ ___  │ ___  │ ___  │ ___  │ ___ │
//    ├─────┼─────┼───┼───┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼──────┼──────┼─────┤
//    │ ___ │ ___ │ 1 │ 2 │       3       │       0       │                                       │      ___      │ lsft │ lctl │ lgui │ lalt │ ___ │
//    ├─────┼─────┼───┼───┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼──────┼──────┼─────┤
//    │ ___ │ ___ │ 4 │ 5 │       6       │      ___      │                                       │      ___      │  +   │  ,   │  .   │  -   │ ___ │
//    └─────┴─────┴───┴───┼───────────────┼───────────────┼───────────────┐       ┌───────────────┼───────────────┼──────┼──────┴──────┴──────┴─────┘
//                        │ OSM(MOD_RALT) │ LT(_NAV, spc) │ OSM(MOD_LSFT) │       │ LT(_NUM, tab) │ LT(_SYM, ent) │ esc  │
//                        └───────────────┴───────────────┴───────────────┘       └───────────────┴───────────────┴──────┘
[_NUM] = LAYOUT_split_3x6_3(
  ___ , ___ , KC_7 , KC_8 , KC_9          , ___              ,                                            ___                , ___     , ___      , ___     , ___      , ___,
  ___ , ___ , KC_1 , KC_2 , KC_3          , KC_0             ,                                            ___                , KC_LSFT , KC_LCTL  , KC_LGUI , KC_LALT  , ___,
  ___ , ___ , KC_4 , KC_5 , KC_6          , ___              ,                                            ___                , KC_PLUS , KC_COMMA , KC_DOT  , KC_MINUS , ___,
                            OSM(MOD_RALT) , LT(_NAV, KC_SPC) , OSM(MOD_LSFT) ,         LT(_NUM, KC_TAB) , LT(_SYM, KC_ENTER) , KC_ESC
),

//    ┌───────────┬──────┬───┬───┬───────────────┬───────────────┐                                       ┌───────────────┬──────┬──────┬──────┬──────┬─────┐
//    │    ___    │  @   │ & │ ^ │       $       │       +       │                                       │      ___      │ ___  │ ___  │ ___  │ ___  │ ___ │
//    ├───────────┼──────┼───┼───┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼──────┼──────┼─────┤
//    │ bACKSLASH │  ~   │ / │ _ │       =       │       -       │                                       │      ___      │ lsft │ lctl │ lgui │ lalt │ ___ │
//    ├───────────┼──────┼───┼───┼───────────────┼───────────────┤                                       ├───────────────┼──────┼──────┼──────┼──────┼─────┤
//    │    ___    │ '--' │ | │ ~ │       %       │       *       │                                       │      ___      │ ___  │ ___  │ ___  │ ___  │ ___ │
//    └───────────┴──────┴───┴───┼───────────────┼───────────────┼───────────────┐       ┌───────────────┼───────────────┼──────┼──────┴──────┴──────┴─────┘
//                               │ OSM(MOD_RALT) │ LT(_NAV, spc) │ OSM(MOD_LSFT) │       │ LT(_NUM, tab) │ LT(_SYM, ent) │ esc  │
//                               └───────────────┴───────────────┴───────────────┘       └───────────────┴───────────────┴──────┘
[_SYM] = LAYOUT_split_3x6_3(
  ___          , KC_AT    , KC_AMPERSAND , KC_CIRC       , KC_DOLLAR     , KC_PLUS          ,                                            ___                , ___     , ___     , ___     , ___     , ___,
  KC_BACKSLASH , KC_TILDE , KC_SLASH     , KC_UNDERSCORE , KC_EQUAL      , KC_MINUS         ,                                            ___                , KC_LSFT , KC_LCTL , KC_LGUI , KC_LALT , ___,
  ___          , KC_HASH  , KC_PIPE      , KC_TILDE      , KC_PERCENT    , KC_ASTERISK      ,                                            ___                , ___     , ___     , ___     , ___     , ___,
                                                           OSM(MOD_RALT) , LT(_NAV, KC_SPC) , OSM(MOD_LSFT) ,         LT(_NUM, KC_TAB) , LT(_SYM, KC_ENTER) , KC_ESC
)
};

enum combos {
    // left combos
    // WR_AT,
    // FS_SHARP,
    // PT_DOLLAR,
    // BG_PERCENTAGE,
    RS_LCURLY_BRACE,
    ST_RCURLY_BRACE,
    // RX_BACKTICK,
    // SC_BACKSLASH,
    // TD_EQUAL,
    // GV_TIDLE,
    // right combos
    // JM_CARET,
    // LN_PLUS,
    // UE_STAR,
    // YI_AMPERSAND,
    NE_LPAR,
    EI_RPAR,
    HCOMMA_LANGLE,
    COMMADOT_RANGLE,
    // MK_UNDERSCORE,
    // NH_MINUS,
    // ECOMMA_SLASH,
    // IDOT_PIPE,
    XC_LSQUARE_BRACKET,
    CD_RSQUARE_BRACKET,
    // right combos but not next to each other
    // NI_E_AIGUE,
    // XD_C_CEDILLE,


    // SHIFT_NE_L_ANGLE_BRACKET,
    // SHIFT_EI_R_ANGLE_BRACKET,

    // crossover
    TN_CAPS_WORD,
    COMBO_LENGTH
};


uint16_t COMBO_LEN = COMBO_LENGTH;

// const uint16_t PROGMEM wr_at_combo[] = {KC_W, LGUI_T(KC_R), COMBO_END};
// const uint16_t PROGMEM fs_sharp_combo[] = {KC_F, LCTL_T(KC_S), COMBO_END};
// const uint16_t PROGMEM pt_dollar_combo[] = {KC_P, LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM bg_percentage_combo[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM rs_lcurly_brace_combo[] = {LGUI_T(KC_R), LCTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM st_rcurly_brace_combo[] = {LCTL_T(KC_S), LSFT_T(KC_T), COMBO_END};
// const uint16_t PROGMEM rx_backtick_combo[] = {LGUI_T(KC_R), KC_X, COMBO_END};
// const uint16_t PROGMEM sc_backslash_combo[] = {LCTL_T(KC_S), KC_C, COMBO_END};
// const uint16_t PROGMEM td_equal_combo[] = {LSFT_T(KC_T), KC_D, COMBO_END};
// const uint16_t PROGMEM gv_tidle_combo[] = {KC_G, KC_V, COMBO_END};
// const uint16_t PROGMEM jm_caret_combo[] = {KC_J, KC_M, COMBO_END};
// const uint16_t PROGMEM ln_plus_combo[] = {KC_L, LSFT_T(KC_N), COMBO_END};
// const uint16_t PROGMEM ue_star_combo[] = {KC_U, LCTL_T(KC_E), COMBO_END};
// const uint16_t PROGMEM yi_ampersand_combo[] = {KC_Y, LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM ne_lpar_combo[] = {LSFT_T(KC_N), LCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM ei_rpar_combo[] = {LCTL_T(KC_E), LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM hcomma_langle_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM commadot_rangle_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
// const uint16_t PROGMEM mk_underscore_combo[] = {KC_M, KC_K, COMBO_END};
// const uint16_t PROGMEM nh_minus_combo[] = {LSFT_T(KC_N), KC_H, COMBO_END};
// const uint16_t PROGMEM ecomma_slash_combo[] = {LCTL_T(KC_E), KC_COMM, COMBO_END};
// const uint16_t PROGMEM idot_pipe_combo[] = {LGUI_T(KC_I), KC_DOT, COMBO_END};
const uint16_t PROGMEM xc_lsquare_bracket_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cd_rsquare_bracket_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM tn_caps_word_combo[] = {LSFT_T(KC_T), LSFT_T(KC_N), COMBO_END};
// const uint16_t PROGMEM ni_e_aigue_combo[] = {LSFT_T(KC_N), LGUI_T(KC_I), COMBO_END};
// const uint16_t PROGMEM xd_c_cedille_combo[] = {KC_X, KC_D, COMBO_END};

combo_t key_combos[] = {
    // [WR_AT] = COMBO(wr_at_combo, KC_AT),
    // [FS_SHARP] = COMBO(fs_sharp_combo, KC_HASH),
    // [PT_DOLLAR] = COMBO(pt_dollar_combo, KC_DOLLAR),
    // [BG_PERCENTAGE] = COMBO(bg_percentage_combo, KC_PERCENT),
    [RS_LCURLY_BRACE] = COMBO(rs_lcurly_brace_combo, KC_LCBR),
    [ST_RCURLY_BRACE] = COMBO(st_rcurly_brace_combo, KC_RCBR),
    // [RX_BACKTICK] = COMBO(rx_backtick_combo, KC_GRAVE),
    // [SC_BACKSLASH] = COMBO(sc_backslash_combo, KC_BACKSLASH),
    // [TD_EQUAL] = COMBO(td_equal_combo, KC_EQUAL),
    // [GV_TIDLE] = COMBO(gv_tidle_combo, KC_TILDE),
    // [JM_CARET] = COMBO(jm_caret_combo, KC_CIRCUMFLEX),
    // [LN_PLUS] = COMBO(ln_plus_combo, KC_PLUS),
    // [UE_STAR] = COMBO(ue_star_combo, KC_ASTERISK),
    // [YI_AMPERSAND] = COMBO(yi_ampersand_combo, KC_AMPERSAND),
    [NE_LPAR] = COMBO(ne_lpar_combo, KC_LPRN),
    [EI_RPAR] = COMBO(ei_rpar_combo, KC_RPRN),
    [HCOMMA_LANGLE] = COMBO(hcomma_langle_combo, KC_LABK),
    [COMMADOT_RANGLE] = COMBO(commadot_rangle_combo, KC_RABK),
    // [MK_UNDERSCORE] = COMBO(mk_underscore_combo, KC_UNDERSCORE),
    // [NH_MINUS] = COMBO(nh_minus_combo, KC_MINUS),
    // [ECOMMA_SLASH] = COMBO(ecomma_slash_combo, KC_SLASH),
    // [IDOT_PIPE] = COMBO(idot_pipe_combo, KC_PIPE),
    [XC_LSQUARE_BRACKET] = COMBO(xc_lsquare_bracket_combo, KC_LBRC),
    [CD_RSQUARE_BRACKET] = COMBO(cd_rsquare_bracket_combo, KC_RBRC),
    [TN_CAPS_WORD] = COMBO(tn_caps_word_combo, QK_CAPS_WORD_TOGGLE),
    // [NI_E_AIGUE] = COMBO(ni_e_aigue_combo, RALT(KC_E)),
    // [XD_C_CEDILLE] = COMBO(xd_c_cedille_combo, RALT(KC_COMMA)),
};

const custom_shift_key_t custom_shift_keys[] = {
    {KC_QUESTION, KC_EXCLAIM},
    {KC_COMMA, KC_SEMICOLON},
    {KC_DOT, KC_COLON},
    // {KC_LPRN, KC_LABK},
    // {KC_RPRN, KC_RABK},

};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  return true;
}
