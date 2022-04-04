#include <stdio.h>
#include <stdlib.h>

double* get2mins(double array[], int size) {
	double* result;
	int i;
	result = (double*)malloc(2 * sizeof(double));
	
	for (i = 0; i < size; i++) {
		if (i == 0) {
			result[0] = array[0];
			result[1] = array[0];
		}
		else {
			if (array[i] < result[1]) {
				if (array[i] < result[0]) {
					result[0] = array[i];
				}
				else {
					result[1] = array[i];
				}
			}
			if (result[1] < result[0]) {
				double temp = result[0];
				result[0] = result[1];
				result[1] = temp;
			}
		}
	}
	
	return result;
}

int main(int argc, char* argv[]) {
	double array[] = {1.2, 1.4, 1.9, 2, 23, 8, 100, 98.0, 0.8, 18, 2};
	int size = 11;
	double* result = get2mins(array, size);
	printf("Min 1: %lf, Min 2: %lf", result[0], result[1]);
	
	return 0;
}