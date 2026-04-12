#include <stdio.h>
#include "epsilon/engine.h"

int main(){

	setup_epsilon();
	window win;
	win.title="epsilon";
	win.w=256;
	win.h=256;

	create_window(&win);






	while(running){


		check_close_button();
	}


}
