#define INSERTIONSORT_H

void insertionSort(unsigned int arr[], int n)
{
	printf("Using Insertion Sort\n");
	int i,j,temp;
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>=1;j--)
		{
			if(arr[j+1]<arr[j])
			{
				//Perform sorting
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
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
