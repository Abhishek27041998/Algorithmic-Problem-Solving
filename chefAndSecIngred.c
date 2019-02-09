#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int t;

	scanf("%d",&t);

	int n;

	char string[300];

	while(t--)
	{
		scanf("%d",&n);

		int hashArr[26] = {0};

		for(int i = 0; i < n; i++)
		{
			scanf("%s",string);
			
			for(int j = 0; j < strlen(string); j++)
			{
				if(hashArr[string[j] - 'a'] == i)
				{
					hashArr[string[j] - 'a'] = i + 1;
				}
			}			
		}

		int cnt = 0;
		
		for(int i = 0; i < 26; i++)
		{
			if(hashArr[i] == n)
				cnt++;
		}

		printf("%d\n",cnt);
	}

	return 0;
}
