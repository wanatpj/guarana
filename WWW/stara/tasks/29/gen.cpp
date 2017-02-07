#include <iostream>

int n;

main()
{
	printf("5\n");
	scanf("%d",&n);
	if(n%2==1) printf("TYLKO N PARZYSTE!\n");
	for(int z=0;z<5;z++)
	{
	printf("%d\n",n);
	for(int i=0;i<n;i++)
	{	
		if(i==0)
		{
			for(int j=0;j<n;j++)
			{
					if(j%2==0) printf("p");
					else printf("d");
			}
		}
		else if(i==n-1)
		{
			for(int j=0;j<n-1;j++)
			{
				if(j%2==0) printf("g");
				else printf("p");
			}
			printf("k");
		}
		else
		{
			for(int j=0;j<n;j++)
			{
				if(j%2==0) printf("g");
				else printf("d");
			}
		}
		printf("\n");
	}
	}
	return 0;
}

