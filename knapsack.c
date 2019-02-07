#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    //Can change the following inputs to read from user
    int weights[4] = {2,1,3,2};
    int value[4] = {12,10,2,15};

    int maxWeight = 5;

    int maxValue;

    int knapsackTab[5][6];

    //initialize the first row with 0;
    memset(knapsackTab,6,sizeof(int));

    //initialize the first column with 0;
    for(int i = 0; i < 5; i++)
        knapsackTab[i][0] = 0;

    for(int i = 1; i < 5; i++)
    {
        for(int j = 1; j < 6; j++)
        {
            if(weights[i-1] <= j) 
                 knapsackTab[i][j] = max(value[i-1] + knapsackTab[i-1][j-weights[i-1]],  knapsackTab[i-1][j]); 
           else
                 knapsackTab[i][j] = knapsackTab[i-1][j];
        }
    }

    maxValue = knapsackTab[4][5];
    printf("Max Value : %d\n",maxValue);

    return 0;
}