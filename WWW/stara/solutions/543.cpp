// SumaDzielnikowE2.cpp : Defines the entry point for the console application.
// Z dedykacja dla mojego kochaniego Kalq'a :*:*:*
// PS: Moje kody sa ladne!!! ;p 
// PS2: I nie wszystkie maja 1200 linii!!! 

#include <cstdio>
#include <vector>

using namespace std;

#define lli long long int

const int RM = 32000; // troche wiecej niz pierwiastek z 10^9, ale mniejsze niz pierwiastek z 2^32 :)
int divisor[RM]; // jak divisor[i] == i tzn ze i jest pierwsze, dla i != 0, i != 1
vector<int> primes; 
lli result[RM]; 
int n;
lli m;

void Sito()
{
	primes.clear();
	for(int i=0; i<RM; i++)
	{
		divisor[i]=i;
		result[i]=(lli)-1; // tu zeruje, bo resulty niektore ustalam nizej w sumie
	}
	for(int i=2; i<RM; i++)
	{
		if(divisor[i]==i) // liczba pierwsza
		{
			int j = i*i; // dopiero od kwadratu sie oplaca nam sprawdzac :)
			while(j < RM) 
			{
				if(divisor[j]==j) // czyli jeszcze frajer byl pierwszy, ale mu pokaze :D
					divisor[j] = i;
				j+=i;
			}
		}
	}
	for(int i=2; i<RM; i++)
		if(divisor[i]==i) // ostaly sie pierwsze ;) 
		{
			primes.push_back(i);
			result[i] = (lli)(i+1); // no chyba jasne, mozemy juz ustalic, bo p dzieli 1, i p, no bo p pierwsze ;p
		}
	result[0]=result[1]=(lli)1; // zeby miec juz dno ;)
	return;
}
//podnosze x^k, przy czym x^(k-1) jeszcze sie miesci w incie, wiec nie ma bata by x^k sie nie miescilo w lli ;)
lli Exponentiation(int d, int exp)  // d^exp
{
	if(exp==1) return (lli)d;
	if(exp==0) return (lli)1;
	lli temp = Exponentiation(d, exp/2);
	if(exp%2==0)
		return temp*temp;
	else return temp*temp*d;
}

lli geometric_progression(int d, int exp) // wzor na sume szeregu geometrycznego: 1 + d + ... + d^exp mod m ofc ;)
{
	return ((Exponentiation(d, exp) - (lli)1) / ((lli)d - (lli)1)) %m;
}
void countResult(int a) // liczymy result dla a, przy czy a < RM
{
	int newA = a;
	int times = 0;
	int d = divisor[a];
	while(newA%d==0)
	{
		times++;
		newA/=d;
	}
	if(result[newA]==-1) // jesli dla tego tez jeszcze nie mam policzone, to licze
		countResult(newA);
	result[a] = (result[newA] * geometric_progression(d, times+1)) %m ; // obydwa skladniki mnozenia juz sa modulo m, wiec nie musze ich modulowac przed mnozeniem
	return;
}
								// tak naprawde to znajdz indeks tej liczby
int findFactor(int a, int prev) // dla jakiejs liczby a > RM, znajdz pierwsza liczbe pierwsza co ja dzieli
{								// jesli wiesz ze liczby pierwsze od primes[0] -> primes[prev] juz napewno jej nie dziela
	if(a==0) return -1;			// jak dalismy a = 0 (bo w mainie juz doszlismy do a < RM) to zwroc -1, zeby nam sie while skonczyl ;)
	int s = primes.size();
	for(int i=prev+1; i<s; i++)
		if(a%primes[i]==0)
			return i;
	return -1;					// jak nie ma takiej to zwroc -1, 
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
			int b = findFactor(a, -1); // no poki co jeszcze zadnej liczby pierwszej nie sprawdzilismy, czyli on zacznie wyszukiwania od 0-wej ;)
			lli tempRes = 1; // mamy tymczasowy wynik, ktory powiekszamy, a newA zmniejszamy, z nadzieja ze dojdzie do < RM, badz pierwszej :)
			while(b!=-1)
			{
				int times = 0;
				int d = primes[b]; //bo b to tylko indeks
				while(a%d==0)
				{
					times++;
					a/=d;
				}
				tempRes*=geometric_progression(d, times+1);
				tempRes%=m;
				if(a<RM) // jesli juz zeszlismy wystarczajaco nisko wartosciami
				{
					if(result[a]==-1)
						countResult(a);
					tempRes *= result[a]; // to powieksz wynik
					a = 0;// zeby miec 0+1 = 1, 1 * cos = cos, czyli tak jak chcemy
							// wpp, tj dla pierwszej, chcemy miec Result = (p + 1) * tempResult
				}
				b = findFactor(a, b); // znajdz kolejny dzielnik pierwszy, dla a == 0, znajdzie -1 wiec wyjdzie z petli
			}
			printf("%Ld\n", (((lli)(a + 1)%m) * tempRes) %m);
		}
	}
	return 0;
}
