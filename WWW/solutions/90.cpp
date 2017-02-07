#include <iostream>
#include <vector>
using namespace std;

long long T[2][101000];
long long W[101000];

int main(){
long long n, k, m;

scanf("%lld%lld%lld", &n, &k, &m);

for (int i=0; i<=n+3; ++i) T[0][i] = T[1][i] = 0;
T[0][0] = T[1][0] = 1;

for ( int i=1; i<=n; ++i ){
    for (int j=1; j<=n+2; ++j) T[ i&1 ][j] = ( T[ (i-1)&1 ][j-1] + T[ (i-1)&1 ][j] ) % m;
}

for ( int i=0; i<=n; ++i ) {
    W[i%k] = ( W[ i %k] + T[ n&1 ][i] ) % m;
}

for ( int i=0; i<k; ++i ) printf("%lld\n", W[i]);// printf("\n");

return 0;
}
