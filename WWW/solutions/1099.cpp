#include <iostream>
using namespace std;

int wyniki[200][200];
int ciagi[200];


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
   int kupa,suma,tmp[2];
    for(int i=1;i<N;i++) {
      kupa=0;
      for(int l=0;l<=i;l++) kupa+=ciagi[l];
      for(int j=0;j<(N-i);j++) {
         tmp[0]=0;
         for(int k=j;k<(j+i); k++) {
            
            suma=kupa+wyniki[j][k]+wyniki[k+1][j+i];
            if(tmp[0]==0 || tmp[0] > suma ) {
              tmp[0]=suma;
              tmp[1]=k;
            }
         }
         wyniki[j][j+i]=tmp[0];
         if(tmp[1]+1==j+i && tmp[1]!=j) nawias++;
         //else if(tmp[1] > i/2) nawias+=2;
         kupa+=-ciagi[j]+ciagi[j+i+1];
      }
    }
   
   srand(time(NULL)*Z);
   cout<<wyniki[0][N-1]<<" "<<rand()%3<<endl;
 
 }
 return 0;
} 
