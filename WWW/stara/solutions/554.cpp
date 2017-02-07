#include <iostream>
#define MAX 210
#define INF 1000000000

struct ww { int il, w; } F[MAX][MAX];

int t[MAX];
int tmp,z,n,wynik;

void fun(int from, int to)
{
	//printf("from:%d to:%d\n",from,to);
	if(from==to)
	{
		F[from][to].w=t[from];
		F[from][to].il=0;
		return;
	}
	int mini=INF,minil,helpp;
	helpp=0;
	for(int i=from;i<=to;i++) helpp+=t[i];
	for(int i=from;i<to;i++)
	{
		if(F[from][i].w==-1) fun(from,i);
		if(F[i+1][to].w==-1) fun(i+1,to);
		wynik=F[from][i].w+F[i+1][to].w;
		wynik+=helpp;
		if(i==from) wynik-=t[i];
		if(i+1==to) wynik-=t[i+1];
		if(wynik<mini)
		{
			mini=wynik;
			minil=F[from][i].il+F[i+1][to].il;
			if(i+1!=to) minil++;
		}
		if(wynik==mini)
		{
			tmp=F[from][i].il+F[i+1][to].il;
			if(i+1!=to) tmp++;
			if(tmp<minil)
			{
				minil=tmp;
			}
		}
	}
	F[from][to].w=mini;
	F[from][to].il=minil;
}

int main()
{
	scanf("%d",&z);
	while(z--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) F[i][j].w=-1;
		for(int i=0;i<n;i++) scanf("%d",&t[i]);
		fun(0,n-1);
		printf("%d %d\n",F[0][n-1].w,F[0][n-1].il);
	}
	return 0;
}

