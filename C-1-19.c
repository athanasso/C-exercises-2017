#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int*, int, int, int);
int generateInt(int, int);
int containsDuplicates(int* array, int);
int isDuplicate(int* array, int, int);

int main() {
    int* array;
    int length, i;
    int min, max;
    int isFullUnique;
    
    printf("Size of array : ");
    scanf("%d", &length);
    
    printf("Minimum bound: ");
    scanf("%d", &min);
    
    printf("Maximum bound: ");
    scanf("%d", &max);
    
    array = (int*)malloc(length * sizeof(int));
    fill(array, length, min, max);
	
	for (i = 0; i < length; i++) { //1
		printf("%d\n", array[i]);
	}
	
	if (containsDuplicates(array, length) == 1) {
		printf("\nDuplicates found in the array.");
	}
	else {
		printf("\nEvery number in the array is unique");
	}
	
	free(array);
	
	return 0;
}

void fill(int* array, int length, int min, int max) {
	int i;
	srand(time(NULL));
	
	for (i = 0; i < length; i++) {
		array[i] = generateInt(min, max);
	}
}

int generateInt(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

int containsDuplicates(int* array, int length) {
	int i;
	for (i = 0; i < length; i++) {
		if (isDuplicate(array, length, array[i])) {
			printf("isduplicate return 1: %d-%d\n", i, array[i]);
			return 1;
		}
	}
	return 0;
}

int isDuplicate(int* array, int length, int needle) {
	int i, occurencies = 0;
	for (i = 0; i < length; i++) {
		if (array[i] == needle)
			occurencies++;
	}
	
	if (occurencies == 1) return 0;
	else return 1;
}