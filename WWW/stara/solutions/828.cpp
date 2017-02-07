#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define FOR(i,p,k) for(int (i) = (p);(i) <= (k);(i)++)
#define VAR(i,u) __typeof((u)) (i) = (u)
#define FOREACH(i,u) for(VAR((i),(u).begin());(i)!=(u).end();(i)++)

#define INF 1000000000

bool G[500][500];
int n;
bool s[1000];
queue <int> Q;

void bfs(int * d, int u, bool opt)
{
	Q.push(u);
	s[u]=0;
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		d[u]=1;
		for(int i = 0;i<n;i++)
		{
			if(s[i]==1 && (G[u][i]^opt)==1)
			{
				s[i]=0;
				Q.push(i);
			}
		}
	}
}
int h=0;
vector <int> f(int *t)
{
	/*
	cout << "wywolanie: ";
	for(int i = 0;i<n;i++)
		cout << t[i] << " ";
	cout << endl;*/
	int size=0;
	vector <int> r;
	for(int i = 0;i<n;i++)
	{
		s[i]=t[i];
		if(s[i]==1)
		{
			size++;
			r.PB(i);
		}
	}
	int il=0;
	int d[n][n];
	for(int i = 0;i<n;i++)
		if(s[i]==1)
		{
			REP(j,n)
				d[il][j]=0;
			bfs(d[il],i,0);
			il++;
		}
	//cout << il << endl;
	if(size==1)
	{
		/*
		cout << "zwraca: ";
		for(vector <int>::iterator it=r.begin();it!=r.end();it++)
			cout << *it << " ";
		cout << endl;*/
		return r;
	}
	vector <int> V, best;
	int res=0;
	if(il>1)
	{
		//cout << "faza\n";
		REP(i,il)
		{
			V=f(d[i]);
			if(res<V.size())
			{
				best=V;
				res=V.size();
			}
			else if(res==V.size())
				REP(j,res)
				{
					if(V[j]!=best[j])
					{
						if(V[j]<best[j])
							REP(k,res)
								best[k]=V[k];
						break;
					}
				}
		}
	}
	else
	{
		//cout << "tu\n";
		il=0;
		for(int i = 0;i<n;i++)
			s[i]=t[i];
		for(int i = 0;i<n;i++)
			if(s[i]==1)
			{
				REP(j,n)
					d[il][j]=0;
				bfs(d[il],i,1);
				il++;
			}
		REP(i,il)
		{
			V=f(d[i]);
			for(vector <int>::iterator it=V.begin();it!=V.end();it++)
			{
				//cout << *it << " ";
				best.PB(*it);
			}
			//cout << endl;
		}
	}
	/*
	cout << "zwraca: ";
	for(vector <int>::iterator it=best.begin();it!=best.end();it++)
		cout << *it << " ";
	cout << endl;*/
	return best;
}

int p[1000];

int main()
{
	int T, m, u;
	scanf("%d", &T);
	for(int i = 0;i<1000;i++)
		p[i]=1;
	while(T>0)
	{
		T--;
		scanf("%d", &n);
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++)
				G[i][j]=0;
		for(int i = 1;i<n;i++)
		{
			scanf("%d", &m);
			for(int j = 0;j<m;j++)
			{
				scanf("%d", &u);
				u--;
				G[i][u]=1;
				G[u][i]=1;
			}
		}
		if(n>200)
		{
			printf("1\n%d\n", n);
			continue;
		}
		vector <int> w = f(p);
		printf("%d\n", w.size());
		for(vector <int>::iterator it=w.begin();it!=w.end();it++)
			printf("%d ", *it+1);
		printf("\n");
	}
	return 0;
}
