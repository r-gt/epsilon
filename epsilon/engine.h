#ifndef EPSILON_ENGINE_H
#define EPSILON_ENGINE_H

#define SDL_MAIN_USE_CALLBACKS

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdlib.h>




typedef struct {
	int w;
	int h;
	int scale;
	char* title;
	SDL_Window *window;
	SDL_Renderer *renderer;
	MIX_Mixer *mixer;

} window;



window * selected_window = NULL;



void create_window(window* win){
	SDL_SetHint(SDL_SCALEMODE_NEAREST, "0");

	win->window = SDL_CreateWindow(win->title, win->w, win->h, SDL_WINDOW_OPENGL);
	win->renderer = SDL_CreateRenderer(win->window, NULL);

	SDL_SetDefaultTextureScaleMode(win->renderer, SDL_SCALEMODE_NEAREST);

	win->scale=1;

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
}



void select_window(window * win){

	selected_window = win;
}


// if something has to be set up, here is the place to do it.

void setup_epsilon(){


	SDL_Init(SDL_INIT_GAMEPAD | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
	MIX_Init();


}



#include "drawing.h"
#include "events.h"
#include "audio.h"

#endif
