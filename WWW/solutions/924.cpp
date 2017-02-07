#include <iostream>
#include <algorithm>
using namespace std;

int tab[10000];

long long suma;

int main() {
  ios_base::sync_with_stdio(0);
  int Z;
  cin>>Z;
  while(Z--) {
    
    int N,il;
    cin>>N;
    il=0;
    suma =0;
    for(int i=0;i<N;i++) {
       cin>>tab[i];     
    }
    if(N==1) {
      cout<<tab[0]<<endl;
      continue;
    }
    sort(tab,tab+N);
    suma+=tab[1];
    int i=2;
    if( N%2 == 1) { suma+=tab[2] + tab[0];i++; }
    for(;i<N;i+=2) {
       if( tab[i] <= 2*tab[1] - tab[0] ) suma+= tab[i]+tab[i+1]+2*tab[0];
       else suma+= tab[i+1] + tab[0] + 2 * tab[1];
    }
    
    cout<<suma<<endl;
  
  }
  return 0;
}
