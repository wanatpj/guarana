//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

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

using namespace std;

unsigned int indX = 0;
unsigned int *liczbyPierwsze;

unsigned int pow(unsigned int i, unsigned int p){
	if(p == 0)return 1;
	int tmp = i;
	p--;
	while(p--)i = i * tmp;
	return i;
	}

unsigned int doIt(unsigned int n){
	//Rozklad na czynniki pierwsze
	//unsigned short int *iloscLiczbPierwszych = new unsigned short int[100000000];

	unsigned int liczba = n;
	//unsigned int last = 2;

	while(liczba != 1){
		for(unsigned int i = 2;;i++){
			if(liczba%i == 0){
				liczbyPierwsze[indX++] = i;
				liczba /= i;
				break;
				}
			if(i > 1000003){return n+1;}
			}
		}

	//for(int i = 0;i < indX;i++)cout << liczbyPierwsze[i] << endl;

	unsigned int currentPos = 0;
	unsigned int suma = 1;
	unsigned int potega = 0;
	while(currentPos < indX){
		unsigned int *x = upper_bound(liczbyPierwsze+currentPos, liczbyPierwsze+indX, liczbyPierwsze[currentPos]);
		potega = x - liczbyPierwsze - currentPos + 1;
		suma = suma * ((pow(liczbyPierwsze[currentPos], potega)-1)/(liczbyPierwsze[currentPos]-1));
		currentPos = x - liczbyPierwsze;
		}

	indX = 0;
	return suma;
	}

int main(){
	liczbyPierwsze = new unsigned int[2000000];
	udefget(C);
	udefget(M);
	while(C--){
		udefget(n);
		unsigned int tmp = doIt(n);
		if(tmp < M)printf("%d\n", tmp);
		else printf("%d\n", tmp%M);
		}
	return 0;
	}
