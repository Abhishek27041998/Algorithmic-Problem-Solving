#include<stdio.h>
#include<stdlib.h>

int main()
{
	int t;

	scanf("%d",&t);

	int n;

	int a[100];
	int d[100];

	while(t--)
	{
		scanf("%d",&n);

		for(int i = 0; i < n; i++)
			scanf("%d",&a[i]);
	
		int maxDef = -1;

		for(int i = 0; i < n; i++)
		{
			scanf("%d",&d[i]);

			if(i >= 2)
			{
				if((a[i-2] >= d[i-1]) || (a[i] >= d[i-1]) || (a[i-2] + a[i] >= d[i-1]))
					continue;
				else
				{
					if(maxDef < d[i-1])
						maxDef = d[i-1];
				}
			}
		}

		if((a[n-1] >= d[0]) || (a[1] >= d[0]) || (a[n-1] + a[1] >= d[0]));
		else
		{
			if(maxDef < d[0])
						maxDef = d[0];	
		}

		
		if((a[n-2] >= d[n-1]) || (a[0] >= d[n-1]) || (a[n-2] + a[0] >= d[n-1]));
		else
		{
			if(maxDef < d[n-1])
						maxDef = d[n-1];	
		}	

		printf("%d\n",maxDef);
		
	}


	
	return 0;
}
