#include <stdlib.h>
#include <stdio.h>
#include "navui.h"

char* music_get(char ret[]) {
	FILE *fp;

	fp = popen("sudo -u nathan xmms2 current", "r");
	
	if(fp != NULL) {
		//ret is formatted UTC-8. This will be a problem when we print because
		//accents span two chars, but we'll worry about that later.
		fgets(ret, 399, fp);
		pclose(fp);
	}
	
	return ret;
}
