ENGINE = epsilon/SDL/
BIN=bin

ifeq ($(OS),Windows_NT)
    HOST_OS := Windows
else
    HOST_OS := $(shell uname -s)
endif

TARGET ?= $(HOST_OS)


	ifeq ($(HOST_OS), Linux)
		GPP= gcc -std=c17
		OUT = ./$(BIN)/game.out
		MKDIR=mkdir -p
		ARGS= -o $(OUT) $(shell pkg-config --cflags --libs sdl3 sdl3-image sdl3-ttf sdl3-mixer) -lm

		ifeq ($(TARGET), Windows)
			GPP= x86_64-w64-mingw32-gcc -std=c17
			OUT = ./$(BIN)/game.exe
			ARGS= -o $(OUT) -lSDl3 -lSDL3_image -lSDL3_mixer -lSDL3_ttf -lmingw32 -I$(ENGINE)include -L$(ENGINE)lib

		endif


	endif

ifeq ($(HOST_OS), Windows)
	GPP= gcc -std=c17
	MKDIR = if not exist $(BIN) mkdir
	OUT = ./$(BIN)/game.exe


endif


.PHONY: make test test-liwin

make:
	$(MKDIR) bin
	$(GPP) main.c $(ARGS)

test: make
	$(OUT)


