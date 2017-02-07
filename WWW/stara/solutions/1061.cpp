//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <vector>

#define null NULL
#define iget(exp) scanf("%d",&exp);
#define uget(exp) scanf("%u",&exp);
#define usget(exp) scanf("%hu",&exp);
#define gets(exp) scanf("%s",exp);
#define idefget(exp) int exp;scanf("%d",&exp);
#define udefget(exp) unsigned int exp;scanf("%u",&exp);
#define dataset() udefget(z);while(z--)
#define cind_ex(exp) exp+1000000000
#define until(exp1, exp2) for(int exp1 = 0;exp1 < exp2;exp1++)

using namespace std;

int main(){
	dataset(){
		udefget(n);
		unsigned short int *people = new unsigned short int [n+1];
		until(i, n)usget(people[i]);
		if(n == 1){printf("%hu\n", people[0]);continue;}
		else if(n == 2){printf("%hu\n", people[0]+people[1]);continue;}

		unsigned int *wartosci = new unsigned int[n/2];

		for(unsigned int k = 0;k <= n/2-1;k++){
			wartosci[k] = (n - k - 2)*people[0] + (2*k + 1)*people[1];
			for(unsigned int i = 3;i <= n-2*k;i++)wartosci[k] += people[i-1];
			if(k != 0)for(int i = 0;i <= k-1;i++)wartosci[k] += people[n - 2*i-1];
			}

		unsigned int min = 2000000000;
		until(i, n/2)if(wartosci[i] < min)min = wartosci[i];

		cout << min << endl;

		delete[] people;
		delete[] wartosci;
		}
	return 0;
	}