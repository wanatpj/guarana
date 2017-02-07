#include <cstdio>
using namespace std;

int main()
{
	int D,N,stan,temp,C;
	scanf ("%d",&D);
	for (int y=1;y<=D;y++)
	{
		stan=0;
		scanf ("%d",&N);
		for (int i=1;i<=N;i++)
		{
			scanf ("%d",&temp);
			stan+=temp;
		}
		scanf ("%d",&C);
		if (stan==0)
			printf ("%d\n",C);
		else
			printf ("%d\n",C%stan);
	}
	return 0;
}
