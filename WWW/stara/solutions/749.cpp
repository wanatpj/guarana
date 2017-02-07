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

#define MAX 300000

using namespace std;

bool *liczbyPierwsze;
unsigned long long int *pierwsze;
unsigned long long czynniki[64];
int _last = 0;

unsigned long long int pow(unsigned long long int x, unsigned long long int n){
	unsigned long long a = 0;
	if(n == 0)return 1;
	if(n%2 == 1)return x * pow(x, n - 1);
	else a = pow(x, n / 2);
	return a*a;
	}

unsigned long long int doIt(unsigned int n){

	unsigned int liczba = n;
	unsigned int last = 0;

	while(liczba != 1){
		for(unsigned long long i = 1;;i++){
			if(i >= _last-1)return n+1;
			if(liczba%pierwsze[i] == 0){
				czynniki[last++] = pierwsze[i];
				liczba /= pierwsze[i];
				break;
				}
			else if(pierwsze[i]*pierwsze[i] > liczba){
				czynniki[last++] = liczba;
				goto next;
				}
			}
		}

next:
	//until(i, last)cout << czynniki[i] << " ";
	//cout << endl << endl;;
	unsigned long long currentPos = 0;
	unsigned long long suma = 1;
	unsigned long long potega = 0;
	while(currentPos < last){
		unsigned long long int *x = upper_bound(czynniki+currentPos, czynniki+last, czynniki[currentPos]);
		potega = x - czynniki - currentPos + 1;
		suma = suma * ((pow(czynniki[currentPos], potega)-1)/(czynniki[currentPos]-1));
		currentPos = x - czynniki;
		}
	

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
	pierwsze = new unsigned long long int[MAX];
	for(unsigned int i = 0;i < MAX;i++)liczbyPierwsze[i] = false;
	sito();
	for(unsigned int i = 1;i < MAX;i++)if(liczbyPierwsze[i] == false)pierwsze[_last++] = i;

	//cout << pierwsze[_last-1] << endl << endl;

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
