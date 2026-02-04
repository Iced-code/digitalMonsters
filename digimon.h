#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sprite.h"
#include "species.h"

#define MAX_NAME_LEN 21

extern const char* stageNames[NUM_STAGES]; //  = {"In-Training", "Rookie", "Champion", "Ultimate", "Mega"};
extern const char* species[][NUM_STAGES];

typedef enum STAGE { 
	IN_TRAINING=0, 
	ROOKIE,
	CHAMPION,
	ULTIMATE,
	MEGA 
} STAGE;

typedef struct Digimon {
	char* name;
	int age;
	STAGE stage;
	SPECIES_ID species_id;
	char* sprite;
} Digimon;

Digimon* new_digimon(const char* name);

char* getName(const Digimon* digimon);
SPECIES_ID getSpeciesID(const Digimon* digimon);
int getAge(const Digimon* digimon);
STAGE getStage(const Digimon* digimon);
char* getSprite(const Digimon* digimon);

void print_digimon(const Digimon* digimon, char* buffer);

int delete_digimon(Digimon* digimon);