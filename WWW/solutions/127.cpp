#include <cstdio>

using namespace std;

int n, k;
long long M;
long long V[1010];
long long V2[1010];
long long w[1010];

void raise()
{
	for(int i = 0;i<k;i++)
	{
		V2[i]=0;
		for(int j = 0, l = i;j<k;j++,l=(k+l-1)%k)
		{
			V2[i]+=V[j]*V[l];
			V2[i]%=M;
		}
	}
	for(int i = 0;i<k;i++)
		V[i]=V2[i];
}

void mult()
{
	for(int i = 0;i<k;i++)
	{
		V2[i]=0;
		for(int j = 0,l=i;j<k;j++,l=(k+l-1)%k)
		{
			V2[i]+=w[j]*V[l];
			V2[i]%=M;
		}
	}
	for(int i = 0;i<k;i++)
		w[i]=V2[i];
}

void gen()
{
	int l = n;
	for(int i = 0;i<k;i++)
		V[i]=w[i]=0;
	V[0]=w[0]=1;
	V[1]=1;
	while(l>0)
	{
		if(l%2==1)
			mult();
		l/=2;
		raise();
	}
}

long long pot2(int k)
{
	long long pot=2, wynik=1;
	while(k>0)
	{
		if(k%2==1)
			wynik*=pot;
		wynik%=M;
		k/=2;
		pot*=pot;
		pot%=M;
	}
	return wynik;
}

int main()
{
	scanf("%d %d %lld", &n, &k, &M);
	if(k==1)
	{
		printf("%lld\n", pot2(n));
		return 0;
	}
	gen();
	for(int i = 0;i<k;i++)
		printf("%lld\n", w[i]);
	return 0;
}
