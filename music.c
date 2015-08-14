#include <stdio.h>
#include <stdlib.h>

char* music_get(char ret[]) {
	FILE *fp;
	
	fp = popen("xmms2 current", "r");
	
	if(fp != NULL) {
		while(fgets(ret, 199, fp) != NULL);
		pclose(fp);
	}
	
	return ret;
}
