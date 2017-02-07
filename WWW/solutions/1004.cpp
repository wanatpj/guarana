#define DBiG
// autor programu: Grzegorz Guspiel
// 2e, V LO Krakow

#ifdef DBG
#define REP(x) cout<<x<<endl;
#else
#define REP(x)
#endif

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// =====================================================

typedef long long lld;
const int inf=1000000000;
const int maxZones=1<<4;
const int maxSegments=1<<16;
const int maxVal=(1<<2);
const int maxSum=(1<<8);

struct cPoint {
	int x,y;
	bool operator<(const cPoint& rhs) const {
		if(x==rhs.x) return y<rhs.y;
		return x<rhs.x;
	}
	bool operator==(const cPoint& rhs) const {
		return x==rhs.x&&y==rhs.y;
	}
	lld operator*(const cPoint& rhs) const {
		return ((lld)x)*rhs.y-((lld)y)*rhs.x;
	}
	cPoint operator-(const cPoint& rhs) const {
		cPoint res;
		res.x=x-rhs.x;
		res.y=y-rhs.y;
		return res;
	}
};
	struct cRange {
		int a,b;
		cRange() {}
		cRange(int aa, int bb): a(aa), b(bb) {}
		cRange intersection(const cRange& rhs) const {
			cRange r;
			r.a=max(a,rhs.a);
			r.b=min(b,rhs.b);
			return r;
		}
		bool belongs(int x) {
			return x>=a&&x<=b;
		}
		bool empty() {
			return a>b;
		}
	};

struct cSegment {
	cPoint a,b; 
	int insideUp;
	int zone,uid;
	bool operator==(const cSegment& rhs) const {
		return a==rhs.a&&b==rhs.b;
	}
	bool pointBelongs(const cPoint p) const {
		// TODO swap ab
		return (p-a)*(b-a)==0 && p.x>=a.x && p.x<=b.x;
	}
	bool onLine(const cSegment& rhs) const {
		//return (pointBelongs(rhs.a)||pointBelongs(rhs.b))&&(rhs.pointBelongs(a)||rhs.pointBelongs(b))&&(rhs.a-a)*(b-a)==0 && (rhs.b-a)*(b-a)==0;
		return (rhs.a-a)*(b-a)==0 && (rhs.b-a)*(b-a)==0;
	}
	int hi() const {
		return max(a.y,b.y);
	}
	int lo() const {
		return min(a.y,b.y);
	}
	cRange range()const { return cRange(a.x,b.x); }
	bool operator<(const cSegment& rhs) const {
		bool r;
		if(onLine(rhs)) {
			r= !insideUp;
			REP("UUU "<<uid<<" "<<rhs.uid);
			if(insideUp==rhs.insideUp) r= uid<rhs.uid;
		}
		else {
			cRange inter = range().intersection(rhs.range());
			if(inter.b>inter.a) {
				cPoint p=a;
				cPoint oa=rhs.a;
				cPoint ob=rhs.b;
				bool sw2a=0;
				if(!inter.belongs(p.x)||oa==ob||rhs.pointBelongs(p)) { p=b; sw2a=1; }
				bool swapped=0;
				if(rhs.pointBelongs(a)&&rhs.pointBelongs(b)) {
					REP("ASSERTION FAILED beta");
				}
				bool sw2=0;
				if(oa==ob||rhs.pointBelongs(p)||!inter.belongs(p.x)) {
					swapped=1;
					oa=a;
					ob=b;
					p=rhs.a;
					if(pointBelongs(p)||!inter.belongs(p.x)) { p=rhs.b; sw2=1; }
				}
				if(oa.x>ob.x) swap(oa,ob);
				lld il = (p-oa)*(ob-oa);
				if(il==0) {
				       	r= uid<rhs.uid;
					REP("ASSERTION FAILED alfa sw "<<swapped<<" sw2a "<<sw2a<<" sw2 "<<sw2);
				}
				else if(!swapped) r= il>0;
				else r= il<0;
			} else {
				cPoint pa = a;
				if(!inter.belongs(pa.x)) pa=b;
				cPoint pb=rhs.a;
				if(!inter.belongs(pb.x)) pb=rhs.b;
				if(pa==pb) r= uid<rhs.uid;
				else r=pa.y<pb.y;
			}
		}	
		REP("set: operator<, result: "<<r);
		dDescribe();
		rhs.dDescribe();
		return r;
	}
	void dDescribe() const {
#ifdef DBG
		REP("seg ("<<a.x<<","<<a.y<<") ("<<b.x<<","<<b.y<<")");
#endif
	}
};

