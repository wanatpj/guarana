#define DBG
// autor programu: Grzegorz Guspiel
// 2e, V LO Krakow

#ifdef DBG
#define REP(x) cout<<x<<endl;
#else
#define REP(x)
#endif

#include <iostream>
using namespace std;

// =====================================================
int m;

int t[] = {2,3,5,7,11,13,17,19,23,29,31,37,41 };

typedef long long lld;

lld pot(int a, int b) {

}

int suma(int nr) {
	int n=nr;
	lld s=1;
	for(int i=0; t[i]*t[i]<=nr; i++) {
		int wyk=0;
		while(n%t[i]==0) { wyk++; n/=t[i]; }
		lld p=1;
		wyk++;
		while(wyk) { p*=t[i]; wyk--; }
		p-=1; p/=t[i]-1;
		s=(s*p)%m;
	}
	if(n>1) s=(s*(n+1))%m;
	return s;
}

int main() {
	int z; scanf("%d%d", &z, &m);
	while(z--) {
		int nr; scanf("%d", &nr);
		printf("%d\n", suma(nr));
	}
	return 0;

}
