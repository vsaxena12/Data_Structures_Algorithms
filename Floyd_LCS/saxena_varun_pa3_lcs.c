#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include "LCS.h"


int main(int argc, char * argv[])
{
	int i;
	if((strlen(argv[1]) > 100 || strlen(argv[2]) > 100) || (argc != 3)) 
	{
		
		
			printf("Error: Enter the String 1 and String 2\n");
			return 1;	
	}
	else 
		{
			printf("String 1: %s\n", argv[1]);
			printf("String 2: %s\n", argv[2]);
			LCS(argv[1], argv[2]);
			return 0;
		}
		    
    
}