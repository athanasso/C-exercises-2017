#include <stdio.h>
#include <stdlib.h>

void push(double **sorted, int size, double item) {
	double *newArray;
	double *array = *sorted;
	int asc = 0, found = 0, i;
	newArray = (double*)malloc((size + 1) * sizeof(double));
	
	if (array[0] < array[1]) {
		asc = 1;
	}
	
	for (i = 0; i <= size; i++) {
		if (!found) {
			if (asc) {
				if (array[i] <= item && array[i+1] > item) {
					newArray[i] = array[i];
					newArray[i+1] = item;
					i++;
					found = i;
					continue;
				}
			}
			else {
				if (array[i] >= item && array[i+1] < item) {
					newArray[i] = array[i];
					newArray[i+1] = item;
					i++;
					found = i;
					continue;
				}
			}
		}
		if (!found)
			newArray[i] = array[i];
		else
			newArray[i] = array[i-1];
	}
	
	*sorted = newArray;
}

int main(int argc, char* argv[]) {
	double *sorted = (double*)malloc(8 * sizeof(double));
	double item = 4.5;
	int i;
	
	
	for (i=0;i<8;i++) {
		sorted[i] = i;
	}
	push(&sorted, 8, item);
	
	for (i = 0; i < 9; i++) {
		printf("%lf,", sorted[i]);
	}
	
	return 0;
}