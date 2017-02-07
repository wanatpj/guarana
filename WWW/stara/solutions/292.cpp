#include <stdio.h>
#include <string.h>
#define N 1000
char map[N][N];
typedef struct {
	unsigned short x;
	unsigned short y;
} cord_t;
unsigned short stack[N*N][3];
int stack_i = 0;
cord_t path[N*N];
int path_i = 0;
bool visited[N][N];
unsigned short parent[N][N];

void push(int x, int y, int d)
{
	if(!visited[x][y])
	{
		visited[x][y]=true;
		stack[stack_i][0] = x;
		stack[stack_i][1] = y;
		stack[stack_i++][2] = d+1;
		path_i = ((d+1) > path_i) ? (d+1) : (path_i);
	}
}

int main(int argc, char* argv[])
{
	int x;
	scanf("%d", &x);
	while(x--)
	{
		memset(visited, 0, sizeof(visited));
		int n, i;
		scanf("%d", &n);
		for(i=n-1; i>=0; i--)
			scanf("%s", &map[i][0]);
		stack_i = 0;
		push(0, 0, -1);
		path_i = 0;
		while(stack_i > 0)
		{
			cord_t c;
			c.x = stack[--stack_i][0];
			c.y = stack[stack_i][1];
			int d = stack[stack_i][2];
			path[d] = c;
			char s = map[c.y][c.x];
			if(s == 'k')
			{
				path_i = d+1;
				break;
			}
			if(((s == 'g') || (s == '.')) && (c.y+1 < n))
				push(c.x, c.y+1, d);
			if(((s == 'd') || (s == '.')) && (c.y-1 >= 0))
				push(c.x, c.y-1, d);
			if(((s == 'p') || (s == '.')) && (c.x+1 < n))
				push(c.x+1, c.y, d);
			if(((s == 'l') || (s == '.')) && (c.x-1 >= 0))
				push(c.x-1, c.y, d);
		}
		printf("%d\n", path_i);
		for(i=0; i<path_i; i++)
			printf("%d %d\n", path[i].x+1, path[i].y+1);
	}
	return 0;
}

