#include QMK_KEYBOARD_H
#include <stdio.h> // Include for printf
/* #include "keymap_us_international.h" */
/* #include "sendstring_us_international.h" */

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN LCTL_T(KC_SCLN)

// layers
/* #define LY1BS LT(1, KC_BSPC) */
/* #define LY2T LT(2, KC_TAB) */
/* #define LY3BS LT(3, KC_BSPC) */
/* #define LY3T LT(4, KC_TAB) */
#define LBASE 0
#define LNUM 1
#define LARROW 2
#define LBOOT 3
#define LPART 4
#define LWIN1 5
#define LVIMNAV 6
#define LVIMGIT 7
#define LVIMMOV 8
#define LGAME 9
#define LMOUSE 10



// For the tap_hold tap dance:
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// For custom tap dance:
typedef struct {
    uint16_t keycode;
} tap_dance_keycode;



// --- tap dances ---
// Tap Dance declarations
enum tap_dances {
    TD_V_ESC,
    TD_A_ESC,
    TD_CLN,
    TD_EQL,
    TD_BSPC,
    TD_QUOT,
    TD_COLN,
    TD_SLSH,
    TD_LPRN,
    TD_RPRN,
    TD_LBRC,
    TD_AMPR,
    TD_DLR,
    TD_AT,
    TD_CIRC,
    TD_COM,
    TD_DOT,
    // for window managements:
    TD_WRS1,
    TD_WRS2,
    TD_WRS3,
    TD_WRS4,
    TD_WRS5,
    TD_WRS6,
    TD_WRS7,
    TD_WRS8,
    TD_WRS9,
    TD_WND,
    TD_WSW,
    // for vim navigation:
    TD_SD1,
    TD_SU1,
    TD_ZZ,
    // for vim shortcuts
    TD_YC,
    TD_FF,
    TD_GSH,
    TD_GRH,
    TD_GPV,
    TD_GTD,
    TD_GDT,
    TD_GBL,
    TD_GC,
};

enum custom_keycodes {
    BEGIN = SAFE_RANGE,
// --- For send strings ---
    SS_WL, //Window left
    SS_WR, //Window right
    SS_WU, //Window up
    SS_WD, //Window down
    SS_WSU, //Window size increase
    SS_WSD, //Window size decrease
    SS_WSR, //Window size reset
    SS_GG, //GG for move line number
    SS_GUS, //Git undo stage hunk
    SS_QR, //Quit(close) current window and resize
    SS_GNH, //Git next hunk
    SS_GPH, //Git previous hunk
// --- For sm_td ---
// https://github.com/stasmarkin/sm_td

    SMTD_KEYCODES_BEGIN,
    CKC_A, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_UNDS,
    CKC_1,
    CKC_2,
    CKC_3,
    CKC_4,
    CKC_7,
    CKC_8,
    CKC_9,
    CKC_0,
    CKC_DOWN,
    CKC_UP,
    CKC_RIGHT,
    CKC_ENT,
    CKC_ENT_GUI,
    CKC_STAB,
    CKC_SPACE,
    CKC_ENTER,
    CKC_SPACE3,
    CKC_ENTER3,
    CKC_TAB,
    CKC_ESC,
    CKC_VIMGIT,
    SMTD_KEYCODES_END,
    DBG_ENUM, // Add a keycode to trigger debug print
};

enum tapdances_keycodes {
    V_ESC = TD(TD_V_ESC),
    A_ESC = TD(TD_A_ESC),
    CLN = TD(TD_CLN),
    EQL = TD(TD_EQL),
    BSPC = TD(TD_BSPC),
    QUOT = TD(TD_QUOT),
    COLN = TD(TD_COLN),
    SLSH = TD(TD_SLSH),
    LPRN = TD(TD_LPRN),
    RPRN = TD(TD_RPRN),
    LBRC = TD(TD_LBRC),
    AMPR = TD(TD_AMPR),
    DLR = TD(TD_DLR),
    AT = TD(TD_AT),
    CIRC = TD(TD_CIRC),
    COM = TD(TD_COM),
    DOT = TD(TD_DOT),
// --- For window resize ---
    WRS1 = TD(TD_WRS1),
    WRS2 = TD(TD_WRS2),
    WRS3 = TD(TD_WRS3),
    WRS4 = TD(TD_WRS4),
    WRS5 = TD(TD_WRS5),
    WRS6 = TD(TD_WRS6),
    WRS7 = TD(TD_WRS7),
    WRS8 = TD(TD_WRS8),
    WRS9 = TD(TD_WRS9),
    WND = TD(TD_WND),
    WSW = TD(TD_WSW),
// --- For vim navigation ---
    SD1 = TD(TD_SD1),
    SU1 = TD(TD_SU1),
    ZZ = TD(TD_ZZ), //Window center-top
// --- For vim shortcuts ---
    FF = TD(TD_FF), // Telescope find files
    YC = TD(TD_YC), // Yank to clipboard or a buffer
// --- For vim git shortcuts (gitsigns,...) ---
    GSH = TD(TD_GSH), // git stage hunk
    GRH = TD(TD_GRH), // git reset hunk
    GPV = TD(TD_GPV), // git preview hunk
    GTD = TD(TD_GTD), // git toggle diffs
    GDT = TD(TD_GDT), // git diff this
    GBL = TD(TD_GBL), // git blame
    GC = TD(TD_GC), // git commits
};


