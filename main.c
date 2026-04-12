#include <stdio.h>
#include "epsilon/engine.h"

int main(int argc, char *argv){

	setup_epsilon();
	window win;
	win.title="epsilon";
	win.w=256;
	win.h=256;

	create_window(&win);

	while(running){


		check_close_button();
	}

	return 0;
}
