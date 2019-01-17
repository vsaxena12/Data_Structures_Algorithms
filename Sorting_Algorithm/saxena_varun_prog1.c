#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mergeSort.h"
#include "randomizedQuickSort.h"
#include "exchangeSort.h"
#include "insertionSort.h"

/**
*Count of total numbers
*/
int n;  

int main()
{
/**
*Size of an array
*/
	unsigned int arr[1000]; 
	unsigned int i; 
	printf("Enter the Numbers count\n");
	scanf("%d",&n);
    int low=1,high=n;
    int start=1,end=n;

/**
*0<n<=1000
*/
	if(n<=0)
	{
		printf("Invalid Input\nNumber should be greater than 0\n");
	}
	else if(n>1000)
	{
		printf("Invalid Input\nNumber should not be greater than 1000\n");
	}

	else{
	srand(time(NULL));   //Random function
	
		for(i=1;i<=n;i++)
		{
			if(n<=20)
			{
				arr[i]=rand()%((15 + 1 - 0) + 0); //when n<=20
				if(arr[i]==0)
				{
					arr[i]=arr[i]+rand()%((15 + 1 - 0) + 0);  
				}

			}
			else if (n>20)
			{
				arr[i]=rand()%1000;   //when n>20
				if(arr[i]==0)
				{
					arr[i]=arr[i]+rand()%1000;  
				}
				//printf("%d \n",arr[n]);
			}
			printf("arr[%d] = %d \n",i,arr[i]);
					
		}
	printf("\n");

	if(n<=20)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<arr[i];j++)
			{
				printf("*");
			}
			printf("\n");
		}
		
	}

	int choice;
	printf("1. Merge Sort\n2. Exchange Sort\n3. Insertion Sort\n4. Randomized Quick Sort\nSelect the Sorting Algorithm: ");
	scanf("%d", &choice);
	printf("\n");
		switch(choice)
		{
			int i;
			case 1:
			
			merge_sort(arr,low,high);  //Calling the function merge_sort
			
			if(n<=20)
        	{
            //iterations print * if n<=20
            for(int a=0;a<=n;a++)
            {
                for(int b=0;b<arr[a];b++)
                {
                    printf("*");
                }
                printf("\n");
            }
            printf("\n");
        	}	
			printf("Sorted values are: \n");
			for(i=1;i<=n;i++)
			{
				printf("arr[%d] = %d \n",i,arr[i]);
			}
			break;

			case 2:
			exchangeSort(arr,n);      //Calling the function in exchange sort
			if(n<=20)
			{
				printf("Sorted Pattern Is");
			}
			printf("Sorted values are: \n");
			for(i=1;i<=n;i++)
			{
				printf("arr[%d] = %d \n",i,arr[i]);
			}
			break;

			case 3:
			insertionSort(arr,n);	//Calling the function Insertion sort
			if(n<=20)
			{
				printf("Sorted Pattern Is\n");
			}
			printf("Sorted values are: \n");
			for(i=1;i<=n;i++)
			{
				printf("arr[%d] = %d \n",i,arr[i]);
			}
			break;

			case 4:
			
			randomizedQuickSort(arr, start, end);	  //Calling the function randomized quick sort
			printf("Sorted values are: \n");
			for(i=1;i<=n;i++)
			{
				printf("arr[%d] = %d \n",i,arr[i]);
			}
			break;

			default:
			printf("Invalid\n");
			
			break;
		}
	}
		return 0;
}
