CC = clang
CXX = clang++
LDFLAGS = -O2
WASM_FLAGS = --target=wasm32 -nostdlib -ffreestanding -fno-exceptions '-Wl,--no-entry' '-Wl,--export-all' '-Wl,--allow-undefined' 

INCLUDES = -I./include/

SRCS = ./src/main.c ./src/env/print.c ./src/env/memory.c

OUTPUT = ./public/build/main.wasm 

$(OUTPUT): $(SRCS)
	$(CC) $(WASM_FLAGS) $(LDFLAGS) -o $(OUTPUT) $(INCLUDES) $(SRCS)