#include "sm_td.h"
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LSFT)
        SMTD_MT(CKC_S, KC_S, KC_LCTL)
        SMTD_MT(CKC_D, KC_D, KC_LALT)
        SMTD_MT(CKC_F, KC_F, KC_LGUI)
        SMTD_MT(CKC_J, KC_J, KC_RGUI)
        SMTD_MT(CKC_K, KC_K, KC_RALT)
        SMTD_MT(CKC_L, KC_L, KC_LCTL)
        SMTD_MT(CKC_UNDS, KC_UNDS, KC_RSFT)
        SMTD_MT(CKC_1, KC_1, KC_LSFT)
        SMTD_MT(CKC_2, KC_2, KC_LCTL)
        SMTD_MT(CKC_3, KC_3, KC_LALT)
        SMTD_MT(CKC_4, KC_4, KC_LGUI)
        SMTD_MT(CKC_7, KC_7, KC_RGUI)
        SMTD_MT(CKC_8, KC_8, KC_RALT)
        SMTD_MT(CKC_9, KC_9, KC_LCTL)
        SMTD_MT(CKC_0, KC_0, KC_RSFT)
        SMTD_MT(CKC_DOWN, KC_DOWN, KC_RGUI)
        SMTD_MT(CKC_UP, KC_UP, KC_RALT)
        SMTD_MT(CKC_RIGHT, KC_RIGHT, KC_LCTL)
        SMTD_MT(CKC_ENT, KC_ENT, KC_RSFT)
        SMTD_MT(CKC_STAB, G(KC_GRV), KC_LGUI)
        SMTD_MT(CKC_ENT_GUI, KC_ENT, KC_LGUI)
        SMTD_LT(CKC_SPACE, KC_SPACE, LNUM, 2)
        SMTD_LT(CKC_ENTER, KC_ENT, LARROW, 2)
        SMTD_LT(CKC_SPACE3, KC_SPACE, LBOOT, 2)
        SMTD_LT(CKC_ENTER3, KC_ENT, LBOOT, 2)
        SMTD_LT(CKC_TAB, KC_TAB, LMOUSE, 2)
        SMTD_LT(CKC_ESC, KC_ESC, LVIMNAV, 2)
        SMTD_LT(CKC_VIMGIT, KC_ESC, LVIMGIT, 2)
    }
}
// --- end sm_td ---
//

//--- For the quad actions tap dance: ---
// see: https://docs.qmk.fm/features/tap_dance (example n'4)
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

// for the quote tap dance. put it here so it can be used in any keymap
void quot_finished(tap_dance_state_t *state, void *user_data);
void quot_reset(tap_dance_state_t *state, void *user_data);
void coln_finished(tap_dance_state_t *state, void *user_data);
void coln_reset(tap_dance_state_t *state, void *user_data);
//
// for the parentheses tap dance. put it here so it can be used in any keymap
void lprn_finished(tap_dance_state_t *state, void *user_data);
void lprn_reset(tap_dance_state_t *state, void *user_data);
void rprn_finished(tap_dance_state_t *state, void *user_data);
void rprn_reset(tap_dance_state_t *state, void *user_data);
//
// for the slashes tap dance. put it here so it can be used in any keymap
void slsh_finished(tap_dance_state_t *state, void *user_data);
void slsh_reset(tap_dance_state_t *state, void *user_data);

// for the window management tap dance. put it here so it can be used in any keymap
void wm_finished(tap_dance_state_t *state, void *user_data);
void wm_reset(tap_dance_state_t *state, void *user_data);
//
// for the vim shortcuts tap dance. put it here so it can be used in any keymap
void vs_finished(tap_dance_state_t *state, void *user_data);
void vs_reset(tap_dance_state_t *state, void *user_data);

// --- end of for the quad actions tap dance: ---

// ---for the tap_hold tap dance:---
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1 && !state->interrupted
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

#define ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(keycode) \
    { .fn = {NULL, wm_finished, wm_reset}, .user_data = (void *)&((tap_dance_keycode){keycode}), }

#define ACTION_TAP_DANCE_FN_VIM_SHORTCUT(keycode) \
    { .fn = {NULL, vs_finished, vs_reset}, .user_data = (void *)&((tap_dance_keycode){keycode}), }
// --- End of for tap_hold tap dance ---

// --- For the quad actions tap dance: ---
/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicative that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currently not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustrating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'quote' tap dance.
static td_tap_t qtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t colntap_state = {
    .is_press_action = true,
    .state = TD_NONE
};
// Create an instance of 'td_tap_t' for the 'parentheses' tap dances.
static td_tap_t lprn_state = {
    .is_press_action = true,
    .state = TD_NONE
};
static td_tap_t rprn_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Create an instance of 'td_tap_t' for the 'slashes' tap dance.
static td_tap_t slsh_state = {
    .is_press_action = true,
    .state = TD_NONE
};
//
// Create an instance of 'td_tap_t' for the 'window management' tap dance.
static td_tap_t wm_state = {
    .is_press_action = true,
    .state = TD_NONE
};
//
// Create an instance of 'td_tap_t' for the 'vim shortcuts' tap dance.
static td_tap_t vs_state = {
    .is_press_action = true,
    .state = TD_NONE
};



void quot_finished(tap_dance_state_t *state, void *user_data) {
    qtap_state.state = cur_dance(state);
    switch (qtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: register_code16(KC_SCLN); break;
        case TD_DOUBLE_TAP: register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: register_code(KC_SCLN); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_SCLN); break;
        default: break;
    }
}

void coln_finished(tap_dance_state_t *state, void *user_data) {
    colntap_state.state = cur_dance(state);
    switch (colntap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_COLN); break;
        case TD_SINGLE_HOLD: register_code(KC_SCLN); break;
        case TD_DOUBLE_TAP: register_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: register_code(KC_SCLN); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: register_code(KC_SCLN); break;
        default: break;
    }
}

void quot_reset(tap_dance_state_t *state, void *user_data) {
    switch (qtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: unregister_code16(KC_SCLN); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SCLN); break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SCLN); break;
        default: break;
    }
    qtap_state.state = TD_NONE;
}

