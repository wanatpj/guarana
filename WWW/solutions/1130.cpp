#include<iostream>
using namespace std;
int n,a;
long long maxi,tmp;
main()
{
    scanf("%d",&n);
    maxi=0;
    while(n--) {
        scanf("%d",&a);
        tmp+=a;
        tmp=max(tmp,0LL);
        maxi=max(tmp,maxi);
    }
    printf("%lld\n",maxi);
    return 0;
}
