#include <cstdio>
#include <algorithm>

using namespace std;

long long T[10001];

long long min(long long a,long long b) {
    if(a < b) return a;
    return b;
}

long long c(long long i) {
    if(i == 2) return T[2];
    if(i == 3) return T[1]+T[2]+T[3];
    if(i == 1) return T[1];
    return min(c(i-2)+T[1]+2*T[2]+T[i],c(i-1)+T[1]+T[i]);
}

int main() {
    long long z,n;
    for(scanf("%lld",&z);z>0;z--) {
       scanf("%lld",&n);
       for(int i=1;i<=n;i++) scanf("%lld",&T[i]);
       sort(T,T+n);
       printf("%lld\n",c(n));
    }
    return 0;
}
