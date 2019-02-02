#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	char data[] = {'a','b','c'};
	
	int set_size = 3;

	unsigned int size = pow(2,set_size);

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < set_size; j++)
		{
			if(i & (1<<j))
				printf("%c",data[j]);
		}

		printf("\n");
	}

	return 0;
}
