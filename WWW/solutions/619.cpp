#include <iostream>
using namespace std;
int ciagi[2000];
int min_=-1;
int czas=0;
int j=0;
void minimum_(int l) {
  if( (l<min_) || min_ == -1 ) min_=l;
}
 
int main() {
 int Z;
 cin>>Z;
 while(Z--) {
   int N;
   cin>>N;
   czas=0;
   min_=-1;
   j=0;
   int nawias=0;
   for(int i=0;i<N;i++) {
      cin>>ciagi[i];
      j++;
   }
  
   while(j>1) {
  // cout<<"TAB: ";
  // for(int k=0;k<N;k++) cout<<ciagi[k]<<" ";
  // cout<<endl;
   j=0;
   int i=0;
   bool ble=0;
   for(;i<N-1;i++) {
       minimum_(ciagi[i]+ciagi[i+1]);
   }
   //cout<<j<<" "<<czas<<endl;
   for(int i=0;i<N-1;i++) {
       //cout<<"C: "<<ciagi[i]<<" "<<ciagi[i+1]<<endl;
       if(ciagi[i]+ciagi[i+1] == min_) {
       //   cout<<"Sumujemy: "<<ciagi[i]<<" "<<ciagi[i+1]<<endl;
          if(i!=0) nawias++;
          czas+=ciagi[i]+ciagi[i+1];
          ciagi[j++]=ciagi[i]+ciagi[i+1];
          //cout<<"Wylazi: "<<ciagi[i]+ciagi[i+1]<<endl;
          min_=-1;
          
          //cout<<N<<endl;
          if(i+2==N) {ble=1;}
          i++;
       }else {
         ciagi[j++]=ciagi[i];
       }
       
   }
     if(!ble) ciagi[j++]=ciagi[i];
     //cout<<j<<" "<<czas<<endl;
     N=j;
   }
   cout<<czas<<" "<<nawias<<endl;
 
 }
 return 0;
} 
