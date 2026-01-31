#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "species.h"

#define MAX_NAME_LEN 21

#define KBLUE "\x1B[34m"
#define KC "\x1B[46m"
#define RESET "\x1B[0m"

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
	SPECIES_ID id;
	// char* species;
	// char* species_family[5];
	char* sprite;
} Digimon;

Digimon* new_digimon(const char* name);

char* getName(const Digimon* digimon);
int getAge(const Digimon* digimon);
//int getStage(const Digimon* digimon);
STAGE getStage(const Digimon* digimon);
// char* getSpecies(const Digimon* digimon);
char* getSprite(const Digimon* digimon);
// char* getSpecies_Family(const Digimon* digimon);
// int calcStage(int age);

void print_digimon(const Digimon* digimon, char* buffer);

int delete_digimon(Digimon* digimon);