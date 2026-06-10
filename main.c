#include "epsilon/engine.h"


int main(int argc, char **argv){
	setup_epsilon();

	window win;
	win.title="Epsilon";
	win.w=256;
	win.h=256;

	create_window(&win);

	// set running to "0" to close the game.
	
	while(running){
		set_render_color(0x000000FF);
		clear_screen();


		render();
		end_frame();
		check_close_button();
	}
	return 0;
}
