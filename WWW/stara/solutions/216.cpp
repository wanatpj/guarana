#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define PI pair<int,int>
#define st first
#define nd second

int n;
vector <int> G[100001];
int a[100001], b[100001], c[100001];
vector <int> C;
int x, y;

int dfs_cykl(int u, int v)
{
	int ret;
	c[u]=v;
	for(vector <int>::iterator it = G[u].begin();it!=G[u].end();it++)
	{
		if(*it!=v && c[*it]==-1)
		{
			ret=dfs_cykl(*it,u);
			if(ret==-2)
				return -2;
			else if(ret!=-1 && ret!=-2)
			{
				C.push_back(u);
				if(ret==u)
					return -2;
				else
					return u;
			}
		}
		else if(*it!=v && c[*it]!=-1 && c[*it]!=u)
		{
			C.push_back(u);
			return *it;
		}
		else if(*it!=v && c[*it]==u)
		{
			C.push_back(u);
			C.push_back(*it);
			return -2;
		}
	}
	return -1;
}

int z1, z2;
void oblicz(int u, int v)
{
	int sum=0;
	int val1=-1000000, val2=-1000000, val3=-1000000;
	for(vector <int>::iterator it = G[u].begin();it!=G[u].end();it++)
	{
		if(*it!=v && ((u!=z1 && u!=z2) || (*it!=z1 && *it!=z2)))
		{
			oblicz(*it, u);
			sum+=c[*it];
			if(a[*it]-c[*it]>val1)
			{
				val2=val1;
				val1=a[*it]-c[*it];
			}
			else if(a[*it]-c[*it]>val2)
				val2=a[*it]-c[*it];
			if(b[*it]-c[*it]>val3)
				val3=b[*it]-c[*it];
		}
	}
	a[u]=sum;
	if(val1==-1000000)
		b[u]=c[u]=sum;
	else if(val2==-1000000)
	{
		c[u]=max(sum,sum+val3);
		b[u]=max(c[u],1+val1+sum);
	}
	else
	{
		c[u]=max(sum,max(1+val1+val2+sum,sum+val3));
		b[u]=max(c[u],1+val1+sum);
	}
	//printf("%d: %d %d %d\n", u, a[u], b[u], c[u]);
}

int main()
{
	int u, v;
	scanf("%d", &n);
	for(int i = 0;i<n;i++)
	{
		c[i+1]=-1;
		scanf("%d %d", &u, &v);
		if(u==v)
			C.push_back(u);
		else
		{
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	if(C.size()==0)
		dfs_cykl(1,0);
	a[0]=0;
	b[0]=2000000;
	c[0]=1000000;
	int il=C.size();
	if(il==1)
	{
		oblicz(1,-1);
		printf("%d\n", c[1]);
	}
	else if(il==2)
	{
		for(vector <int>::iterator it = G[C[0]].begin();it!=G[C[0]].end();it++)
			if(*it==C[1])
			{
				G[C[0]].erase(it);
				break;
			}
		for(vector <int>::iterator it = G[C[1]].begin();it!=G[C[1]].end();it++)
			if(*it==C[0])
			{
				G[C[1]].erase(it);
				break;
			}
		oblicz(1,-1);
		printf("%d\n", c[1]);
	}
	else
	{
		int best=0;
		z1=C[0];z2=C[1];
		oblicz(1,-1);
		best=max(best,c[1]);
		z1=C[1];z2=C[2];
		oblicz(1,-1);
		best=max(best,c[1]);
		if(il==3)
		{
			z1=C[2];z2=C[0];
		}
		else
		{
			z1=C[2];z2=C[3];
		}
		oblicz(1,-1);
		best=max(best,c[1]);
		printf("%d\n", best);
	}
	return 0;
}
