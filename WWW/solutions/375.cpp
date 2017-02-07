#include <cstdio>
#include <cstring>
#define MIN(x, y) ((x<y) ? (x) : (y))
#define N 10000
#define Z 20000
#define GUILTY 1
#define INNOCENT 0

int list_i;
int head[N];
int list[Z][4];
bool inconsistent[N];
int result[N];
int n, z, q;

inline void add(int s, char c, int d)
{
	list[list_i][0] = c;
	if(c == 'W')
		list[list_i][1] = d;
	else
		list[list_i][1] = list[d][1];
	list[list_i][2] = (c == 'W') ? (GUILTY) : ((list[d][2] == GUILTY) && (c == 'P'));
	list[list_i][3] = head[s];
	head[s] = list_i++;
}

inline void removeInconsistency(void)
{
	int guilty[N];
	int innocent[N];
	memset(guilty, 0, sizeof(guilty));
	memset(innocent, 0, sizeof(innocent));
	for(int i=0; i<n; i++)
	{
		int guilty_count = 0;
		for(int k=head[i]; k!=-1; k=list[k][3])
		{
			printf("debug(%d): %d -> %d : %s\n", k+1, i+1, list[k][1]+1, (list[k][2]) ? "GUILTY" : "INNOCENT");
			if(list[k][2] == GUILTY)
			{
				if(innocent[list[k][1]] == i+1)
				{
					printf("debug: inconsistend %d (1)\n", i+1);
					inconsistent[i] = true;
					break;
				}
				guilty_count++;
				guilty[list[k][1]] = i+1;
			}
			else
			{
				if(guilty[list[k][1]] == i+1)
				{
					inconsistent[i] = true;
					break;
				}
				innocent[list[k][1]] = i+1;
			}
		}
		if(guilty_count > 1)
		{
			printf("debug: inconsistend %d (2) - %d\n", i+1, guilty_count);
			inconsistent[i] = true;
		}
		if(guilty_count == 0)
			q++;
	}
}

inline void countIt(void)
{
	for(int i=0; i<n; i++)
	{
		if(!inconsistent[i])
		{
			printf("debug: %d - not inconsistent\n", i+1);
			for(int k=head[i]; k!=-1; k=list[k][3])
			{
				printf("debug(%d): %d -> %d : %s\n", k+1, i+1, list[k][1]+1, (list[k][2]) ? "GUILTY" : "INNOCENT");
				if(list[k][2] == GUILTY)
					result[list[k][1]][0]++;
				else
					result[list[k][1]][1]++;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int d;
	scanf("%d", &d);
	while(d--)
	{
		list_i = 0;
		q = 0;
		memset(head, -1, sizeof(head));
		memset(inconsistent, 0, sizeof(inconsistent));
		memset(result, 0, sizeof(result));
		scanf("%d %d", &n, &z);
		for(int i=0; i<z; i++)
		{
			int s, d;
			char c;
			scanf("%d %c %d", &s, &c, &d);
			add(s-1, c, d-1);
		}
		for(int i=0; i<z; i++)
			printf("debug: %c %d %s\n", list[i][0], list[i][1], (list[i][2]) ? "GUILTY" : "INNOCENT");
		removeInconsistency();
		countIt();
		printf("debug: ");
		for(int i=0; i<n; i++)
			printf("(%d %d) ", result[i][0], result[i][1]);
		printf("\n");
		{
			int min = 0x7FFFFFFF;
			for(int i=0; i<n; i++)
				min = MIN(n-result[i][0]-result[i][1], min);
			for(int i=0; i<n; i++)
			{
				if(n-result[i] == min)
					printf("%d ", i+1);
			}
			printf("\n");
		}
	}
	return 0;
}

