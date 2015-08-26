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
	char string[400];
	while(1) {
		gps_refresh();
		//io_clearscreen();
		io_printWide(0, 0, music_get(string));
		if(gps_isSettled()) {
			io_print(0, 2, gps_getDirection());
			io_printSpeed(0, 3);
			io_print(0, 4, gps_getTime());
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
