#include <stdio.h>
#include <stdlib.h>

double* getAverages(double **grades, int totalStudents, int totalSubjects) {
	double* results = (double*)malloc(totalSubjects * sizeof(double));
	int i, j;
	
	for (i=0; i < totalSubjects; i++) {
		results[i] = 0;
	}
	
	for (i=0; i < totalStudents; i++) {
		for (j = 0; j < totalSubjects; j++) {
			results[j] += grades[i][j];	
		}
	}
	
	for (i=0; i < totalSubjects; i++) {
		if (results[i] != 0) {
			results[i] /= totalStudents;
		}
	}
	
	return results;
}

int main(int argc, char* argv[]) {
	int M, N;
	int i, j;
	double **grades;
	double* averages;
	printf("Get averages N subjects from M students.\n");
	printf("Students: ");
	scanf("%d", &M);
	printf("Subjects: ");
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
	
	for (i = 0; i < N; i++) {
		printf("Average of subject %d: %lf\n", i + 1, averages[i]);
	}
	return 0;
}