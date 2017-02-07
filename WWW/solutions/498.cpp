// SumaDzielnikowE.cpp : Defines the entry point for the console application.
//

#include <cstdio>

using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
//		printf("moje a to %d\n", a);
		int wyn = 0;
		for(int j=1; j*j <= a; j++)
		{
//			printf("teraz j to %d\n", j);
			if(a%j==0) 
			{
				wyn+=j; 
				if(a/j != j) 
					wyn+=a/j;
			}
		}
		wyn%=m;
		printf("%d\n", wyn);
	}
	return 0;
}