ENGINE = epsilon/SDL/
BIN=bin
NAME=game



ifeq ($(OS),Windows_NT)
    HOST_OS := Windows
else
    HOST_OS := $(shell uname -s)
endif

TARGET ?= $(HOST_OS)


	ifeq ($(HOST_OS), Linux)
		CC= gcc -std=c17
		OUT = ./$(BIN)/$(NAME).out
		MKDIR=mkdir -p
		ARGS= -o $(OUT) -L${BIN} -Wl,-rpath,'$$ORIGIN' -I$(ENGINE)include -L$(ENGINE)lib ${BIN}/libSDL3.so.0 ${BIN}/libSDL3_image.so.0 ${BIN}/libSDL3_mixer.so.0 ${BIN}/libSDL3_ttf.so.0 -lm

		ifeq ($(TARGET), Windows)
			CC= x86_64-w64-mingw32-gcc -std=c17
			OUT = ./$(BIN)/$(NAME)exe
			ARGS= -o $(OUT) -lSDl3 -lSDL3_image -lSDL3_mixer -lSDL3_ttf -lmingw32 -I$(ENGINE)include -L$(ENGINE)lib

		endif

	endif

ifeq ($(HOST_OS), Windows)
	CC= gcc -std=c17
	MKDIR = if not exist $(BIN) mkdir
	OUT = ./$(BIN)/$(NAME).exe


endif

ifeq ($(TARGET), Web)
	CC = emcc --std=c17
	ARGS = -I./epsilon/SDL/include/ -L./epsilon/SDL/lib -L./epsilon/SDL/build-wasm -lSDL3 -lSDL3_image -lSDL3_mixer -lSDL3_ttf -sALLOW_MEMORY_GROWTH=1 -sASYNCIFY\
 -s USE_SDL=3 \
 -s USE_SDL_MIXER=3 \
 -s USE_SDL_IMAGE=3 \
 -s USE_SDL_TTF=3 \
 --shell-file epsilon/shell.html -o bin-web/index.html
endif
# add --preload-file with the path of all your assets so emcc can load them correctly.


.PHONY: make test test-liwin

make:
	@if [ "$(TARGET)" = "Web" ]; then $(MKDIR) bin-web; fi

	$(CC) main.c $(ARGS)

test: make
	cd bin &&\
	../$(OUT)


