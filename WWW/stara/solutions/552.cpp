#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int (i) = 0;(i)<(n);(i)++)
#define FOR(i,p,k) for(int (i) = (p);(i) <= (k);(i)++)

#define INF 1000000000

int n, t[200][200], w[200][200];
int s[200];
int v[200];

int main()
{
	int T, u, d, temp;
	scanf("%d", &T);
	while(T>0)
	{
		T--;
		scanf("%d", &n);
		REP(i,n)
			scanf("%d", &v[i]);
		s[0]=v[0];
		FOR(i,1,n-1)
			s[i]=s[i-1]+v[i];
		REP(i,n)
			t[i][i]=w[i][i]=0;
		for(int i = 1;i<n;i++)
		{
			for(int j = 0;j+i<n;j++)
			{
				t[j][j+i]=w[j][j+i]=INF;
				for(int k = j;k<j+i;k++)
				{
					temp=t[j][k]+t[k+1][j+i]+s[j+i]-s[j]+v[j];
					if(t[j][j+i]>temp)
					{
						d=w[j][k]+w[k+1][j+i];
						if(j+i-k-1>0)
							d++;
						t[j][j+i]=temp;
						w[j][j+i]=d;
					}
					else if(t[j][j+i]==temp)
					{
						d=w[j][k]+w[k+1][j+i];
						if(j+i-k-1>0)
							d++;
						if(d<w[j][j+i])
						{
							t[j][j+i]=temp;
							w[j][j+i]=d;
						}
					}
				}
			}
		}
		printf("%d %d\n", t[0][n-1], w[0][n-1]);
	}
	return 0;
}
