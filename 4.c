#include <stdio.h>
#include <stdlib.h>

double* makeArray(int length, double fill) {
	double *array;
	int i;
	array = (double*)malloc(length * sizeof(double));
	if (array == NULL)
		exit(404);
	for (i = 0; i < length; i++) {
		array[i] = fill;
	}
	
	return array;
}

int main(int argc, char* argv[]) {
	int N, L;
	double *array;
	printf("Create N length Array and fill with L.\n");
	printf("Insert array length: ");
	scanf("%d", &N);
	printf("Insert fill character: ");
	scanf("%lf", &L);
	
	array = makeArray(N, L);
	
	free(array);
	
	return 0;
}