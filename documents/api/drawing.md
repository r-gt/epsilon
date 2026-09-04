# API: DRAWING.H


## Definitions

```c
typedef struct {
	SDL_Texture *texture_data;
	int x, y;
	int mask[4];
	float scale[2];
	int angle;
	int origin_x, origin_y;
	bool loaded;

} texture;


texture *selected_texture = NULL;

```


## texture* create_texture(const char * path)

Creates a texture and loads **path** (relative to our executable).

Usage:
```c
texture * player = create_texture("./path/to/texture.png");
```


## void load_texture(const char* path)

Loads a texture from **path** into `selected_texture` notice it won't initialize it.
Since it loads a texture from disk, you might not want to run it every frame, your disk will totally bottleneck your CPU.

Usage:
```c
selected_texture = player;
load_texture("./path/to/another_texture.png");
```


## void draw_texture(int x, int y)
Draws `selected_texture` on screen, being `x` and `y` it's position (relative to the texture's origin)

Usage:
```c
selected_texture = player;
draw_texture(10, 5) // draws our texture on screen at x:10 y:5
```


## void destroy_texture()
Destroys `selected_texture`, freeing it's space in memory
**WARNING: Since we don't know what you expect, `selected_texture` is set to NULL, potentially crashing your game!**

Usage:
```c
selected_texture = player;
destroy_texture();
```


## void set_scale(float x, float y)

Sets `selected_texture`'s horizontal and vertical scale.

Usage:
```c
selected_texture = player;
set_scale(2, 2); // twice as wide, twice as tall
```


## void set_mask(int x, int y, int w, int h)

Sets `selected_texture`'s mask.

Usage:
```c
selected_texture = player;
set_mask(8,3, 16,16); // from pixel x:8 y:3 a rectangle 16x16.
```


## void set_origin(int x, int y)
Sets `selected_texture`'s origin for position, scale and rotation.

Usage:
```c
selected_texture = player;
set_origin(14,2); // set's pixel x:14 y:2 as player's origin
```


## void set_render_color(uint32_t rgba)
Sets an RGBA value to multiply.

Usage:
```c
set_render_color(0xFFAA00FF); // red:FF, green:AA, blue:00, alpha:FF
```


## void set_texture_color(uint32_t rgba)
Sets an RGBA value to multiply to a texture.

Usage:
```c
selected_texture = player;
set_texture_render_color(0xFFAA00FF); // red:FF, green:AA, blue:00, alpha:FF
```


## void draw_line(int x1, int y1, int x2, int y2)
Draws a line from Point A (defined by `x1` and  `y1`) and point B (defined by `x2` and  `y2`).

Usage:
```c
set_render_color(0xFF0000FF); // solid red
draw_line(10,10, 30,30);      // diagonal red line from 10,10 to 30,30
```


## void draw_rect(int x, int y, int w, int h)
Draws a rect at `x` and `y` being `w` pixels wide and `h` pixels tall

Usage:
```c
set_render_color(0xFF0000FF); // solid red
draw_rect(10,10, 20,30);      // red 20x30 rectangle at x:10 y:10
```


## void draw_pixel(int x, int y)
Draws a single pixel at `x` and `y`.

Usage:
```c
set_render_color(0xFF0000FF); // solid red
draw_pixel(15,10);            // red pixel at x:15 y:10
```


## void render()
Presents our rendered scene to the window.

Usage:
```c
render();
```


## void clear_screen()
Clears the whole screen with the multiply color selected with `set_render_color()`.

Usage:
```c
set_render_color(0xFF0000FF) // solid red
clear_screen();              // clears the whole screen with the red color
```
