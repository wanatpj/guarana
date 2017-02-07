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
int s[maxn][maxn];
int d[maxn];
int n;

void readData() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", d+i);
	for(int i=0; i<n; i++)  for(int j=0; j<n; j++) t[i][j].first=s[i][j]=-1;
}

int sum(int a, int b) {
	if(s[a][b]>-1) return s[a][b];
	if(a>b) {
		s[a][b]=0;
		return s[a][b];
	} else if(a==b) {
		s[a][b]=d[a];
		return s[a][b];
	}
	s[a][b]=sum(a,b-1)+sum(b,b);
	return s[a][b];
}

pii f(int a, int b) {
	if(t[a][b].first>-1) return t[a][b];
	if(a>=b) {
		t[a][b].first=t[a][b].second=0;
		return t[a][b];
	}
	// prawy dl. 1
	t[a][b].first=sum(a,b-1)+sum(b,b)+f(a,b-1).first+f(b,b).first;
	t[a][b].second=f(a,b-1).second;
	for(int i=a+1; i<b; i++) {
		pii act;
		act.first=sum(a,i-1)+sum(i,b)+f(a,i-1).first+f(i,b).first;
		act.second=f(a,i-1).second+f(i,b).second+1;
		if(act<t[a][b]) t[a][b]=act;
	}
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
