the-mikedavis' keymaps:

- keyboards/planck/keymaps/the-mikedavis/
- keyboards/lets_split_eh/keymaps/the_mikedavis/

compile them (planck for example) with

    qmk compile -kb planck/rev6 -km the-mikedavis

and flash them onto the device with

    qmk flash -kb planck/rev6 -km the-mikedavis
