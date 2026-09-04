# API: AUDIO.H

## Definitions:
```c

typedef struct {
	MIX_Audio* data;
	MIX_Track* track;
} audio;

 audio * selected_audio = NULL;
```


## audio * create_audio(const char* path, bool predecode)
Creates, defines and loads an audio form `path`.

- **predecode=true:** decodes audio first, then saves it into ram, requieres less CPU overhead but needs more memory, useful for sound effects.
- **predecode=false:** saves audio first, then decodes it as it plays, needs less memory but needs extra CPU cycles.

Usage:
```c
audio * level_1_music = create_audio("./path/to/music.ogg", false);

audio * player_jump_sfx= create_audio("./path/to/sfx.ogg", true);
```


## void destroy_audio()
Destroys `selected_audio`, freeing it's memory space.

**WARNING: Since we don't know what you expect, selected_audio gets set to NULL, potentially crashing your game if you don't set it to anything else!**

Usage:
```c
selected_audio = level_1_music;
destroy_audio();
```


## void play_audio()
Plays `selected_audio` with it's setted volume and speed.

*NOTICE: this function won't consider if selected_audio is already playing, if you run it every frame you will go deaf.*

Usage:
```c
selected_audio = level_1_music;
play_audio();
```


## void set_speed(float speed)
Sets `selected_audio`'s speed.

Usage:
```c
selected_audio = level_1_music;
set_speed(2); // twice as fast
```


## void set_volue(float volume)
Sets `selected_audio`'s volume.

Usage:
```c
selected_audio = level_1_music;
set_volume(0.5); // half it's volume
```


## bool is_playing()
Returns `true` if `selected_audio` is actually playing.

Usage:
```c
selected_audio = level_1_music;
if(!is_playing()){
    // do something, like playing it again, like a loop.
}
```
