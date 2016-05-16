#include "navui.h"
#include <wiringPi.h>
#include <stdlib.h>
#include <pthread.h>

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
			system("mpc next");
			break;
		case 12:
			system("mpc prev");
			break;
		case 6:
			system("mpc toggle");
			break;
		case 5:
			break;
		default:
			break;
	}
}

int checkButtons() {
	int i;
	for(i = 0; i < pinlen; i++) {
		if(! digitalRead(pins[i])) {
			buttonPressed(pins[i]);
			return 1;
		}
	}
	return 0;
}

void *buttonPoller(void *arg) {
	while(1) {
		if(checkButtons()) {
			delay(200);
		}
	}
}

void buttons_init() {
	wiringPiSetupGpio();
	int i;
	for(i = 0; i < pinlen; i++) {
		pinMode(pins[i], INPUT);
		pullUpDnControl(pins[i], PUD_UP);
	}
	pthread_t pth;
	pthread_create(&pth, NULL, buttonPoller, "");
}
