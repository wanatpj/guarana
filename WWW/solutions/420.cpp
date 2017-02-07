#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
int d; long long m; scanf("%d %lld", &d, &m); 
while(d--){
	int n; scanf("%d", &n);
	int sq = sqrt( n );
	long long cnt = 0;
	for (int i=1; i<sq; ++i){
		if ( n%i == 0 ) {
			cnt += i;
			cnt += (n/i);
			cnt %= m;
		}
	}
	
	if ( n%sq == 0 ) {
		cnt += sq;
		if ( sq != (n/sq) ) cnt += (n/sq);
		cnt %= m;
	}
	
	printf("%lld\n", cnt);
}

return 0;
}

