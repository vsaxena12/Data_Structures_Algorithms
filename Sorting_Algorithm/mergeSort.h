#define MERGESORT_H
int n;
void merge(unsigned int arr[],int l,int m,int h)
{
    //Merge two sub arrays
    //Sub-array 1 and sub-array 2
    unsigned int arr_left[1000],arr_right[1000];
    int n1,n2,i,j,k;
    n1=m-l+1;
    n2=h-m;
    for(i=0; i<n1; i++)
    {
        arr_left[i]=arr[l+i];
        
    }
    for(j=0; j < n2; j++)
    {
        arr_right[j]=arr[m+j+1];
    }
    arr_left[i]=1000;
    arr_right[j]=1000;
    i=0;
    j=0;
    k=l;
    while(k<=h)
    {
        if(arr_left[i]<=arr_right[j])
        {
            arr[k]=arr_left[i++];
        }
        else
        {
            arr[k]=arr_right[j++];
        }
        k++;   
    }  
}

void merge_sort(unsigned int arr[],int low,int high)
    {
        //Sort first and second half
        int mid;
        if(low < high)
        {
            mid=(low+high)/2;
            merge_sort(arr,low,mid);
            merge_sort(arr,mid+1,high);

            //Merge 
            merge(arr,low,mid,high);
        }
    }



