#include <stdio.h>
#include <stdlib.h>

int* getMinMax(int array[], int size) {
	int min, max, i;
	int* result;
	result = (int*)malloc(2 * sizeof(int));
	min = max = array[0];
	
	for (i = 0; i < size; i++) {
		if (array[i] < min)
			min = array[i];
		else if (array[i] > max)
			max = array[i];
	}
	
	result[0] = min;
	result[1] = max;
	return result;
}

int main(int argc, char* argv[]) {
	int array[] = {30, 10, 23, 25, 35, 65, 2, 4, 5};
	int size = 9;
	int* minMax = getMinMax(array, size);
	
	printf("Get min/max from array.\n\n");
	printf("min: %d\n", minMax[0]);
	printf("max: %d\n", minMax[1]);
	
	return 0;
}