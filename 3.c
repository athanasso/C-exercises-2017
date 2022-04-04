#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* solveEquation(double A, double B, double C) {
	double *result;
	double x1, x2, D;
	result = (double*)malloc(3 * sizeof(double));
	
	if (A == 0) {
    	if (B == 0) {
    		if (C == 0)
    			result[0] = 2;
			else
				result[0] = 1;
		}
		else {
			x1 = -C / B;
			result[0] = 0;
			result[1] = x1;
			result[2] = 0;
		}
	}
	else {
		D = pow(B, 2) - 4 * A * C;
		if (D == 0) {
			x1 = -B / (2 * A);
			result[0] = 0;
			result[1] = x1;
			result[2] = x2;
		}
		else if (D > 0) {
			x1 = (-B + sqrt(D)) / (2 * A);
			x2 = (-B - sqrt(D)) / (2 * A);
			result[0] = 0;
			result[1] = x1;
			result[2] = x2;
		}
		else {
			result[0] = 1;
		}
	}
	
	return result;
}

int main(int argc, char* argv[]) {
	double A, B, C;
	double *result;
	
	printf("Insert A: ");
	scanf("%lf", &A);	
	
	printf("Insert B: ");
	scanf("%lf", &B);
	
	printf("Insert C: ");
	scanf("%lf", &C);
	
	result = solveEquation(A, B, C);
	if (result[0] == 0) {
			if (result[2] == 0)
				printf("First grade equation. Result: %lf.\n", result[1]);
			else if (result[1] == result[2])
				printf("One double result: %lf.\n", result[1]);
			else
				printf("Result 1: %lf, Result 2: %lf.\n", result[1], result[2]);
	}
	else if (result[0] == 1)
		printf("Unsolvable.\n");
	else
		printf("Elusive.\n");
	
	return 0;
}