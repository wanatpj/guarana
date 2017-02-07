#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <sstream>
#include <bitset>
using namespace std;

typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef long double D;

const int INF = 1000*1000*1000+1;
#define FOR(x,b,e) for (int x = (b); x < (e); ++x)
#define FORD(x,b,e) for (int x = (b); x >= (e); --x)
#define REP(x,n) for (int x = 0; x < (n); ++x)
#define VAR(v,n) __typeof(n) v = (n)
#define ALL(c) c.begin(), c.end()
#define SIZE(x) (int)x.size()
#define FOREACH(i,c) for (VAR(i,c.begin()); i != c.end(); ++i)
#define PB push_back
#define ST first
#define ND second
const int N = 3;
LD x1[N], yz[N], x2[N], y2[N];

inline D vp0(D x1, D y1, D x2, D y2) { return x1*y2-x2*y1; }
inline D vp(D x1, D y1, D x2, D y2, D x3, D y3) { return vp0(x2-x1,y2-y1,x3-x1,y3-y1); }

inline bool on_segment(D x1, D y1, D x2, D y2, D x, D y) { 
	return (min(x1,x2) <= x && x <= max(x1,x2) && min(y1,y2) <= y && y <= max(y1,y2) );
}
typedef pair<D,D> PD;
vector<PD> pt;

inline int segments_intersect(D x1, D y1, D x2, D y2, D x3, D y3, D x4, D y4) {
	D d1 = vp(x3,y3,x4,y4,x1,y1);
	D d2 = vp(x3,y3,x4,y4,x2,y2);
	D d3 = vp(x1,y1,x2,y2,x3,y3);
	D d4 = vp(x1,y1,x2,y2,x4,y4);
	if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
	   return 5;	
	else if (d1 == 0 && on_segment(x3,y3,x4,y4,x1,y1)) return 1;
	else if (d2 == 0 && on_segment(x3,y3,x4,y4,x2,y2)) return 2;
	else if (d3 == 0 && on_segment(x1,y1,x2,y2,x3,y3)) return 3;
	else if (d4 == 0 && on_segment(x1,y1,x2,y2,x4,y4)) return 4;
	else return 0;
}
inline void intersect_point(D x1, D y1, D x2, D y2, D x3, D y3, D x4, D y4) {
	if (vp0(x2-x1,y2-y1,x4-x3,y4-y3) == 0) return;
	int r = segments_intersect(x1,y1,x2,y2,x3,y3,x4,y4);
	if (r == 0) return;
	else if (r == 1) { pt.PB(PD(x1,y1)); return; }
	else if (r == 2) { pt.PB(PD(x2,y2)); return; }
	else if (r == 3) { pt.PB(PD(x3,y3)); return; }
	else if (r == 4) { pt.PB(PD(x4,y4)); return; }
	if (x3 == x4) { swap(x1,x3); swap(y1,y3); swap(x2,x4); swap(y2,y4); }
	D a1, b1, a2, b2;
	a2 = (y4-y3)/(x4-x3);
	b2 = y3-(y4-y3)*x3/(x4-x3);
//	cout << "XY " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << endl;
//	cout << "A2 B2 " << a2 << ' ' << b2 << endl;
	bool ver = (x1 == x2);
	D xp, yp;
	if (ver) { xp = x1; yp = a2*x1+b2; }
	else {
		D a1 = (y2-y1)/(x2-x1);
		D b1 = y1-(y2-y1)*x1/(x2-x1);
//		cout << "A1 B1 " << a1 << ' ' << b1 << endl;
		xp = (b2-b1)/(a1-a2);
		yp = a1*xp+b1;
	}
//	cout << "XYP " << xp << ' ' << yp << endl;
//		if (on_segment(x1,y1,x2,y2,xp,yp) && on_segment(x3,y3,x4,y4,xp,yp))
//		{
//			if (r == 0) while (1);
			pt.PB(PD(xp,yp));
//		}
}

inline D surf(D x1, D y1, D x2, D y2, D x3, D y3) { 
	return fabs(vp(x1,y1,x2,y2,x3,y3))/2;
}
inline bool inside(D x1, D y1, D x2, D y2, D x3, D y3, D x, D y) {
	return surf(x1,y1,x2,y2,x,y) + surf(x2,y2,x3,y3,x,y) + surf(x3,y3,x1,y1,x,y) == surf(x1,y1,x2,y2,x3,y3);
}
// naklepac segments intersect, i wrzucac zawsze jeśli sie przecinają...
int main() {
	scanf("%llf%llf%llf%llf%llf%llf",&x1[0],&yz[0],&x1[1],&yz[1],&x1[2],&yz[2]);
	scanf("%llf%llf%llf%llf%llf%llf",&x2[0],&y2[0],&x2[1],&y2[1],&x2[2],&y2[2]);
	REP(i,N) REP(j,N) intersect_point(x1[i],yz[i],x1[(i+1)%N],yz[(i+1)%N],x2[j],y2[j],x2[(j+1)%N],y2[(j+1)%N]);
	REP(j,N) if (inside(x1[0],yz[0],x1[1],yz[1],x1[2],yz[2],x2[j],y2[j])) pt.PB(PD(x2[j],y2[j]));
	REP(i,N) if (inside(x2[0],y2[0],x2[1],y2[1],x2[2],y2[2],x1[i],yz[i])) pt.PB(PD(x1[i],yz[i]));
	sort(ALL(pt));
	pt.resize(unique(ALL(pt))-pt.begin());
//	REP(i,SIZE(pt)) cout << pt[i].ST << ' ' << pt[i].ND << endl;
	vector<PII> ed;
	REP(i,SIZE(pt)) REP(j,SIZE(pt)) if (i != j) {
		int k = 0;
		for(; k < SIZE(pt); ++k) if (k != j && k != i)
			if (vp(pt[i].ST,pt[i].ND,pt[j].ST,pt[j].ND,pt[k].ST,pt[k].ND) >= 0)
				break;
		if (k == SIZE(pt)) ed.PB(PII(i,j));
	}
	
//	cout << "EDG:\n"; REP(i,SIZE(ed)) cout << ed[i].ST << ' ' << ed[i].ND << endl;
	D ar = 0;
	REP(i,SIZE(ed)) {
		int i1 = ed[i].ST;
		int i2 = ed[i].ND;
		ar += vp0(pt[i1].ST,pt[i1].ND,pt[i2].ST,pt[i2].ND);
	}
	ar = -fabs(ar)/2;
	ar += surf(x1[0],yz[0],x1[1],yz[1],x1[2],yz[2]);
	ar += surf(x2[0],y2[0],x2[1],y2[1],x2[2],y2[2]);
	printf("%.5llf\n",ar);
	return 0;
}
