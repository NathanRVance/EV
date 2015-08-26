#include <curses.h>
#include "navui.h"
#include <wchar.h>
#include <locale.h>

void io_init() {
	setlocale(LC_ALL, "");
	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);
	keypad(stdscr, TRUE);
	start_color();
	use_default_colors();
}

void io_clearscreen() {
	clear();
}

void io_refresh() {
	refresh();
}

void io_print(int x, int y, char string[]) {
	mvprintw(y, x, "%s                                                    ", string);
}

void io_printFloat(int x, int y, float num) {
	mvprintw(y, x, "%f                                                    ", num);
}

void io_printMusic(int x, int y) {
	mvprintw(y, x, "%s: %s\n%s\n%s", music_getStatus(), music_getArtist(), music_getTitle(), music_getTime());
}

void io_printSpeed(int x, int y) {
	mvprintw(y, x, "Traveling at %.1f Km/h, %.1f mph       ", gps_getSpeed(), gps_getSpeed() * 0.621371);
}
