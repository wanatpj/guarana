//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>
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

#define MAX1 103
#define MAX2 103

int primeArray[MAX1][MAX1];                                     // tablica dzielnikow pierwszych
int outArray[MAX2];                                             // tablica wszystkich dzielnikow
int ind_ex;                                                      // zmienna pomocnicza

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
      outArray[ind_ex++] = value*primeArray[row][i];
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
  ind_ex = 0;
  add(1, 0, row);
}

int main(){  
	udefget(Z);
	udefget(m);

	while(Z--){
	clearar();
	udefget(n)
	if(n == 1){
		printf("1\n");
		continue;
		}
	divnat(n);

	unsigned long long int sum = 0;

	for(int i=0; outArray[i]; i++)sum += outArray[i];

	if(sum <= m)printf("%d\n", sum);
	else printf("%d\n", sum%m);
	}

	//system("PAUSE");
	return 0;
	}