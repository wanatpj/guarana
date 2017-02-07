#include <cstdio>
#define ABS(a) (((a)<0) ? (0-(a)) : (a))
#define N 200

int arg[N];
int z[N];
int b, gt;

int findResult(int p, int n)
{
	int m = 0;
	int t = 0;
	int tmp = 0x7FFFFFFF;
	int s = z[p+n-1]-z[p-1];
	for(int i=0; i<n; i++)
	{
		if(p >= 1)
		{
			if(ABS(s - 2*(z[p+i] + z[p-1])) < tmp)
			{
				m = i;
				tmp = ABS(s - 2*(z[p+i] + z[p-1]));
			}
		}
		else
		{
			if(ABS(s - 2*z[p+i]) < tmp)
			{
				m = i;
				tmp = ABS(s - 2*z[p+i]);
			}
		}
	}
	m++;
	if(m == 1)
	{
		t += arg[p+m-1];
	}
	else
	{
		t += findResult(p, m);
	}
	if(n-m == 1)
	{
		t += arg[p+n-1];
	}
	else
	{
		t += findResult(p+m, n-m);
		b++;
	}
	gt += t;
	return t;
}

int main(int argc, char* argv[])
{
	int d;
	scanf("%d", &d);
	while(d--)
	{
		int n;
		b=0;
		gt=0;
		/// wczytanie wejscia
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d", &arg[i]);
		/// wypelnienie tablicy zliczaina
		z[0] = arg[0];
		for(int i=1; i<n; i++)
			z[i] = z[i-1] + arg[i];
		/// uruchomienie rekurencyjnego wyszukiwania wyniku
		findResult(0, n);
		printf("%d %d\n", gt, b);

	}
	return 0;
}

