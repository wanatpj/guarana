/*
 * Sciezka
 * III Internetowe Mistrzostwa Polski w Programowaniu
 * @author: Aleksandra Rzemyk
 * @shool: V LO Krakow
 */

#include<cstdio>
using namespace std;

struct point
{
	int x;
	int y;
	int z;
	int t;
};

point stack[1000001];
point result[1000001];
char path[1005][1005];
int visited[1005][1005];

int main ()
{
	int c, n;
	int ind = 0;
	scanf("%d", &c);

	while (c--)
	{
		scanf ("%d", &n);
		for (int i=n; i>0; i--)
		{
			scanf ("%s", path[i]);
		}	
		
		for (int i=0; i<=n; i++)
			for (int j=0; j<=n; j++)
				visited[i][j]=false;
		
		stack[ind].x=0;
		stack[ind].y=1;
	
		ind ++;
		char cur;
		point actual;

		while (ind>=0)
		{
			cur = path[stack[ind-1].y][stack[ind-1].x];

			actual = stack[ind-1];

			if (!visited[actual.y][actual.x])
			{
				visited[actual.y][actual.x] = true;
				if (cur == 'k')
				{
					break;
				}
				else if (cur == 'p')
				{
					actual.z=actual.x;
					actual.t=actual.y;
					actual.x++;

					if (actual.x < n && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
				}
				else if (cur == 'd')
				{
					actual.z=actual.x;
					actual.t=actual.y;
					
					actual.y--;

					if (actual.y > 0 && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
	
				}
				else if (cur == 'l')
				{
					actual.z=actual.x;
					actual.t=actual.y;
					
					actual.x--;
					if (actual.x >= 0 && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
	
				}
				else if (cur == 'g')
				{
					actual.z=actual.x;

					actual.t=actual.y;
					
					actual.y++;

					if (actual.y <= n && !visited[actual.y][actual.x])
					{

						stack[ind]=actual;
						ind++;
					}
					
				}
				else if (cur == '.')
				{
					actual.z=actual.x;

					actual.t=actual.y;
					actual.y++;

					if (actual.y <= n && !visited[actual.y][actual.x])
					{	

						stack[ind]=actual;
						ind++;
					}
					actual.y-=2;

					if (actual.y > 0 && !visited[actual.y][actual.x])
					{	

						stack[ind]=actual;
						ind++;
					}
					actual.y++;	
					actual.x++;

					if (actual.x < n && !visited[actual.y][actual.x])
					{	

						stack[ind]=actual;
						ind++;
					}

					actual.x-=2;

					if (actual.x >= 0 && !visited[actual.y][actual.x])
					{	

						stack[ind]=actual;
						ind++;
					}
				}
			}
			else
				ind--;


		}

	
	actual = stack[ind-1];
	int ires = 0;
	for (int i=ind-2; i>=0; i--)
	{
		if (stack[i].x == actual.z && stack[i].y == actual.t)
		{
			result[ires]=actual;
			ires++;
			actual=stack[i];
		}
	}
	result[ires]=stack[0];
	printf ("%d\n", ires+1);
	for (int i=ires; i>=0; i--)
		printf ("%d %d\n", result[i].x+1, result[i].y);
	}

return 0;
}
