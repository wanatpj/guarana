#include <iostream>
#include <queue>
using namespace std;

struct point
{
	short x;
	short y;
	point(const short &a=0, const short &b=0) : y(a), x(b) {};
};

int main()
{
	int C, N, result;
	char plansza[1007][1007];
	point prev[1007][1007];
	point end, act;
	queue<point> Q;
	scanf("%d", &C);
	while(C--)
	{
		scanf("%d\n", &N);
		for(int i=0; i<N; i++)
			scanf("%s", plansza[i]);
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(plansza[i][j] == 'k')
				{
					end.y = i;
					end.x = j;
					prev[i][j] = point(-1,-1);
				}
			}
		}
		Q.push(end);
		while(!Q.empty())
		{
			act = Q.front();
			Q.pop();
			if(act.y-1>=0 && (plansza[act.y-1][act.x] == 'd' || plansza[act.y-1][act.x] == '.'))
			{
				Q.push(point(act.y-1,act.x));
				prev[act.y-1][act.x] = act;
			}
			if(act.x+1<N && (plansza[act.y][act.x+1] == 'l' || plansza[act.y][act.x+1] == '.'))
			{
				Q.push(point(act.y,act.x+1));
				prev[act.y][act.x+1] = act;
			}
			if(act.y+1<N && (plansza[act.y+1][act.x] == 'g' || plansza[act.y+1][act.x] == '.'))
			{
				Q.push(point(act.y+1,act.x));
				prev[act.y+1][act.x] = act;
			}
			if(act.x-1>=0 && (plansza[act.y][act.x-1] == 'p' || plansza[act.y][act.x-1] == '.'))
			{
				Q.push(point(act.y,act.x-1));
				prev[act.y][act.x-1] = act;
			}
		}
		result = 0;
		act = point(N-1,0);
		while(act.x != -1 || act.y != -1)
		{
			act = prev[act.y][act.x];
			result++;
		}
		printf("%d\n", result);
		act = point(N-1,0);
		while(act.x != -1 || act.y != -1)
		{
			printf("%hd %hd\n", act.x+1, N-act.y);
			act = prev[act.y][act.x];
		}
	}
	return 0;
}
