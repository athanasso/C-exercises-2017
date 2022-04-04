#include <stdio.h>
#include <stdlib.h>

double* solveEquation(double a, double b) {
	double* response;
	response = (double*)malloc(2 * sizeof(double));
	
	if (a == 0 && b == 0) {
		response[0] = 2;
	}
	else if (a == 0 && b != 0) {
		response[0] = 1;
	}
	else {
		response[0] = 0;
		response[1] = b/a;
	}
	
	return response;
}

int main(int argc, char* argv[]) {
	double a, b, *solved;
	printf("Solve equation of ax = b type\n");
	printf("Insert A: ");
	scanf("%lf", &a);
	printf("Insert B: ");
	scanf("%lf", &b);
	
	solved = solveEquation(a, b);
	if (!solved[0]) {
		printf("Result: %lf", solved[1]);
	}
	else if (solved[0] == 1) {
		printf("Unsolvable.\n");
	}
	else {
		printf("Elusive.\n");
	}
	return 0;
}