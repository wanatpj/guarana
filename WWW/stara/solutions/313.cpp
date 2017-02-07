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
using namespace std;

// =====================================================

int n,z;
const int maxn=10100;
const int maxz=20100;

struct person {
	vector<person*> good,bad;
	int counter,nr;
	void init(int nnn) {
		counter=0;
		nr=nnn;
		good.clear();
		bad.clear();
	}
	void count() {
		if(bad.size()>1) return;
		vector<person*> sum = good; sum.insert(sum.end(), bad.begin(), bad.end());
		sort(sum.begin(), sum.end());
		bool col=0;
		for(int i=1; i<sum.size(); i++) if(sum[i]==sum[i-1]) col=1;
		if(col) return;
		if(bad.size()) {
			bad[0]->counter--;
		} else {
			for(int i=0; i<good.size(); i++) good[i]->counter++;
		}
	}
	bool operator<(const person& rhs) const {
		return counter<rhs.counter;
	}
};

struct testimony {
	int speaker, suspect;
	bool bad;
};

person t[maxn];
testimony stm[maxz];

void readData() {
	scanf("%d%d", &n, &z);
	for(int i=0; i<=n; i++) t[i].init(i);
	for(int i=1; i<=z; i++) {
		char c; 
		int a,b; scanf("%d %c %d\n", &a, &c, &b);
		stm[i].speaker=a;
		if(c=='W') {
			stm[i].suspect=b;
			stm[i].bad=1;
		} else {
			stm[i].suspect=stm[b].suspect;
			stm[i].bad=stm[b].bad;
			if(c=='F') stm[i].bad=!stm[i].bad;
		}
	}
}

void createPeople() {
	for(int i=1; i<=z; i++) if(stm[i].bad) t[stm[i].speaker].bad.push_back(&t[stm[i].suspect]);
	else t[stm[i].speaker].good.push_back(&t[stm[i].suspect]);
	for(int i=1; i<=n; i++) {
		for(int k=0; k<2; k++) {
			vector<person*> tmp;
			vector<person*>* src;
			if(k==0) src=&t[i].good;
			else src=&t[i].bad;
			sort(src->begin(), src->end());
			if(!src->size()) continue;
			tmp.push_back((*src)[0]);
			for(int j=1; j<src->size(); j++) if((*src)[j]!=(*src)[j-1]) tmp.push_back((*src)[j]);
			*src=tmp;
		}
#ifdef DBG
		REP("GOOD "<<i);
		for(int j=0; j<t[i].good.size(); j++) cout<<t[i].good[j]->nr<<" ";
		cout<<endl;
		REP("BAD  "<<i);
		for(int j=0; j<t[i].bad.size(); j++) cout<<t[i].bad[j]->nr<<" ";
		cout<<endl;
#endif
		
	}
}

void globalCount() {
	for(int i=1; i<=n; i++) t[i].count();
}

void printResult() {
	int best=t[1].counter;
	vector<int> res;
	for(int i=1; i<=n&&t[i].counter==best; i++) res.push_back(t[i].nr);
	sort(res.begin(), res.end());
	for(int i=0; i<res.size(); i++) printf("%d ", res[i]);
	printf("\n");
}

int main() {
	int zest; scanf("%d", &zest);
	while(zest--) {
		readData();
		createPeople();
		globalCount();
		sort(t+1,t+n+1);
		printResult();		
	}
	return 0;

}
