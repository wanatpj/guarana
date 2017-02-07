#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()

int n, m, il;
char str[2];
int k[20000], p[20000];
int o[20000];
int s[20000], t[20000], b[20000];
vector <int> V[20000];

void f(int i, int u, char c, int v)
{
	s[i]=u;
	if(c=='W')
	{
		t[i]=v;
		b[i]=1;
		if(o[u]!=-2 && o[u]!=-1 && o[u]!=v)
		{
			k[o[u]]--;
			o[u]=-2;
		}
		else if(o[u]==-1)
		{
			o[u]=v;
			k[v]++;
			il++;
		}
	}
	else if(c=='F')
	{
		if(b[v]==1)
		{
			b[i]=0;
			t[i]=t[v];
			V[t[i]].PB(u);
		}
		else
			f(i,u,'W',t[v]);
	}
	else
	{
		if(b[v]==1)
			f(i,u,'W',t[v]);
		else
		{
			b[i]=0;
			t[i]=t[v];
			V[t[i]].PB(u);
		}
	}
	//cout << i << " " << u << " " << c << " " << v << " " << s[i] << " " << b[i] << " " << t[i] << endl;
}

int main()
{
	int T, u, v;
	scanf("%d", &T);
	while(T>0)
	{
		T--;
		scanf("%d %d", &n, &m);
		for(int i = 0;i<n;i++)
		{
			V[i].clear();
			k[i]=p[i]=0;
			o[i]=-1;
		}
		il=0;
		for(int i = 0;i<m;i++)
		{
			scanf("%d %s %d", &u, str, &v);
			u--;
			v--;
			f(i,u,str[0],v);
		}
		for(int i = 0;i<n;i++)
		{
			sort(ALL(V[i]));
			V[i].resize(unique(ALL(V[i]))-V[i].begin());
			for(vector <int>::iterator it = V[i].begin();it!=V[i].end();it++)
			{
				if(o[*it]==i)
				{
					o[*it]=-2;
					k[i]--;
				}
			}
		}
		for(int i = 0;i<n;i++)
		{
			for(vector <int>::iterator it = V[i].begin();it!=V[i].end();it++)
			{
				if(o[*it]==-1)
					p[i]++;
			}
		}
		//for(int i = 0;i<n;i++)
		//{
		//	printf("%d %d\n", k[i], p[i]);
		//}
		int res=1000000;
		for(int i = 0;i<n;i++)
			res=min(il-k[i]+p[i],res);
		for(int i = 0;i<n;i++)
			if(il-k[i]+p[i]==res)
				printf("%d ", i+1);
		printf("\n");
	}
	return 0;
}
