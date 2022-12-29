CC = clang
CXX = clang++
LDFLAGS = -O2
WASM_FLAGS = --target=wasm32 -nostdlib -ffreestanding -fno-exceptions '-Wl,--no-entry' '-Wl,--export-all' '-Wl,--allow-undefined' 

SRCS = main.c

main.wasm: $(SRCS)
	$(CC) $(WASM_FLAGS) $(LDFLAGS) -o main.wasm $(SRCS)