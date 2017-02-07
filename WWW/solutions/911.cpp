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

const int maxn=10100;
int t[maxn];

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) 
			scanf("%d", t+i);
		if(n==1) {
			printf("%d\n", t[1]);
			continue;
		}
		sort(t+1,t+n+1);
		int s=(n-2)*t[1]+t[2];
		for(int i=3;i<=n; i++) s+=t[i];
		int m=s;
		for(int i=1; i<=n/2-1; i++) {
			s+=-t[1]+2*t[2]-t[n-2*i+1];
			m=min(m,s);
		}
		printf("%d\n", m);
	}
	return 0;

}
