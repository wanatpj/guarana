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
#define release true;
#define cindex(exp) exp+1000000000
#define until(exp1, exp2) for(int exp1 = 0;exp1 < exp2;exp1++)

using namespace std;

struct OBJECT{
	unsigned short int osoba1, osoba2;
	char akcja;

	int oskarzenie;

	OBJECT(unsigned short int osoba1, char akcja, unsigned short int osoba2){
		this->osoba1 = osoba1;
		this->osoba2 = osoba2;
		this->akcja = akcja;
		this->oskarzenie = 0;
		}

	OBJECT(){
		this->osoba1 = this->osoba2 = this->akcja = this->oskarzenie = 0;
		}
	};

OBJECT wejscie[20003];

vector<int> zeznania[10002];
vector<int> uniewinnienia[10002];

unsigned int iloscKlamcow[10002];

int main(){
	dataset(){
		udefget(N);
		udefget(Z);

		until(i, N+1)zeznania[i].clear();
		until(i, N+1)uniewinnienia[i].clear();

		until(i, Z){
			unsigned short int o1, o2;
			char c;
			scanf("%hu %c %hu", &o1, &c, &o2);


			wejscie[i].akcja = c;
			wejscie[i].osoba1 = o1;
			wejscie[i].osoba2 = o2;

			if(c == 'W')wejscie[i].oskarzenie = o2;
			else if(c == 'F')wejscie[i].oskarzenie = wejscie[o2-1].oskarzenie*-1;
			else if(c == 'P')wejscie[i].oskarzenie = wejscie[o2-1].oskarzenie;

			if(wejscie[i].oskarzenie > 0)zeznania[o1].push_back(wejscie[i].oskarzenie);
			else uniewinnienia[o1].push_back(wejscie[i].oskarzenie);

			}

		until(i, N+1)iloscKlamcow[i] = 0;

		until(j, N){
			until(i, N){
				if(zeznania[i+1].size() == 0 && uniewinnienia[i+1].size() == 0)iloscKlamcow[j+1]++;
				else if(zeznania[i+1].size() > 1)iloscKlamcow[j+1]++;
				else if(zeznania[i+1].size() == 1)if(zeznania[i+1][0] != j+1)iloscKlamcow[j+1]++;
				until(k, uniewinnienia[i+1].size())if(uniewinnienia[i+1][k] == (j+1)*-1){iloscKlamcow[j+1]++;break;}
				}
			}

		int min = 30000;
		bool first = true;
		until(i, N)if(iloscKlamcow[i+1] < min)min = iloscKlamcow[i+1];
		until(i, N)if(iloscKlamcow[i+1] == min)
			if(first){cout << i+1;first = false;}
			else cout << " " << i+1;
		cout << endl;
		}

	system("PAUSE");
	return 0;
	}