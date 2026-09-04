# API: EVENTS.H
## Definitions
```c
_Bool running = true
```


## _Bool key_is_pressed(const char *key)
Returns true if a key is currently being pressed, if not, returns false.

*NOTICE: this is internally handled by the `SDL_GetScancodeFromName` function, you might need to search for special keys names.*

Usage:
```c
if(key_is_pressed("left")){
    // do something while left key is pressed
}
```


## _Bool key_just_pressed(const char *key)
Returns true only the frame the key just got pressed.

*NOTICE: this is internally handled by the `SDL_GetScancodeFromName` function, you might need to search for special keys names.*

Usage:
```c
if(key_just_pressed("left")){
// do something when left arrow gets pressed
}
```


## _Bool key_just_released(const char *key)
Returns true only the frame the key just got released.

*NOTICE: this is internally handled by the `SDL_GetScancodeFromName` function, you might need to search for special keys names.*

Usage:
```c
if(key_just_released("left")){
    // do something when left arrow gets released
}
```


## _Bool mouse_button_is_pressed(const char *button)
Returns true or false based on `button` being pressed or not.

*possible choices:*
- *"left"*
- *"middle"*
- *"right"*
- *"x1"*
- *"x2"*

Usage:
```c
if(mouse_button_is_pressed("left")){
    // do something while left click is being pressed
}
```


## float mouse_x()
Returns mouse position in `X` axis.

Usage:
```c
int player_aim_x = mouse_x();
```


## float mouse_y()
Returns mouse position in `Y` axis.

Usage:
```c
int player_aim_y = mouse_y();
```


## void check_close_button()
Checks if the window's X button gets pressed, if so, sets `running=false`, in other words, closing the game.

*NOTICE: This is important to be inside your game loop, otherwise you won't be able to close your game.*

Usage:
```c
while(running){ // your game loop.

    check_close_button();
}
```
