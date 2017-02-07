#include <cstdio>
#include <cstring>

using namespace std;

int len;
char t[1000003];
int p[1000003];

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

void manacher()
{
	int z=0, c=0;
	p[0]=0;
	for(int poz = 1;poz<len;poz++)
	{
		if(poz<z)
		{
			p[poz]=min(p[c-(poz-c)],z-poz);
		}
		while(t[poz+p[poz]]==t[poz-p[poz]])
			p[poz]++;
		if(z<=poz+p[poz]-1)
		{
			z=poz+p[poz];
			c=poz;
		}
	}
}

int main()
{
	scanf("%s", t+1);
	t[0]=1;
	len=strlen(t);
	t[len]=2;
	manacher();
	for(int i = 1;i<len;i++)
		printf("%d ", p[i]-1);
	printf("\n");
}
