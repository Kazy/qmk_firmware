/*
 Adaptive Keys
 Called from early within process_record_user

 Tailored for HD Vibranium-b (vb)

 NOTE: assumed dual-function keys (MOD_TAP, LAYER_TAP) have already been handled AND
    FILTERED OUT! The combos handler will have already taken out combo candidates,
    which have a shorter keydown threshhold (COMBO_TERM).

 */

/*
 * Check https://norvig.com/mayzner.html to see which bigram to prioritize
 * Enabled:
 * - GJ: GTH
 * - MV: MN
 * - GM: GL
 * - MG: LG
 * - JM: LM
 * - TN: TION
 * - PN: PT
 * - GP: PL
 * - AH: AU
 * - UH: UA
 * - IH: IY
 * - YB: YI
 */

#include "keymap.h"
#include QMK_KEYBOARD_H

static uint16_t prior_keycode = KC_NO;
static uint16_t preprior_keycode = KC_NO;
static uint32_t prior_keydown = 0;
static uint8_t saved_mods;

bool process_adaptive_key_inner(uint16_t keycode, const keyrecord_t *record) {
    bool return_state = true; // assume we don't do anything.

    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    switch (keycode) { // process ignoring multi-function keys & shift state?
/*
// Left hand adaptives (most are single-handed neighbor fingers, bc speed, dexterity limits)
*/
        // case KC_B:
        //     switch (prior_keycode) {
        //         case KC_D: // avoid SFB (DV is 5x more common than DB)
        //             tap_code(KC_V);
        //             return_state = false; // done.
        //             break;
        //        case KC_P: // avoid row step (PS is 40x more common than PB)
        //             tap_code(KC_S);
        //             return_state = false; // done.
        //             break;
        //        case KC_C: // eliminate SB SFB (CB is 11x more common than SB)
        //             tap_code(KC_BSPC);
        //             tap_code(KC_S);
        //             break;
        //    }
        //     break;

        // case KC_C:
        //     switch (prior_keycode) {
        //         case KC_T: // roll for tch
        //             send_string("ch"); // 85% of tc is tch, so this saves a lot of key press "H"
        //             return_state = false; // done.
        //             break;
        //         case KC_B: // eliminate BS SFB (BS is 23x more common than BC)
        //             tap_code(KC_S);  //
        //             return_state = false; // done.
        //             break;
        //     }
        //     break;

//         case KC_D: // (for KD=KL; least code, no side effects)
//             switch (prior_keycode) { //
//                 case KC_K:
//                 case KC_V:
//                     tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
//                     return_state = false; // done.
//                     break;
// /*
//                 case KC_B: // to avoid the scissor on BM
//                     tap_code(KC_M);
//                     return_state = false; // done.
//                     break;
// */
//                 case KC_L:
//                     if (preprior_keycode == KC_P) { // PLD = PWD?
//                         tap_code(KC_BSPC);
//                         tap_code(KC_W); // replace the L with W
//                         break; // process the D normally
//                     }
//             }
//             break;

        case KC_G:
            switch (prior_keycode) {
                case KC_P:
                    tap_code(KC_L);  // pull up "L" (KL is 5x more common than KG)
                    return_state = false; // done.
                    break;
               case KC_M:
                    // if (preprior_keycode == KC_W) { // to roll WMG -> lml?
                    //     tap_code(KC_L); // replace the G with L
                    //     return_state = false; // done.
                    //     break; // process the D normally
                    // }
                    tap_code(KC_BSPC);
                    tap_code(KC_L);
                    break; // and let current keycode send normally
                // case KC_J: // JG = jpg
                //     tap_code(KC_P); // insert a P
                //     break; // and let current keycode send normally
                // case KC_W:
                //     tap_code(KC_D); // pull up D (WD is 35x more common than WG)
                //     return_state = false; // done.
                //     break;
            }
            break;

        case KC_J:
            switch (prior_keycode) {
                case KC_G: // "GTH" is an awkward trigram/skipgram
                    send_string("th"); // for "length"
                    return_state = false; // done.
                    break;
                // case KC_M: // Eliminate MN SFB
                //     tap_code(KC_N); // MJ = mn (MN is 83x more common than MJ)
                //     return_state = false; // done.
                //     break;
            }
            break;

        // case KC_L: // catch this so we can unshift L on these rolls.
        //     switch (prior_keycode) {
        //         case KC_P:
        //         case KC_B: //
        //         case KC_S: //
        //         case KC_V: //
        //             tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
        //             return_state = false; // done.
        //             break;
        //     }
        //     break;

        case KC_M: // M becomes L (pull up "L" to same row)
            switch (prior_keycode) {
                case KC_G: // pull up "L" (GL is 5x more common than GM)
                // case KC_X: // pull up "L" (XL is 1.5x more common than XM)
                    tap_code(KC_L);  // pull up "L" (PL is 15x more common than PM)
                    return_state = false; // done.
                    break;
                case KC_J: // WM = LM (LM 20x more common)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
                    // switch (preprior_keycode) {
                    //     case KC_M:
                    //     case KC_X:
                    //     default:
                    //         tap_code(KC_BSPC);
                    //         send_string("lm");
                    //         return_state = false; // done.
                    // }
            }
            break;

        case KC_N: // N becomes H (for H-Digraph rolls)
            switch (prior_keycode) {
                case KC_T: // "TION" is 58x more common than "TN"
                    send_string("ion");
                    return_state = false; // done.
                    break;
                case KC_P: // "TION" is 58x more common than "TN"
                    tap_code(KC_T);
                    return_state = false; // done.
                    break;
//                case KC_C: // cn = ln (CN 5x more common)
                // case KC_X: // xn = ln (LN 101x more common)
                //     tap_code(KC_BSPC);
                //     tap_code(KC_L);
                //     return_state = true; // let the N happen.
                //     break;
            }
            break;

        // case KC_P:
        //     switch (prior_keycode) {
        //         case KC_D: // DP = DT eliminate SFB (DT is 2.5x more common)
        //             tap_code(KC_G);
        //             return_state = false; // done.
        //             break;
        //         case KC_B: // Pull S down (SP is 83x more common than BP)
        //             tap_code(KC_BSPC);
        //             tap_code(KC_S); //(but maybe should be BS? SP/BS are about equal...)
        //             return_state = true; // not done (process this key normally)
        //             break;
        //     }
        //     break;

        // case KC_T:  // alt fingering remedy for middle-index splits
        //     switch (prior_keycode) {
        //         case KC_K: // quickly typing "kt" yields "kn" (+48x)
        //             tap_code(KC_N);
        //             return_state = false; // done.
        //             break;
        //     }
        //     break;

        // case KC_W: // W becomes P (pull up "P" to same row)
        //     switch (prior_keycode) {
        //         // case KC_M: // pull up P (W becomes P after M to set up "mp"+l)
        //         //     if (preprior_keycode == KC_W) { // except for WMW -> lml?
        //         //         tap_code(KC_L); // replace the W with L
        //         //         return_state = false; // done.
        //         //         break; // process the D normally
        //         //     }
        //         // case KC_W: // WW doesn't exist, so to permit PP after M...
        //         // case KC_X: // pull up P (W becomes P after X to set up "xp"+l)
        //         //     tap_code(KC_P); // pull up P from bottom row.
        //         //     return_state = false; // done.
        //         //     break;
        //         // case KC_G:
        //         //     tap_code(KC_D); // eliminate SFB on index
        //         //     return_state = false; // done.
        //         //     break;
        //         // case KC_N: // avoid SFB (NL is 10x more common than NW)
        //         //     tap_code(KC_L);
        //         //     return_state = false; // done.
        //         //     break;
        //     }
        //     break;

            // remedy ring-index split by shifting fingering
            // Since the hand is already displaced to reach the inner column,
            // pull the L over with alternate fingering to avoid the stretch.
        // case KC_K:
        //     switch (prior_keycode) {
        //         case KC_T: // TK = CK (CK is 252x more common than TK))
        //             tap_code(KC_BSPC); // replace T
        //             tap_code(KC_C);
        //             break; // Send K normally
        //         case KC_D:
        //         case KC_G:
        //             tap_code(KC_BSPC); // replace D/G
        //             tap_code(KC_L);
        //             break; // Send K normally
        //     }
        //     break;

        case KC_V: // remedy inner column split by shifting fingering
            switch (prior_keycode) {
                case KC_M:
                    tap_code(KC_N);
                    return_state = false;
                    break;
//                case KC_D: // TV/DV/GV = LV ()
//                case KC_G: //

                // case KC_T: // TK/DK/GK = LK ()
                //     tap_code(KC_BSPC);
                //     tap_code(KC_L);
                //     break; // and let current keycode send normally
            }
            break;

/*
        case KC_R:  // LL is the highest consonant repeat, and it's off home, so eliminate this SFB
            switch (prior_keycode) {
                case KC_L: // quickly typing "lr" yields "ll" (+56x)
                    tap_code(KC_L);
                    return_state = false; // done.
                    break;
            }
            break;
*/
        // case KC_X:
        //     switch (prior_keycode) {
        //         case KC_M: // "MB" is 2558x more frequent than "MX"
        //             tap_code(KC_B); // pull up B from bottom row.
        //             return_state = false; // done.
        //             break;
        //         case KC_G: // "GT" is 778x more frequent than "GX"
        //             tap_code(KC_T); // eliminate GT SFB.
        //             return_state = false; // done.
        //             break;
        //         case KC_N: // avoid SFB (NL is 23x more common than NX)
        //             tap_code(KC_L);
        //             return_state = false; // done.
        //             break;
        //     }
        //     break;


/*
// right hand adaptives
*/

          // case KC_QUOT:
          //     switch (prior_keycode) {
          //     }
          //     break;

            // case KC_SLSH:
            //     switch (prior_keycode) {
            //         case KC_DOT:
            //             send_string("com");
            //             return_state = false; // done.
            //             break;
            //
            //     }
            //     break;

        case KC_H: // H precedes a vowel much more often than it follows (thanks, Ancient Greek!)
            switch (prior_keycode) { // maybe OK? What about xxR? resulting in a SFB on thumb?
#ifdef ADAPT_VOWEL_H
                case KC_A: // AE is a fraction less common (8x), but the EAE trill may be harder than EAH.
                    tap_code(KC_U); // "AH" yields "AU" (7x more common)
                    return_state = false; // done.
                    break;
                case KC_U:
                    tap_code(KC_A); // "UH" yields "UA" (126x more common)
                    return_state = false; // done.
                    break;
                // case KC_E: // these EO/OE adaptives are of questionable value
                //     tap_code(KC_O); // "EH" yields "EO" (1.75:1)
                //     return_state = false; // done.
                    // break;
                // case KC_O:
                //     tap_code(KC_E); // "OH" yields "OE" (almost 1:1, but eliminates an SFB?)
                //     return_state = false; // done.
                //     break;
#endif // ADAPT_VOWEL_H
                // case KC_I:
                //     tap_code(KC_Y); // (inverted IH->IF = IF->IY)
                //     return_state = false; // done.
                //     break;
                case KC_I: // avoid row skip on outward pinky roll
                    tap_code(KC_Y); // "IH" yields "IF" (96x more common)
                    return_state = false; // done.
                    break;
            }
            break;
        case KC_B:
            switch (prior_keycode) { // IF is much more common than IY, so optimizing
                case KC_Y: // YF = YI (eliminate SFB on ring finger)
                    tap_code(KC_I); // (YI is 37x more common)
                    return_state = false; // done.
                    break;
            }
            break;


#ifdef ADAPTIVE_TRAILER
#include "adaptive_trailer.c"
#endif // ADAPTIVE_TRAILER

    }
    if (return_state) { // no adaptive processed, cancel state and pass it on.
        set_mods(saved_mods);
        prior_keycode = preprior_keycode = keycode = 0;
    }
    return return_state;
}

bool process_adaptive_key(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
        if (!process_adaptive_key_inner(keycode, record)) {
            prior_keydown = timer_read(); // (re)start prior_key timing
            preprior_keycode = prior_keycode; // look back 2 keystrokes?
            prior_keycode = keycode; // this keycode is stripped of mods+taps
            return false; // took care of that key
        }
        prior_keydown = timer_read(); // (re)start prior_key timing
        preprior_keycode = prior_keycode; // look back 2 keystrokes?
        prior_keycode = keycode; // this keycode is stripped of mods+taps
    }

    return true;
}
