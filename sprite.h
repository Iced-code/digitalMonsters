#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KBLUE "\x1b[38;5;117m"
#define KPINK "\x1b[38;5;13m"
#define KORANGE "\x1b[38;5;196m"

#define RESET "\x1B[0m"

extern const char* colors[];
extern const char* digi_sprites[];

const char* makeSprite(int index);