#include <cstdio>
#include <algorithm>
#define MN 1000
#define Mod0(P) make_pair( P.first, P.second+1 )
#define Mod1(P) make_pair( P.first, P.second-1 )
#define Mod2(P) make_pair( P.first-1, P.second )
#define Mod3(P) make_pair( P.first+1, P.second )

using namespace std;

int n;
char G[MN][MN];
pair<int,int> Route[MN*MN+1];
int RL;

bool DFS( pair<int,int> P )
{
	if ( P.first < 0 || P.first >= n || P.second < 0 || P.second >= n )
	{
		--RL;
		return false;
	}
	switch (G[P.first][P.second])
	{
		case 'k':
			return true;
		case 'p':
			Route[++RL] = Mod0(P);
			break;
		case 'l':
			Route[++RL] = Mod1(P);
			break;
		case 'g':
			Route[++RL] = Mod2(P);
			break;
		case 'd':
			Route[++RL] = Mod3(P);
			break;
		case 'z':
			--RL;
			return false;
	}
	
	if (G[P.first][P.second] == '.')
	{
		G[P.first][P.second] = 'z';
		Route[++RL] = Mod0(P);
		if (DFS(Route[RL]))
			return true;
		Route[++RL] = Mod1(P);
		if (DFS(Route[RL]))
			return true;
		Route[++RL] = Mod2(P);
		if (DFS(Route[RL]))
			return true;
		Route[++RL] = Mod3(P);
		if (DFS(Route[RL]))
			return true;
		--RL;
		return false;
	}
	else
	{
		G[P.first][P.second] = 'z';
		if (DFS(Route[RL]))
			return true;
		--RL;
		return false;
	}
}

int main()
{
	int lw;
	scanf("%d",&lw);

	while (lw--)
	{
		scanf("%d\n",&n);
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				G[i][j] = getchar();
			getchar();
		}
		RL = 0;
		Route[ RL ] = make_pair( n-1, 0 );
		DFS( Route[RL] );

		printf("%d\n",RL+1);
		for (int i=0;i<=RL;i++)
			printf("%d %d\n",Route[i].second+1,n-Route[i].first);
	}

	return 0;
}

