void io_init();
void io_clearscreen();
void io_refresh();
void io_print(int x, int y, char string[]);
void io_printFloat(int x, int y, float num);
void io_printSpeed(int x, int y);
void io_printMusic(int x, int y);

char* music_getArtist();
char* music_getTitle();
char* music_getTime();
char* music_getStatus();

void gps_init();
void gps_refresh();
float gps_getLatitude();
float gps_getLongitude();
float gps_getSpeed();
char* gps_getTime();
float gps_getTrack();
char* gps_getDirection();
int gps_isSettled();

void buttons_init();
