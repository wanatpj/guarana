//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>

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

unsigned int liczby[203];
unsigned int suma = 0;
unsigned int iloscNawiasow = 0;
unsigned int n;


void doIt(unsigned int l){
	if(l == 1)return;
	unsigned int min = 5000;
	unsigned int tmp[203];
	unsigned int last = 0;

	//szukanie najmniejszej sumy
	until(i, l-1)if(liczby[i] + liczby[i+1] < min)min = liczby[i] + liczby[i+1];

	until(i, l){
		if(liczby[i] + liczby[i+1] == min){
			if(i%2 == 1)iloscNawiasow++;
			suma += liczby[i] + liczby[i+1];
			tmp[last++] = liczby[i] + liczby[i+1];
			i++;
			min = 5000;
			}
		else tmp[last++] = liczby[i];
		}

	until(i, last)liczby[i] = tmp[i];
	//cout << endl;
	doIt(last);
	}

int main(){
	dataset(){
		uget(n);
		//n = 200;
		suma = 0;
		iloscNawiasow = 0;
	
		//until(i, 203)liczby[i] = 1;
		until(i, 203)liczby[i] = 0;
		until(i, n)uget(liczby[i]);

		doIt(n);

		cout << suma << " " << iloscNawiasow << endl;
		}

	return 0;
	system("PAUSE");
	}
