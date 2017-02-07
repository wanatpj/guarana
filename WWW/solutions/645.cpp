//Maciej Prokopiuk 
//V LO Krk
//Zadanie -1A Wejscie Mikolaja
#include<cstdio>
int main(){
	 int u,n,x,y,z,suma,a;
	 scanf("%d %d",&u,&a);
	 while(u--){
	 scanf("%d %d %d",&x,&y, &z);
	 if(x>a) printf("komin\n");
	 else if(y>a) printf("okno\n");
	 else if(z>a) printf("drzwi\n");
	 else printf("brak\n");
	 }
	 return 0;
	 }
