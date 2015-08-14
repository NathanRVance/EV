void io_init();
void io_clearscreen();
void io_refresh();
void io_print(int x, int y, char string[]);
void io_printFloat(int x, int y, float num);

char* music_get(char ret[]);

void gps_init();
void gps_refresh();
float gps_getLatitude();
float gps_getLongitude();
float gps_getSpeed();
