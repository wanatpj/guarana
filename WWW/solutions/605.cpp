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
//	for(int i=0; i<n; i++)  for(int j=i; j<n; j++) t[i][j].first=-1;
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
	{
	pii act,fa,fb,best;
	best.first=f(a,b-1).first+f(b,b).first;
	best.second=f(a,b-1).second;
	for(int i=a+1; i<b; i++) {
		fa=f(a,i-1);
		fb=f(i,b);
		act.first=fa.first+fb.first;
		act.second=fa.second+fb.second+1;
		if(act<best) best=act;
	}
	best.first+=sum(a,b);
	t[a][b]=best;
	return t[a][b];
	}
}

void dynamicProgram() {
	for(int i=0; i<n; i++) t[i][i].first=t[i][i].second=0;
	pii* act;
	pii ch;
	for(int l=2; l<=n; l++) for(int i=0; i+l-1<n; i++) {
		act=&t[i][i+l-1];
		act->first=t[i][i+l-2].first+t[i+l-1][i+l-1].first;
		act->second=t[i][i+l-2].second;
		for(int j=i+1; j<i+l-1; j++) {
			ch.first=t[i][j-1].first+t[j][i+l-1].first;
			ch.second=t[i][j-1].second+t[j][i+l-1].second+1;
			if(ch<*act) *act=ch;
		}
		act->first+=sum(i,i+l-1);
	}
}

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		readData();
		//pii res = f(0,n-1);
		dynamicProgram();
		pii res=t[0][n-1];
		printf("%d %d\n", res.first, res.second);
	}
	return 0;

}
