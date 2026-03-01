# endgame-config

QMK configuration for The Endgame keyboard, ported from a ZMK Corne/Chocofi setup.
It is inspired by this ZMK config: https://github.com/YannickHerrero/chocofi-config

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

## Install

After building, flash the firmware to your keyboard:

```bash
qmk flash -kb endgame -km zmk_port
```

If your board does not auto-enter bootloader mode, put it in bootloader manually (usually by pressing the reset button or using the keyboard reset key), then run the flash command again.

Quick workflow:
- Plug in the keyboard over USB
- Enter bootloader mode
- Run `qmk flash -kb endgame -km zmk_port`
- Wait for flashing to finish and for the keyboard to reboot

## What Was Ported From ZMK

- Layers: `base`, `num`, `nav`, `opt`, `util`
- Home-row mods on `A/S/D/F` and `U/I/O/P`
- Thumb behavior equivalents:
  - `MO(1)` for number layer access
  - `LGUI_T(KC_ENT)` for GUI-hold / Enter-tap
  - `LT(_NAV, KC_SPC)` for Nav-hold / Space-tap
  - `LT(_UTIL, KC_F18)` for Util-hold / F18-tap
- Timing intent:
  - `TAPPING_TERM = 200`
  - thumb tap-holds overridden to `280`
  - `QUICK_TAP_TERM = 175`
  - `HOLD_ON_OTHER_KEY_PRESS`
  - `CHORDAL_HOLD` enabled (Achordion-like opposite-hand tap-hold behavior)
- Combos:
  - `T + Y -> Esc`
  - `Q + W -> Tab`
  - `A + S -> Ctrl+A` (tmux leader)
- Dead-key helper outputs (macro style): quote, double-quote, tilde, backtick, caret (all followed by space)

## Intentional Differences

- ZMK Bluetooth actions were omitted as requested.
- QMK behavior is very close but not perfectly identical to ZMK hold-tap internals.
