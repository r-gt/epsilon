#include <stdio.h>
#include "epsilon/engine.h"

int main(){

	setup_epsilon();
	window win;
	win.title="we";
	win.w=512;
	win.h=256;

	create_window(&win);

	set_window_scale(3);

	tilemap map;

	create_tilemap(&map, 0,0, 16,16, 6,4);


	while(running){

		load_texture_tilemap("./asset/sprite.png");

		for (int i = 0; i < 24; i++){
			draw_tile(i*17,10,i);
		}


		end_frame();
		render();

		check_close_button();
	}


}
