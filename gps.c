#include <gps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

static struct gps_data_t gpsdata;

void gps_init() {
	if (gps_open("localhost", "2947", &gpsdata) == -1) {
		return;
	}
	gps_stream(&gpsdata, WATCH_ENABLE | WATCH_JSON, NULL);
}

void gps_refresh() {
	/* wait for .5 seconds to receive data */
	if (gps_waiting (&gpsdata, 500000)) {
		gps_read(&gpsdata);
	}
}

float gps_getLatitude() {
	return gpsdata.fix.latitude;
}

float gps_getLongitude() {
	return gpsdata.fix.longitude;
}

float gps_getSpeed() {
	//Speed is in knots, convert to Km/hour
	int speed = gpsdata.fix.speed * 1.852;
	if(speed > 0.1) {
		return speed;
	}
	return 0;
}

char* gps_getTime() {
	time_t seconds;
	seconds = ((time_t) gpsdata.fix.time) - 60 * 60 * 4;
	return ctime(&seconds);
}

float gps_getTrack() {
	return gpsdata.fix.track;
}

int gps_isSettled() {
	return !isnan(gpsdata.fix.speed);
}

void gps_exit() {
	gps_stream(&gpsdata, WATCH_DISABLE, NULL);
	gps_close (&gpsdata);
}
