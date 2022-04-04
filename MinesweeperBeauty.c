#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//definitions for colour coding the results later when the program is ran
#define white "\x1b[97m" //this results in the next texts being printed in BRIGHT WHITE until colour is reset
#define green "\x1b[92m" //this results in the next texts being printed in GREEN until colour is reset
#define yellow "\x1b[93m" //this results in the next texts being printed in YELLOW until colour is reset
#define red "\x1b[91m" //this results in the next texts being printed in RED until colour is reset
#define C_Reset "\x1b[0m" //this resets the colour to default

char **Dimiourgia_Pediou(int *,int *,int *);
void Gemisma(char **,int *,int *,int *);
void Isagogi_Se_Arxio(char **,int *,int *);
void Emfanisi(char **,int *,int *);
void Free_Pinakes(char **,int *);

int main(int argc,char *argv[])
{
	char **Pedio_Narkon; //the minefield array
	int K; //bombs
	int M; //rows
	int N; //columns
	
	Pedio_Narkon=Dimiourgia_Pediou(&K,&M,&N);	
	Gemisma(Pedio_Narkon,&K,&M,&N);	
	Isagogi_Se_Arxio(Pedio_Narkon,&M,&N);
	system("cls"); //for some added beauty and also without this the colours don't work [system("clear"); for linux]
	Emfanisi(Pedio_Narkon,&M,&N);
	Free_Pinakes(Pedio_Narkon,&M);

	return 0;
} 

char **Dimiourgia_Pediou(int *K,int *M,int *N)
{
	int i;
	int j;
	char **Pedio_Narkon;
	
	do
	{
		printf("Dose K ( plithos bombon ), M ( grammes ), N ( stiles ): \n");
		scanf("%d %d %d",K,M,N);
		fflush(stdin);
		printf("\n");
	}while((*K)<1||(*M)<1||(*N)<1||(*K)>((*M)*(*N))); //gives number of bombs,rows and columns
	Pedio_Narkon=(char **)malloc((*M)*sizeof(char *));
	if (Pedio_Narkon==NULL)
	{
		printf("error1"); 
		exit (1);
	}
	for (i=0;i<(*M);i++)
	{
		Pedio_Narkon[i]=(char *)malloc((*N)*sizeof(char));
		if (Pedio_Narkon[i]==NULL)
		{
			printf("error2"); 
			exit (2);
		}	
	}
	for(i=0;i<(*M);i++)
		for(j=0;j<(*N);j++)
			Pedio_Narkon[i][j]='0'; //Every character of the array(s) is set to 0
			
	return Pedio_Narkon;
}

void Gemisma(char **Pedio_Narkon,int *K,int *M,int *N)
{
	int randomi;
	int randomj;
	int i;
	int j;
	
	srand(time(NULL)); //pseudorandom seed for rand
	do
    {
		randomi=rand()%(*M); //gets random row position coordinate (the coordinate number doesn't exceed the number of rows)
		randomj=rand()%(*N); //gets random column position coordinate (the coordinate number doesn't exceed the number of columns)
		if(Pedio_Narkon[randomi][randomj]!='#')
		{
			Pedio_Narkon[randomi][randomj]='#';
			(*K)--;
			for(i=(-1);i<2;i++)
			    for(j=(-1);j<2;j++)
				    if(randomi+i>=0&&randomj+j>=0&&randomi+i<(*M)&&randomj+j<(*N)) //this if statements makes sure we don't go out of bounds
				    	if(Pedio_Narkon[randomi+i][randomj+j]!='#') 
				    		Pedio_Narkon[randomi+i][randomj+j]++; //if not out of bounds and not a bomb, add 1 to the value of the ascii character in this feild (from 48 (0) to 49 (1) for example)
		}
	}while((*K)>0); //do this until we run out of bombs to place
}

