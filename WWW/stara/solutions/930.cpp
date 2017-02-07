#include <cstdio>
#include<algorithm>
using namespace std;
int n,z,czas,mniejszy,wiekszy,jeszcze,ostatni,osoby[10001];
void zeruj(){
 for(int i=0;i<n;i++)
  osoby[i]=0;  
}
void ustaw(){
 ostatni=n-1;
 jeszcze=n-2;  
 czas=osoby[1];
}
int mostek(){
 if(n==1)  return osoby[0];  
 ustaw(); 
 while(jeszcze>1) 
  { mniejszy=osoby[0]+osoby[ostatni]+ (2*osoby[1]);
    wiekszy=(2*osoby[0])+osoby[ostatni]+osoby[ostatni-1];
   if( mniejszy < wiekszy )
   czas += mniejszy ; //wraca najszybszy 
   ostatni-=2;
   jeszcze-=2;  
  } 
 while(jeszcze>0){
   czas += osoby[ostatni--]+osoby[0]; //najszybszy i pozostali
   jeszcze--;
 }
 zeruj();
return czas;
}
int main()
{scanf("%ld",&z); 
 while(z--){
 scanf("%ld",&n); 
 for(int i=0; i<n ;i++) scanf("%ld",&osoby[i]);
 sort(osoby, osoby+n);
 printf("%ld\n",mostek());
}
 return 0;
}

