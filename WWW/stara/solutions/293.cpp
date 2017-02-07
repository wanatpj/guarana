#include <cstdio>
using namespace std;

char T[1001][1001];
bool Visited[1001][1001];
int N,wolne;
int Wynik[1000002][2];

bool add(bool a, int y, int x)
{
	if (a==1)
	{
		Wynik[wolne][0]=y;
		Wynik[wolne][1]=x;
		wolne++;
		return 1;
	}
	return 0;
}

bool fun(int y, int x)
{
	bool a=0;
	if (Visited[y][x]==0)
	{
		Visited[y][x]=1;
		if (T[y][x]=='.')
		{
			if (y<N)
				a=a |fun (y+1,x);
			if (x<N)
				a=a |fun (y,x+1);
			if (x>1)
				a=a |fun (y,x-1);
			if (y>1)
				a=a |fun (y-1,x);
			return add(a,y,x);
		}
		else
		{
			if (T[y][x]=='p')
			{
				if (x<N)
					return add(fun(y,x+1),y,x);
				else
					return 0;
			}
			if (T[y][x]=='l')
			{
				if (x>1)
					return add(fun (y,x-1),y,x);
				else
					return 0;
			}
			if (T[y][x]=='g')
			{
				if (y<N)
					return add(fun (y+1,x),y,x);
				else
					return 0;
			}
			if (T[y][x]=='d')
			{
				if (y>1)
					return add(fun (y-1,x),y,x);
				else
					return 0;
			}
			if (T[y][x]=='k')
			{
				Wynik[wolne][0]=y;
				Wynik[wolne][1]=x;
				wolne++;
				return 1;
			}
		}
	}
	else
		return 0;
}

int main()
{
	bool a;
	int C;
	scanf ("%d",&C);
	while (C>0)
	{
		wolne=1;
		for (int i=1;i<=N;i++)
			for (int y=1;y<=N;y++)
				Visited[y][i]=0;
		scanf ("%d",&N);
		for (int i=N;i>=1;i--)
			scanf ("%s",T[i]+1);
		a=fun(1,1);
		printf ("%d\n",wolne-1);
		for (int i=wolne-1;i>0;i--)
			printf ("%d %d\n",Wynik[i][1], Wynik[i][0]);
		C--;
	}
	return 0;
}
