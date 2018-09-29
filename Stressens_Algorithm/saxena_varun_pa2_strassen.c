#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "STRASSEN.h"

int n;
int main() 
{ 
    int i, j, m, temp, sum=0;
    unsigned int k;
 
    printf("Enter the value of k to find the size of the matrix nxn:\n");
    printf("Note: n=2^k:\n");
    scanf("%d",&k); //n=2^k-> k decides the size of the matrix
    n=pow(2,k);
    temp = n;
    //printf("\n %d%d %d \n", k,n,temp);

    int max = floor(sqrt(INT_MAX/n));
    int min_limit = 0;
    
    if(n < 0 && n > 1024)
    {
        printf("\"n\" should be greater than 0 and less than or equal to 1024\n");
    }
    
    else
    {
        int A[n][n], B[n][n], C[n][n], D[n][n];

        for(int i = 0; i < n; i++) 
        {
           for(int j = 0; j < n; j++) 
            {
             A[i][j]=0;
             B[i][j]=0;
             C[i][j]=0;
            }
        }/*      int **A=(int **)malloc(sizeof(int *)*n);
        int **B=(int **)malloc(sizeof(int *)*n);
        int **C=(int **)malloc(sizeof(int *)*n);
        for(i=0;i<n;i++)
        {
            A[i]=(int *)malloc(sizeof(int)*(n));
            B[i]=(int *)malloc(sizeof(int)*(n));
            C[i]=(int *)malloc(sizeof(int)*(n));
        }
*/
        srand(time(NULL));
        printf("Printing Matrix A:\n");  
        for(int i = 0; i < n; i++) 
        {
           for(int j = 0; j < n; j++) 
            {
             A[i][j]=((rand()%10));
             printf("%d\t", A[i][j]);
            }
            printf("\n");
        }
        printf("\nPrinting Matrix B:\n");
        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < n; j++) 
                {
                B[i][j]=((rand()%10));
                printf("%d\t ", B[i][j]);
                }
         printf("\n");
        }


        //Printing Original Matrix
        printf("\n");
        printf("Printing Original Matrix C\n");
        for (int i = 0; i < n; i++) 
        {
          for (int j = 0; j < n; j++) 
          {
            D[i][j] = 0;
            for (int m = 0; m < n; m++) 
            {
              D[i][j] += A[i][m]*B[m][j];
            }
          }
        }

        //printf("\nMatrix C is:\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                {
                    printf("%d\t", D[i][j]);
                }
            printf("\n");
        }



        printf("\n");
        printf("Printing Matrix C Using Strassen's Algorithm\n");
        strassen(n,A, B, C);  //function call strassen's algo
     
        //printf("\nMatrix C is:\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                {
                    printf("%d\t", C[i][j]);
                }
            printf("\n");
        }

        printf("\n");
        //compare arrays

        for(int i=0; i< n; i++)
        {
            for(int j=0; j< n; j++)
            {
               if(C[i][j] == D[i][j])
                {
                    printf("The Two Matrix are equal\n");
                }

                else
                {
                    printf("The two Matrix are not equal\n");
                }        
            }
        }
        
       
    }

    return 0;
}
