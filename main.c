#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define SDL_MAIN_HANDLED
#include "SDL.h"

#include "digimon.h"
#include "party.h"

#include "species.h"

int main() {
	char input[100] = "";
	char command[100] = "";
	char args[50];
	int inputCount= 0;

	Digimon* d1 = NULL;
	Party* myParty = make_party();

	char outputBuffer[100];

	//readSpeciesFamily();
	//makeFamilies();

	/*SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 600, 0);
	SDL_Delay(3000);
	SDL_Quit();*/

	printf("Digimon (Digital Monsters) Management Console (v1/2026)\nCreated by Iced-Code\n");
	printf("\nadd - Adds Digimon to party.\nadd [name] - Adds Digimon with inputted name to party.\ndelete [name] - Removes Digimon with the inputted from your party.\ninfo - Displays party info.\ninfo [name] - Displays info of inputted Digimon.\nclear - Clears program console.\nquit - Quits program.\n\n");

	while (true) {

		printf("\nInput command: ");
		fgets(input, 100, stdin);
		inputCount = sscanf_s(input, "%s %s", command, 100, args, 50);

		if (strlen(command) > 0) {
			if (strcmp(command, "add") == 0 && inputCount == 1) {
				d1 = new_digimon("Koromon");

				if (add_to_party(myParty, d1) == 1) {
					print_digimon(d1, outputBuffer);
					printf("%s", outputBuffer);
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
					printf("%s", outputBuffer);
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

		memset(outputBuffer, 0, sizeof(outputBuffer));
		memset(command, 0, sizeof(command));
		memset(args, 0, sizeof(args));
		memset(input, 0, sizeof(input));
	}

	
	return 0;
}