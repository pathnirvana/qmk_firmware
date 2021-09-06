/* 
compile this keymap with the following command
qmk compile -kb handwired/dactyl_manuform/5x6  -km pathnirvana
make handwired/dactyl_manuform/5x6:pathnirvana

flash with the following command or can use the qmk toolbox too
.\avrdude.exe -p atmega32u4 -c avr109 -P COM5 -U flash:w:"\\wsl.localhost\Ubuntu\home\janaka\qmk_firmware\handwired_dactyl_manuform_5x6_pathnirvana.hex":i 
*/

#include QMK_KEYBOARD_H

#define DEFAULT 0
#define _NAV 1
#define _SYM 2
#define _MOUSE 3
#define _NUM 4
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_ENT LT(_SYM, KC_ENT)
#define MS_RIGHT LT(_MOUSE, KC_RIGHT)
#define NUM_LEFT LT(_NUM, KC_LEFT)

// Left-hand home row mods
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

// Right-hand home row mods
#define HOME_N RCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)

#define UNDO C(KC_Z)
#define REDO C(KC_Y)
#define CLOSE C(KC_W)
#define FIND C(KC_F)
#define OS_LSFT OSM(MOD_LSFT)
#define RGB_FWD RGB_MODE_REVERSE
#define RGB_BAK RGB_MODE_FORWARD

enum custom_keycodes {
    ARROW_R = SAFE_RANGE,
    METTA,
    NUM_LTOG, MOUSE_LTOG,
    SFT_BTN3,
    ALT_TAB
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_NAV_TAB
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_NAV_TAB] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_TAB, _NAV)
};

#define TD_ESC TD(TD_ESC_CAPS)
#define TD_MINS TD(TD_MINS_UNDS)
#define TD_QUOT TD(TD_QUOT_DQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DEFAULT] = LAYOUT_5x6(
     TD_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                 KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_ENT ,
     KC_GRV , KC_Q  , KC_W  , KC_F  , KC_P  , KC_B  ,                 KC_J  , KC_L  , KC_U  , KC_Y  ,KC_SCLN,KC_MINS,
     KC_BSPC, KC_A  , HOME_R, HOME_S, HOME_T, KC_G  ,                 KC_M  , KC_N  , KC_E  , KC_I  , KC_O  ,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_D  , KC_V  ,                 KC_K  , KC_H  ,KC_COMM, KC_DOT,KC_SLSH,KC_BSLASH,
                     KC_BTN1,S(KC_DEL),                                                A(KC_LSFT),KC_LGUI,
                                      KC_SPC ,NAV_TAB,                SYM_ENT,OS_LSFT,
                                      MOUSE_LTOG,NUM_LTOG,            KC_LEFT,KC_RIGHT,
                                      _______, _______,               _______, _______
  ),

  [_NAV] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 , KC_F11,
      C(KC_GRV), KC_F2 , CLOSE , FIND  , UNDO  ,C(KC_B),    _______,KC_PGUP, KC_UP ,KC_PGDN, KC_F5 ,KC_MUTE,
        KC_DEL ,C(KC_A),KC_LALT,KC_LSFT,KC_LCTL,C(KC_G),    KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END ,KC_VOLU,
        ALT_TAB,_______,C(KC_X),C(KC_C),C(KC_D),C(KC_V),    _______,_______,XXXXXXX,KC_PSCR,_______,KC_VOLD,
                        _______,_______,                                    _______,_______,
                                         _______,_______,   _______,S(KC_TAB),
                                         _______,_______,   KC_WBAK,KC_WFWD,
                                         _______,_______,   _______,_______
  ),

  [_SYM] = LAYOUT_5x6(
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
        _______,_______, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,    KC_CIRC,KC_AMPR,KC_ASTR,KC_COLON,_______,_______,
        _______,KC_EXLM,KC_LCBR,KC_LPRN,KC_LBRC,KC_TILD,  KC_BSLASH,KC_UNDS,KC_EQL ,KC_PLUS,KC_SCLN,KC_DQUO,
        ARROW_R, METTA ,KC_RCBR,KC_RPRN,KC_RBRC,_______,    KC_PIPE,KC_MINS,KC_LABK,KC_RABK,KC_QUES,_______,
                        KC_PGUP,KC_PGDN,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        KC_HOME,KC_END ,    _______,_______,
                                        _______,_______,    _______,_______
  ),
  [_NUM] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,    _______,_______,_______,_______,_______,_______,
        _______,_______,KC_SLSH,KC_LPRN,KC_MINS,_______,    _______,KC_PLUS,KC_ASTR,KC_RPRN,_______,_______,
        _______, KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,     KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,_______,
        KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,    KC_F6  , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11,
                        _______,_______,                                    _______,_______,
                                        _______,_______,    _______,_______,
                                        _______,_______,    KC_EQL ,_______,
                                        _______,_______,    _______,_______
  ),

  [_MOUSE] = LAYOUT_5x6(
        RESET  ,_______,_______,_______,_______,_______,    RGB_TOG,RGB_FWD,RGB_BAK,RGB_HUI,RGB_SAI,RGB_VAI,
        _______,_______,_______,KC_WH_U,_______,KC_ACL2,    _______,_______,KC_MS_U,RGB_HUD,RGB_SAD,RGB_VAD,
        _______,_______,KC_WH_L,KC_WH_D,KC_WH_R,KC_ACL1,    _______,KC_MS_L,KC_MS_D,KC_MS_R,_______,_______,
        KC_SLEP,_______,KC_BTN1,KC_BTN3,KC_BTN2,KC_ACL0,    _______,KC_BTN3,_______,_______,_______,_______,
                        _______,SFT_BTN3,                                     _______,_______,
                                        KC_BTN2,KC_BTN1,    _______,_______,
                                        _______,KC_BTN3,    _______,_______,
                                        _______,_______,    _______,_______
    )
};