void Isagogi_Se_Arxio(char **Pedio_Narkon,int *M,int *N)
{
	int i;
	int j;
	FILE *arxnark;
	
	/*
	notepad .txt files don't recognize ascii characters
	for some reason so i replaced the beautiful
	table lines with dashes,lines,crosses and middle dots
	*/
	
	arxnark=fopen("askisi3.txt","w");
	if(arxnark==NULL)
	{
		printf("Den anixtike arxio."); 
		return;
	}
	//first line of board being printed
	fprintf(arxnark,"·");
	for (i=0;i<(*N);++i)
		if(i==(*N)-1)
			fprintf(arxnark,"---");
		else
			fprintf(arxnark,"----");
	fprintf(arxnark,"·");
	fprintf(arxnark,"\n");
	for(i=0;i<(*M);i++) //main minefield "board" being printed
	{
        fprintf(arxnark,"|");
		for(j=0;j<(*N);j++)
			fprintf(arxnark," %c |",Pedio_Narkon[i][j]);
		fprintf(arxnark,"\n");
		if(i!=(*M)-1) //prints lines that are inbetween the lines of bombs+numbers except the last one
		{
			fprintf(arxnark,"|");
			for (j=0;j<(*N);++j)
				if(j==(*N)-1)
					fprintf(arxnark,"---");
				else
					fprintf(arxnark,"---+");
			fprintf(arxnark,"|");
			fprintf(arxnark,"\n");
		}
	}
	//last line of board being printed
	fprintf(arxnark,"·");
	for (i=0;i<(*N);++i)
		if(i==(*N)-1)
			fprintf(arxnark,"---");
		else
			fprintf(arxnark,"----");
	fprintf(arxnark,"·");
	fclose(arxnark);
}

void Emfanisi(char **Pedio_Narkon,int *M,int *N)
{
	int i;
	int j;
	
	/*
	All ascii table lines are printed in Bright White, bombs 
	in Red, Zeros (no bombs around this square) in green and
	numbers other than 0 are printed in yellow
	*/
	
	//first line of board being printed
	printf(white); //prints in bright white
	printf("%c",218);
	for (i=0;i<(*N);++i)
		if(i==(*N)-1)
			printf("%c%c%c",196,196,196);
		else
			printf("%c%c%c%c",196,196,196,194);
	printf("%c",191);
	printf("\n");
	printf(C_Reset); //stops printing in bright white
	for(i=0;i<(*M);i++) //main minefield "board" being printed
	{
        printf(white"%c"C_Reset,179); //line printed in bright white, start of each line being printed
		for(j=0;j<(*N);j++)
			if(Pedio_Narkon[i][j]=='#')
				printf(red" %c "C_Reset white"%c"C_Reset,Pedio_Narkon[i][j],179); //if its a bomb print in RED, prints bomb and delimiter(special ascii table character)
			else
				if(Pedio_Narkon[i][j]=='0')
					printf(green" %c "C_Reset white"%c"C_Reset,Pedio_Narkon[i][j],179); //if it's a 0 print in GREEN, prints 0 and delimiter(special ascii table character)
				else
					printf(yellow" %c "C_Reset white"%c"C_Reset,Pedio_Narkon[i][j],179); //if it's another number print in YELLOW, prints number and delimiter(special ascii table character)
		printf("\n");
		printf(white); //starts printing in bright white
		if(i!=(*M)-1) //prints lines that are inbetween the lines of bombs+numbers except the last one
		{
			printf("%c",195);
			for (j=0;j<(*N);++j)
				if(j==(*N)-1)
					printf("%c%c%c",196,196,196);
				else
					printf("%c%c%c%c",196,196,196,197);
			printf("%c",180);
			printf("\n");
		}
	}
	//last line of board being printed
	printf("%c",192);
	for (i=0;i<(*N);++i)
		if(i==(*N)-1)
			printf("%c%c%c",196,196,196);
		else
			printf("%c%c%c%c",196,196,196,193);
	printf("%c",217);
	printf(C_Reset); //stops printing in bright white
}

void Free_Pinakes(char **Pedio_Narkon,int *M)
{
	int i;
	
	for(i=0;i<(*M);i++)
		free(Pedio_Narkon[i]); //frees the individual tables that the pointers from the doublepointer table were pointing at
	free(Pedio_Narkon); //frees the double pointer table
}
