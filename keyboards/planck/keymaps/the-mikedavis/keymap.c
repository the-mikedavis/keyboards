/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV
};

#define _PDVORAK 0

#define _LOWER 1
#define _RAISE 2
#define _DIRECT 3

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

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
[_PDVORAK] = LAYOUT_planck_grid( \
  KC_TAB,              KC_SCLN,        KC_COMM,     KC_DOT,  KC_P,                KC_Y,    KC_F,   KC_G,               KC_C,    KC_R,    KC_L,    KC_SLSH, \
  LT(_DIRECT, KC_ESC), KC_A,           KC_O,        KC_E,    KC_U,                KC_I,    KC_D,   KC_H,               KC_T,    KC_N,    KC_S,    KC_MINS, \
  KC_LSFT,             CTL_T(KC_QUOT), GUI_T(KC_Q), KC_J,    KC_K,                KC_X,    KC_B,   KC_M,               KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  KC_LALT,             XXXXXXX,        XXXXXXX,     XXXXXXX, LT(_LOWER, KC_BSPC), KC_BSPC, KC_SPC, LT(_RAISE, KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT  \
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
[_LOWER] = LAYOUT_planck_grid( \
  KC_DLR,  XXXXXXX,  KC_LABK, KC_RABK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AT,   KC_PIPE, \
  KC_AMPR, KC_LBRC,  KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, \
  _______, KC_LCTL,  KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______,  _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |      |      |      |      |      |      |      |      |      |   ^  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  %   |   7  |   5  |   3  |   1  |  9   |   0  |   2  |   4  |   6  |   8  |  `   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|LCTRL | LGUI |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Bksp |Space |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid( \
  KC_TILD, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_BSLS, \
  KC_PERC, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_GRV,  \
  _______, KC_LCTL, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______  \
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |LCTRL |Shift |      |      | left | down |right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |LCTRL | LGUI |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_DIRECT] = LAYOUT_planck_grid( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______, \
  _______, _______, _______, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, KC_LCTL, KC_LGUI, _______, _______, _______, _______, KC_F12 , _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
