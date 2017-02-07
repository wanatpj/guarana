#include <cstdio>

using namespace std;

long long nwd(long long a, long long b)
{
	while(a!=0 && b!=0)
	{
		if(a>b)
			a%=b;
		else
			b%=a;
	}
	if(a>0)
		return a;
	return b;
}

void f(long long p, long long q, long long & a, long long & b)
{
	long long d = nwd(p,q);
	if(d==1 && p>=q)
	{
		a=p*q-(q*(q-1))/2;
		b=q*(q-1)/2;
		d=nwd(a,b);
		a/=d;
		b/=d;
	}
	else if(d==1 && q>p)
	{
		a=p*(p+1)/2;
		b=p*q-(p*(p+1))/2;
		d=nwd(a,b);
		a/=d;
		b/=d;
	}
	else
		f(p/d,q/d,a,b);
}

int main()
{
	int z;
	scanf("%d", &z);
	long long p, q, a, b;
	while(z>0)
	{
		z--;
		scanf("%lld %lld", &p, &q);
		f(p,q,a,b);
		printf("%lld %lld\n", a, b);
	}
	return 0;
}
