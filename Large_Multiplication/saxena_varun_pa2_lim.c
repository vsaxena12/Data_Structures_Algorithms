#include <stdio.h>
#include <math.h>
#include <time.h>
#include <limits.h>
//#include "lim_product.h"

/*
*Declaring Global variables
*/

//int count;

long long w,x,y,z;
long long maximum_Number_Digits(long number1, long number2)
{
    int count = 0;
    long long maximum;
    

    if(number1>=number2)
    {
    	maximum=number1;
    }
    else
    {
    	maximum=number2;
    }
    while(maximum != 0)
    {   
        maximum = maximum/10;
        ++count;
    }
    return count;
}

long long large_Integer_Multiplication(long long u, long long v)
{
	
	long long count = maximum_Number_Digits(u,v);
	printf("Number of digits: %lld\n", count);
	printf("COUNT: %lld\n", count);

    //long n = count;
    
    //printf("Value of n: %ld\n",n);

    if(u == 0 || v == 0)
    {
    	printf("Multiplication of u x v is Zero\n");
    	return (long)0;
    }

    else if(count <= 4)
    {	//printf("Multiplication is:%ld\n", (long)u*v);
    	return (long)(u*v);	
    }
    
    else
    {
    	long long m =floor(count/2);
	    //printf("Value of m: %ld\n",m);
    	
    	long long power = pow(10,m);
    	//printf("The Power of 10^m is: %ld\n", power);
	    
	    //printf("Number 1: %ld\n",u);

	    
	    x=(u/power);
	    //printf("X is: %ld\n", x);
	    y=u%power;
	    //printf("Y is: %ld\n", y);
	    w=v/power;
	    //printf("W is: %ld\n", w);
	    z=v%power;
	    //sprintf("z is: %ld\n", z);
	    long long m2 = 2*m;
	    
	    return ((large_Integer_Multiplication(x,w) * pow(10,m2)) + ((large_Integer_Multiplication(x,z) + large_Integer_Multiplication(w,y)) * pow(10,m)) + (large_Integer_Multiplication(y,z)));
	    //long ans = large_Integer_Multiplication(x,w);
	    //printf("ANS: %ld\n", ans);
	}
}


void main()
{
	//long number_1,number_2;
    int n,k;
    printf("Enter the value of k\n");
    scanf("%d",&k);
    n=6*k;

	long long u,v;
    srand(time(NULL));
    u=rand()%n;
    v=rand()%n;
	printf("Enter  Random number1: %lld\n",u);
    printf("Enter  Random number2: %lld\n",v);
    //scanf("%ld %ld", &u, &v);
	long long ans1 = large_Integer_Multiplication(u, v);
	printf("\n");
    printf("Final Answer: %lld\n", ans1);
    
}