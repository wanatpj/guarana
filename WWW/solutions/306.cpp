#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define PB push_back

int n;
char t[1000][1000];
int dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
char s[5]="dlgp";
vector <int> X, Y;
bool dfs(int x, int y)
{
	char c;
	if(t[x][y]=='k')
	{
		t[x][y]=0;
		X.PB(x);
		Y.PB(y);
		return true;
	}
	if(t[x][y]=='.')
	{
		t[x][y]=0;
		for(int i = 0;i<4;i++)
		{
			if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n)
			{
				if(t[x+dx[i]][y+dy[i]]!=0)
				{
					if(dfs(x+dx[i],y+dy[i]))
					{
						X.PB(x);
						Y.PB(y);
						return true;
					}
				}
			}
		}
	}
	else
	{
		c=t[x][y];
		t[x][y]=0;
		for(int i = 0;i<4;i++)
		{
			if(c==s[i])
			{
				if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n)
				{
					if(dfs(x+dx[i],y+dy[i]))
					{
						X.PB(x);
						Y.PB(y);
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T>0)
	{
		T--;
		X.clear();
		Y.clear();
		scanf("%d", &n);
		for(int i = n-1;i>=0;i--)
			scanf("%s", t[i]);
		dfs(0,0);
		printf("%d\n", X.size());
		for(int i = X.size()-1;i>=0;i--)
			printf("%d %d\n", Y[i]+1, X[i]+1);
	}
	return 0;
}
