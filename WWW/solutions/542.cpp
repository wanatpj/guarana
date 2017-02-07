//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define null NULL
#define iget(exp) scanf("%d",&exp);
#define uget(exp) scanf("%u",&exp);
#define usget(exp) scanf("%hu",&exp);
#define gets(exp) scanf("%s",exp);
#define idefget(exp) int exp;scanf("%d",&exp);
#define udefget(exp) unsigned int exp;scanf("%u",&exp);
#define dataset() udefget(z);while(z--)
#define release true;
#define cind_ex(exp) exp+1000000000
#define until(exp1, exp2) for(int exp1 = 0;exp1 < exp2;exp1++)

#define MAX 500000

using namespace std;

unsigned int indX = 0;
bool *liczbyPierwsze;
unsigned int *pierwsze;
unsigned long long czynniki[64];
int _last = 0;

unsigned long long int pow(unsigned int x, unsigned int n){
	unsigned long long a = 0;
	if(n == 0)return 1;
	if(n%2 == 1)return x * pow(x, n - 1);
	else a = pow(x, n / 2);
	return a*a;
	}

unsigned long long int doIt(unsigned int n){

	unsigned int liczba = n;

	while(liczba != 1){
		for(unsigned int i = 1;;i++){
			//cout << pierwsze[i] << " ";
			if(i >= _last-3){return n+1;}
			else if(liczba%pierwsze[i] == 0){
				czynniki[indX++] = pierwsze[i];
				liczba /= pierwsze[i];
				break;
				}
			}
		}

	//for(int i = 0;i < indX;i++)cout << czynniki[i] << " ";
	//cout << endl;
	
	unsigned int currentPos = 0;
	unsigned long long int suma = 1;
	unsigned int potega = 0;
	while(currentPos < indX){
		unsigned long long int *x = upper_bound(czynniki+currentPos, czynniki+indX, czynniki[currentPos]);
		potega = x - czynniki - currentPos + 1;
		suma = suma * ((pow(czynniki[currentPos], potega)-1)/(czynniki[currentPos]-1));
		currentPos = x - czynniki;
		}

	indX = 0;
	return suma;
	}

void sito(){
	for(unsigned int i = 2;i < MAX/2;i++){
		if(liczbyPierwsze[i] == true)continue;
		for(unsigned int j = 2*i;j < MAX;j += i)liczbyPierwsze[j] = true;
		}

	}


int main(){
	liczbyPierwsze = new bool[MAX];
	pierwsze = new unsigned int[MAX];
	for(unsigned int i = 0;i < MAX;i++)liczbyPierwsze[i] = false;
	sito();
	for(unsigned int i = 1;i < MAX;i++)if(liczbyPierwsze[i] == false)pierwsze[_last++] = i;

	udefget(C);
	udefget(M);
	while(C--){
		udefget(n);
		unsigned long long int tmp = doIt(n);
		if(tmp < M)printf("%d\n", tmp);
		else printf("%d\n", tmp%M);
		}
	return 0;
	}
