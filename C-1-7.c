#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int* countCapitals(char*, int);

int main() {
	char* letters;
	int length, i;
	int* result;
	printf("How many characters should I read: ");
	scanf("%d", &length);
	letters = (char*)malloc(length * sizeof(char));
	
	for(i = 0; i < length; i++) {
		fflush(stdin);
		printf("Char %d from %d: ", i + 1, length);
		scanf("%c", &letters[i]);
	}
	
	result = countCapitals(letters, length);
	for(i = 0; i < 26; i++) {
		printf("%c: %d\n", 65 + i, result[i]);
	}
	
	free(letters);
	free(result);
	
	return 0;
}

int *countCapitals(char* letters, int length) {
    int *result = (int*)malloc(26 * sizeof(int));
    int i;
    for (i = 0; i < 26; i++) {
        result[i] = 0;
    }
   
   
    for (i = 0; i < length; i++) {
        if (letters[i] >= 65 && letters[i] <= 90) {
            result[letters[i] - 65] += 1;
        }
    }
   
    return result;
}