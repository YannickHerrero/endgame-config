#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NUM,
    _NAV,
    _OPT,
    _UTIL,
};

enum custom_keycodes {
    QUOT_SPC = SAFE_RANGE,
    DQUO_SPC,
    TILD_SPC,
    GRV_SPC,
    CIRC_SPC,
};

#define HM_A LSFT_T(KC_A)
#define HM_S LCTL_T(KC_S)
#define HM_D LALT_T(KC_D)
#define HM_F LGUI_T(KC_F)
#define HM_U LGUI_T(KC_U)
#define HM_I LALT_T(KC_I)
#define HM_O LCTL_T(KC_O)
#define HM_P LSFT_T(KC_P)

#define TH_GUI_ENT LGUI_T(KC_ENT)
#define TH_NAV_SPC LT(_NAV, KC_SPC)
#define TH_UTIL_F18 LT(_UTIL, KC_F18)

enum combos {
    ESC_COMBO,
    TAB_COMBO,
    TMUX_COMBO,
};

const uint16_t PROGMEM esc_combo[]  = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM tab_combo[]  = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tmux_combo[] = {HM_S, HM_D, COMBO_END};

combo_t key_combos[] = {
    [ESC_COMBO] = COMBO(esc_combo, KC_ESC),
    [TAB_COMBO] = COMBO(tab_combo, KC_TAB),
    [TMUX_COMBO] = COMBO(tmux_combo, C(KC_A)),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_eg(
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
    '*',           '*', '*',  '*', '*',           '*'
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_eg(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,        HM_U,         HM_I,         HM_O,        HM_P,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                      KC_H,        KC_J,         KC_K,         KC_L,        KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,        KC_M,         KC_COMM,      KC_DOT,      KC_QUOT,
        KC_TRNS,          KC_SPC,  MO(_NUM),                           TH_GUI_ENT,  KC_SPC,                                       TH_NAV_SPC
    ),

    [_NUM] = LAYOUT_eg(
        KC_EXLM, KC_GRV,  KC_LCBR, KC_RCBR, A(KC_BSPC),                DQUO_SPC,    KC_7,         KC_8,         KC_9,        KC_BSPC,
        KC_LT,   KC_TILD, KC_LPRN, KC_RPRN, KC_DEL,                    QUOT_SPC,    KC_4,         KC_5,         KC_6,        KC_SLSH,
        KC_GT,   CIRC_SPC,KC_LBRC, KC_RBRC, KC_TRNS,                   KC_0,        KC_1,         KC_2,         KC_3,        KC_QUES,
        KC_TRNS,          KC_TRNS, KC_TRNS,                            KC_TRNS,     KC_TRNS,                                      MO(_OPT)
    ),

    [_NAV] = LAYOUT_eg(
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   CIRC_SPC,    KC_AMPR,      KC_ASTR,      KC_MINS,     KC_EQL,
        KC_LT,   KC_TRNS, KC_UNDS, KC_SLSH, KC_PIPE,                   A(KC_1),     A(KC_2),      A(KC_3),      A(KC_4),     GRV_SPC,
        KC_GT,   KC_TRNS, KC_PLUS, KC_QUES, KC_NUBS,                   A(KC_5),     A(KC_6),      KC_PIPE,      KC_NUBS,     TILD_SPC,
        KC_TRNS,          KC_TRNS, MO(_OPT),                           KC_TRNS,     KC_TRNS,                                      KC_TRNS
    ),

    [_OPT] = LAYOUT_eg(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_UNDS,     KC_PLUS,
        KC_TRNS, KC_TRNS, G(KC_V), G(KC_C), G(KC_X),                   KC_LEFT,     KC_DOWN,      KC_UP,        KC_RGHT,     KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS,                            KC_TRNS,     KC_TRNS,                                      KC_TRNS
    ),

    [_UTIL] = LAYOUT_eg(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_LEFT,     KC_RGHT,      KC_TRNS,      KC_TRNS,     KC_TRNS,
        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    G(S(KC_4)),  KC_MPLY,      KC_VOLU,      KC_BRIU,     KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     G(S(KC_5)),  KC_MUTE,      KC_VOLD,      KC_BRID,     KC_CAPS,
        KC_TRNS,          KC_TRNS, KC_TRNS,                            KC_TRNS,     KC_TRNS,                                      TH_UTIL_F18
    ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TH_GUI_ENT:
        case TH_NAV_SPC:
        case TH_UTIL_F18:
            return 280;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_A:
        case HM_S:
        case HM_D:
        case HM_F:
        case HM_U:
        case HM_I:
        case HM_O:
        case HM_P:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case QUOT_SPC:
            tap_code(KC_QUOT);
            tap_code(KC_SPC);
            return false;
        case DQUO_SPC:
            tap_code16(S(KC_QUOT));
            tap_code(KC_SPC);
            return false;
        case TILD_SPC:
            tap_code16(S(KC_GRV));
            tap_code(KC_SPC);
            return false;
        case GRV_SPC:
            tap_code(KC_GRV);
            tap_code(KC_SPC);
            return false;
        case CIRC_SPC:
            tap_code16(S(KC_6));
            tap_code(KC_SPC);
            return false;
        default:
            return true;
    }
}
