#include <iostream>
#include <stack>
#define MAX 1010
using namespace std;

struct point { short int x,y; } tmp;
stack <point> S;
stack <point> Q;

int z,n;
char t[MAX][MAX];
char color[MAX][MAX]; //1 - ok, 0 - not visited, 2 - zlo, 3 - przetwarzany
 
void DFS(short int y, short int x)
{
	color[y][x]=3;
	if(t[y][x]=='.')
	{
		if(x>0)
		{
			if(color[y][x-1]==0)
			{
				DFS(y,x-1);
				if(color[y][x-1]==1) color[y][x]=1;
			}
		}
		if(x<n-1)
		{
			if(color[y][x+1]==0)
			{
				DFS(y,x+1);
				if(color[y][x+1]==1) color[y][x]=1;
			}
		}
		if(y>0)
		{
			if(color[y-1][x]==0)
			{
				DFS(y-1,x);
				if(color[y-1][x]==1) color[y][x]=1;
			}
		}
		if(y<n-1)
		{
			if(color[y+1][x]==0)
			{
				DFS(y+1,x);
				if(color[y+1][x]==1) color[y][x]=1;
			}
		}
	}
	else if(t[y][x]=='g')
	{
		if(y==0)
		{
			color[y][x]=2;
		}
		else
		{
			if(color[y-1][x]==0)
			{
				DFS(y-1,x);
				if(color[y-1][x]==1) color[y][x]=1;
			}
		}
	}
	else if(t[y][x]=='d')
	{
		if(y==n-1)
		{
			color[y][x]=2;
		}
		else
		{
			if(color[y+1][x]==0)
			{
				DFS(y+1,x);
				if(color[y+1][x]==1) color[y][x]=1;
			}
		}

	}
	else if(t[y][x]=='l')
	{
		if(x==0)
		{
			color[y][x]=2;
		}
		else
		{
			if(color[y][x-1]==0)
			{
				DFS(y,x-1);
				if(color[y][x-1]==1) color[y][x]=1;
			}
		}

	}
	else if(t[y][x]=='p')
	{
		if(x==n-1)
		{
			color[y][x]=2;
		}
		else
		{
			if(color[y][x+1]==0)
			{
				DFS(y,x+1);
				if(color[y][x+1]==1) color[y][x]=1;
			}
		}

	}
	else if(t[y][x]=='k')
	{
		color[y][x]=1;
	}
	if(color[y][x]==3) color[y][x]=2;
	else if(color[y][x]==1)
	{
		tmp.x=x;
		tmp.y=y;
		Q.push(tmp);
	}
}

int main()
{
	scanf("%d",&z);
	while(z--)
	{
			scanf("%d",&n);
			for(int i=0;i<n;i++)
			{
				scanf("%s",t[i]);
			}
			for(int i=0;i<n;i++) for(int j=0;j<n;j++) color[i][j]=0;
			DFS(n-1,0);
			printf("%d\n",Q.size());
			while(!Q.empty())
			{
				tmp=Q.top();
				Q.pop();
				printf("%hd %hd\n",tmp.x+1,n-tmp.y);
			}
	}
	return 0;
}

