// SumaDzielnikowE2.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <vector>

using namespace std;

// LLI Gdzies??
#define lli long long int

const int RM = 1000009;

bool tab[RM];
int divisor[RM];
vector<int> primes;
lli result[RM];
int n;
lli m;

void Sito()
{
	primes.clear();
	for(int i=0; i<RM; i++)
		tab[i]=true;
	tab[0] = tab[1] = false;
	for(int i=2; i<RM; i++)
	{
		if(tab[i])
		{
			divisor[i]=i;
			if(i < 46349)
			{
				int j = i*i;
				while(j < RM) 
				{
					if(tab[j])
						divisor[j] = i;
					tab[j] = false;
					j+=i;
				}
			}
		}
	}
	for(int i=0; i<RM; i++)
		if(tab[i]) 
			primes.push_back(i);
	return;
}
lli Exponentiation(int d, int exp) // chyba tu nie musze modulowac, bo i tak dostaje liczbe mniejszej od takie na wejsciu, czyli anyway int... :)
{
	if(exp==1) return (lli)d;
	if(exp==0) return (lli)1;
	lli temp = Exponentiation(d, exp/2);
	if(exp%2==0)
		return (temp*temp);
	else return (temp*temp*d);
}


lli geometric_progression(int d, int exp)
{
	return ((Exponentiation(d, exp) - (lli)1) / ((lli)d - (lli)1)) %m;
}
void countResult(int a)
{
	int newA = a;
	int times = 0;
	int d = divisor[a];
	while(newA%d==0)
	{
		times++;
		newA/=d;
	}
	if(result[newA]==-1)
		countResult(newA);
	result[a] = (result[newA] * geometric_progression(d, times+1)) %m ;
	return;
}

int findFactor(int a, int prev)
{
	if(a==0) return -1;
	int s = primes.size();
	for(int i=prev+1; i<s; i++)
		if(a%primes[i]==0)
			return i;
	return -1;
}

int main()
{
	Sito();
	for(int i=0; i<RM; i++)
		result[i]=(lli)-1;
	result[0]=result[1]=(lli)1;

	scanf("%d%Ld", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
	//	printf("no wczytalam a\n");
		if(a < RM)
		{
	//		printf("przypadek pierwszy\n");
			if(result[a]==-1)
				countResult(a);
			printf("%Ld\n", result[a]);
		}
		else
		{
	//		printf("przypadek drugi\n");
			int b = findFactor(a, -1);
			int newA = a;
	//		printf("znalezlismy liczbe %d\n", b);
			lli tempRes = 1;
			while(b!=-1)
			{
				int times = 0;
				int d = primes[b];
				while(newA%d==0)
				{
					times++;
					newA/=d;
				}
				tempRes*=geometric_progression(d, times+1);
//				printf("wynik pomnazamy szereg %d^%d, a nowe a to %d\n", d, times, newA);
//				printf("new wynik to %d\n", tempRes);
				tempRes%=m;
				if(newA<RM)
				{
					if(result[newA]==-1)
						countResult(newA);
					tempRes *= result[newA];
					newA = 0;
				}
				b = findFactor(newA, b);
			}
			printf("%Ld\n", ((lli)(newA + 1)%m * tempRes%m) %m);
		}
	}
	return 0;
}
