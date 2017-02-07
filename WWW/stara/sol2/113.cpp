#include <iostream>
#include <stack>
#define MAX 1010
using namespace std;

struct przedzial { int from,to; } a,tmp;
stack <przedzial> S;

int n,m;
int t[MAX];

main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++) scanf("%d",&t[j]);
		a.from=1;
		a.to=n;
		while(!S.empty()) S.pop();
		for(int j=0;j<n;j++)
		{
			if(t[j]>=a.from)
			{
				tmp.from=a.from;
				tmp.to=t[j]-1;
				a.from=t[j]+1;
				if(tmp.to>=tmp.from) S.push(tmp);
			}
			else if(!S.empty())
			{
				tmp=S.top();
				S.pop();
				if(tmp.to==t[j]) tmp.to--;
				else
				{
					printf("NIE\n");
					break;
				}
				if(tmp.to>=tmp.from) S.push(tmp);
			}
			else
			{
				printf("NIE\n");
				break;
			}
			if(j==n-1) printf("TAK\n");
		}
	}
	return 0;
}

