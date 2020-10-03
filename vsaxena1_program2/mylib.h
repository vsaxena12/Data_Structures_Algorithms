#include <string.h>
#include <stdio.h>
int myStrStr(char haystack[], char needle[], char buffer[])
{
	int haystack_length=strlen(haystack);
	int needle_length=strlen(needle);
	int i,j;
	for(i=0;i<=haystack_length-needle_length;i++)			
	{
		for(j=i;j<i+needle_length;j++)
		{
			if(haystack[j]!=needle[j-i])
			{
				break;
			}
		}
		if(j==i+needle_length)				
		{
			int k;
			for(k=0;k<needle_length;k++)
			{
				buffer[k]=haystack[i+k];
			}
			buffer[k]='\0';
			return 1;
		}
	}
											
	strcpy(buffer,"");
	return 0;
}

unsigned int countOnes(int num)
{
	unsigned int n=num;
	int no_of_ones=0;
	while(n)
	{
		if(n%2==1)
		{
			no_of_ones++;
		}
		n/=2;
	}
	return no_of_ones;
}

void binaryArray(int n,int array[],int size)
{	
	unsigned int num=n;
	while(num && size>0)
	{
		array[size-1]=num%2;
		num/=2;
		size--;
	}
	while(size>0)
	{
		array[size-1]=0;
		size--;
	}
}
void binaryPrinter(int array[],int size)
{
	int i;
	printf("Binary representation is: ");
	for(i=0;i<size;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}