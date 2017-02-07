#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define PB push_back

int n, m, il;
char str[2];
int k[10000], p[10000];
int o[10000];
int s[10000], t[10000], b[10000];
void f(int i, int u, char c, int v)
{
	s[i]=u;
	if(c=='W')
	{
		t[i]=v;
		b[i]=1;
		if(o[u]!=-1 && o[u]!=v)
			k[o[u]]--;
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
			p[t[i]]++;
			t[i]=t[v];
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
			p[t[i]]++;
			t[i]=t[v];
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
			//cout << k[i] << " " << p[i] << endl;
		}
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
