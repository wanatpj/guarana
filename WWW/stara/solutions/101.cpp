#include <iostream>
using namespace std;

long long T[2][1010];
long long n, m, k;

inline int prev(int i){
    if ( i==0 ) return k-1;
    return i-1;
}

int main(){
scanf("%lld%lld%lld", &n, &k, &m);

for ( int i=0; i<k; ++i ) T[0][i] = T[1][i] = 0;
T[0][0] = 1;

for ( int i=1; i<=n; ++i ){
    for ( int j=0; j<k; ++j ){
        T[ i&1 ][ j ] = ( T[ (i-1)&1 ][ prev(j) ] + T[ (i-1)&1 ][ j ] ) % m;
    }
}

for (int i=0; i<k; ++i) printf("%lld\n", T[ n&1 ][i]);

return 0;
}
