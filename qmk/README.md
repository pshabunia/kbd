# How I stopped fearing the QMK firmware and loved Dactyl Manuform 5x6

TODO: picture 

## Prerequisites
* `port install avrdude`
* [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)

### QMK in the Docker

```shell  
# from qmk directory
alias DOCKER_QMK="docker run --rm -ti --volume $(pwd):/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia qmkfm/qmk_firmware"
```

## Flash It!

The keymap (`pshabunia.json`) can be edited with [QMK Config Web UI](https://config.qmk.fm) and built as following: 

```shell
DOCKER_QMK /bin/bash -c 'qmk compile keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/pshabunia.json && cp .build/handwired_dactyl_manuform_5x6_pshabunia.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/layout.hex'
```

Please note, the firmware (`layer.hex`) needs to be applied individually for each keyboard half. 

## Handedness

By default, the firmware does not know which side is which; it needs some help to determine that.
Each Micro can use its internal EEPROM memory to store a distinguishing *handedness* marker which combined with the firmware's ability to recognize the orign of power source - USB or TRRS - allows to apply the keymap automatically.

Once set, EEPROM markers can't be changed with a regular keymap flashing and need to be intentionally cleared.

 The EEPROM bootloader files (`eeprom_left.hex` and `eeprom_right.hex`) need to be applied to the left and right halves respectively. For each file opened in QMK Toolbox, connect USB cable to the appropriate keyboard half and flash it using `Tools > EEPROM> Set Left/Right Hand`.

In case of emergency, EEPROM bootloader files can be re-generated as following:

```shell
DOCKER_QMK /bin/bash
# Make sure that handwired/dactyl_manuform/5x6/config.h
#   contains `#define EE_HANDS`. Update if necessary.
# Now build the firmware.
# Left Half
make handwired/dactyl_manuform/5x6:default:avrdude-split-left 
# Success? Ctrl+C
cp .build/handwired_dactyl_manuform_5x6_default.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/eeprom_left.hex
# Right Half
make handwired/dactyl_manuform/5x6:default:avrdude-split-right
# Success? Ctrl+C
cp .build/handwired_dactyl_manuform_5x6_default.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/eeprom_right.hex
# Done! Ctrl+D
```

## More Info
* https://docs.qmk.fm
* https://docs.qmk.fm/#/feature_split_keyboard?id=handedness-by-eeprom
* https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/dactyl_manuform
* https://github.com/qmk/qmk_firmware/blob/master/docs/cli_commands.md 
