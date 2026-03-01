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
- Combos:
  - `T + Y -> Esc`
  - `Q + W -> Tab`
  - `A + S -> Ctrl+A` (tmux leader)
- Dead-key helper outputs (macro style): quote, double-quote, tilde, backtick, caret (all followed by space)

## Intentional Differences

- ZMK Bluetooth actions were omitted as requested.
- QMK behavior is very close but not perfectly identical to ZMK hold-tap internals.
