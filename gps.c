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
	/* wait for .2 seconds to receive data */
	if (gps_waiting (&gpsdata, 200000)) {
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
	//Speed is in m/s, convert to Km/hour
	int speed = gpsdata.fix.speed * 60 * 60 / 1000;
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

char* gps_getDirection_private() {
	char ret[3] = {0, 0, 0};	
	float track = gps_getTrack();
	if(track > 337.5 && track < 22.5) return "N";
	if(track < 67.5) return "NE";
	if(track < 112.5) return "E";
	if(track < 157.5) return "SE";
	if(track < 202.5) return "S";
	if(track < 247.5) return "SW";
	if(track < 292.5) return "W";
	if(track < 337.5) return "NW";
	return "F"; //for FAIL!
}

char* dir = "N";
char* gps_getDirection() {
	char* tmp = gps_getDirection_private();
	if(tmp[0] != 'F') dir = tmp;
	return dir;
}
int gps_isSettled() {
	return gpsdata.fix.mode > 1 &&
		!isnan(gpsdata.fix.speed);
}

void gps_exit() {
	gps_stream(&gpsdata, WATCH_DISABLE, NULL);
	gps_close (&gpsdata);
}
