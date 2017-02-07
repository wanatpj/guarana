#include <cstdio>
#include<algorithm>
using namespace std;
int osoby[10001],jeszcze,ostatni,czas,n,z,mniejsze;
void zeruj(){
 for(int i=0;i<n;i++)
  osoby[i]=0;  
}
void ustaw(){
 jeszcze = n-2;
 ostatni=(n-1);
 czas=osoby[1];   
}
int mostek (){
 if(n==1)  return osoby[0];
  ustaw();
  while(jeszcze>1) 
  { mniejsze=osoby[0]+2*osoby[1]+osoby[ostatni];
    if( mniejsze > (2*osoby[0]+osoby[ostatni-1]+osoby[ostatni]) )  break;
   
    czas += mniejsze;
    ostatni-=2;
    jeszcze -= 2;
  }
 czas += jeszcze*osoby[0]; 
 while(jeszcze>0)
  { czas += osoby[ostatni--];
    jeszcze--;
  }
  zeruj();
  return czas;
}

int main()
{scanf("%d",&z);
 while(z--){
   scanf("%d",&n);
   for(int i=0; i<n ;i++) scanf("%d",&osoby[i]);
   sort(osoby,osoby+n); 
   printf("%d\n",mostek());
}
 return 0;
}


