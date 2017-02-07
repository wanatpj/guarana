#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int ps = 0;

int primes[ 4500 ];
bool prime[ 35000 ];

void sitko(){
	for (int i=0; i<35000; ++i){
		prime[i] = true;
	}

	for (int i=2; i<35000; ++i){
		if ( prime[i] == false ) continue;
		
		for ( int q=i+i; q<35000; q+=i ){
			prime[q] = false;
		}
	}
	
	for (int i=2; i<35000; ++i){
		if ( prime[i] ) {
			primes[ps] = i;
			++ps;
		}
	}
}

int main(){

sitko();

int d; long long m; scanf("%d %lld", &d, &m); 
while(d--){
	int n; scanf("%d", &n);
	long long cnt = 1;
	int sq = sqrt(n);
	
	long long tmp = 1;
	long long pp = 1;
	int a = 0;
	
	for ( int i=0; ( i<ps && primes[i]<=sq ); ++i ){

		tmp = pp = 1;
		a = 0;
		
		while ( n % (primes[i]) == 0 ){
			n /= (primes[i]);
			pp *= (primes[i]);
			tmp += pp;
		}
		
		if ( tmp > 1 ) {
			tmp %= m;
			cnt *= tmp;
			cnt %= m;
		}
	}
	
	if (n > 1) cnt *= (n+1);
	
	cnt %= m;
	printf("%lld\n", cnt);
}

return 0;
}

