#include <stdio.h>
#include <stdlib.h>

int readN();
int *readx1x2();
int *ready1y2();
int *readNumbers(int);
int isInArray(int,int*,int);
void BubbleSort(int*,int);
void Frequency(int, int *, int *,int *);
void PrintFrequencies(int *,int,int *);
int *lotto(int,int*,int,int,int,int);
int Sum(int, int, int, int, int, int);
int Evens(int, int, int, int, int, int);
void PrintLotto(int*);

int main()
{
	system ("chcp 1253");
	int N,x1,x2,y1,y2,*x1x2,*y1y2,*aNum,*lresults;
	N=readN();
	aNum=readNumbers(N);
	x1x2=readx1x2();
	y1y2=ready1y2();
	x1=*(x1x2);
	x2=*(x1x2+1);
	y1=*(y1y2);
	y2=*(y1y2+1);
	printf("���������� ------------------------------\n\n");
	lresults=lotto(N,aNum,x1,x2,y1,y2);
	printf("������ ����������: %d\n", *(lresults));
	printf("���������� ��� ������� ��� ������������: %d\n", *(lresults + 1));
	printf("���������� ��� �������� ���� ����� ����������: %d\n", *(lresults + 2));
	printf("���������� ��� �������� ���� ������� ����������: %d\n\n", *(lresults + 3));
	
	free(x1x2);
	free(y1y2);
	free(aNum);
	free(lresults);
	return 0;
}

int *lotto(int N,int *a,int x1,int x2,int y1,int y2)
{
	int i,j,k,l,m,n;
	int *results,evens,sum,*frequencies;
	int totalSum=0,Fail1=0,Fail2=0,successes=0;
	int nI,nJ,nK,nL,nM,nN;
	results=(int*)malloc(5*sizeof(int));
	frequencies=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
		*(frequencies+i)=0;
	int *combination=(int*)malloc(6*sizeof(int));
	for(i=0;i<N-5;i++)
	{
		for(j=i+1;j<N-4;j++)
		{
			for(k=j+1;k<N-3;k++)
			{
				for(l=k+1;l<N-2;l++)
				{
					for(m=l+1;m<N-1;m++)
					{
						for(n=m+1;n<N;n++)
						{
							nI=*(a+i);
							nJ=*(a+j);
							nK=*(a+k);
							nL=*(a+l);
							nM=*(a+m);
							nN=*(a+n);
							evens=Evens(nI,nJ,nK,nL,nM,nN);
							totalSum++;
							if(evens>=x1&&evens<=x2)
							{
								sum=Sum(nI,nJ,nK,nL,nM,nN);
								if(sum>=y1&&sum<=y2)
								{
									*(combination+0)=nI;
									*(combination+1)=nJ;
									*(combination+2)=nK;
									*(combination+3)=nL;
									*(combination+4)=nM;
									*(combination+5)=nN;
									PrintLotto(combination);
									Frequency(N,frequencies,combination,a);
									successes++;
								}
								else
									Fail2++;
							}
							else
								Fail1++;
						}
					}
				}
			}
		}
	}
	free(combination);
	PrintFrequencies(frequencies,N,a);
	*(results)=totalSum;
	*(results+1)=successes;
	*(results+2)=Fail1;
	*(results+3)=Fail2;
	return results;	
}

int Sum(int i,int j,int k,int l,int m,int n)
{
	return i+j+k+l+m+n;
}

int Evens(int i,int j,int k,int l,int m,int n)
{
	int sum=0;
	if(i%2==0) 
		sum++;
	if(j%2==0) 
		sum++;
	if(k%2==0) 
		sum++;
	if(l%2==0) 
		sum++;
	if(m%2==0) 
		sum++;
	if(n%2==0) 
		sum++;
	return sum;
}

void PrintLotto(int *combination)
{
	int i;
	for(i=0;i<6;i++)
	{
		printf("%02d",*(combination+i));
		if (i!=5)
			printf("-");
		else
			printf("\n");
	}
}

void Frequency(int N,int *frequencies,int *combination,int *a)
{
	int i,j;
	for (i=0;i<6;i++)
		for (j=0;j<N;j++)
			if (*(a+j)==*(combination+i))
				(*(frequencies+j))++;
}

void PrintFrequencies(int *frequencies,int N,int *a)
{
	int i=0;
	printf("\n��������� --------------------------------\n");
	while(i<N) 
	{
		printf("������� %02d - ����������� %02d �����.\n",*(a+i),*(frequencies+i));
		i++;
	}
}

int readN()
{
    int N;
    printf("������ �������� ������ �� ���������������;\n");
    printf("������� : ");
    scanf("%d",&N);
    while(N<7||N>49)
    {
        printf("���� ����� ������ ��� �� ������.\n������ �� ����� ������ ��� 7 ��� ��� 49.\n");
        scanf("%d",&N);
    }
    return N;
}

int *readx1x2()
{
	int x1,x2;
	int *x1x2=(int*)malloc(2*sizeof(int));
	printf("���� �� ���� ��� �� ������ ������.\n");
	printf("���� �������� ������ ������.\n");
	scanf("%d",&x1);
	while(x1<0||x1>6)
	{
		printf("� ������� ������ �� ����� ������ ��� 0 ��� ��� 6.\n");
		scanf("%d",&x1);
	}
	printf("���� ������� ������ ������.\n");
	scanf("%d",&x2);
	while(x2<0||x2<x1||x2>6)
	{
		printf("� ������� ������ �� ����� ������ ��� %d ��� ��� 6.\n",x1);
		scanf("%d",&x2);
	}
    *(x1x2)=x1;
    *(x1x2+1)=x2;
	return x1x2;
}

int *ready1y2()
{
	int y1,y2;
	int *y1y2=(int*)malloc(2*sizeof(int));
	printf("���� �� ���� ����������� ��� �������.\n");
	printf("���� �� �������� �������� ��� �������.\n");
	scanf("%d",&y1);
	while(y1<21||y1>279)
	{
		printf("� ������� ������ �� ����� ������ ��� 21 ��� ��� 279.\n");
		scanf("%d",&y1);
	}
	printf("���� ������� �������� ��� �������.\n");
	scanf("%d",&y2);
	while(y2<21||y2<y1||y2>279)
	{
		printf("� ������� ������ �� ����� ������ ��� %d ��� ��� 279.\n",y1);
		scanf("%d",&y2);
	}
	*(y1y2)=y1;
	*(y1y2+1)=y2;
	return y1y2;
}

int *readNumbers(int N)
{
	int i,c;
	int *a;
	a=(int*)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		*(a+i)=0;
	}
	for(i=0;i<N;i++)
	{
		printf("������� %d ��� %d: ",i+1,N);
		scanf("%d",&c);
		while(c<0||c>50)
		{
			printf("���� ����� ��� ������ %d ��� %d: ",i+1,N);
			scanf("%d",&c);
		}	
		if(!isInArray(c,a,N))
			*(a+i)=c;
		else
		{
			printf("� ���� ������� ������ �� ����� ������������.\n");
			i--;
		}
	}
	BubbleSort(a,N);
	return a;
}

int isInArray(int c,int *array,int N)
{
	int i;
	for(i=0;i<N;i++)
	{
		if(*(array+i)==c) return 1;
	}
	return 0;
}

void BubbleSort(int *a,int N)
{
	int i,j,temp;
	for(i=1;i<N;++i)
        for(j=0;j<(N-i);++j)
            if(*(a+j)>*(a+j+1))
            {
                temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
}