struct cItem {
	int time,val;
};

struct cEvent {
	cSegment segment;
	cPoint p;
	bool modeIn,modeSeg;
	cItem item;
	int key() const {
		if(!modeIn) return max(segment.a.x,segment.b.x);
		else return min(segment.a.x,segment.b.x);
	}
	bool operator<(const cEvent& rhs) const {
		if(modeSeg) {
			if(rhs.modeSeg) 
				return key()<rhs.key();		
			 else {
				if(key()==rhs.p.x)  return modeIn;
				 else return key()<rhs.p.x;
			}
		} else {
			if(rhs.modeSeg) {
				if(p.x==rhs.key()) return !rhs.modeIn;
				else return p.x<rhs.key();

			} else 
				return p<rhs.p;
		}
	}
	void dDescribe() {
#ifdef DBG
		REP("event seg "<<modeSeg<<" in "<<modeIn);
		if(modeSeg) cout<<"("<<segment.a.x<<","<<segment.a.y<<") ("<<segment.b.x<<","<<segment.b.y<<")"<<endl;
		else cout<<"("<<p.x<<","<<p.y<<"): t"<<item.time<<"v"<<item.val<<endl;
#endif
	}
};

struct cZone {
	vector<cItem> items;
	int t[maxSum];
	int v[maxZones*maxSum];	
	int upBound,realSum;
	void init() { items.clear(); }
	void knapsack() {
		upBound=0;
		for(int i=0; i<items.size(); i++) if(items[i].val>0) upBound+=items[i].val; else realSum+=items[i].val;
		realSum+=upBound;
		for(int i=0; i<=upBound; i++) t[i]=inf;
		t[0]=0;
		for(int i=0; i<items.size(); i++) for(int j=upBound; j>0; j--) if(j>=items[i].val&&items[i].val>0) t[j]=min(t[j-items[i].val]+items[i].time,t[j]);
		int reach=realSum+(abs(realSum)*items.size()+99)/100;
		if(reach>0) {
			for(int i=upBound+1; i<=reach; i++) t[reach]=inf;
			int tmr=0;
			for(int i=0; i<items.size(); i++) tmr+=items[i].time;
			t[reach]=min(t[reach],tmr);
			upBound=max(upBound,reach);
		}
#ifdef DBG
		REP("knapsack report: upBound: "<<upBound);
		for(int i=0; i<=upBound; i++) cout<<t[i]<<" ";
		cout<<endl;
#endif
	}
	void dDescribe() {
#ifdef DBG
		REP("describe zone");
		for(int i=0; i<items.size(); i++) cout<<"(t"<<items[i].time<<"v"<<items[i].val<<"),";
		cout<<endl;
#endif
	}
};

typedef pair<int,int> pii;

int nItems, nZones, nSegments;
cZone tZones[maxZones];
cPoint buf[maxSegments];
vector<cEvent> vEvents;
set<cSegment> sTree;
int timeLimit;

int md(int a,int b) {
	while(a<0) a+=b;
	a=a%b;
	return a;
}

