#define DBiG
// Grzegorz Guspiel 1e
// V-LO Krakow

#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef DBG
#define REPORT(s) cout<<s<<endl
#else
#define REPORT(s)
#define NDEBUG
#endif

const double eps=10e-9;
typedef long long lld;

lld sgn(lld x) {
	if(!x) return 0;
	if(x<0) return -1;
	return 1;
}

lld ll(int x) {
	return ((lld)x);
}

bool iszero(double a) {
	return a>=-eps&&a<=eps;
}

struct cPointI {
	int x,y;
	cPointI() {}
	cPointI(int xx, int yy): x(xx), y(yy) {}
	lld operator*(const cPointI& rhs) const {
		return ((lld)x)*rhs.y-((lld)y)*rhs.x;
	}
	bool operator==(const cPointI& rhs) const {
		return x==rhs.x&&y==rhs.y;
	}
	cPointI operator-(const cPointI& rhs) const {
		cPointI r=*this;
		r.x-=rhs.x;
		r.y-=rhs.y;
		return r;
	}
	bool operator<(const cPointI& rhs) const {
		if(x==rhs.x) return y<rhs.y;
		return x<rhs.x;
	}
	bool intri(vector<cPointI> t) {
		int va=sgn((*this-t[0])*(t[1]-t[0]));
		int vb=sgn((*this-t[1])*(t[2]-t[1]));
		int vc=sgn((*this-t[2])*(t[0]-t[2]));
		return va==vb&&vb==vc&&vc==va;
	}
};

struct cPointD {
	double x,y;
	cPointD() {}
	cPointD(double xx, double yy): x(xx), y(yy) {}
	cPointD(cPointI i): x(i.x), y(i.y) {}
	bool operator==(const cPointD& rhs) const {
		return iszero(x-rhs.x)&&iszero(y-rhs.y);
	}
};

struct cSegmentI {
	cPointI a, b;
	cSegmentI() {}
	cSegmentI(cPointI aa, cPointI bb): a(aa), b(bb) {}
	cSegmentI(int x1, int x2, int y1, int y2): a(x1,y1), b(x2,y2) {}
	vector<cPointD> intersection(cSegmentI r) {
		vector<cPointD> w;
		int w1=sgn((b-a)*(r.a-a));
		int w2=sgn((b-a)*(r.b-a));
		int v1=sgn((r.b-r.a)*(a-r.a));
		int v2=sgn((r.b-r.a)*(b-r.a));
		if(w1*w2>0||v1*v2>0) return w;
		cPointI pt1=a;
		cPointI pt2=b;
		cPointI lt1=r.a;
		cPointI lt2=r.b;
		if(!w1&&!w2) {
			if(pt2<pt1) swap(pt2,pt1);
			if(lt2<lt1) swap(lt2,lt1);
			if(pt2<lt1||lt2<pt1) return w;
			if(pt2==lt1) w.push_back(cPointD(pt2.x,pt2.y));
			else if(pt1==lt2) w.push_back(cPointD(lt2.x,lt2.y));
			else {
				w.push_back(pt1<lt1 ? lt1 : pt1);
				w.push_back(pt2<lt2 ? pt2 : lt2);
			}
		}
		else if(lt1==lt2) w.push_back(lt1);
		else if(pt1==pt2) w.push_back(pt2);
		else {
			double t = double(ll(lt2.x-pt2.x)*(lt1.y-lt2.y)-ll(lt2.y-pt2.y)*(lt1.x-lt2.x))/double(ll(pt1.x-pt2.x)*(lt1.y-lt2.y)-ll(pt1.y-pt2.y)*(lt1.x-lt2.x));
			w.push_back(cPointD(t*pt1.x+(1.0-t)*pt2.x, t*pt1.y+(1.0-t)*pt2.y));
		}
		return w;
	}
};

double area(vector<cPointD> v) {
	double a=0;
	int s=v.size();
	for(int i=0; i<s; i++) a+=(v[i].x+v[(i+1)%s].x)*(v[i].y-v[(i+1)%s].y);
	if(a<0) return a/-2;
	return a/2;
}

int main()
{
	cPointI in[7];
	for(int i=1; i<=6; i++)
		scanf("%d %d", &in[i].x, &in[i].y);
	vector<cPointD> all;
	for(int i=1; i<3; i++) for(int j=i+1; j<=3; j++)
	for(int k=4; k<6; k++) for(int l=k+1; l<=6; l++) {
		vector<cPointD> r = cSegmentI(in[i],in[j]).intersection(cSegmentI(in[k],in[l]));
		all.insert(all.end(), r.begin(), r.end());
	}
	vector<cPointI> ti[2];
	for(int i=1; i<=3; i++) ti[0].push_back(in[i]);
	for(int i=4; i<=6; i++) ti[1].push_back(in[i]);
	for(int i=1; i<=3; i++) if(in[i].intri(ti[1])) all.push_back(in[i]);	
	for(int i=4; i<=6; i++) if(in[i].intri(ti[0])) all.push_back(in[i]);	
	for(int i=0; i<all.size()-1; i++)
		for(int j=i+1; j<all.size(); j++)
			if(all[i]==all[j]) { all.erase(all.begin()+j); j--; }
	vector<cPointD> t[2];
	for(int i=1; i<=3; i++) t[0].push_back(in[i]);
	for(int i=4; i<=6; i++) t[1].push_back(in[i]);
	for(int i=0; i<all.size(); i++) REPORT("all "<<all[i].x<<" "<<all[i].y);
	REPORT("1 "<<area(t[0])<<" 2 "<<area(t[1]));
	REPORT("wspolne "<<area(all));
	printf("%.5lf\n", area(t[0])+area(t[1])-area(all));
	return 0;
}

