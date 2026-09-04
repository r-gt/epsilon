# API: FONT.H

## Definitions
```c
typedef struct {
	TTF_Font *font_data;
	SDL_Color color;
	float scale;
	bool loaded;
} font;

font * selected_font = NULL;
```

## font * create_font(const char *path, int size)
Creates a font and sets `selected_font` to it, loading `path` with the desired `size` in pixels (if you're using a bitmap font, make sure you set the correct size).

*NOTICE: Epsilon doesn't include any default font, you might get one by yourself, either from your system or downloading one online.*

Usage:
```c
font * modern_dos = create_font("./path/to/font.ttf", 16);
```


## void load_font(const char *path, int size)
Loads a font into `selected_font`, but won't initialize it (use `create_font` for that).

Usage:
```c
selected_font = modern_dos;
load_font("./path/to/font.ttf", 16);
```


## void set_font_color(uint32_t rgba)
Sets `selected_font`'s font color.

Usage:
```c
selected_font = modern_dos;
set_font_color(0x11223344); // red:11 green:22 blue:33 alpha:44
```

## void set_font_scale(float scale)
Sets `selected_font`'s scale (might look blurry/pixelated if you scale it up, careful with that).

Usage:
```c
selected_font = modern_dos;
set_font_scale(2); // Twice as big.
```

## void draw_text(const char *text, int x, int y)
Writes `text` to the desired `x` and `y` position using `selected_font`.

Usage:
```c
selected_font = modern_dos;
draw_text("example", 20,30);
```


## void destroy_font()
Destroys `selected_font`, freeing it's memory space.

**WARNING: Since we don't know what you expect, selected_font gets set to NULL, potentially crashing your game if you don't set it to anything else!**

Usage:
```c
selected_font = modern_dos;
destroy_font();
```
