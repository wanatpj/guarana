#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long long t,m=0,r=0,s=0;
    for(int i=0;i<n;i++){
        scanf("%lld", &t);
        s+=t;
        m=min(m,s);
        r = max(r, s-m);
    }
    printf("%lld", r);
    return 0;
}
