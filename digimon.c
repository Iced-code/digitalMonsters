#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "digimon.h"

const char* stageNames[] = { "In-Training", "Rookie", "Champion", "Ultimate", "Mega" };

Digimon* new_digimon(const char* name) {
	Digimon* digimon = malloc(sizeof(Digimon));
	if (!digimon) {
		perror("ERROR: Unable to allocate memory for Digimon.");
		exit(-1);
	}

	
	srand(time(NULL));
	//char* family[] = species[(rand() % NUM_SPECIES) + 1];

	//digimon->species_family = malloc(sizeof(species) * NUM_SPECIES);
	//digimon->species_family = species[7][1];

	int species_num = (rand() % NUM_SPECIES) + 1;
	if (strcmp(name, "") == 0) {
		digimon->name = malloc(20);
		strcpy_s(digimon->name, 20, getSpeciesName(species_num));
	}
	else {
		digimon->name = malloc(strlen(name) + 1);
		strcpy_s(digimon->name, strlen(name) + 1, name);
	}

	digimon->age = 15;
	digimon->stage = IN_TRAINING;

	//const char* sprite = "" KBLUE "#     #\n #####\n# # # #" "\n#  #  #\n #####";
	const char* sprite = makeSprite(species_num);
	//digimon->species_id = setSpecies();

	digimon->sprite = malloc(strlen(sprite) + 1);
	strcpy_s(digimon->sprite, strlen(sprite) + 1, sprite);

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

STAGE getStage(const Digimon* digimon) {
	if (!digimon) {
		return -1;
	}
	return digimon->stage;
}

char* getSprite(const Digimon* digimon) {
	if (!digimon) {
		return NULL;
	}
	return digimon->sprite;
}

SPECIES_ID getSpeciesID(const Digimon* digimon) {
	if (!digimon) {
		return -1;
	}
	return digimon->species_id;
}

void print_digimon(const Digimon* digimon, char* buffer) {
	if (!digimon) {
		strcpy_s(buffer, 50, "ERROR: No Digimon found.");
	}

	char* dName = getName(digimon);
	SPECIES_ID dSpeciesID = getSpeciesID(digimon);
	int dAge = getAge(digimon);
	STAGE dStage = getStage(digimon);

	if ( dName && dAge && (dStage >= 0) && dSpeciesID) {
		char* stageName = malloc(20);
		strcpy_s(stageName, strlen(stageNames[dStage]) + 1, stageNames[dStage]);

		//char* speciesName = malloc(20);
		//strcpy_s(speciesName, sizeof(speciesName), getSpeciesName(dSpeciesID));

		char* dSprite = getSprite(digimon);
		snprintf(buffer, 100, "\n%s\n\n%s\nAge: %d (%s)\n" RESET, dSprite, dName, dAge, stageName);
		//printf("\n%s\n\n%s\nAge: %d (%s)\n" RESET, dSprite, dName, dAge, stageName);
	
		free(stageName);
	}
	else {
		strcpy_s(buffer, 50, "\nERROR: Could not access this Digimon's info.");
	}
}

int delete_digimon(Digimon* digimon) {
	if (digimon) {
		free(digimon->name);
		free(digimon);

		return(1);
	}
	else {
		return(0);
	}
}
