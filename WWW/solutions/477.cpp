// SumaDzielnikowE2.cpp : Defines the entry point for the console application.
//

#include <cstdio>
#include <vector>

using namespace std;

// LLI Gdzies??

const int RM = 1000009;

bool tab[RM];
int divisor[RM];
vector<int> primes;
int result[RM];
int n, m;

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
int Exponentiation(int d, int exp) // chyba tu nie musze modulowac, bo i tak dostaje liczbe mniejszej od takie na wejsciu, czyli anyway int... :)
{
	if(exp==1) return d;
	if(exp==0) return 1;
	int temp = Exponentiation(d, exp/2);
	if(exp%2==0)
		return (temp*temp);
	else return (temp*temp*d);
}


int geometric_progression(int d, int exp)
{
	return ((Exponentiation(d, exp) - 1) / (d - 1)) %m;
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

int findFactor(int a)
{
	int s = primes.size();
	for(int i=0; i<s; i++)
		if(a%primes[i]==0)
			return primes[i];
	return -1;
}

int main()
{
	Sito();
	for(int i=0; i<RM; i++)
		result[i]=-1;
	result[1]=1;

	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a < RM)
		{
			if(result[a]==-1)
				countResult(a);
			printf("%d\n", result[a]);
		}
		else
		{
			int b = findFactor(a);
			if(b==-1)
				printf("%d\n", (a + 1) %m);
			else 
			{
				int newA = a;
				int times = 0;
				int d = b;
				while(newA%d==0)
				{
					times++;
					newA/=d;
				}
				if(result[newA]==-1)
					countResult(newA);
				printf("%d\n", (result[newA] * geometric_progression(d, times+1)) /*%m*/ );
			}
		}
	}
}
