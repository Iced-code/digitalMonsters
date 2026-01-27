#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "party.h"

char outputBuffer[50];

Party* make_party(){
	Party* party = malloc(sizeof(Party));
	if (!party) {
		perror("ERROR: Unable to allocate memory for party.\n");
		exit(-1);
	}

	party->members = malloc(sizeof(Party) * MAX_CAPACITY);
	if (!party->members) {
		perror("ERROR: Unable to allocate memory for party.\n");
		free(party);
		exit(-1);
	}

	party->size = 0;
	party->capacity = MAX_CAPACITY;
	
	return party;
}

int add_to_party(Party* party, Digimon* digimon) {
	if (!party) {
		perror("ERROR: Unable to acess party.\n");
		exit(-1);
	}

	if (party->size >= party->capacity) {
		printf("Unable to add Digimon. Party is at maximum capacity.\n");
		return(0);
	}

	party->members[party->size++] = digimon;
	printf("%s was added to your party.\n", digimon->name);
	return(1);
}

int delete_from_party(Party* party, Digimon* digimon) {
	if (!party) {
		perror("ERROR: Unable to access party.\n");
		exit(-1);
	}

	if (party->size == 0) {
		printf("There are no Digimon in your party.\n");
		return(0);
	}

	for (int i = 0; i < getSize(party); i++) {
		if (digimon == getMembers(party)[i]) {
			delete_digimon(getMembers(party)[i]);

			for (int j = i; j < getSize(party) - 1; j++) {
				party->members[j] = party->members[j + 1];
			}
			party->size--;

			printf("Digimon was removed from your party.\n");
			return(1);
		}
	}

	printf("Could not find this Digimon in your party.\n");
	return(0);
}


Digimon** getMembers(Party *party) {
	if (getSize(party) == 0) {
		printf("Party is empty. No Digimon found.\n");
		return NULL;
	}

	return party->members;
}

Digimon* getDigimon(Party *party, const char* name) {
	int s = getSize(party);
	if (s == 0) {
		printf("Party is empty. No Digimon found.\n");
		return NULL;
	}

	Digimon** members = party->members;
	for (int i = 0; i < s; i++) {
		if (strncmp(members[i]->name, name, 50) == 0) {
			return(members[i]);
		}
	}

	printf("Could not find Digimon \"%s\".\n", name);
	return(NULL);
}

int getSize(Party* party) {
	if (!party) {
		perror("ERROR: Unable to access party.\n");
		exit(1);
	}

	return party->size;
}

void print_party(const Party* party) {
	if (!party) {
		perror("ERROR: Unable to access party.\n");
		exit(1);
	}

	if (getSize(party) == 0) {
		printf("Party is empty. No Digimon found.\n");
	}
	else {
		Digimon** members = getMembers(party);
		int s = getSize(party);

		printf("Your Digimon party:\n\n");
		for (int i = 0; i < s; i++) {
			print_digimon(members[i], outputBuffer);
			printf("%s", outputBuffer);
		}
		memset(outputBuffer, 0, sizeof(outputBuffer));
	}
}

void delete_party(Party* party) {
	if (party) {
		if (getSize(party) > 0) {
			for (int i = 0; i < getSize(party); i++) {
				delete_digimon(party->members[i]);
			}
		}

		free(party->members);
		free(party);
	}
}