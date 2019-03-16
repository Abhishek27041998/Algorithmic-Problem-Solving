#include<stdio.h>
#include<stdlib.h>


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int lc = 2*i + 1;
    int rc = 2*i + 2;

    if(lc < n && arr[lc] > arr[largest])
        largest = lc;
    
    if(rc < n && arr[rc] > arr[largest])
        largest = rc;

    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >=0; i--)
        heapify(arr,n,i);

    for(int i = n - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        heapify(arr,i,0);
    }
}

int main()
{
    int arr[] = {5,3,2,1,4};

    heapSort(arr,5);

    for(int i = 0; i < 5; i++)
        printf("%d ",arr[i]);

    printf("\n");
    

    return 0;
}
