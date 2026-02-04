#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "sprite.h"

const char* colors[] = { KBLUE, KPINK, KORANGE };
const char* digi_sprites[] = { "" KBLUE "#     #\n #####\n# # # #" "\n#  #  #\n #####", "" KPINK "#     #\n #####\n# # # #" "\n#  #  #\n #####" };

const char* makeSprite(int index) {
	int num_sprites = sizeof(digi_sprites) / sizeof(digi_sprites[0]);

	return digi_sprites[index % num_sprites];
	// return strcat_s( digi_sprites[index % num_sprites], 100, getColor(index) );
}

const char* getColor(int index) {
	int num_colors = sizeof(colors) / sizeof(colors[0]);

	return strcat_s(calloc(20, sizeof(char)), 20, colors[index % num_colors]);
}