void coln_reset(tap_dance_state_t *state, void *user_data) {
    switch (colntap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_COLN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_TAP: unregister_code(KC_SCLN); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_SCLN); break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SCLN); break;
        default: break;
    }
    colntap_state.state = TD_NONE;
}

// const toto='toto'
// const tata="toto"
// const titi={toto:'toto', tata:'tata'}
// const tutu=([[[[toto]]]:toto, tata:tata, titi:titi]) // 3D array
void lprn_finished(tap_dance_state_t *state, void *user_data) {
    lprn_state.state = cur_dance(state);
    switch (lprn_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: register_code(KC_LBRC); break;
        case TD_DOUBLE_TAP: register_code16(KC_LCBR); break;
        case TD_DOUBLE_HOLD: register_code16(KC_LCBR); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_LCBR); break;
        default: break;
    }
}

void lprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (lprn_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LBRC); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_LCBR); break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
        default: break;
    }
    lprn_state.state = TD_NONE;
}

void rprn_finished(tap_dance_state_t *state, void *user_data) {
    rprn_state.state = cur_dance(state);
    switch (rprn_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_RPRN); break;
        case TD_SINGLE_HOLD: register_code(KC_RBRC); break;
        case TD_DOUBLE_TAP: register_code16(KC_RCBR); break;
        case TD_DOUBLE_HOLD: register_code16(KC_RCBR); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_RCBR); break;
        default: break;
    }
}

void rprn_reset(tap_dance_state_t *state, void *user_data) {
    switch (rprn_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RBRC); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_RCBR); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
        default: break;
    }
    rprn_state.state = TD_NONE;
}

void slsh_finished(tap_dance_state_t *state, void *user_data) {
    slsh_state.state = cur_dance(state);
    switch (slsh_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SLSH); break;
        case TD_SINGLE_HOLD: register_code(KC_BSLS); break;
        case TD_DOUBLE_TAP: register_code16(KC_PIPE); break;
        case TD_DOUBLE_HOLD: register_code16(KC_PIPE); break;
        case TD_DOUBLE_SINGLE_TAP: register_code16(KC_PIPE); break;
        default: break;
    }
}

void slsh_reset(tap_dance_state_t *state, void *user_data) {
    switch (slsh_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SLSH); break;
        case TD_SINGLE_HOLD: unregister_code(KC_BSLS); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
        default: break;
    }
    slsh_state.state = TD_NONE;
}

void wm_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_keycode *tap_keycode = (tap_dance_keycode *)user_data;


    wm_state.state = cur_dance(state);
    switch (wm_state.state) {
        case TD_SINGLE_TAP:
            switch (tap_keycode->keycode) {
                case WRS1:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("u"))));
                  break;
                case WRS2:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("t"))));
                  break;
                case WRS3:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("i"))));
                  break;
                case WRS4:
                  SEND_STRING(SS_LALT(SS_LCTL("d")));
                  break;
                case WRS5:
                  SEND_STRING(SS_LALT(SS_LCTL("f")));
                  break;
                case WRS6:
                  SEND_STRING(SS_LALT(SS_LCTL("g")));
                  break;
                case WRS7:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("j"))));
                  break;
                case WRS8:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("b"))));
                  break;
                case WRS9:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI("l"))));
                  break;
                case ZZ:
                  SEND_STRING("zz");
                  break;
                default:
                  break;
            }
            /* register_code(KC_LALT); */
            /* register_code(KC_LCTL); */
            /* register_code(KC_LGUI); */
            break;
        case TD_SINGLE_HOLD:
            switch (tap_keycode->keycode) {
                case WRS1:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_U))));
                  break;
                case WRS2:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_UP))));
                  break;
                case WRS3:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_I))));
                  break;
                case WRS4:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
                  break;
                case WRS5:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_ENTER))));
                  break;
                case WRS6:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_RIGHT))));
                  break;
                case WRS7:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_J))));
                  break;
                case WRS8:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_DOWN))));
                  break;
                case WRS9:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_K))));
                  break;
                case ZZ:
                  SEND_STRING("zt");
                  break;
                default:
                  break;
            }
            break;
        case TD_DOUBLE_TAP:
            switch (tap_keycode->keycode) {
                case WRS1:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_Y))));
                  break;
                case WRS2:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_R)))); */
                  break;
                case WRS3:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_I)))); */
                  break;
                case WRS4:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_H))));
                  break;
                case WRS5:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_V))));
                  break;
                case WRS6:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_T)))); */
                  break;
                case WRS7:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_N))));
                  break;
                case WRS8:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_B)))); */
                  break;
                case WRS9:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_K)))); */
                  break;
                case ZZ:
                  SEND_STRING("zu");
                  break;
                default:
                  break;
            }
            break;
        case TD_DOUBLE_HOLD:
            switch (tap_keycode->keycode) {
                case WRS1:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_U)))); */
                  break;
                case WRS2:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_R))));
                  break;
                case WRS3:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_I)))); */
                  break;
                case WRS4:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_E))));
                  break;
                case WRS5:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_C))));
                  break;
                case WRS6:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_T))));
                  break;
                case WRS7:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_J)))); */
                  break;
                case WRS8:
                  SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_B))));
                  break;
                case WRS9:
                  /* SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_K)))); */
                  break;
                default:
                  break;
            }
            break;
        case TD_DOUBLE_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_U))));
            break;
        default: break;
    }
}

