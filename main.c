#include "navui.h"
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void halt() {
	endwin();
	exit(0);
}

void main_loop() {
	while(1) {
		gps_refresh();
		//io_clearscreen();
		io_printMusic(0, 0);
		if(gps_isSettled()) {
			io_print(0, 3, gps_getDirection());
			io_printSpeed(0, 4);
			io_print(0, 5, gps_getTime());
		}
		io_refresh();
	}
}

int main() {
	io_init();
	gps_init();
	buttons_init();
	main_loop();
	halt();
}
