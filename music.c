#include <stdlib.h>
#include <stdio.h>
#include "navui.h"

char* music_get(char ret[], char command[]) {
	FILE *fp;

	fp = popen(command, "r");
	
	if(fp != NULL) {
		//ret is formatted UTF-8. This will be a problem when we print because
		//accents span two chars, but we'll worry about that later.
		fgets(ret, 399, fp);
		pclose(fp);
	}

	//The shell puts a newline at the end. Annoying!
	int i = 0;
	while(ret[i++] != '\0');
	i -= 2;
	if(ret[i] == '\n') ret[i] = '\0';
	
	return ret;
}

char* music_getArtist() {
	static char ret[400];
	return music_get(ret, "mpc current -f '\%artist\%'");
}

char* music_getTitle() {
	static char ret[400];
	return music_get(ret, "mpc current -f '\%title\%'");
}

char* music_getTime() {
	static char ret[400];
	return music_get(ret, "mpc | sed '2q;d' | awk '{print $3}'");
}

char* music_getStatus() {
	static char ret[400];
	return music_get(ret, "mpc | sed '2q;d' | awk '{print $1}' | sed 's/\\[\\|\\]//g'");
}