void vs_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_keycode *tap_keycode = (tap_dance_keycode *)user_data;


    vs_state.state = cur_dance(state);
    switch (vs_state.state) {
        case TD_SINGLE_TAP:
            switch (tap_keycode->keycode) {
                case FF:
                  SEND_STRING(SS_TAP(X_SPACE) "ff");
                  break;
                case YC:
                  /* SEND_STRING(SS_LSFT(SS_TAP(X_QUOT)) "ay"); */
                  SEND_STRING("\"ay");
                  break;
                case GSH:
                  SEND_STRING(SS_TAP(X_SPACE) "hs");
                  break;
                case GRH:
                  SEND_STRING(SS_TAP(X_SPACE) "hr");
                  break;
                case GPV:
                  SEND_STRING(SS_TAP(X_SPACE) "hp");
                  break;
                case GTD:
                  SEND_STRING(SS_TAP(X_SPACE) "td" );
                  SEND_STRING(SS_TAP(X_SPACE) "tw" );
                  break;
                case GDT:
                  SEND_STRING(SS_TAP(X_SPACE) "hd");
                  break;
                case GBL:
                  SEND_STRING(SS_TAP(X_SPACE) "hb");
                  break;
                case GC:
                  SEND_STRING(SS_TAP(X_SPACE) "gc");
                  SEND_STRING(SS_TAP(X_ESC));
                  break;
                default:
                  break;
            }
            break;
        case TD_SINGLE_HOLD:
            switch (tap_keycode->keycode) {
                case FF:
                  SEND_STRING(SS_TAP(X_SPACE) "gs");
                  break;
                case YC:
                  SEND_STRING("\"*y");
                  break;
                case GSH:
                  SEND_STRING(SS_TAP(X_SPACE) "hS");
                  break;
                case GRH:
                  SEND_STRING(SS_TAP(X_SPACE) "hR");
                  break;
                case GPV:
                  SEND_STRING(SS_TAP(X_SPACE) "hi");
                  break;
                case GTD:
                  SEND_STRING(SS_TAP(X_SPACE) "td" );
                  break;
                case GDT:
                  SEND_STRING(SS_LCTL("w") "h");
                  SEND_STRING(SS_TAP(X_SPACE) "q");
                  SEND_STRING(SS_LCTL("w") "e");
                  break;
                case GBL:
                  SEND_STRING(SS_TAP(X_SPACE) "hB");
                  break;
                case GC:
                  SEND_STRING(SS_TAP(X_SPACE) "gcc");
                  SEND_STRING(SS_TAP(X_ESC));
                  break;
                default:
                  break;
            }
            break;
        case TD_DOUBLE_TAP:
            switch (tap_keycode->keycode) {
                case YC:
                  SEND_STRING("\"ap");
                  break;
                case GTD:
                  SEND_STRING(SS_TAP(X_SPACE) "tw" );
                  break;
                default:
                  break;
            }
            break;
        case TD_DOUBLE_HOLD:
            /* switch (tap_keycode->keycode) {
                case FF:
                  // SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_U))));
                  break;
                default:
                  break;
            } */
            break;
        case TD_DOUBLE_SINGLE_TAP:
            break;
        default: break;
    }
}

void wm_reset(tap_dance_state_t *state, void *user_data) {
    /* switch (wm_state.state) {
        case TD_SINGLE_TAP:
            // unregister_code(KC_LALT);
            // unregister_code(KC_LCTL);
            // unregister_code(KC_LGUI);
            break;
        case TD_SINGLE_HOLD: unregister_code(KC_BSLS); break;
        case TD_DOUBLE_TAP: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_HOLD: unregister_code16(KC_PIPE); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(KC_PIPE); break;
        default: break;
    } */
    wm_state.state = TD_NONE;
}


void vs_reset(tap_dance_state_t *state, void *user_data) {
    vs_state.state = TD_NONE;
}

