#include<iostream>
using namespace std;

main(){
  int n, mikolaj;
  scanf("%d %d",&n,&mikolaj);
  int komin,okno,drzwi;
  for(int i=1;i<=n;i++){
    scanf("%d %d %d",&komin,&okno,&drzwi);
    if(mikolaj < komin) printf("komin\n");
    else if(mikolaj < okno) printf("okno\n");
    else if(mikolaj < drzwi) printf("drzwi\n");
    else printf("brak\n");
  }
}
