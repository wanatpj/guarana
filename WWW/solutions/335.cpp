#include<cstdio>
main(){
  int d,n,i,a;
  scanf("%d",&d);
  while(d--){
    i=0;
    scanf("%d",&n);
    while(n--){
      scanf("%d",&a);
      i += a;
    }
    scanf("%d",&n);
    printf("%d\n",i? n%i : n);
  }
}
