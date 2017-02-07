//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include <cstdlib>

#define null NULL
#define iget(exp) scanf("%d",&exp);
#define uget(exp) scanf("%u",&exp);
#define usget(exp) scanf("%hu",&exp);
#define gets(exp) scanf("%s",exp);
#define idefget(exp) int exp;scanf("%d",&exp);
#define udefget(exp) unsigned int exp;scanf("%u",&exp);
#define dataset() udefget(z);while(z--)
#define release true;
#define cindex(exp) exp+1000000000
#define until(exp1, exp2) for(int exp1 = 0;exp1 < exp2;exp1++)

using namespace std;


#define MAX1 50
#define MAX2 100

int primeArray[MAX1][MAX1];                                     // tablica dzielnikow pierwszych
int outArray[MAX2];                                             // tablica wszystkich dzielnikow
int index;                                                      // zmienna pomocnicza

void clearar(){
  for(int i=0; outArray[i]; i++)
    outArray[i] = 0;

  for(int i=0; i<MAX1; i++)
    for(int j=0; primeArray[i][j]; j++)
      primeArray[i][j] = 0;
}


/* funkcja rekurencyjna znajdujaca wszystkie iloczyny dzielnikow pierwszych */
void add(int value, int row, int maxrow) {
  int tmp;

  for(int i=0; primeArray[row][i]; i++) {
    if(row < maxrow-1) {
      tmp = value*primeArray[row][i];
      add(tmp, ++row, maxrow);
      row--;
    }
    else
      outArray[index++] = value*primeArray[row][i];
  }
}


void divnat(int n){

  /* Znajdowanie dzielnikow pierwszych */
  int tmp = n;
  int row = 0;
  for(int i=2, k=1; i<=tmp; ) {
    if(tmp%i == 0) {
      if(k==1){
        primeArray[row][0] = 1;
      }
      primeArray[row][k] = pow((double)i,k);
      tmp /= i;
      k++;
      if(tmp%i != 0) {
        primeArray[row][k] = 0;
        row++;
      }
    }
    else {
      k = 1;
      i++;
	  }
  }
	index = 0;
	add(1, 0, row);
}

int main(){  
	ios::sync_with_stdio(0);
	
	//udefget(Z);
	//udefget(m);

	int Z, m, n;

	srand(time(0));

	Z = 2000000;
	m = rand()%999999999 + 1;

	while(Z--){
	clearar();
	n = rand()%999999999 + 1;
	divnat(n);

	unsigned long long int sum = 0;

	for(int i=0; outArray[i]; i++)sum += outArray[i];

	cout << sum%m << endl;
	}
	return 0;
	}