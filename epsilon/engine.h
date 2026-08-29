#ifndef EPSILON_ENGINE_H
#define EPSILON_ENGINE_H

#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#ifndef REMOVE_EPSILON_EXTRAS
#include "./extras/maploader.h"
#endif








typedef struct {
	int w;
	int h;
	int scale;
	char* title;
	uint32_t multiply_color;
	SDL_Window *window;
	SDL_Renderer *renderer;
	MIX_Mixer *mixer;

} window;



window * selected_window = NULL;



void create_window(window* win){

	#ifdef __EMSCRIPTEN__

	win->window   = SDL_CreateWindow(win->title, win->w, win->h, 0);
	win->renderer = SDL_CreateRenderer(win->window, NULL);
	#else

	win->window   = SDL_CreateWindow(win->title, win->w, win->h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	win->renderer = SDL_CreateRenderer(win->window, "opengl");
	#endif

	win->scale=1;
	win->multiply_color = 0xFFFFFFFF;

	selected_window = win;

	selected_window->mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
}




void set_window_scale(float scale){
	selected_window->scale = scale;
	SDL_SetRenderScale(selected_window->renderer, scale, scale);
}




void update_window(window* win){

	SDL_SetWindowSize(win->window, win->w, win->h);
	SDL_SetWindowTitle(win->window, win->title);

	SDL_GetWindowSize(win->window, &win->w, &win->h);
}



void select_window(window * win){

	selected_window = win;
}


void toggle_fullscreen(){
	if( SDL_GetWindowFlags(selected_window->window) & SDL_WINDOW_FULLSCREEN)
		SDL_SetWindowFullscreen(selected_window->window, false);
	else
		SDL_SetWindowFullscreen(selected_window->window, true);
}



// if something has to be set up, here is the place to do it.

void setup_epsilon(){


	SDL_Init(SDL_INIT_GAMEPAD | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
	MIX_Init();
	TTF_Init();


}



#include "drawing.h"
#include "font.h"
#include "events.h"
#include "audio.h"



void end_frame(){

	memcpy(previous_key_state, current_key_state, sizeof(current_key_state));
	const _Bool *state = SDL_GetKeyboardState(NULL);
	memcpy(current_key_state, state, SDL_SCANCODE_COUNT);

	SDL_Delay(1000/60); //60 fps
}




#endif


