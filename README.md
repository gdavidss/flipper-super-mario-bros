# Super Mario Bros — Flipper Zero

A side-scrolling platformer for the Flipper Zero, ported from the 1985 NES *Super Mario Bros.* The level geometry, physics, and music are derived from the published [SMB1 disassembly (SMBDIS.ASM)](https://github.com/nwoeanhinnogaehr/smb-assembler), scaled down to a 128×64 1-bit screen.

## Features

- All 32 SMB1 levels (worlds 1-1 through 8-4) with castles, pits, pipes, bricks, ?-blocks
- Goomba and Koopa enemies with SMB1-accurate behaviors (walk, stomp, shell kick, ledge turn for red koopas)
- Mushroom power-up → big Mario; crouch with Down-arrow to fit through 1-tile gaps
- Variable-height jump with coyote time + jump buffer
- Double-tap a direction to sprint
- Overworld theme decoded byte-for-byte from SMBDIS's Square-2 channel data, plus jump/stomp/coin/powerup/1-up/death/win SFX
- Title menu with Controls page and Settings page (Music vol / SFX vol / Brightness sliders)
- Hold OK to quit (confirmation overlay)

## Building

Requires [ufbt](https://github.com/flipperdevices/flipperzero-ufbt):

```sh
ufbt           # build flipper_mario.fap
ufbt launch    # build + push to a connected Flipper + run
```

The `.fap` lands at `dist/flipper_mario.fap` and `/ext/apps/Games/flipper_mario.fap` on the SD card.

## Controls

| Action | Button |
|---|---|
| Move | D-pad ← / → |
| Jump | Back |
| Sprint | Double-tap a direction and hold |
| Crouch (big Mario only) | Down |
| Navigate menu | Up / Down |
| Adjust setting | Left / Right |
| Select / cycle setting | OK |
| Quit | Hold OK |

## Project layout

```
application.fam      # Flipper app manifest
flipper_mario.c      # game loop, physics, rendering, menu, input
sprites.h            # 8x8 monochrome sprite atlas
sound.h              # piezo sequencer + SMB1 music/SFX
level_format.h       # tile table + Level struct
level_<world>_<n>.h  # 32 levels (1-1 through 8-4)
icon.png             # 10x10 app icon
```

## Credits

- Original game: Nintendo, 1985 (Koji Kondo — music)
- SMB1 NES disassembly: Doppelganger, mirrored in [nwoeanhinnogaehr/smb-assembler](https://github.com/nwoeanhinnogaehr/smb-assembler)
- Port: Gui Dávid
