#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;

	scanf("%d",&t);

	unsigned long long int n;

	unsigned long long int a;

	unsigned long long int res;

	while(t--)
	{
		res = 1;

		scanf("%llu",&n);
	
		for(int i = 0; i < n; i++)
		{
			scanf("%llu",&a);
			
			res += (a - 1);
		}

		printf("%llu\n",res);

	}

	return 0;
}
