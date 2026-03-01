# endgame-config

QMK configuration for The Endgame keyboard, ported from a ZMK Corne/Chocofi setup.

## Goal

Replicate the original ZMK behavior as closely as possible:
- Same layer structure and key placement
- Same home-row mod timing intent
- Same combo timing intent
- Equivalent macro behavior for dead-key style output

## Source Repositories

- ZMK source layout: `/home/yannick/dev/chocofi-config`
- Endgame keyboard definition: `/home/yannick/dev/TheEndgame2024/003 FIRMWARE/qmk-config-endgame`

## Build (inside a QMK checkout)

Copy this repo's `keyboards/endgame` folder into your `qmk_firmware/keyboards/` tree,
then compile:

```bash
qmk compile -kb endgame -km zmk_port
```
