#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateInt(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

int main(int argc, char* argv[]) {
	int chosen, tries = 0, input, won = 0;
	srand(time(NULL));
	chosen = generateInt(0, 100);
	
	printf("-----Guess the number-----\n\n", chosen);
	
	do {
		printf("Input a number: ");
		scanf("%d", &input);
		
		if (input == chosen) {
			won = 1;
			printf("Congratulations, you won with %d tries!", tries);
		}
		else {
			if (input > chosen) {
				printf("The magic number is smaller than your input. Tries left: %d\n", 6 - tries);
			}
			else {
				printf("The magic number is bigger than your input. Tries left: %d\n", 6 - tries);
			}
			tries++;
		}
	} while (input != chosen && tries < 7 && !won);
	
	if (!won) {
		printf("You lost\n");
	}
	
	return 0;
}