Building QMK for HHBK Pi Pico

WORK IN PROGRESS

https://github.com/qmk/qmk_firmware/blob/master/docs/cli.md

`brew install qmk/qmk/qmk`
`export QMK_HOME='~/qmk_firmware'` # Optional, set the location for qmk_firmware
`qmk setup`  # This will clone qmk/qmk_firmware and optionally set up your build environment

https://github.com/qmk/qmk_firmware/blob/master/docs/custom_matrix.md

`cd ~/qmk_firmware/keyboards/hhkb_lite_2_pico/keymaps/via`
`qmk compile`
`open ~/qmk_firmware/.build`

Drag .uf2 file to Pi Pico

To reset Pico in bootloader mode, hold `BOOTSEL` button while plugging in or
while shorting `run` pin to ground.