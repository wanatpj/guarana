#include<iostream>
using namespace std;
typedef long long ll;

const int N = 50001;
const int K = 5134;
int liczby[K];
bool pier[N];
int n,m,ind;
ll wynik;

void sito(){
  for(int i=2;i<N;i++)
    pier[i] = true;
  for(int i=2;i*i<N;++i){
    if(pier[i]){
      for(int j=i*i;j<N;j += i)
        pier[j] = false;
    }
  }
  int ile = 0;
  for(int i=2;i<N;i++)
    if(pier[i])
      liczby[++ile] = i;
}

main(){
  sito();
  int t;
  scanf("%d %d",&t,&m);
  while(t--){
    scanf("%d",&n);
    ind =0;
    wynik = 1;
    for(int j=1;liczby[j]*liczby[j] <= n;j++){
      if(n%liczby[j] == 0){
        ll dzielnik = 1, temp = 1;
        while(n%liczby[j] == 0){
          temp *= liczby[j];
          n /= liczby[j];
          dzielnik += temp;
        }
        wynik *= dzielnik;
        wynik %= m;
      }
    }
    if(n>1){
      wynik *= (n+1);
      wynik %= m;
    }
    printf("%d\n",wynik);
  }
}
