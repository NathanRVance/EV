#include <gps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

static struct timeval tv;
static struct gps_data_t gpsdata;

void gps_init() {
	if (gps_open("localhost", "2947", &gpsdata) == -1) {
		return;
	}
	gps_stream(&gpsdata, WATCH_ENABLE | WATCH_JSON, NULL);
}

void gps_refresh() {
	/* wait for 2 seconds to receive data */
	if (gps_waiting (&gpsdata, 500000)) {
		/* read data */
		if (gps_read(&gpsdata) == -1) {
			//Error!
		} else {
			/* Display data from the GPS receiver. */
			if ((gpsdata.status == STATUS_FIX) && (gpsdata.fix.mode == MODE_2D || gpsdata.fix.mode == MODE_3D) &&
				!isnan(gpsdata.fix.latitude) && !isnan(gpsdata.fix.longitude)) {
				gettimeofday(&tv, NULL);
				//printf("latitude: %f, longitude: %f, speed: %f, timestamp: %ld\n", gpsdata.fix.latitude, gpsdata.fix.longitude, gpsdata.fix.speed, tv.tv_sec);
			} else {
				printf("no GPS data available\n");
			}
		}
	}
}

float gps_getLatitude() {
	return gpsdata.fix.latitude;
}

float gps_getLongitude() {
	return gpsdata.fix.longitude;
}

float gps_getSpeed() {
	return gpsdata.fix.speed;
}

char* gps_getTime() {
	time_t seconds;

	seconds = ((time_t) gpsdata.fix.time) - 60 * 60 * 4;

	return ctime(&seconds);
}

void gps_exit() {
	gps_stream(&gpsdata, WATCH_DISABLE, NULL);
	gps_close (&gpsdata);
}
