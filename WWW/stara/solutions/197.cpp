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
#define REPMAT(a,tx) cout<<"macierz "<<tx<<endl; \
for(int i=0; i<4; i++) { \
	for(int j=0; j<4; j++) cout<<(a).t[i][j]<<" "; \
	cout<<endl; \
}
#else
#define REPORT(s)
#define REPMAT(a,t)
#define NDEBUG
#endif

#define fore(i,j) for(int i=0; i<4; i++) for(int j=0; j<4; j++)
typedef long long lld;
lld ll(int x) { return ((lld)x); }
int p;

struct matrix {
	int t[4][4];
	matrix() {
		fore(i,j) t[i][j]=0;
	}
	matrix operator*(const matrix rhs) const {
		matrix w;
		fore(i,j) {
			w.t[i][j]=0;
			for(int k=0; k<4; k++) w.t[i][j]=(w.t[i][j]+ll(t[i][k])*rhs.t[k][j])%p;
		}
		return w;
	}
	void operator=(const matrix& rhs) {
		fore(i,j) t[i][j]=rhs.t[i][j];
	}
	void pot(int wykl) {
		matrix mn=*this;
		fore(i,j) t[i][j]=0;
		for(int i=0; i<4; i++) t[i][i]=1;
		while(wykl) {
			if(wykl%2) (*this)=(*this)*mn;
			mn=mn*mn;
			wykl/=2;
		}
	}

};

int potega(long long x, int y) {
	long long r=1;
	while(y) {
		if(y%2) r=r*x%p;
		x=x*x;
		y/=2;
	}
	return r;
}

int main()
{
	int z; scanf("%d", &z);
	while(z--)
	{
		matrix start;
		int wyk,arg;
		scanf("%d%d%d%d%d%d%d", &p,&start.t[0][0],&start.t[0][1],&start.t[0][2],&start.t[0][3],&arg,&wyk);
		matrix mnoz;
		mnoz.t[0][0]=start.t[0][0];
		mnoz.t[0][1]=start.t[0][1];
		mnoz.t[0][2]=mnoz.t[1][0]=mnoz.t[1][3]=start.t[0][2];
		mnoz.t[1][1]=mnoz.t[2][2]=mnoz.t[3][3]=start.t[0][3];
		mnoz.pot(wyk-1);
		start=start*mnoz;
		REPORT("wynik "<<(start.t[0][0]*arg+start.t[0][1])%p<<"/"<<(start.t[0][2]*arg+start.t[0][3])%p);
		long long wynik=start.t[0][0];
		wynik*=arg; wynik+=start.t[0][1];
		wynik%=p;
		long long w2=start.t[0][2];
		w2*=arg; w2+=start.t[0][3];
		w2%=p;
		wynik=wynik*potega(w2,p-2);
		wynik%=p;
		printf("%lld\n", wynik);
	}
	return 0;
}
