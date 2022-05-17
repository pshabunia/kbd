# How I stopped fearing the QMK firmware and loved Dactyl Manuform 5x6

*Or vice versa*

TODO: picture 

# Memo

```shell 
alias DOCKER_QMK="docker run --rm -ti --volume $(pwd):/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia qmkfm/qmk_firmware"
```

## Flash It!

It sucks, but the firmware (`layer.hex`) has to be applied to each keyboard half individually. 

As of today, the keymap (`pshabunia.json`) can be fully managed with QMK Config Web UI https://config.qmk.fm but maybe it will need to be eventually replaced or augmended with C code (in order to truly support Fn key which is surprisingly powerful mod in OSX).


```shell
DOCKER_QMK /bin/bash -c 'qmk compile keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/pshabunia.json && cp .build/handwired_dactyl_manuform_5x6_pshabunia.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/layout.hex'
```

## EEPROM Bootloader

Each Micro uses internal EEPROM memory to store a distinguishing marker making it possible to recognize which half serves which hand. 
Combined with the firmware's ability to recognize the orign of power source - USB or TRS - each half can automatically align keymap with the physical layer.
Once set, EEPROM markers can't be changed with a regular keymap flashing and need to be intentionally cleared.

 As you can guess from the repository content, `eeprom_left.hex` and `eeprom_right.hex` are two EEPROM bootloader files. They need to be applied to the left and right halves respectively. For each file opened in QMK Toolbox, connect USB wire to the appropriate half's Micro slot and **Flash it!** 

In case of emergency, EEPROM bootloader files can be re-generated in the Docker.

```shell
DOCKER_QMK /bin/bash
# Left Half
make handwired/dactyl_promicro:default:avrdude-split-left 
# Success? Ctrl+C
cp .build/handwired_dactyl_promicro_default.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/eeprom_left.hex
# Right Half
make handwired/dactyl_promicro:default:avrdude-split-right
# Success? Ctrl+C
cp .build/handwired_dactyl_promicro_default.hex keyboards/handwired/dactyl_manuform/5x6/keymaps/pshabunia/eeprom_right.hex
# Done! Ctrl+D
```


# Prerequisites
* `port install avrdude`
* [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)

# More Info:
* https://docs.qmk.fm
* https://github.com/qmk/qmk_firmware/tree/master/keyboards/handwired/dactyl_manuform
* https://github.com/qmk/qmk_firmware/blob/master/docs/cli_commands.md
