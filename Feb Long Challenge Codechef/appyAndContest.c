#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned long long int t;

	scanf("%llu",&t);

	while(t--)

	{
		unsigned long long int n,a,b,k;

		scanf("%llu %llu %llu %llu",&n,&a,&b,&k);

		unsigned long long int cnt = 0;

		if(a == b)
		{
			cnt = 0;
		}
		else if(a % b == 0)
		{
			cnt = n/b - n/a; 
		}
		else if(b % a == 0)
		{	
			cnt = n/a - n/b;
		}
		else
		{
			cnt = n/a + n/b - n/(a*b);
		}

	
		if(cnt >= k)
			printf("Win\n");
		else
			printf("Lose\n");
	}

	return 0;
}
