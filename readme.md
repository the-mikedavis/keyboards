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
