#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STAGES 5
#define NUM_SPECIES 8

extern const char* agumon_family[NUM_STAGES]; // = { "Koromon","Agumon","Greymon","MetalGreymon","WarGreymon" };

typedef enum SPECIES_ID {
	AGUMON = 1,
	GABUMON = 2,
	BIYOMON = 3,
	TENTOMON = 4,
	PALMON = 5,
	GOMAMON = 6,
	PATAMON = 7,
	GATOMON = 8
} SPECIES_ID;

SPECIES_ID getSpecies(int id);
char* getSpeciesName(SPECIES_ID id);

typedef struct Species {
	SPECIES_ID ID;
	char* family[NUM_STAGES];
} Species;

void write_species_file();
char* readSpeciesFamily();
void makeFamilies();
