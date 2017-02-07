//heureza
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    long long ma=0,mi=0;
    long long t,s=0;
    for(int i=0;i<n;i++){
        scanf("%lld", &t);
        s+=t;
        if(t>0) ma = max(ma, s);
        else mi = min(mi, s);
    }
    printf("%lld", ma-mi);
    return 0;
}