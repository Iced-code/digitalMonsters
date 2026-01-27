#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 21
#define NUM_SPECIES 5

#define KBLUE "\x1B[34m"
#define KC "\x1B[46m"
#define RESET "\x1B[0m"

extern const char* stageNames[]; //  = {"In-Training", "Rookie", "Champion", "Ultimate", "Mega"};
extern const char* species[][NUM_SPECIES];

typedef struct Digimon {
	char* name;
	int age;
	int stage;
	char* species_family[5];
	char* sprite;
} Digimon;

Digimon* new_digimon(const char* name);

// Digimon* getDigimon(const char* name);
char* getName(const Digimon* digimon);
int getAge(const Digimon* digimon);
int getStage(const Digimon* digimon);
char* getSpecies_Family(const Digimon* digimon);
// int calcStage(int age);

void print_digimon(const Digimon* digimon, char* buffer);

//void delete_digimon(Digimon* digimon);
int delete_digimon(Digimon* digimon);