void readData() {
	scanf("%d%d", &nZones, &nItems);
	vEvents.clear();
	sTree.clear();
	int uid=0;
	for(int d=0; d<nZones; d++) {
		tZones[d].init();
		int p; scanf("%d", &p);
		for(int i=0; i<p; i++) scanf("%d%d", &buf[i].x, &buf[i].y);
		// should be clockwise!
		{ // check for rightmost element 
			int r=0;
			for(int i=1; i<p; i++) if(buf[r]<buf[i]) r=i;
			if((buf[r]-buf[md(r-1,p)])*(buf[md(r+1,p)]-buf[r])>0) for(int i=0; i<p/2; i++) swap(buf[i],buf[p-i]);
		}
		for(int i=0; i<p; i++) {
			cSegment o;
			o.uid=uid++;
			o.a.x=buf[i].x; o.a.y=buf[i].y;
			o.b.x=buf[(i+1)%p].x; o.b.y=buf[(i+1)%p].y;
			if(o.a.x-o.b.x==0) continue; // nie chcemy pionowych bo po co
			o.insideUp=o.a.x>o.b.x;
			if(o.a.x>o.b.x) swap(o.a,o.b);
			o.zone=d;
			cEvent z1,z2;
			z1.segment=z2.segment=o;
			z1.modeSeg=z2.modeSeg=1;
			z1.modeIn=1;
			z2.modeIn=0;
			vEvents.push_back(z1);
			vEvents.push_back(z2);
		}
	}
	for(int i=0; i<nItems; i++) {
		cEvent item;
		scanf("%d%d%d%d", &item.p.x, &item.p.y, &item.item.time, &item.item.val);
		item.modeSeg=0;
		vEvents.push_back(item);
	}
	sort(vEvents.begin(), vEvents.end());
	scanf("%d", &timeLimit);
	REP("data read");
	REP("EVENTS "<<vEvents.size());
	for(int i=0; i<vEvents.size(); i++) vEvents[i].dDescribe();
}

void redefineProblem() {
	// keep safety precautions!
	for(int i=0; i<vEvents.size(); i++) {
#ifdef DBG
		REP("setdump");
		for(set<cSegment>::iterator j=sTree.begin(); j!=sTree.end(); j++) j->dDescribe();
		REP("endsetdump");
#endif
		REP("processing event "<<i<<" count "<<sTree.size());
		vEvents[i].dDescribe();
		if(vEvents[i].modeSeg) {
			if(vEvents[i].modeIn) {
				int cnt=sTree.size();
				sTree.insert(vEvents[i].segment);
				if(sTree.size()-cnt==0) REP("AAAA");
			}
			else {
				sTree.erase(vEvents[i].segment);
			}
		} else {
			if(!sTree.size()) continue;
			cSegment ins;
			ins.a=ins.b=vEvents[i].p;
			cSegment f =*(--sTree.find(ins));
			ins.dDescribe();
			REP("find  result: ");
			f.dDescribe();
			int at = f.zone;
			tZones[at].items.push_back(vEvents[i].item);
		}
	}
}

int Sum;
void finallyDynamic() {
	Sum=0;
	for(int i=0; i<nZones; i++) tZones[i].knapsack();
	for(int i=0; i<nZones; i++) Sum+=tZones[i].upBound;
	for(int i=0; i<=Sum; i++) tZones[0].v[i]=inf;
	for(int i=0; i<=tZones[0].upBound; i++) tZones[0].v[i]=tZones[0].t[i];
	for(int i=1; i<nZones; i++) {
		for(int j=0; j<=Sum; j++) {
			tZones[i].v[j]=inf;
			for(int k=0; k<=min(j,tZones[i].upBound); k++) tZones[i].v[j]=min(tZones[i].v[j],tZones[i-1].v[j-k]+tZones[i].t[k]);
		}
	}
#ifdef DBG
	REP("vdump");
	for(int i=0; i<nZones; i++) {
		cout<<i<<": ";
		for(int j=0; j<=Sum; j++) cout<<tZones[i].v[j]<<" ";
		cout<<endl;
	}
#endif
}

int main() {
	int z; scanf("%d", &z);
	while(z--) {
		REP("==============================================");
		readData();	
		redefineProblem();
		for(int i=0; i<nZones; i++) tZones[i].dDescribe();
		finallyDynamic();
		int best=0;
		for(int i=0; i<=Sum; i++) if(tZones[nZones-1].v[i]<=timeLimit) best=max(best,i);
		printf("%d\n", best);
	}
	return 0;

}
