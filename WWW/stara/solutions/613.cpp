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

int suma(int nr) {
	int n=nr;
	int s=0;
	for(int i=1; i*i<=n; i++) if(n%i==0) {
		s=(s+i)%m;
		if(i*i<n) s=(s+n/i)%m;
	}
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