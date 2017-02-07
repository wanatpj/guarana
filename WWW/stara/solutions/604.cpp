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

const int maxn=203;
typedef pair<int,int> pii;
pii t[maxn][maxn];
int s[maxn];
int d[maxn];
int n;

void readData() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", d+i);
	for(int i=0; i<n; i++)  for(int j=i; j<n; j++) t[i][j].first=-1;
	s[0]=d[0];
	for(int i=1; i<n; i++) s[i]=d[i]+s[i-1];
}

inline int sum(int a, int b) {
	return s[b]-s[a]+d[a];
}

inline pii f(int a, int b) {
	if(t[a][b].first>-1) return t[a][b];
	if(a>=b) {
		t[a][b].first=t[a][b].second=0;
		return t[a][b];
	}
	// prawy dl. 1
	t[a][b].first=f(a,b-1).first+f(b,b).first;
	t[a][b].second=f(a,b-1).second;
	pii act,fa,fb;
	for(int i=a+1; i<b; i++) {
		fa=f(a,i-1);
		fb=f(i,b);
		act.first=fa.first+fb.first;
		act.second=fa.second+fb.second+1;
		if(act<t[a][b]) t[a][b]=act;
	}
	t[a][b].first+=sum(a,b);
	return t[a][b];
}

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		readData();
		pii res = f(0,n-1);
		printf("%d %d\n", res.first, res.second);
	}
	return 0;

}