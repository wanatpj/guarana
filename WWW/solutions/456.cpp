#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector<int> primes;
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
		if ( prime[i] ) primes.push_back(i);
	}
}

int main(){

sitko();

//cout << "zasiane" << endl;

int d; long long m; scanf("%d %lld", &d, &m); 
while(d--){
	int n; scanf("%d", &n);
	long long cnt = 1;
	int sq = sqrt(n);
	
	//cout << "============== przypadek testowy : " << n << endl;
	
	bool pr = true;
	
	
	for ( vector<int>::iterator i=primes.begin(); ( i!=primes.end() && (*i)<=sq ); ++i ){
	
		//cout << "liczba pierwsza: " << *i << endl;
	
		int a = 0;
		long long tmp = 1;
		long long pp = 1;
		//cout << "n " << n << endl;
		
		while ( n % (*i) == 0 ){
			++a;
			n /= (*i);
			pp *= (*i);
			tmp += pp;
			//cout << "zwiekszone o " << pp << endl;
		}
		
		//cout << "tmp " << tmp << endl;
		
		if ( a > 0 ) {
		pr = false;
			cnt *= ( tmp % m );
			cnt %= m;
		}
	}
	
	if (pr)
	{
		cnt = n + 1;
		cnt = cnt % m;
	}
	
	printf("%lld\n", cnt);
}

return 0;
}

