# Quantum Mechanical Keyboard Firmware

This is my fork of QMK with my board configs.

I have a...

* Corne (crkbd)
* Planck
* Let's Split, Eh?

And I use a custom key layout based on Programmer's Dvorak.

### Building

```
git clone git@github.com:the-mikedavis/qmk_firmware.git
cd qmk_firmware
git submodule update --init --force
nix-shell
qmk compile -kb crkbd -km the-mikedavis
```

produces a `crkbd_rev1_the-mikedavis.hex` file.

Then I use QMK-toolbox on a Windows/MacOS machine to flash (it gets complicated
to do it on NixOS).

### Tricks

I use a **lot** of snake_case so I switched `KC_MINUS` to send `_` with
no shift modifier and `-` with the shift modifier. This is easy but not
trivial with QMK:

```c
// setup a custom keycode
enum custom_keycodes {
  REV_MINUS = SAFE_RANGE,
};

// replace KC_MINUS with REV_MINUS in your keymaps block:
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ...
}

// implement process_record_user
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // check for record->event.pressed (keydown) and that the keycode was our
  // custom keycode
  if (record->event.pressed && keycode == REV_MINUS) {
    // if the shift mod is currently registered
    if (get_mods() & MOD_MASK_SHIFT) {
      // unregister it, send `-`, then reregister it.
      // (we need to do this because the operating system will see shift held
      // and `-` sent and convert it to `_`.)
      unregister_code(KC_LSFT);
      SEND_STRING("-");
      register_code(KC_LSFT);
    } else {
      // if not shifted, send a literal `_`
      SEND_STRING("_");
    }
  }
  return true;
}
```

See https://github.com/the-mikedavis/qmk_firmware/commit/0211661c057c49c7e3b73d26cf8564d8564dce73.

This can be done for macos as well: https://github.com/the-mikedavis/qmk_firmware/commit/9778486b473a512b9db20ba8ee14931aba167eb0.
