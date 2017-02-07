#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	unsigned int d,n,t,k,s;
	scanf("%u",&d);
	while(d--)
	{
		scanf("%u",&n);
		unsigned int tab[n+1];
		for(unsigned int i=1;i<=n;++i)
		{
			scanf("%u",tab+i);
		}
		if(n<=3)
		{
			s=0;
			for(unsigned int i=1;i<=n;++i)
				s+=tab[i];
			printf("%u\n",s);
			continue;
		}
		sort(tab+1,tab+n+1);
		k=0;
		for(unsigned int i=1;2*i<=n;++i)
		{
			if(2*tab[2]-tab[1]<tab[n-2*i+1])
			{
				t=i;
				if(t>k)
					k=t;
			}
		}
		s=(n-k-2)*tab[1]+(2*k+1)*tab[2];
		for(unsigned int i=3;i<=n-2*k;++i)
			s+=tab[i];
		for(unsigned int i=0;i<=k-1;++i)
			s+=tab[n-(2*i)];
		
		printf("%u\n",s);
	}
	return 0;
}
