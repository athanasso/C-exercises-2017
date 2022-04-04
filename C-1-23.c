#include <stdio.h>
#include <stdlib.h>

void sort(char*, int, int);

int main() {
    char** names;
    int* ages;
    int length, i;
    
    printf("How many names shall I read? : ");
    scanf("%d", &length);
    
    names = (char**)malloc(length * sizeof(char*));
    ages = (int*)malloc(length * sizeof(int));
    
    for (i = 0; i < length; i++) {
    	char* buffer = (char*)malloc(255 * sizeof(char));
    	
    	fflush(stdin);
    	printf("Name: ");
    	gets(buffer);
    	names[i] = buffer;
    	
    	printf("Age: ");
    	scanf("%d", &ages[i]);
    	
	}
	
	sort(names, ages, length);
	
	for (i = 0; i < length; i++) {
		printf("\n\nName: %s\n", names[i]);
		printf("Age: %d", ages[i]);
	}
	
	free(names);
	free(ages);
	
	return 0;
}

void sort(char* names[], int ages[], int length) { //bubblesort with 2 arrays with age[] array as the base
	int i, newN;
	
	do {
		newN = 0;
		for (i = 1; i < length; i++) {
			if (ages[i - 1] < ages[i]) {
				int tempAge;
				char* tempName;
				
				tempAge = ages[i-1];
				ages[i - 1] = ages[i];
				ages[i] = tempAge;
				
				tempName = names[i-1];
				names[i - 1] = names[i];
				names[i] = tempName;
				
				newN = i;
			}
		}
		length = newN;
	} while (length != 0);
}