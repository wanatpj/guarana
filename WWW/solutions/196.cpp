#include <cstdio>

using namespace std;

#define ULL unsigned long long

struct f{
	ULL a, b, c, d;
};

f F, F2;
ULL p, x;
ULL wynik;

ULL raise(int n, ULL k)
{
	ULL wyn=1, pow=k;
	while(n>0)
	{
		if(n%2==1)
		{
			wyn*=pow;
			wyn%=p;
		}
		n/=2;
		pow*=pow;
		pow%=p;
	}
	return wyn;
}

void calc(int n)
{
	ULL val, val2;
	while(n>0)
	{
		if(n%2==1)
		{
			val=F.a*wynik;
			val%=p;
			val+=F.b;
			val%=p;
			val2=F.c*wynik;
			val2%=p;
			val2+=F.d;
			val2%=p;
			wynik=val;
			wynik*=raise(p-2,val2);
			wynik%=p;
		}
		n/=2;
		F2.a=F.a*F.a+F.b*F.c;
		F2.a%=p;
		F2.b=F.a*F.b+F.b*F.d;
		F2.b%=p;
		F2.c=F.a*F.c+F.d*F.c;
		F2.c%=p;
		F2.d=F.b*F.c+F.d*F.d;
		F2.d%=p;
		F=F2;
	}
}

int main()
{
	int z, n;
	scanf("%d", &z);
	while(z>0)
	{
		z--;
		scanf("%llu %llu %llu %llu %llu %llu %d", &p, &F.a, &F.b, &F.c, &F.d, &x, &n);
		wynik=x;
		calc(n);
		printf("%llu\n", wynik);
	}
}
