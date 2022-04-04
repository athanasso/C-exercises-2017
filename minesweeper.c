#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **getinput(int *,int *,int *);
void fill(char **,int *,int *,int *);
void Printmap(char **,int *,int *);
void Filemap(char **,int *,int *);
void free_array(char **,int *);

int main(int argc,char **argv)
{
	system ("chcp 1253");
	char **map;
	int K,M,N;
	map=getinput(&K,&M,&N);	
	fill(map,&K,&M,&N);
	Printmap(map,&M,&N);
	free_array(map,&M);
	return 0;
} 

char **getinput(int *K,int *M,int *N)
{
	int i,j;
	char **a;
	printf("Δώσε μου τα K (αριθμός βομβών), M (αριθμός γραμμών), N (αριθμός στηλών): \n");
	scanf("%d %d %d",K,M,N);
	fflush(stdin);
	printf("\n");
	while((*K)<1||(*M)<1||(*N)<1||(*K)>((*M)*(*N)))
	{
		printf("Δώσε μου σωστά τα K, M, N: \n");
		scanf("%d %d %d",K,M,N);
		fflush(stdin);
		printf("\n");
	}
	a=(char **)malloc((*M)*sizeof(char *));
	for (i=0;i<(*M);i++)
		a[i]=(char *)malloc((*N)*sizeof(char));
	for(i=0;i<(*M);i++)
		for(j=0;j<(*N);j++)
			a[i][j]='0';
	return a;
}

void fill(char **a,int *K,int *M,int *N)
{
	int randi,randj,i,j;
	srand(time(NULL));
	while((*K)>0)
    {
		randi=rand()%((*M));
		randj=rand()%((*N));
		if(a[randi][randj]!='*')
		{
			a[randi][randj]='*';
			(*K)--;
			for(i=-1;i<2;i++)
			    for(j=-1;j<2;j++)
				    if((randi+i>=0&&randj+j>=0&&randi+i<(*M)&&randj+j<(*N))&&a[randi+i][randj+j]!='*')
				    	a[randi+i][randj+j]++;
		}	
	}
}

void Printmap(char **a,int *M,int *N)
{
	int i,j;
	for(i=0;i<(*M);i++)
	{
		for(j=0;j<(*N);j++)
		{    
			printf("%c ",a[i][j]);
		}
		printf("\n");
	}
}

void Filemap(char **a,int *M,int *N)
{
	int i,j;
	FILE *fp;
	fp=fopen("minesweeper.txt","w");
	for(i=0;i<(*M);i++)
	{
		for(j=0;j<(*N);j++)
		{    
			fprintf(fp,"%c ",a[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

void free_array(char **a,int *M)
{
	int i;
	for(i=0;i<(*M);i++)
		free(a[i]);
	free(a);
}
