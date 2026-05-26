#include <stdio.h>
#include <stdlib.h>
#include "epsilon/engine.h"


int main(int argc, char **argv){
	setup_epsilon();

	window win;
	win.title="Epsilon";
	win.w=256;
	win.h=256;

	create_window(&win);


	while(running){
		set_render_color(0x000000FF);
		clear_screen();

		set_render_color(0xFFFFFFFF);
		draw_rect(mouse_x()-8, mouse_y()-8, 16, 16);

		render();
		end_frame();
		check_close_button();
	}
	return 0;
}
