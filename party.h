#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "digimon.h"

#define MAX_CAPACITY 3


typedef struct Party {
	Digimon** members;
	int size;
	int capacity;
} Party;

Party* make_party();

int add_to_party(Party* party, Digimon* digimon);
int delete_from_party(Party* party, Digimon* digimon);

Digimon** getMembers(Party *party);
Digimon* getDigimon(Party* party, const char* name);
int getSize(Party* party);

void print_party(const Party* party);

void delete_party(Party* party);