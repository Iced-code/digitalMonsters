#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#include "digimon.h"
#include "party.h"

int main() {
	char input[50] = "";
	char command[50] = "";
	char args[50];
	int inputCount= 0;

	Digimon* d1 = NULL;
	Party* myParty = make_party();

	while (true) {
		printf("\nInput command: ");
		fgets(input, 50, stdin);
		inputCount = sscanf_s(input, "%s %s", command, 50, args, 50);

		if (strlen(command) > 0) {
			if (strcmp(command, "create") == 0 && inputCount == 1) {
				d1 = new_digimon("Koromon");

				if (add_to_party(myParty, d1) == 1) {
					print_digimon(d1);
				}
				else {
					free(d1->name);
					free(d1);
					d1 = NULL;
				}
			}
			if (strcmp(command, "create") == 0 && inputCount == 2) {
				d1 = new_digimon(args);

				if (add_to_party(myParty, d1) == 1) {
					print_digimon(d1);
				}
				else {
					free(d1->name);
					free(d1);
					d1 = NULL;
				}
			}
			else if (strcmp(command, "delete") == 0 && inputCount == 1) {
				printf("Include the name of the Digimon you wish to remove. ex. (\"delete Koromon\")\n");
			}
			else if (strcmp(command, "delete") == 0 && inputCount == 2) {
				d1 = getDigimon(myParty, args);
				if (d1) {
					if (delete_from_party(myParty, d1) != 1) {
							
						delete_digimon(d1);
					}
					d1 = NULL;
				}
			}
			else if (strcmp(command, "info") == 0) {
				print_party(myParty);
			}
			else if (strcmp(command, "quit") == 0) {
				
				delete_party(myParty);
				printf("\nGoodbye.\n");
				break;
			}
			else {
				printf("Unknown command.\n");
			}
		}

		memset(input, 0, sizeof(input));
		memset(command, 0, sizeof(command));
		memset(args, 0, sizeof(args));
	}

	
	return 0;
}
