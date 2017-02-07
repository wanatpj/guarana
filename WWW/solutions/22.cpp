#include <cstdio>

using namespace std;

char m[7][7];
int BKx, BKy;
int dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
int r[7][7];

bool mat(int x, int y)
{
	bool zdal=0;
	if(m[x-1][y-1]!='C'&&m[x-1][y+1]!='C')
		return false;
	if(m[x-1][y-1]=='b'||m[x-1][y+1]=='b')
		return false;
	for(int i = 0;i<7;i++)
		for(int j = 0;j<7;j++)
			r[i][j]=0;
	for(int i = 0;i<7;i++)
		for(int j = 0;j<7;j++)
		{
			if(m[i][j]=='b')
			{
				r[i-1][j-1]=1;
				r[i-1][j+1]=1;
			}
			else if(m[i][j]=='B')
			{
				for(int k = 0;k<8;k++)
					r[i+dx[k]][j+dy[k]]=1;
			}
			else if(m[i][j]=='c'||m[i][j]=='X')
			{
				r[i][j]=1;
			}
		}
	if(r[BKx][BKy]==0)
		return false;
	for(int i = 0;i<8;i++)
	{
		if(r[BKx+dx[i]][BKy+dy[i]]==0)
			return false;
	}
	return true;
}

bool da_sie()
{
	for(int i = 1;i<=4;i++)
	{
		for(int j = 1;j<=4;j++)
		{
			if(m[i][j]=='b')
			{
				if(m[i-1][j]=='.')
				{
					m[i-1][j]='b';
					m[i][j]='.';
					if(mat(i-1,j))
						return true;
					m[i][j]='b';
					m[i-1][j]='.';
				}
				if(m[i-1][j-1]=='c')
				{
					m[i-1][j-1]='b';
					m[i][j]='.';
					if(mat(i-1,j-1))
						return true;
					m[i][j]='b';
					m[i-1][j]='c';
				}
				if(m[i-1][j+1]=='c')
				{
					m[i-1][j+1]='b';
					m[i][j]='.';
					if(mat(i-1,j+1))
						return true;
					m[i][j]='b';
					m[i-1][j+1]='c';
				}

			}
		}
	}
	return false;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t>0)
	{
		t--;
		for(int i = 1;i<=4;i++)
			scanf("%s", m[i]+1);
		for(int i = 0;i<=5;i++)
			m[0][i]=m[5][i]=m[i][0]=m[i][5]='X';
		for(int i = 1;i<=4;i++)
		{
			for(int j = 1;j<=4;j++)
			{
				if(m[i][j]=='C')
				{
					BKx=i;
					BKy=j;
					break;
				}
			}
		}
		if(da_sie())
			printf("TAK\n");
		else
			printf("NIE\n");
	}
}
