// SumaDzielnikowE3.cpp : Defines the entry point for the console application.
//

#include <cstdio>

using namespace std;

#define lli long long int

const int RM = 32000; // troche wiecej niz pierwiastek z 10^9, ale mniejsze niz pierwiastek z 2^32 :)
int divisor[RM]; // jak divisor[i] == i tzn ze i jest pierwsze, dla i != 0, i != 1
int primes[RM]; 
lli result[RM]; 
int n;
lli m;
int endPrimes;

void Sito()
{
	endPrimes=0;
	for(int i=0; i<RM; i++)
	{
		divisor[i]=i;
		result[i]=(lli)-1; 
	}
	for(int i=2; i<RM; i++)
	{
		if(divisor[i]==i) 
		{
			int j = i*i; 
			while(j < RM) 
			{
				if(divisor[j]==j) 
					divisor[j] = i;
				j+=i;
			}
		}
	}
	for(int i=2; i<RM; i++)
		if(divisor[i]==i) 
		{
			primes[endPrimes]=i;
			endPrimes++;
			result[i] = (lli)(i+1); 
		}
	result[0]=result[1]=(lli)1; 
	return;
}

lli Exponentiation(int d, int exp)  
{
	if(exp==1) return (lli)d;
	if(exp==0) return (lli)1;
	lli temp = Exponentiation(d, exp/2);
	if(exp%2==0)
		return temp*temp;
	else return temp*temp*d;
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
	int s = endPrimes;
	for(int i=prev+1; i<s; i++)
		if(a%primes[i]==0)
			return i;
	return -1;				
}

int main()
{
	Sito();
	scanf("%d%Ld", &n, &m);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a < RM)
		{
			if(result[a]==-1)
				countResult(a);
			printf("%Ld\n", result[a]);
		}
		else
		{
			int b = findFactor(a, -1); 
			lli tempRes = 1; 
			while(b!=-1)
			{
				int times = 0;
				int d = primes[b]; 
				while(a%d==0)
				{
					times++;
					a/=d;
				}
				tempRes*=geometric_progression(d, times+1);
				tempRes%=m;
				if(a<RM) 
				{
					if(result[a]==-1)
						countResult(a);
					tempRes *= result[a]; 
					a = 0;
						
				}
				b = findFactor(a, b); 
			}
			printf("%Ld\n", (((lli)(a + 1)%m) * tempRes) %m);
		}
	}
	return 0;
}
