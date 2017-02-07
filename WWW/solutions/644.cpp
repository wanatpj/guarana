//Maciej Prokopiuk 
//V LO Krk
//Zadanie -1B Ciastka
#include<iostream>
using namespace std;
int main(){ 
	 int u,n,x,suma,a;
	 scanf("%d",&u);
	 while(u--){
	 suma=0;				
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{scanf("%d",&x);
		 suma=suma+x;
	   } 
	 	scanf("%d",&a);
	 	if(suma==0) printf("%d\n",a);
	 	else
		printf("%d\n", a%suma ); 			
		} 
	 return 0;
	 }
