#include<iostream>
using namespace std;
typedef long long ll;

const ll duzo = 1000000000LL;
const int N = 50001;
const int K = 5134;
const int M = 31;
int liczby[K][M];
int rozkl[K];
int ile[K];
bool pier[N];
int n,m,ind;
int wynik;
bool wiek;

void zeruj(){
  for(int i=1;i<=ind;i++)
    ile[i]=rozkl[i] =0;
}

void dodaj(int roz, int t[]){
  if(roz == ind){
    int dzielnik = 1;
    for(int i=1;i<=ind;i++)
      dzielnik *= liczby[rozkl[i]][t[i]];
    wynik += dzielnik;
    wynik %= m;
    if(wiek){
      dzielnik *= n;
      wynik += dzielnik;
      wynik %= m;
    }
    return;
  }
  else{
    for(int i=0;i<=ile[roz+1];i++){
      t[roz+1] = i;
      dodaj(roz+1,t);
    }
  }
}

void sito(){
  for(int i=2;i<N;i++)
    pier[i] = true;
  for(int i=2;i*i<N;i++){
    if(pier[i]){
      for(int j=2*i;j<N;j += i)
        pier[j] = false;
    }
  }
  int ile = 0;
  for(int i=2;i<N;i++)
    if(pier[i]){
      liczby[++ile][1] = i;
    }
  for(int i=1;i<=5133;i++){
    liczby[i][0] = 1;
    for(int j=2; ll(liczby[i][j-1])*ll(liczby[i][1])<= duzo;j++){
      liczby[i][j] = liczby[i][j-1]*liczby[i][1];
    }
  }
}

main(){
  sito();
  int t;
  scanf("%d %d",&t,&m);
  while(t--){
    scanf("%d",&n);
    ind =0;
    for(int j=1;ll(liczby[j][1])*ll(liczby[j][1]) <= n;j++){
      if(n%liczby[j][1] == 0){
        rozkl[++ind] = j;
	ile[ind] = 0;
	while(n%liczby[j][1] == 0){
	  ile[ind]++;
	  n/=liczby[j][1];
	}
      }
    }
    wiek = n > 1;
    int t[K]={0};
    wynik = 0;
    dodaj(0,t);
    printf("%d\n",wynik);
    zeruj();
  }
}
