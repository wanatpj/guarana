#include<iostream>
using namespace std;

main(){
  int a,b,c,d,f,e,g;
  scanf("%d %d",&a,&b);
  int ile = 0;
  for(int i=1;i<=b;i++){
    scanf("%d %d %d %d %d",&c,&d,&e,&f,&g);
    if(f && !g) ile++;
  }
  printf("%d\n",ile);
}
