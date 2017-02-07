#define DBiG
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

struct vrt {
	short x,y;
	vrt* p;
	bool v;
	char et;
};

int n;
const int maxn=1003;
vrt t[maxn][maxn];
char buf[maxn];
vrt* pstart;
vrt* pend;

struct cStack {
	int sptr;
	vrt* sd[maxn];
	void init() { sptr=0; }
	void push(vrt* v) { sd[sptr++]=v; }
	vrt* pop() { return sd[--sptr]; }
	bool empty() { return sptr==0; }
};

cStack s;

void readData() {
	scanf("%d\n", &n);
	for(int y=n; y>=1; y--) {
		fgets(buf,n+2,stdin);
		for(int x=1; x<=n; x++) {
			t[x][y].x=x;
			t[x][y].y=y;
			t[x][y].v=0;
			t[x][y].p=0;
			t[x][y].et=buf[x-1];
		}
	}
	s.init();
	pstart=&t[1][1];
	for(int i=0; i<=n+1; i++) t[0][i].v=t[n+1][i].v=t[i][0].v=t[i][n+1].v=1;
}

bool dfsgo(vrt* v, int x, int y) {
	if(t[x][y].v) return 0;
	t[x][y].v=1;
	t[x][y].p=v;
	s.push(&t[x][y]);
	return 1;
}

void dfs() {
	s.push(pstart);
	pstart->v=1;
	while(!s.empty()) {
		vrt* v = s.pop();
		REP("dfsvisit "<<v->x<<" "<<v->y<<" "<<v->et);
		if(v->et=='k') {
			pend=v;
			break;
		}
		if(v->et=='.') {
			dfsgo(v,v->x,v->y+1);
			dfsgo(v,v->x,v->y-1);
			dfsgo(v,v->x+1,v->y);
			dfsgo(v,v->x-1,v->y);
		} else {
			int x,y;
			if(v->et=='g') { x=v->x; y=v->y+1; }
			if(v->et=='d') { x=v->x; y=v->y-1; }
			if(v->et=='l') { x=v->x-1; y=v->y; }
			if(v->et=='p') { x=v->x+1; y=v->y; }
			dfsgo(v,x,y);
		}	
	}
}

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		readData();
		dfs();
		s.init();
		vrt* a=pend;
		while(a) {
			s.push(a);
			a=a->p;
		}
		printf("%d\n", s.sptr);
		while(!s.empty()) {
			a=s.pop();
			printf("%d %d\n", a->x, a->y);
		}
	}
	return 0;

}
