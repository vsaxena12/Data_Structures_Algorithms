#define RANDOMIZEDQUICKSORT_H
int partition(int arr[], int start, int end, int pivot);
/*arr[]->Array to be sorted,
  low->Starting index,
  high->Ending index
*/ 

void randomizedQuickSort(unsigned int arr[], int start, int end)
{
    int pivot;
    if(start < end) {
            pivot = start;
            pivot = rand() % (end - start) + start ;
            pivot = partition(arr,start,end,pivot);
            // Separately sort elements before partition and after partition
            randomizedQuickSort(arr,start,pivot-1);
            randomizedQuickSort (arr,pivot+1,end);
    }
}
int partition(int arr[], int start, int end, int pivot)
{
    int iteration,temp,first,last;
        temp =arr[pivot];
        arr[pivot]=arr[start]; 
        arr[start]=temp;
        pivot = start;

        for(first = start+1;first<=end;first++)
        {

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

          if(arr[first]<arr[pivot])
            {
              temp = arr[first];
                for(last=first;last!=pivot+1;last--)        
                    arr[last]=arr[last-1];
                    arr[last]=arr[pivot];
                    arr[pivot]=temp;
                    pivot++;
            }    
        }
return pivot;   
}