#include "navui.h"
#include <sys/time.h>
#include <stdio.h>

struct timeval t0;
struct timeval t1;
static double distance;

void stats_init() {
	gettimeofday(&t0, NULL);
	gettimeofday(&t1, NULL);
	distance = 0;
}

double stats_refresh() {
	gettimeofday(&t1, NULL);
	long elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec; //microseconds
	double speed = gps_getSpeed(); //meters per second
	double dist = (speed * elapsed) / 1000000;
	distance += dist;
	t0.tv_sec = t1.tv_sec;
	t0.tv_usec = t1.tv_usec;
	return distance;
}
