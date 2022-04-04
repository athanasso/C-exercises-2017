#include <stdio.h>
#include <stdlib.h>

double* getAverages(double **grades, int totalStudents, int totalSubjects) {
	double* results = (double*)malloc(totalStudents * sizeof(double));
	int i, j;
	
	for (i=0; i < totalStudents; i++) {
		double mo = 0;
		int passed = 0;
		for (j = 0; j < totalSubjects; j++) {
			if (grades[i][j] > 5) {
				passed++;
				mo += grades[i][j];
			} 
		}
		if (passed != 0) {
			mo /= passed;
		}
		
		results[i] = mo;
	}
	
	return results;
}

int main(int argc, char* argv[]) {
	int M, N;
	int i, j;
	double **grades;
	double* averages;
	printf("Get averages of M students in N subjects.\n");
	printf("M: ");
	scanf("%d", &M);
	printf("N: ");
	scanf("%d", &N);
	
	grades = (double**)malloc(M * sizeof(double*));
	for (i = 0; i < M; i++) {
		grades[i] = (double*)malloc(N * sizeof(double));
	}
	
	for (i = 0; i < M; i++) {
		printf("Student %d:\n\n", i + 1);
		for (j =0; j < N; j++) {
			printf("Grade on subject %d from %d: ", j+1, N);
			scanf("%lf", &grades[i][j]);
		}
	}
	
	averages = getAverages(grades, M, N);
	
	for (i = 0; i < M; i++) {
		printf("Average of student %d: %lf\n", i + 1, averages[i]);
	}
	return 0;
}