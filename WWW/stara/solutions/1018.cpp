#include <iostream>
using namespace std;
struct osk {
 int in,out,last;
 bool nw;
};
long long wj[20000][3]; 
osk tab[10001];
long long max2=0;

long long maximum2(long long x, long long y) {
   if(x>y) return x;
   return y;
}

int main() {
 ios_base::sync_with_stdio(0);
 int Z;
 cin>>Z;
 while(Z--) {
   int l,z;
   cin>>l>>z;
   max2=0;
   for(int i=1;i<=l;i++) {
      tab[i].out=0;
      tab[i].in=0;
      tab[i].last=0;
      tab[i].nw=0;
   }
   for(long long i=0;i<z;i++) {
      //wj[i][1]=0;
      cin>>wj[i][0];
      char kupa;
      cin>>kupa;
      cin>>wj[i][2];
      if(kupa=='W') {
        wj[i][1]=2;
        if( tab[ wj[ i ][ 0 ] ].last !=0 ) tab[ wj[ i ][ 0 ] ].out++;
        else tab[ wj[ i ][ 0 ] ].last = (long long)wj[i][2];
      }else if(kupa=='P') {
         if( wj[ wj[i][2]-1 ][1] == 2 ) {
         wj[i][1]=2;
         wj[i][2]=wj[ wj[i][2]-1 ][2];
         if( tab[ wj[ i ][ 0 ] ].last !=0 ) tab[ wj[ i ][ 0 ] ].out++;
         else tab[ wj[ i ][ 0 ] ].last = (long long)wj[i][2];
         }else if( wj[ wj[i][2]-1 ][1] == 0 ) {
            wj[i][1]=0;
            wj[i][2]=wj[ wj[i][2]-1 ][2];
            if( wj[ wj[i][2]-1 ][ 2 ] != wj[i][0] ) tab[ wj[ wj[i][2]-1 ][ 2 ] ].in--;
             else tab[ wj[ wj[i][2]-1 ][ 2 ] ].nw=1;
         }
      }
      else {
          wj[i][1]=0;
          if( wj[ wj[i][2]-1 ][ 1 ] == 2 && wj[ wj[i][2]-1 ][ 2 ] == tab[ wj[i][0] ].last && tab[ wj[i][0] ].out==0 ) 
               tab[ wj[i][0] ].out++;
          else if( wj[ wj[i][2]-1  ][ 1 ] == 0 ) {
               wj[i][1]=2;
               wj[i][2]= wj[ wj[ wj[i][2]-1 ][ 2 ]-1 ][ 2 ];
               if( tab[ wj[ i ][ 0 ] ].last !=0 )tab[ wj[ i ][ 0 ] ].out++;
               else tab[ wj[ i ][ 0 ] ].last = (long long)wj[i][2];
          }else {
            // if( wj[ wj[i][2]-1 ][ 2 ] != wj[i][0] ) tab[ wj[ wj[i][2]-1 ][ 2 ] ].in--;
            // else tab[ wj[ wj[i][2]-1 ][ 2 ] ].nw=1;
          }
      }
   }

   for(int i=0;i<z;i++) {
      if( wj[ i ][1]==2 && tab[ wj[ i ][0] ].out==0 ) {
        // if( wj[ i ][0]!=wj[ i ][2] || tab[ wj[ i ][0] ].nw!=1  ) {
         tab[ wj[ i ][2] ].in++;
         max2=maximum2( max2,tab[ wj[ i ][2] ].in );
          //}
         //cout<<"dodaje: "<<wj[ i ][0]<<endl; 
      }
   }
   
   for(int i=1;i<=l;i++) {
    if(tab[i].in==max2) cout<<i<<" ";
   }
   cout<<endl;
   //cout<<endl<<"MAX : "<<max2<<endl;
 /*  for(long long i=1;i<=l;i++) {
    cout<<tab[i].in<<endl;
   }*/

 }
 return 0;
}
