#!/bin/bash
docker run --rm -ti \
--volume $(pwd):/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia \
--workdir /qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia \
qmkfm/qmk_firmware \
/bin/bash -c 'qmk json2c ps34.json > keymap.c \
&& qmk compile \
&& cp /qmk_firmware/handwired_dactyl_manuform_5x6_pshabunia.hex keymap.hex'