// Initialize variable holding the binary representation of active modifiers.
uint8_t mod_state, oneshot_mod_state;
bool is_alt_tab_active = false; // ADD this near the begining of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.
uint16_t layer_ltog_timer; bool was_layer_on;
void tap_toggle_hold_mo_layer(uint8_t _layer, keyrecord_t *record) {
    if (record->event.pressed){
        layer_ltog_timer = timer_read();
        was_layer_on = layer_state_is(_layer);
        layer_on(_layer);
    } else {
        if (timer_elapsed(layer_ltog_timer) < TAPPING_TERM) {  
            was_layer_on ? layer_off(_layer) : layer_on(_layer);
        } else {
            layer_off(_layer);
        }
    }
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {
        case METTA:
            if (record->event.pressed) {
                send_string("With Metta\nJanaka");
                return false;
            }
            break;
        case ARROW_R:
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT || oneshot_mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    del_oneshot_mods(MOD_MASK_SHIFT);
                    send_string("->");
                    set_mods(mod_state);
                } else {
                    SEND_STRING("=>");
                }
            }
            break;
        case NUM_LTOG: // tap to toggle or hold to momentarily activate
            tap_toggle_hold_mo_layer(_NUM, record);
            break;
        case MOUSE_LTOG: // tap to toggle or hold to momentarily activate
            tap_toggle_hold_mo_layer(_MOUSE, record);
            break;
        case SFT_BTN3: // not sure if this is working
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_BTN3);
            } else {
                unregister_code(KC_BTN3);
                unregister_code(KC_LSFT);
            }
            break;
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
};

void matrix_scan_user(void) { // reseting the alt tab timers
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

/*
 * Per key tapping term settings
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_I:
        case HOME_R:  // prevent accidential alt activations 
            return TAPPING_TERM + 50;
        case SYM_ENT:  // Very low tapping term to make sure I don't hit Enter accidentally.
            return TAPPING_TERM - 20;
        default:
            return TAPPING_TERM;
    }
};

// Light LEDs 1 through 8 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM rgb_layer1[] = RGBLIGHT_LAYER_SEGMENTS({1, 4, HSV_ORANGE});
const rgblight_segment_t PROGMEM rgb_layer2[] = RGBLIGHT_LAYER_SEGMENTS({1, 4, HSV_PURPLE});
const rgblight_segment_t PROGMEM rgb_layer3[] = RGBLIGHT_LAYER_SEGMENTS({1, 4, HSV_GREEN});
const rgblight_segment_t PROGMEM rgb_layer4[] = RGBLIGHT_LAYER_SEGMENTS({1, 4, HSV_RED});

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer1,    
    rgb_layer2,
    rgb_layer3,
    rgb_layer4
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    for(int i = 0; i < _NUM; i++) {
        rgblight_set_layer_state(i, layer_state_cmp(state, i + 1));
    }
    
    // rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
    return state;
}
