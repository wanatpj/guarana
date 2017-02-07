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
	
		ind=0;
		stack[ind].x=0;
		stack[ind].y=1;
		stack[ind].z=0;
	
		ind ++;
		char cur;
		point actual;
		point current;

		while (ind>=0)
		{
			cur = path[stack[ind-1].y][stack[ind-1].x];
			actual = current = stack[ind-1];
			result[current.z]=current;
			current.z++;
			if (!visited[actual.y][actual.x])
			{
				visited[actual.y][actual.x] = true;
				if (cur == 'k')
				{
					break;
				}
				if (cur == 'p' || cur == '.')
				{
					actual = current;
					actual.x++;

					if (actual.x < n && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
				}
				if (cur == 'd' || cur == '.')
				{
					actual = current;
					
					actual.y--;

					if (actual.y > 0 && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
	
				}
				if (cur == 'l' || cur == '.')
				{
					actual = current;
					
					actual.x--;
					if (actual.x >= 0 && !visited[actual.y][actual.x])
					{
						stack[ind]=actual;
						ind++;
					}
	
				}
				if (cur == 'g' || cur == '.')
				{
					actual = current;
				
					actual.y++;
					if (actual.y <= n && !visited[actual.y][actual.x])
					{

						stack[ind]=actual;
						ind++;
					}
					
				}
			}
			else
				ind--;


		}


	printf ("%d\n", stack[ind-1].z+1);
	for (int i=0; i<=stack[ind-1].z; i++)
		printf ("%d %d\n", result[i].x+1, result[i].y);
	}

return 0;
}
