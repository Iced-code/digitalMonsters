#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "species.h"


void write_species_file() {
	FILE* fptr;
	errno_t err;
	err = fopen_s(&fptr, "species.txt", "w");
	if (err == 0) {
		fprintf(fptr, "%s", "Koromon,Agumon,Greymon,MetalGreymon,WarGreymon\nTsunomon,Gabumon,Garurumon,WereGarurumon,MetalGarurumon\n");
		fprintf(fptr, "%s", "Yokomon,Biyomon,Birdramon,Garudamon,Phoenixmon\nMotimon,Tentomon,Kabuterimon,MegaKabuterimon,HerculesKabuterimon\n");
		fprintf(fptr, "%s", "Tanemon,Palmon,Togemon,Lillymon,Rosemon\nBukamon,Gomamon,Ikkakumon,Zudomon,Vikemon\n");
		fprintf(fptr, "%s", "Tokomon,Patamon,Angemon,MagnaAngemon,Seraphimon\nNyaromon,Salamon,Gatomon,Angewomon,Magnadramon\n");

		fclose(fptr);
	}
}

char* readSpeciesFamily() {
	FILE* fptr;
	errno_t err;
	char* out = malloc(100);

	err = fopen_s(&fptr, "species.txt", "r");
	if (err == 0) {
		for (int i = 0; i < 3; i++) {
			fscanf_s(fptr, "%s", out, 100);
			printf("%s\n", out);
		}

		fclose(fptr);
	}
	
	free(out);
	return "h";
}

SPECIES_ID getSpecies(int id) {
	switch (id)
	{
	case 1:
		return AGUMON;
		break;
	case 2:
		return GABUMON;
		break;
	case 3:
		return BIYOMON;
		break;
	case 4:
		return TENTOMON;
		break;
	case 5:
		return PALMON;
		break;
	case 6:
		return GOMAMON;
		break;
	case 7:
		return PALMON;
		break;
	case 8:
		return GATOMON;
		break;
	default:
		break;
	}
}

char* getSpeciesName(SPECIES_ID id) {
	switch (id) {
		case 1:
			return "Koromon";
		case 2:
			return "Tsunomon";
		case 3:
			return "Yokomon";
		case 4:
			return "Motimon";
		case 5:
			return "Tanemon";
		case 6:
			return "Bukamon";
		case 7:
			return "Tokomon";
		case 8:
			return "Nyaromon";
		default:
			break;
	}

	return "Koromon";
}


char** split(char* string, const char * delimiter) {
	const char** output = malloc(sizeof(string));
	int wordcounter = 0;
	
	char* context = NULL;
	char* token = strtok_s(string, delimiter, &context);

	while (token) {
		output[wordcounter] = token;
		wordcounter++;
		token = strtok_s(NULL, delimiter, &context);
	}

	// output = realloc(output, sizeof(string)*wordcounter);
	return output;
}

void makeFamilies() {
	FILE* fptr;
	errno_t err;
	char* out = malloc(100);
	char** output = malloc(100);

	err = fopen_s(&fptr, "species.txt", "r");
	if (err == 0) {
		Species** digimonSpecies = malloc(sizeof(Species) * (NUM_SPECIES));

		for (int i = 0; i < NUM_SPECIES; i++) {
			fscanf_s(fptr, "%s", out, 100);

			printf("\na");
			if (digimonSpecies) {
				digimonSpecies[i] = malloc(sizeof(Species));
				if (digimonSpecies[i]) {
					digimonSpecies[i]->ID = getSpeciesID(i + 1);

					output = split(out, ",");
					for (int j = 0; j < NUM_STAGES; j++) {
						digimonSpecies[i]->family[j] = output[j];
					}
				}
			}

			printf("%d : %s %s %s %s %s\n", digimonSpecies[i]->ID, digimonSpecies[i]->family[0], digimonSpecies[i]->family[1], digimonSpecies[i]->family[2], digimonSpecies[i]->family[3], digimonSpecies[i]->family[4]);
			
			/*for (int x = 0; x < sizeof(digimonSpecies[i]->family); x++) {
				free(digimonSpecies[i]->family[x]);
			}
				
			free(digimonSpecies[i]->family);*/
			memset(output, 0, sizeof(output));
			memset(out, 0, sizeof(out));
		}

		free(digimonSpecies);
		fclose(fptr);
	}

	free(out);
}

 
