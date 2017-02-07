#include <iostream>
using namespace std;

int wyniki[10000][10000];
int ciagi[10000];

int mini( int l, int lp ) {
  if(l==0 || l>lp) return lp;
  return l;
}

int main() {
 int Z;
 cin>>Z;
 while(Z--) {
   int N;
   cin>>N;
   int nawias=0;
   for(int i=0;i<N;i++) {
      cin>>ciagi[i];
      for(int j=0;j<N;j++) wyniki[i][j]=0;
      
   }
    
    for(int i=1;i<N;i++) {
      //cout<<"Typ: "<<i<<endl;
      int kupa=0;
      for(int l=0;l<=i;l++) kupa+=ciagi[l];
      for(int j=0;j<(N-i);j++) {
         
         for(int k=j;k<(j+i); k++) {
            int suma=0;
            suma+=wyniki[j][k];
            suma+=wyniki[k+1][j+i];
            suma+=kupa;
            //cout<<suma<<endl;
            wyniki[j][j+i]=mini( wyniki[j][j+i],suma );
         }
         kupa-=ciagi[j];
         kupa+=ciagi[j+i+1];
      }
    }
   

   cout<<wyniki[0][N-1]<<" "<<nawias<<endl;
 
 }
 return 0;
} 
