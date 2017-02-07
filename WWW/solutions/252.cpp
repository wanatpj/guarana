
#include <cstdio>

int main()
{
	int ile, obw;
	scanf("%d%d", &ile, &obw);
	int k, o, d;
	while(ile--)
	{
		scanf("%d%d%d", &k, &o, &d);
		if(k > obw)
			printf("komin\n");
		else if(o > obw)
			printf("okno\n");
		else if(d > obw)
			printf("drzwi\n");
		else
			printf("brak\n");
	}

	return 0;
}