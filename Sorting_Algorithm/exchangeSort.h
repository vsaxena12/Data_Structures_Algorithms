#define EXCHANGESORT_H

void exchangeSort(unsigned int arr[], int n)
{
	printf("Using Exchange Sort\n");
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		for(j=(i+1);j<=n;j++)
		{
			//arr[i] compares with arr[j]
			//for non-decending order arr[i]<arr[j]
			if(arr[i]>arr[j])
			{
				//Exchange Sort 
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}

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
	}
	return;
}
