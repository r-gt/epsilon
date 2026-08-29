#ifndef EPSILON_EVENTS_H
#define EPSILON_EVENTS_H

_Bool running = true;


Uint8 previous_key_state[SDL_SCANCODE_COUNT];
Uint8 current_key_state[SDL_SCANCODE_COUNT];


_Bool key_is_pressed(const char *key) {
	SDL_Scancode sc = SDL_GetScancodeFromName(key);
	if (sc == SDL_SCANCODE_UNKNOWN) return false;
	return current_key_state[sc];
}

_Bool key_just_pressed(const char *key) {
	SDL_Scancode sc = SDL_GetScancodeFromName(key);
	if (sc == SDL_SCANCODE_UNKNOWN) return false;
	return current_key_state[sc] && !previous_key_state[sc];
}

_Bool key_just_released(const char *key) {
	SDL_Scancode sc = SDL_GetScancodeFromName(key);
	if (sc == SDL_SCANCODE_UNKNOWN) return false;
	return !current_key_state[sc] && previous_key_state[sc];
}




_Bool mouse_button_is_pressed(const char *button) {
	SDL_MouseButtonFlags buttons = SDL_GetMouseState(NULL, NULL);

	if (SDL_strcasecmp(button, "left")   == 0) return (buttons & SDL_BUTTON_LMASK)  != 0;
	if (SDL_strcasecmp(button, "right")  == 0) return (buttons & SDL_BUTTON_RMASK)  != 0;
	if (SDL_strcasecmp(button, "middle") == 0) return (buttons & SDL_BUTTON_MMASK)  != 0;
	if (SDL_strcasecmp(button, "x1")     == 0) return (buttons & SDL_BUTTON_X1MASK) != 0;
	if (SDL_strcasecmp(button, "x2")     == 0) return (buttons & SDL_BUTTON_X2MASK) != 0;

	return false;
}



float mouse_x(void) {
	float x;
	SDL_GetMouseState(&x, NULL);
	return (x/selected_window->scale);
}



float mouse_y(void) {
	float y;
	SDL_GetMouseState(NULL, &y);
	return (y/selected_window->scale);
}



void check_close_button(){

	SDL_Event event;
	while(SDL_PollEvent(&event)) {

		if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
			running = false;

		}else if (event.type == SDL_EVENT_WINDOW_RESIZED) {
			selected_window->w = event.window.data1;
			selected_window->h = event.window.data2;

		}
	}

}


#endif
