#include<iostream>
using namespace std;
int n;
long long maxi,tmp,a;
main()
{
    scanf("%d",&n);
    maxi=0;
    for(int i=0;i<n;i++) {
        scanf("%lld",&a);
        tmp+=a;
        tmp=max(tmp,0LL);
        maxi=max(tmp,maxi);
    }
    printf("%lld\n",maxi);
    return 0;
}
