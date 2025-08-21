#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "digimon.h"

const char stageNames[5][15] = { "In-Training", "Rookie", "Champion", "Ultimate", "Mega" };

Digimon* new_digimon(const char* name) {
	Digimon* digimon = malloc(sizeof(Digimon));
	if (!digimon) {
		perror("ERROR: Unable to allocate memory for Digimon.");
		exit(1);
	}

	digimon->name = malloc(strlen(name) + 1);
	strcpy_s(digimon->name, strlen(name) + 1, name);
	
	digimon->age = 15;
	digimon->stage = 0;

	return digimon;
}

char* getName(const Digimon *digimon) {
	if (!digimon) {
		return NULL;
	}
	return digimon->name;
}

int getAge(const Digimon* digimon) {
	if (!digimon) {
		return -1;
	}
	return digimon->age;
}

int getStage(const Digimon* digimon) {
	if (!digimon) {
		return -1;
	}
	return digimon->stage;
}

void print_digimon(const Digimon* digimon) {
	if (!digimon) {
		printf("ERROR: No Digimon found.");
	}

	char* dName = getName(digimon);
	int dAge = getAge(digimon);
	int dStage = getStage(digimon);

	if ( dName && dAge >= 0 && (dStage >= 0 && dStage < sizeof(stageNames)) ) {
		char* stageName = malloc(16);
		strcpy_s(stageName, strlen(stageNames[dStage]) + 1, stageNames[dStage]);
		//strncpy_s(stageName, 15, stageNames[dStage], strlen(stageNames[dStage]));
		printf("\n%s\nAge: %d (%s)\n", dName, dAge, stageName);
		free(stageName);
	}
	else {
		printf("\nERROR: Could not access this Digimon's info.");
	}
}

int delete_digimon(Digimon* digimon) {
	if (digimon) {
		free(digimon->name);
		free(digimon);
		//printf("\nDigimon was deleted.\n");
		return(1);
	}
	else {
		//printf("No Digimon could be found.\n");
		return(0);
	}
}
