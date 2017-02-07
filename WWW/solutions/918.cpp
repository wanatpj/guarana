#include <iostream>
#include <algorithm>
using namespace std;

int tab[10000];

int mini[2];
int maxi[2];
long long suma;

int max2( int l1, int l2 ) {
  if( l1>l2 ) return l1;
  return l2;
 
}
int min2( int l1, int l2 ) {
  if( l1<l2 ) return l1;
  return l2;
 
}
int main() {
  ios_base::sync_with_stdio(0);
  int Z;
  cin>>Z;
  while(Z--) {
    
    int N,il;
    cin>>N;
    il=0;
    suma =0;
    int suma2=0;
    for(int i=0;i<N;i++) {
       cin>>tab[i];     
    }
    sort(tab,tab+N);
    for(int i=1;i<N;i++) {
       suma2+=tab[i];   
    } 
    suma2+=tab[0]*(N-2);
    mini[0]=tab[0];
    mini[1]=tab[1];
    tab[0]=0;
    tab[1]=0;
    il+=2;
    suma+=max2( mini[0],mini[1] );
    while( il < N ) {
      suma+=mini[0];
      if( N-2>=il ) { suma+=max2( tab[ N-1 ], tab[ N-2 ]  );
          suma+=mini[1];
          suma+=max2( mini[0],mini[1] );
      }else {
          suma+=tab[ N-1 ];
      }
      N-=2;
    }
    
    cout<<min2(suma,suma2)<<endl;
  
  }
  return 0;
}
