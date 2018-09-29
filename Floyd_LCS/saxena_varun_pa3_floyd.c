#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "Floyd.h"

int main()
{
	srand(time(0));
	int n=5+rand()%6;
	//int n=4;
	printf("Value of n is: %d\n",n );
	int A[n][n],dist[n][n],P[n][n];
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
			{
				A[i][j]=0;
			}
			else
			{
				int random_weight=rand()%10+1;
				A[i][j]=random_weight;
				A[j][i]=random_weight;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dist[i][j]=A[i][j];
			P[i][j]=0;
		}
	}

	printf("Matrix generated:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",A[i][j]);
		}
		printf("\n");
	}

	floyd(n,dist,P);

	printf("\nPrinting shortest paths:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",dist[i][j]);
		}
		printf("\n\n");
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			if((i!=j) && (i>j)){
				printf("Shortest Path between vertex V%d and V%d: ",i+1,j+1 );
				printf("%d\t\t -> ",i+1 );
				printPath(n,P,i,j);
				printf(" -> %d\t\t",j+1 );
				printf("Distance is :%d\t\n",dist[i][j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}