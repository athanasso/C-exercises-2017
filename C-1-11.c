#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j, k;
	char letters[] = {'A', 'C', 'D', 'G', 'J', 'K'};
	int dCounter = 0, totalCounter = 0;
	
	for (i = 1; i <= 4; i++) {
		for (j = i + 1; j <= 5; j++) {
			for (k = j + 1; k <= 6; k++) {
				
				printf("%c-%c-%c\n", letters[i - 1], letters[j-1], letters[k-1]);
				totalCounter++;
				if (letters[i-1] != 'D' && letters[j-1] != 'D' && letters[k-1] != 'D') dCounter++;
			}
		}
	}
	
	printf("Total Counter: %d\n", totalCounter);
	printf("D Counter: %d", dCounter);
	return 0;
}