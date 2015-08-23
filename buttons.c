#include "navui.h"
#include <wiringPi.h>
#include <stdlib.h>

int pins[] = { 21, 20, 19, 16, 13, 12, 6, 5 };
int pinlen = 8;

void buttonPressed(int pin) {
	switch(pin) {
		case 21:
			break;
		case 20:
			break;
		case 19:
			break;
		case 16:
			break;
		case 13:
			system("sudo -u nathan xmms2 next");
			break;
		case 12:
			system("sudo -u nathan xmms2 prev");
			break;
		case 6:
			system("sudo -u nathan xmms2 toggle");
			break;
		case 5:
			break;
		default:
			break;
	}
}

void buttons_init() {
	wiringPiSetupGpio();
	int i;
	for(i = 0; i < pinlen; i++) {
		pinMode(pins[i], INPUT);
		pullUpDnControl(pins[i], PUD_UP);
	}
}

void checkButtons() {
	int i;
	for(i = 0; i < pinlen; i++) {
		if(! digitalRead(pins[i])) {
			buttonPressed(pins[i]);
		}
	}
}
