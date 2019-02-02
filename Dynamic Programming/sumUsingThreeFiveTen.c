#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int arr[16];

    int nums[3] = {3,5,10};

    memset(arr,0,16*sizeof(int));

    arr[0] = 1;

    for(int i = 0, j = nums[2]; j < 16; i++,j++)
        arr[j] = arr[i] + arr[j];

    for(int i = 0, j = nums[1]; j < 16; i++,j++)
        arr[j] = arr[i] + arr[j];

    for(int i = 0, j = nums[0]; j < 16; i++,j++)
        arr[j] = arr[i] + arr[j];


    printf("%d\n",arr[15]);

    return 0;
}