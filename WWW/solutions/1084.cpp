#include <cstdio>
#include <algorithm>
using namespace std;

int tab[10001];
int n,z;
int ret1=0,sum,t,ret2=0,ret,wsk;

void doit()
{
scanf("%d", &n); sum=0;
ret=0; wsk=n-1;
for(int i=0; i<n; i++) {
    scanf("%d", &tab[i]);
    sum+=tab[i];
}
sort(tab,tab+n);
while(wsk>=3) {
    ret+=tab[0]+tab[wsk];
    ret+=min(2*tab[1],tab[0]+tab[wsk-1]);
    wsk-=2;
}
if (wsk==1) ret+=max(tab[0],tab[1]);
else ret+=tab[0]+tab[1]+tab[2];
printf("%d\n", ret);


}

int main()
{
scanf("%d", &z); while(z--) doit();
return 0;
}
