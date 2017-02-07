/*
 * Sciezka
 * III Internetowe Mistrzostwa Polski w Programowaniu
 * @author: Aleksandra Rzemyk
 * @shool: V LO Krakow
 */

#include<cstdio>
//#define DEBUG1
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
#ifdef DEBUG
printf ("ind %d\n", ind);
#endif

			actual = stack[ind-1];
#ifdef DEBUG
printf ("\n\n HERE IS NEW ACTUAL %d %d cur %c VISITED %d\n", actual.x, actual.y, cur, visited[actual.y][actual.x]);
#endif

			if (!visited[actual.y][actual.x])
			{
				visited[actual.y][actual.x] = true;
				if (cur == 'k')
				{
					break;
				}
				else if (cur == 'p')
				{
#ifdef DEBUG
printf ("HERE I AM P\n");	
#endif

					actual.z=actual.x;
					actual.t=actual.y;
					actual.x++;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.x < n && !visited[actual.y][actual.x])
					{
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
				}
				else if (cur == 'd')
				{
#ifdef DEBUG
printf ("HERE I AM D\n");	
#endif

					actual.z=actual.x;
					actual.t=actual.y;
					
					actual.y--;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.y > 0 && !visited[actual.y][actual.x])
					{
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
	
				}
				else if (cur == 'l')
				{
#ifdef DEBUG
printf ("HERE I AM L\n");	
#endif

					actual.z=actual.x;
					actual.t=actual.y;
					
					actual.x--;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.x >= 0 && !visited[actual.y][actual.x])
					{
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
	
				}
				else if (cur == 'g')
				{
					actual.z=actual.x;
#ifdef DEBUG
printf ("HERE I AM G\n");	
#endif

					actual.t=actual.y;
					
					actual.y++;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.y <= n && !visited[actual.y][actual.x])
					{
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
					
				}
				else if (cur == '.')
				{
					actual.z=actual.x;
#ifdef DEBUG
printf ("HERE I AM DOT\n");	
#endif

					actual.t=actual.y;
					actual.y++;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.y <= n && !visited[actual.y][actual.x])
					{	
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
					actual.y-=2;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.y > 0 && !visited[actual.y][actual.x])
					{	
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
					actual.y++;	
					actual.x++;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.x < n && !visited[actual.y][actual.x])
					{	
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}

					actual.x-=2;
#ifdef DEBUG
printf ("ACTUAL %d %d\n", actual.x, actual.y);	
#endif

					if (actual.x >= 0 && !visited[actual.y][actual.x])
					{	
#ifdef DEBUG
printf ("ADD\n");
#endif

						stack[ind]=actual;
						ind++;
					}
				}
			}
			else
				ind--;

#ifdef DEBUG
printf ("ind %d\n", ind);
#endif


		}
#ifdef DEBUG1
printf ("IND %d\n", ind); 
for (int i=0; i<ind; i++)
	printf ("%d %d  parent: %d %d\n", stack[i].x, stack[i].y, stack[i].z, stack[i].t);
#endif	

	
	actual = stack[ind-1];
	int ires = 0;
	for (int i=ind-2; i>=0; i--)
	{
		if (stack[i].x == actual.z && stack[i].y == actual.t)
		{

#ifdef DEBUG
printf ("%d %d\n", actual.x+1, actual.y);
#endif

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
