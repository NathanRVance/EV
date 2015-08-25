#include <stdlib.h>
#include <stdio.h>
#include "navui.h"

wchar_t* music_get(wchar_t ret[]) {
	FILE *fp;
	char tmp[400];

	fp = popen("sudo -u nathan xmms2 current", "r");
	
	if(fp != NULL) {
		fgets(tmp, 399, fp);
		pclose(fp);
	}
	
	int i = 0;
	int j = 0;
	while(tmp[i] != '\0') {
		if(tmp[i] < '\255') {
			mbtowc(&ret[j++], &tmp[i++], 1);
		} else {
			mbtowc(&ret[j++], &tmp[i++], 4);
			i++;
		}
	}
	
	return ret;
}
