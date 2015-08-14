#include "navui.h"
#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void halt() {
	endwin();
	exit(0);
}

void main_loop() {
	char string[200];
	while(1) {
		gps_refresh();
		io_clearscreen();
		io_print(0, 0, music_get(string));
		io_printFloat(0, 1, gps_getLatitude());
		io_printFloat(0, 2, gps_getLongitude());
		io_printFloat(0, 3, gps_getSpeed());
		io_refresh();
		sleep(1);
	}

}

int main() {
	io_init();
	gps_init();
	main_loop();
	getch();
	halt();
}
