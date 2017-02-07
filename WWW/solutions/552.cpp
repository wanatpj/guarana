#include<iostream>
#include<math.h>
using namespace std;

const int SIZE = 1000000010;
const int MAX = 32000;
int c,m,n;
//ilosc liczb pierwszych
int fn;
bool first[MAX];
int firstlist[MAX];
//ilosc liczb pierwszych dla danej liczby
int f;
int firstn[MAX];
void sito(){
	for(int i = 0 ; i < MAX ; ++i)
		first[i] = 1;
	for(int i = 2 ; i < MAX ; ++i){
		if(first[i] == 1){
			int z = i*i;
			while(z < MAX){
				first[z] = 0;
				z+=i;
			}
		}
	} 
	fn = 0;
	for(int i = 2 ; i < MAX ; ++i)
		if(first[i])
			firstlist[fn++] = i;
}
void firstnfill(){
	f = 0;
	int aktn = n;
	for(int i = 0 ; i < fn && aktn > 1; ++i){
		while(!(aktn%firstlist[i])){
			//printf("n: %d, firstlist[%d]: %d\n", aktn,i,firstlist[i]);
			firstn[f++] = firstlist[i];
			aktn/=firstlist[i];
		}
	}
	if(aktn > 1) firstn[f++] = aktn;
}
int result(){
	long long wynik = 1;
	firstn[f] = 1000000000;
	for(int i = 0 ; i < f ; ++i){
		long long tmp = wynik;
		//wynik=(wynik + wynik*(long long)firstn[i]);
		int w = i+1;
		wynik*=(long long)firstn[i];
		while(firstn[i] == firstn[w]){
			wynik%=m;
			tmp+=wynik;
			tmp%=m;
			wynik*=(long long)firstn[w];	
			w+=1;
		}
		wynik+=tmp;
		i = w-1;
		wynik%=m;
	}
	return wynik;
}
//*/
int main(){
	sito();
	//printf("%d\n",MAX*MAX);
	scanf("%d%d",&c,&m);
	//for(int i = 0 ; i < fn ; ++i) printf("%d\n",firstlist[i]);
	while(c--){
		scanf("%d",&n);
		firstnfill();
		printf("%d\n",result());
	}//*/

	return 0;
}