// --- End of for the quad actions tap dance: ---

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_V_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_ESC),
    [TD_A_ESC] = ACTION_TAP_DANCE_TAP_HOLD(KC_A, KC_ESC),
    [TD_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_H),
    [TD_EQL] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, KC_LPRN),
    [TD_BSPC] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_RPRN),
    [TD_COM] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, KC_QUES),
    [TD_DOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_EXLM),
    [TD_LPRN] = ACTION_TAP_DANCE_TAP_HOLD(KC_LPRN, KC_LCBR),
    [TD_RPRN] = ACTION_TAP_DANCE_TAP_HOLD(KC_RPRN, KC_RCBR),
    [TD_LBRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, KC_RBRC),
    [TD_AMPR] = ACTION_TAP_DANCE_TAP_HOLD(KC_AMPR, KC_PIPE),
    [TD_DLR] = ACTION_TAP_DANCE_TAP_HOLD(KC_DLR, KC_PERC),
    [TD_AT] = ACTION_TAP_DANCE_TAP_HOLD(KC_HASH, KC_AT),
    [TD_CIRC] = ACTION_TAP_DANCE_TAP_HOLD(KC_CIRC, KC_TILD),
    [TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, quot_finished, quot_reset),
    [TD_COLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, coln_finished, coln_reset),
    // [TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lprn_finished, lprn_reset),
    // [TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rprn_finished, rprn_reset),
    [TD_SLSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slsh_finished, slsh_reset),
    // For window managements:
    [TD_WRS1] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS1),
    [TD_WRS2] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS2),
    [TD_WRS3] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS3),
    [TD_WRS4] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS4),
    [TD_WRS5] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS5),
    [TD_WRS6] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS6),
    [TD_WRS7] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS7),
    [TD_WRS8] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS8),
    [TD_WRS9] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(WRS9),
    [TD_WND] = ACTION_TAP_DANCE_TAP_HOLD(G(KC_N), G(KC_W)),
    [TD_WSW] = ACTION_TAP_DANCE_TAP_HOLD(G(KC_GRV), KC_LGUI),
    // For vim navigation:
    [TD_SD1] = ACTION_TAP_DANCE_TAP_HOLD(C(KC_E), C(KC_D)),
    [TD_SU1] = ACTION_TAP_DANCE_TAP_HOLD(C(KC_Y), C(KC_U)),
    [TD_ZZ] = ACTION_TAP_DANCE_FN_WINDOW_MANAGEMENT(ZZ),
    // For vim shortcuts:
    [TD_FF] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(FF),
    [TD_YC] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(YC),
    [TD_GSH] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GSH),
    [TD_GRH] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GRH),
    [TD_GPV] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GPV),
    [TD_GTD] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GTD),
    [TD_GDT] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GDT),
    [TD_GBL] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GBL),
    [TD_GC] = ACTION_TAP_DANCE_FN_VIM_SHORTCUT(GC),

};
// --- End Tap dances ---

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    // your code here
    // for tap-hold Tap dances:
    // see: https://docs.qmk.fm/features/tap_dance (example 3)
    tap_dance_action_t *action;

    switch (keycode) {
        // -- Macros:
        /* case MKC_ALCT:
            if (record->event.pressed) {
                // SEND_STRING(SS_LGUI("c"));
                // SEND_STRING(SS_LALT(SS_LCTL(SS_TAP(X_LEFT))));
                register_code(KC_LALT);
                register_code(KC_LCTL);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
            }
            break;
        case MKC_ALCTGU:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(KC_LCTL);
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LALT);
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
            }
            break;
         */
        // -- For send_strings:
        case SS_WL:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "h");
            }
            break;
        case SS_WR:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "l");
            }
            break;
        case SS_WD:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "j");
            }
            break;
        case SS_WU:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "k");
            }
            break;
        case SS_WSU:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "y");
            }
            break;
        case SS_WSD:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "u");
            }
            break;
        case SS_WSR:
            if(record->event.pressed){
                SEND_STRING(SS_LCTL("w") "e");
            }
            break;
        case SS_GG:
            if(record->event.pressed){
                SEND_STRING("gg");
            }
            break;
        case SS_GUS:
            if(record->event.pressed){
                SEND_STRING(SS_TAP(X_SPACE) "hu");
            }
            break;
        case SS_QR:
            if(record->event.pressed){
                SEND_STRING(SS_TAP(X_SPACE) "q" SS_LCTL("w") "e");
            }
            break;
        case SS_GNH:
            if(record->event.pressed){
                SEND_STRING("]c");
            }
            break;
        case SS_GPH:
            if(record->event.pressed){
                SEND_STRING("[c");
            }
            break;
        // -- For tap dances 'tap-hold':
          case A_ESC:  // list all tap dance keycodes with tap-hold configurations
          case CLN:
          case EQL:
          case BSPC:
          case COM:
          case DOT:
          case LPRN:
          case RPRN:
          case LBRC:
          case AMPR:
          case DLR:
          case AT:
          case CIRC:
          case WND:
          case WSW:
          case SD1:
          case SU1:
              action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
              if (!record->event.pressed && action->state.count && !action->state.finished) {
                  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                  tap_code16(tap_hold->tap);
              }
              break;
        // -- Debug Print Case ---
        case DBG_ENUM:
             // to see these outputs, set the CONSOLE_ENABLE and COMMAND_ENABLE to 'yes' in rules.mk
             // then start the qmk console with > qmk console
            if (record->event.pressed) {
                printf("--- Custom Keycode Values ---\n");
                printf("BEGIN: %d\n", BEGIN);
                printf("SS_WL: %d\n", SS_WL);
                printf("SS_WR: %d\n", SS_WR);
                printf("SS_WU: %d\n", SS_WU);
                printf("SS_WD: %d\n", SS_WD);
                printf("SS_WSU: %d\n", SS_WSU);
                printf("SS_WSD: %d\n", SS_WSD);
                printf("SS_WSR: %d\n", SS_WSR);
                printf("SS_GG: %d\n", SS_GG);
                printf("SS_GUS: %d\n", SS_GUS);
                printf("SS_QR: %d\n", SS_QR);
                printf("SS_GNH: %d\n", SS_GNH);
                printf("SS_GPH: %d\n", SS_GPH);
                printf("V_ESC: %d\n", V_ESC);
                printf("A_ESC: %d\n", A_ESC);
                printf("CLN: %d\n", CLN);
                printf("EQL: %d\n", EQL);
                printf("BSPC: %d\n", BSPC);
                printf("QUOT: %d\n", QUOT);
                printf("COLN: %d\n", COLN);
                printf("SLSH: %d\n", SLSH);
                printf("LPRN: %d\n", LPRN);
                printf("RPRN: %d\n", RPRN);
                printf("LBRC: %d\n", LBRC);
                printf("AMPR: %d\n", AMPR);
                printf("DLR: %d\n", DLR);
                printf("AT: %d\n", AT);
                printf("CIRC: %d\n", CIRC);
                printf("COM: %d\n", COM);
                printf("DOT: %d\n", DOT);
                printf("WRS1: %d\n", WRS1);
                printf("WRS2: %d\n", WRS2);
                printf("WRS3: %d\n", WRS3);
                printf("WRS4: %d\n", WRS4);
                printf("WRS5: %d\n", WRS5);
                printf("WRS6: %d\n", WRS6);
                printf("WRS7: %d\n", WRS7);
                printf("WRS8: %d\n", WRS8);
                printf("WRS9: %d\n", WRS9);
                printf("WND: %d\n", WND);
                printf("WSW: %d\n", WSW);
                printf("SD1: %d\n", SD1);
                printf("SU1: %d\n", SU1);
                printf("ZZ: %d\n", ZZ);
                printf("FF: %d\n", FF);
                printf("YC: %d\n", YC);
                printf("GSH: %d\n", GSH);
                printf("GRH: %d\n", GRH);
                printf("GPV: %d\n", GPV);
                printf("GTD: %d\n", GTD);
                printf("GDT: %d\n", GDT);
                printf("GBL: %d\n", GBL);
                printf("GC: %d\n", GC);
                printf("SMTD_KEYCODES_BEGIN: %d\n", SMTD_KEYCODES_BEGIN);
                printf("CKC_A: %d\n", CKC_A);
                printf("CKC_S: %d\n", CKC_S);
                printf("CKC_D: %d\n", CKC_D);
                printf("CKC_F: %d\n", CKC_F);
                printf("CKC_J: %d\n", CKC_J);
                printf("CKC_K: %d\n", CKC_K);
                printf("CKC_L: %d\n", CKC_L);
                printf("CKC_UNDS: %d\n", CKC_UNDS);
                printf("CKC_1: %d\n", CKC_1);
                printf("CKC_2: %d\n", CKC_2);
                printf("CKC_3: %d\n", CKC_3);
                printf("CKC_4: %d\n", CKC_4);
                printf("CKC_7: %d\n", CKC_7);
                printf("CKC_8: %d\n", CKC_8);
                printf("CKC_9: %d\n", CKC_9);
                printf("CKC_0: %d\n", CKC_0);
                printf("CKC_DOWN: %d\n", CKC_DOWN);
                printf("CKC_UP: %d\n", CKC_UP);
                printf("CKC_RIGHT: %d\n", CKC_RIGHT);
                printf("CKC_ENT: %d\n", CKC_ENT);
                printf("CKC_ENT_GUI: %d\n", CKC_ENT_GUI);
                printf("CKC_STAB: %d\n", CKC_STAB);
                printf("CKC_SPACE: %d\n", CKC_SPACE);
                printf("CKC_ENTER: %d\n", CKC_ENTER);
                printf("CKC_SPACE3: %d\n", CKC_SPACE3);
                printf("CKC_ENTER3: %d\n", CKC_ENTER3);
                printf("CKC_TAB: %d\n", CKC_TAB);
                printf("CKC_ESC: %d\n", CKC_ESC);
                printf("CKC_VIMGIT: %d\n", CKC_VIMGIT);
                printf("SMTD_KEYCODES_END: %d\n", SMTD_KEYCODES_END);
                printf("DBG_ENUM: %d\n", DBG_ENUM);
                printf("-----------------------------\n");
                printf("--- Tap Dance Enum Values ---\n");
                printf("TD_V_ESC: %d\n", TD_V_ESC);
                printf("TD_A_ESC: %d\n", TD_A_ESC);
                printf("TD_CLN: %d\n", TD_CLN);
                printf("TD_EQL: %d\n", TD_EQL);
                printf("TD_BSPC: %d\n", TD_BSPC);
                printf("TD_QUOT: %d\n", TD_QUOT);
                printf("TD_COLN: %d\n", TD_COLN);
                printf("TD_SLSH: %d\n", TD_SLSH);
                printf("TD_LPRN: %d\n", TD_LPRN);
                printf("TD_RPRN: %d\n", TD_RPRN);
                printf("TD_LBRC: %d\n", TD_LBRC);
                printf("TD_AMPR: %d\n", TD_AMPR);
                printf("TD_DLR: %d\n", TD_DLR);
                printf("TD_AT: %d\n", TD_AT);
                printf("TD_CIRC: %d\n", TD_CIRC);
                printf("TD_COM: %d\n", TD_COM);
                printf("TD_DOT: %d\n", TD_DOT);
                printf("TD_WRS1: %d\n", TD_WRS1);
                printf("TD_WRS2: %d\n", TD_WRS2);
                printf("TD_WRS3: %d\n", TD_WRS3);
                printf("TD_WRS4: %d\n", TD_WRS4);
                printf("TD_WRS5: %d\n", TD_WRS5);
                printf("TD_WRS6: %d\n", TD_WRS6);
                printf("TD_WRS7: %d\n", TD_WRS7);
                printf("TD_WRS8: %d\n", TD_WRS8);
                printf("TD_WRS9: %d\n", TD_WRS9);
                printf("TD_WND: %d\n", TD_WND);
                printf("TD_WSW: %d\n", TD_WSW);
                printf("TD_SD1: %d\n", TD_SD1);
                printf("TD_SU1: %d\n", TD_SU1);
                printf("TD_ZZ: %d\n", TD_ZZ);
                printf("TD_FF: %d\n", TD_FF);
                printf("TD_YC: %d\n", TD_YC);
                printf("TD_GSH: %d\n", TD_GSH);
                printf("TD_GRH: %d\n", TD_GRH);
                printf("TD_GPV: %d\n", TD_GPV);
                printf("TD_GTD: %d\n", TD_GTD);
                printf("TD_GDT: %d\n", TD_GDT);
                printf("TD_GBL: %d\n", TD_GBL);
                printf("TD_GC: %d\n", TD_GC);
                printf("-----------------------------\n");
                printf("QK_TAP_DANCE: %d\n", QK_TAP_DANCE);
                printf("QK_TAP_DANCE_MAX: %d\n", QK_TAP_DANCE_MAX);

                printf("--- some other keycodes# ---\n");
                printf("KC_1: %d\n", KC_1);
                printf("KC_2: %d\n", KC_2);
                printf("KC_A: %d\n", KC_A);
                printf("KC_DOWN: %d\n", KC_DOWN);
                printf("S(KC_TAB): %d\n", S(KC_TAB));
                printf("LCAG(KC_DOWN): %d\n", LCAG(KC_DOWN));
                printf("VIAL_TAP_DANCE_ENTRIES: %d\n", VIAL_TAP_DANCE_ENTRIES);
            }
            return true; // Consume the keycode
    }
    return true;
}


