#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _PDVORAK 0

#define _LOWER 3
#define _RAISE 4
#define _FUNCTION 15
#define _ADJUST 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Programmer's dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  :;  |  <,  |  >.  |  Pp  |  Yy  |  Ff  |  Gg  |  Cc  |  Rr  |  Ll  |  ?/  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Esc/F |  Aa  |  Oo  |  Ee  |  Uu  |  Ii  |  Dd  |  Hh  |  Tt  |  Nn  |  Ss  |  -_  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|Z/Ctrl|Q/Cmd |  Jj  |  Kk  |  Xx  |  Bb  |  Mm  |  Ww  |  Vv  |  Zz  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  alt |      |      |      |Bacs/L|Backs |Space |Entr/R|      |      |      | alt  |
 * `-----------------------------------------------------------------------------------'
 */
[_PDVORAK] = LAYOUT( \
  KC_TAB,              KC_SCLN,        KC_COMM,     KC_DOT,  KC_P,                KC_Y,    KC_F,   KC_G,               KC_C,    KC_R,    KC_L,    KC_SLSH, \
  LT(_ADJUST, KC_ESC), KC_A,           KC_O,        KC_E,    KC_U,                KC_I,    KC_D,   KC_H,               KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LSFT,             CTL_T(KC_QUOT), GUI_T(KC_Q), KC_J,    KC_K,                KC_X,    KC_B,   KC_M,               KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  KC_LALT,             MO(_FUNCTION),  XXXXXXX,     XXXXXXX, LT(_LOWER, KC_BSPC), KC_BSPC, KC_SPC, LT(_RAISE, KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   $  |      |   <  |   >  |      |      |      |      |      |      |   @  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |  [   |  {   |  }   |  (   |  =   |  *   |  )   |   +  |   ]  |   !  |  #   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|LCTRL | LGUI |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp |Space |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_DLR,  XXXXXXX,  KC_LABK, KC_RABK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AT,   KC_PIPE,  \
  KC_AMPR, KC_LBRC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, \
  _______, KC_LCTL,  KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______,  _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______  \
),

/* Raise TODO rewrite this
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_TILD, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_BSLS, \
  KC_PERC, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_GRV,  \
  _______, KC_LCTL, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise) TODO rewrite this as movement
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |      |RGBVAI|RGBSAI|RGBHUI|caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Qwerty|RGBVAD|RGBSAD|RGBHUD|RGBTOG|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |BLSTEP|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______, \
  _______, _______, _______, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, KC_LCTL, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Function for colors
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |RGBTOG|      |      |      |      |RGBTOG|      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |RGBVAI|RGBSAI|RGBHUI|      |      |RGBVAD|RGBSAD|RGBHUD|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT( \
  _______, _______, _______, RGB_TOG, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, \
  _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_PDVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
