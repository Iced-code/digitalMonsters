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

	char outputBuffer[50];

	printf("Digimon (Digital Monsters) Management Console (v1/2026)\nCreated by Iced-Code\n");
	printf("\nadd - Adds Digimon to party.\nadd [name] - Adds Digimon with inputted name to party.\ndelete [name] - Removes Digimon with the inputted from your party.\ninfo - Displays party info.\ninfo [name] - Displays info of inputted Digimon.\nclear - Clears program console.\nquit - Quits program.\n\n");


	while (true) {
		printf(RESET "\nInput command: ");
		fgets(input, 50, stdin);
		inputCount = sscanf_s(input, "%s %s", command, 50, args, 50);

		if (strlen(command) > 0) {
			if (strcmp(command, "add") == 0 && inputCount == 1) {
				d1 = new_digimon("Koromon");

				if (add_to_party(myParty, d1) == 1) {
					print_digimon(d1, outputBuffer);

				}
				else {
					free(d1->name);
					free(d1);
					d1 = NULL;
				}
			}
			else if (strcmp(command, "add") == 0 && inputCount == 2) {
				d1 = new_digimon(args);

				if (add_to_party(myParty, d1) == 1) {
					print_digimon(d1, outputBuffer);
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
			else if (strcmp(command, "info") == 0 && inputCount == 1) {
				print_party(myParty);
			}
			else if (strcmp(command, "info") == 0 && inputCount == 2) {
				d1 = getDigimon(myParty, args);
				if (d1) {
					print_digimon(d1, outputBuffer);
					d1 = NULL;
					printf("%s", outputBuffer);
				}
				else {
					printf("Digimon does not exist.\n");
				}
			}
			else if (strcmp(command, "help") == 0 && inputCount == 1) {
				printf("\nadd - Adds Digimon to party.\nadd [name] - Adds Digimon with inputted name to party.\ndelete [name] - Removes Digimon with the inputted from your party.\ninfo - Displays party info.\ninfo [name] - Displays info of inputted Digimon.\nclear - Clears program console.\nquit - Quits program.\n");
			}
			else if (strcmp(command, "clear") == 0) {
				system("cls");
				printf("Digimon (Digital Monsters) Management Console (v1/2026)\nCreated by Iced-Code\n");
			}
			else if (strcmp(command, "quit") == 0 || strcmp(command, "exit") == 0) {
				delete_party(myParty);
				printf("\nGoodbye.\n" RESET);
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