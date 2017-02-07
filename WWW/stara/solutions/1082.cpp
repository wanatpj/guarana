#include <cstdio>
#include <algorithm>

using namespace std;

int t[10000];

int main()
{
	int d, n, a, wynik;
	scanf("%d", &d);
	while(d>0)
	{
		d--;
		scanf("%d", &n);
		for(int i = 0;i<n;i++)
			scanf("%d", &t[i]);
		sort(t,t+n);
		wynik=1000000000;
		a=(n-2)*t[0]+t[1];
		for(int i = 2;i<n;i++)
			a+=t[i];
		wynik=min(wynik,a);
		for(int i = 1;i<=(n/2)-1;i++)
		{
			a=a-t[0]+2*t[1]-t[n-2*i];
			wynik=min(wynik,a);
		}
		printf("%d\n", a);
	}
	return 0;
}
