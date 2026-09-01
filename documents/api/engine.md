# API: ENGINE.H

## void create_window(window * win)

creates a window, renderer, audio context, and everything needed to handle user inputs, displays, and sound.

Usage:
```
window win;
win.title="Epsilon";
win.w=256;
win.h=256;

create_window(&win);
```
*(from now on, we will reffer any window as "win")*

## void update_window(window * win)
updates all windows values to match the structure's values.

usage:
```
update_window(&win);
```


## void set_window_scale()
set `selected_window`'s scale factor, **NOTICE: it won't modify it's size in pixels, you might do that manually**

Usage:
```
set_window_scale(2); // now every pixel will be twice as big.
update_window(&win);
```

## void toggle_fullscreen()
sets `selected_window` into fullscreen or windowed mode (might not work with fixed size windows)

**WARNING:** it will actually toggle between fullscreen and windowed, is strongly recommended to not run it every frame.

usage:
```
selected_window  = &win // careful with this line, it's untested atm.
toggle_fullscreen();
```
