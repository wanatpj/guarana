#include <cstdio>
#include <cstring>
#ifdef _DEBUG
#define DEBUG(args ...) printf(args)
#else
#define DEBUG(args ...)
#endif
#define MIN(x, y) ((x<y) ? (x) : (y))
#define N 10000
#define Z 20000

int list_i;
int head[N];
int list[Z][3];
bool inconsistent[N];
int n, z;
int gc[N];
int result[N];

inline void add(int s, char c, int d)
{
	if(c == 'W')
		list[list_i][0] = d;
	else
		list[list_i][0] = list[d][0];
	list[list_i][1] = (c == 'W') || ((list[d][2]) && (c == 'P'));
	list[list_i][2] = head[s];
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
		int innocent_count = 0;
		for(int k=head[i]; k!=-1; k=list[k][2])
		{
			DEBUG("%d -> %s -> %d \n", i+1, (list[k][1]) ? "GUILTY" : "INNOCENT", list[k][0]+1);
			if(list[k][1])
			{
				if(innocent[list[k][0]] == i+1)
				{
					DEBUG("inconsistent (reason: 1)\n");
					inconsistent[i] = true;
					break;
				}
				if(guilty[list[k][0]] != i+1)
					guilty_count++;
				guilty[list[k][0]] = i+1;
			}
			else
			{
				if(guilty[list[k][0]] == i+1)
				{
					DEBUG("inconsistent (reason: 2)\n");
					inconsistent[i] = true;
					break;
				}
				if((innocent[list[k][0]] != i+1) && (list[k][0] != i))
					innocent_count++;
				innocent[list[k][0]] = i+1;
			}
		}
		if(innocent_count >= n-1)
		{
			DEBUG("inconsistent (reason: 3)\n");
			inconsistent[i] = true;
		}
		if(guilty_count > 1)
		{
			DEBUG("inconsistent (reason: 4)\n");
			inconsistent[i] = true;
		}
		gc[i] = guilty_count;
		if(inconsistent[i] == true)
			DEBUG("removeInconsistency: %d - inconsistent\n", i+1);
	}
}

inline void countIt(void)
{
	for(int i=0; i<n; i++)
		result[i] = n;
	for(int i=0; i<n; i++)
	{
		if(!inconsistent[i])
		{
			if(gc[i] == 0)
			{
				for(int k=head[i]; k!=-1; k=list[k][2])
				{
					DEBUG("%d -> %s -> %d (result++)\n", i+1, (list[k][1]) ? "GUILTY" : "INNOCENT", list[k][0]+1);
					result[list[k][0]]++;
				}
			}
			else
			{
				for(int k=head[i]; k!=-1; k=list[k][2])
				{
					if(list[k][1])
					{
						DEBUG("%d -> %s -> %d (result--)\n", i+1, (list[k][1]) ? "GUILTY" : "INNOCENT", list[k][0]+1);
						result[list[k][0]]--;
					}
				}
			}
		}
	}
}

inline void printMins(void)
{
	int min = 0x7FFFFFFF;
	for(int i=0; i<n; i++)
		min = MIN(min, result[i]);
	for(int i=0; i<n; i++)
	{
		if(result[i] == min)
			printf("%d ", i+1);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	int d;
	scanf("%d", &d);
	while(d--)
	{
		list_i = 0;
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
		removeInconsistency();
		countIt();
#ifdef _DEBUG
		printf("result: ");
		for(int i=0; i<n; i++)
			printf("%d ", result[i]);
		printf("\n");
#endif
		printMins();
	}
	return 0;
}

