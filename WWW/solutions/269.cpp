/*
 * Ciastka
 * III Internetowe Mistrzostwa Polski w Programowaniu
 * @author: Aleksandra Rzemyk
 * @shool: V LO Krakow
 */

#include<cstdio>
using namespace std;

int main ()
{
	int d, n, x, c, tmp;
	scanf ("%d", &d);
	while (d--)
	{
		tmp = 0;
		scanf ("%d", &n);
		while (n--)
		{
			scanf("%d", &x);
			tmp += x;
		}
		scanf ("%d", &c);
		if (tmp == 0)
			printf ("%d\n", c);
		else
			printf ("%d\n", c%tmp);
	}
return 0;
}
