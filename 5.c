#include <stdio.h>
#include <stdlib.h>

int* startWithFibonacci(int length) {
	int i;
	int* array;
	array = (int*)malloc(length * sizeof(int));
	if (array == NULL)
		exit(404);
	for (i = 0; i < length; i++) {
		if (i < 2)
			array[i] = i;
		else
			array[i] = array[i - 1] + array[i - 2];
	}
	
	return array;
}

int main(int argc, char* argv[]) {
	int *array;
	int size, i;
	
	printf("Fill N length array with fibonacci sequence numbers.\n");
	printf("Insert array length: ");
	scanf("%d", &size);
	while (size < 1) {
		printf("size must be bigger than one.\n");
		printf("Insert array length: ");
		scanf("%d", &size);
	}
	
	array = startWithFibonacci(size);
	for (i = 0; i < size; i++) {
		printf("%d,", array[i]);
	}
	
	free(array);
	return 0;
}