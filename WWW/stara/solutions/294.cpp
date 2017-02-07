#include <stdio.h>

int main(int argc, char* argv[])
{
	int n, ob;
	scanf("%d %d", &n, &ob);
	while(n--)
	{
		int k, o, d;
		scanf("%d %d %d", &k, &o, &d);
		if(k > ob)
			printf("komin\n");
		else if(o > ob)
			printf("okno\n");
		else if(d > ob)
			printf("drzwi\n");
		else
			printf("brak\n");
	}
	return 0;
}

