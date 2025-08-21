#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 21

extern const char stageNames[5][15]; //  = {"In-Training", "Rookie", "Champion", "Ultimate", "Mega"};

typedef struct Digimon {
	char* name;
	int age;
	int stage;
} Digimon;

Digimon* new_digimon(const char* name);

// Digimon* getDigimon(const char* name);
char* getName(const Digimon* digimon);
int getAge(const Digimon* digimon);
int getStage(const Digimon* digimon);
// int calcStage(int age);

void print_digimon(const Digimon* digimon);

//void delete_digimon(Digimon* digimon);
int delete_digimon(Digimon* digimon);