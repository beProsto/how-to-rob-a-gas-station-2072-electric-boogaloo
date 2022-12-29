# How to rob a gas station 2072 - Electric Boogaloo

POtO Software's [How To Rob A Gas Station](https://poto-software.itch.io/how-to-rob-a-gas-station) game's fangame, but written in pure `C` with `WebAssembly`.

Check out POtO Software on [https://potosoftware.github.io/](https://potosoftware.github.io/)!
Play their games on [https://poto-software.itch.io/](https://poto-software.itch.io/)!

### This is only a Fan Game, check out the original game, it's awesome.

## Compilation:

Make sure you have `clang` with `wasm` compilation target support installed! (Versions )

Use `make` to compile the project:
```bash
make
```

## TODO:

To implement:

1. STDLIB Reimplementation
    - ~~logging (printf, etc)~~
    - memory (malloc, memset, memcpy, realloc?, free)
2. WebGL implementation
    - porting
3. Interactions
    - Keboard input
    - Mouse input
    - Touch controls
4. Sounds
    - WebAudio API / DOM Audio Element

5. __ THE REST __