// TD(TD_A_ESC)
// KC_UNDS

#ifdef LAYOUT_split_3x6_3_ex2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Main layer
  [LBASE] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------.  -------------------------------------------------------------------------------.
        XXXXXXX,     KC_Q,     KC_W,     KC_E,        KC_R,     KC_T, XXXXXXX,     XXXXXXX,     KC_Y,     KC_U,       KC_I,       KC_O,        KC_P,     XXXXXXX,
  //|---------+---------+---------+---------+------------+---------+---------|  |---------+---------+---------+-----------+-----------+------------+------------|
       CKC_ESC,    CKC_A,    CKC_S,    CKC_D,       CKC_F,     KC_G,  XXXXXXX,     XXXXXXX,     KC_H,    CKC_J,      CKC_K,      CKC_L,    CKC_UNDS,        QUOT,
  //|---------+---------+---------+---------+------------+---------+---------'  `---------+---------+---------+-----------+-----------+------------+------------|
        KC_GRV,     KC_Z,     KC_X,     KC_C,     V_ESC,       KC_B,                            KC_N,     KC_M,        COM,        DOT,        COLN,     XXXXXXX,
  //|---------+---------+---------+---------+------------+---------+---------.  ,---------+---------+---------+-----------+-----------+------------+------------|
                                                MO(LPART),  CKC_TAB,CKC_ENTER,   CKC_SPACE,  KC_BSPC, XXXXXXX
                                               //`---------------------------'  `----------------------------'

  ),
  // Numbers layer (calculs,...) (Right thumb1)
  [LNUM] = LAYOUT_split_3x6_3_ex2(
  //,-------------------------------------------------------------------.  ,-------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_ASTR, KC_PLUS,        EQL, XXXXXXX,   XXXXXXX,    XXXXXXX,       LBRC,       BSPC, KC_MINS, KC_SLSH,   XXXXXXX,    XXXXXXX,
  //|--------+--------+--------+--------+-----------+--------+----------|  |--------+-----------+-----------+--------+--------+----------+-----------|
      _______,   CKC_1,   CKC_2,   CKC_3,      CKC_4,    KC_5,   XXXXXXX,    XXXXXXX,       KC_6,      CKC_7,   CKC_8,   CKC_9,     CKC_0,        CLN,
  //|--------+--------+--------+--------+-----------+--------+----------'  `--------+-----------+-----------+--------+--------+----------+-----------|
      XXXXXXX,    KC_J, XXXXXXX, XXXXXXX,      SS_GG, XXXXXXX,                           XXXXXXX,    XXXXXXX, XXXXXXX,  KC_DOT,      KC_K, CKC_ENTER3,
  //|--------+--------+--------+--------+-----------+--------+----------.  ,--------+-----------+-----------+--------+--------+----------+-----------|
                                              KC_TAB,KC_SPACE,CKC_ENTER3,    _______,    XXXXXXX,     XXXXXXX
                                        //`-----------------------------'  `--------------------------------'
  ),

  // Arrows layer (Left thumb1)
  [LARROW] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------.  ,----------------------------------------------------------------------------.
         XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,   XXXXXXX,      XXXXXXX,        YC, DF(LVIMMOV),   XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------+-----------+--------+--------+------------+------------+----------|  |----------+----------+------------+----------+------------+--------+--------|
      CKC_VIMGIT,      CKC_1,   CKC_2,      FF, CKC_ENT_GUI, DF(LVIMGIT), DF(LGAME),      XXXXXXX,   KC_LEFT,    CKC_DOWN,    CKC_UP,   CKC_RIGHT, CKC_ENT, XXXXXXX,
  //|-----------+-----------+--------+--------+------------+------------+----------'  `----------+----------+------------+----------+------------+--------+--------|
      CKC_SPACE3,    XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,     XXXXXXX,                            XXXXXXX,   DF(LWIN1),   XXXXXXX,     XXXXXXX, XXXXXXX, KC_TILD,
  //|-----------+-----------+--------+--------+------------+------------+----------.  ,----------+----------+------------+----------+------------+--------+--------|
                                                    XXXXXXX,     XXXXXXX,   _______,   CKC_SPACE3,   KC_BSPC,    XXXXXXX
                                      //`------------------------------------------'  `---------------------------------'
  ),

  // Boot, flash and led layer (two thumbs1)
  [LBOOT] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------------------.  ,----------------------------------------------------------------.
      QK_BOOT, DBG_ENUM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  , XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT,   QK_BOOT,
  //|--------+---------+--------+--------+--------+--------+----------|  |--------+--------+--------+--------+--------+--------+----------|
      RGB_TOG,  RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   DT_UP,   RGB_TOG,
  //|--------+---------+--------+--------+--------+--------+----------'  `--------+--------+--------+--------+--------+--------+----------|
      RGB_MOD,  RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN,   XXXXXXX,
  //|--------+---------+--------+--------+--------+--------+----------.  ,--------+--------+--------+--------+--------+--------+----------|
                                            KC_ESC, XXXXXXX,   _______,    _______, KC_BSPC, KC_RGUI
                                      //`-----------------------------'  `--------------------------'
  ),
  // Parentheses layer (left thumb2)
  [LPART] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,----------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,        LPRN,      KC_GRV,    RPRN, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+------------+------------+--------+--------+--------|
      XXXXXXX,   CKC_1,   CKC_2,   CKC_3,   CKC_4, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,     KC_LBRC,        SLSH, KC_RBRC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+------------+------------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           AT,        AMPR,         DLR,    CIRC, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+------------+------------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,   KC_SPACE, KC_BSPC,     XXXXXXX
                                      //`--------------------------'  `------------------------------'
  ),
  // Window management layer (new base layer)
  [LWIN1] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------.  ,-----------------------------------------------------------------.
      XXXXXXX, XXXXXXX,       XXXXXXX,    LCAG(KC_UP),           WND, XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX,    WRS1,    WRS2,    WRS3, XXXXXXX, XXXXXXX,
  //|--------+--------+--------------+---------------+--------------+--------+-----------|  |-----------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, LCAG(KC_LEFT),  LCAG(KC_DOWN),LCAG(KC_RIGHT), XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX,    WRS4,    WRS5,    WRS6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------------+---------------+--------------+--------+-----------'  `-----------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX,       XXXXXXX,      S(KC_TAB),        KC_TAB, XXXXXXX,                            XXXXXXX,    WRS7,    WRS8,    WRS9, XXXXXXX, XXXXXXX,
  //|--------+--------+--------------+---------------+--------------+--------+-----------.  ,-----------+--------+--------+--------+--------+--------+--------|
                                                             XXXXXXX, XXXXXXX,  DF(LBASE),      CKC_STAB, XXXXXXX,  XXXXXXX
                                                      //`--------------------------------'  `-----------------------------'
  ),
  // Vim motions
  [LVIMNAV] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------.  ,---------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX,    SS_WSR,     SS_WSU,    SS_WSD,    XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+------------|  |----------+----------+-----------+----------+------------+--------+--------|
      XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX,     SS_WL,        SD1,       SU1,       SS_WR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+------------'  `----------+----------+-----------+----------+------------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX,      SS_WD,     SS_WU,     XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+------------.  ,----------+----------+-----------+----------+------------+--------+--------|
                                          XXXXXXX, XXXXXXX, MO(LVIMGIT),           ZZ,   XXXXXXX,    XXXXXXX
                                      //`------------------------------'  `---------------------------------'
  ),
  // Vim movements
  [LVIMMOV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, DF(LBASE),    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  // Vim Git actions
  [LVIMGIT] = LAYOUT_split_3x6_3_ex2(
  //,----------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,   SS_QR,     GTD, XXXXXXX,     GRH, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,  SS_GUS, XXXXXXX, XXXXXXX,     GPV, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+----------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_ESC, XXXXXXX,     GSH,     GDT, XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX,  SS_GNH,  SS_GPH, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+----------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX,      GC, XXXXXXX,     GBL,                        XXXXXXX,    KC_J,    KC_K, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+----------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, DF(LBASE),    _______, XXXXXXX, XXXXXXX
                                      //`----------------------------'  `--------------------------'
  ),
  // Game controls
  [LGAME] = LAYOUT_split_3x6_3_ex2(
  //,----------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX,    KC_Q, KC_LSFT, KC_LCTL,    KC_R,    KC_T,   XXXXXXX,    XXXXXXX,    KC_Y,    KC_U,   KC_UP,    KC_O,    KC_P,    KC_I,
  //|--------+--------+--------+--------+--------+--------+----------|  |--------+--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, DF(LBASE),    XXXXXXX,    KC_H, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_UNDS,   QUOT,
  //|--------+--------+--------+--------+--------+--------+----------'  `--------+--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,     COM,     DOT,    COLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+----------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,  KC_TAB,    KC_ENT,   KC_SPACE, KC_BSPC, XXXXXXX
                                      //`----------------------------'  `--------------------------'
  ),
  // mouse controls
  [LMOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, MS_WHLR, MS_WHLU, MS_WHLD, MS_WHLL, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,   MS_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    MS_BTN1, MS_BTN2, MS_BTN3
                                      //`--------------------------'  `--------------------------'
  )

  // Template layer (to copy past)
  /*[x] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    _______, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )*/
};
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif


/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     // Do not select the hold action when another key is pressed. */
/*     return false; */
/* } */

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          case AMPR:
          case DLR:
          case AT:
          case CIRC:
              return 80;
          case A_ESC:
          case CLN:
          case COM:
          case DOT:
          case EQL:
          case BSPC:
          case LPRN:
          case LBRC:
          case RPRN:
          case FF:
              return 100;
          case QUOT:
          /* case COLN: */
          case SLSH:
          case WRS1:
          case WRS2:
          case WRS3:
          case WRS4:
          case WRS5:
          case WRS6:
          case WRS7:
          case WRS8:
          case WRS9:
          case SD1:
          case SU1:
          case GSH:
          case GRH:
          case GPV:
          case GTD:
          case GDT:
          case GBL:
          case GC:
              return 120;
          case ZZ:
              return 150;
        default:
            return TAPPING_TERM;
    }
}


// --- For sm_td ---
uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        case CKC_S:
        case CKC_D:
        case CKC_F:
        case CKC_J:
        case CKC_K:
        case CKC_L:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 1;
            break;
        case CKC_A:
        case CKC_UNDS:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 10;
            break;
        case CKC_1:
        case CKC_2:
        case CKC_3:
        case CKC_4:
        case CKC_7:
        case CKC_8:
        case CKC_9:
        case CKC_0:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 1;
            break;
        case CKC_TAB:
        case CKC_ENTER:
        case CKC_VIMGIT:
            if (timeout == SMTD_TIMEOUT_TAP) return 100;
            if (timeout == SMTD_TIMEOUT_FOLLOWING_TAP) return 10;
            break;
        case CKC_ESC:
        case CKC_SPACE:
            if (timeout == SMTD_TIMEOUT_TAP) return 150;
            if (timeout == SMTD_TIMEOUT_FOLLOWING_TAP) return 100;
            if (timeout == SMTD_TIMEOUT_RELEASE) return 10;
            break;
    }

    return get_smtd_timeout_default(timeout);
}
