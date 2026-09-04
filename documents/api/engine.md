# API: ENGINE.H

## void create_window(window * win)

Creates a window, renderer, audio context, and everything needed to handle user inputs, displays, and sound.

Usage:
```c
window win;
win.title="Epsilon";
win.w=256;
win.h=256;

create_window(&win);
```
*(from now on, we will reffer any window as "win")*

## void update_window(window * win)
Updates all windows values to match the structure's values.

usage:
```c
update_window(&win);
```


## void set_window_scale(float scale)
Set `selected_window`'s scale factor, **NOTICE: it won't modify it's size in pixels, you might do that manually**

Usage:
```c
set_window_scale(2); // now every pixel will be twice as big.
update_window(&win);
```

## void toggle_fullscreen()
Sets `selected_window` into fullscreen or windowed mode (might not work with fixed size windows)

**WARNING:** It will actually toggle between fullscreen and windowed, is strongly recommended to not run it every frame.

usage:
```c
selected_window  = &win // careful with this line, it's untested atm.
toggle_fullscreen();
```

## void setup_epsilon()
Sets up everything needed by the engine to work properly.

Usage:
```c
setup_epsilon();
```
## void end_frame()
Does everything needed to process the next frame.

Usage:
```c
end_frame();
```
