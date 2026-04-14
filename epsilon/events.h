#ifndef EPSILON_EVENTS_H
#define EPSILON_EVENTS_H

bool running = true;



bool key_is_pressed(const char *key) {
	const bool *state = SDL_GetKeyboardState(NULL);
	SDL_Scancode sc = SDL_GetScancodeFromName(key);

	if (sc == SDL_SCANCODE_UNKNOWN) return false;
	return state[sc];
}



bool mouse_button_is_pressed(const char *button) {
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
		}
	}

}


#endif
