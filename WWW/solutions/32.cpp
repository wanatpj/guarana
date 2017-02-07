#define DBiG
// Grzegorz Guspiel 1e
// V-LO Krakow

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#ifdef DBG
#define REPORT(s) cout<<s<<endl
#define REPTAB(s) cout<<"tablica"<<endl; \
	for(int ii=0; ii<4; ii++) cout<<s[ii]<<endl;
#else
#define REPORT(s)
#define REPTAB(s)
#define NDEBUG
#endif

char t[6][6];
char s[6][6];
bool sz[6][6];
int kx, ky;

#define foreach(ii,jj) for(int ii=0; ii<4; ii++) for(int jj=0; jj<4; jj++)
#define fornine(ii, jj) for(int ii=-1; ii<=1; ii++) for(int jj=-1; jj<=1; jj++)
#define foreight(ii, jj) for(int ii=-1; ii<=1; ii++) for(int jj=-1; jj<=1; jj++) if(!((!ii)&&!jj))

bool ok(int a, int b) {
	return a>=0&&a<4&&b>=0&&b<4;
}

bool test() {
	bool w=1;
	int sx=-1; int sy=-1;
	foreach(i,j) sz[i][j]=0;
	foreach(i,j) {
		if(s[i][j]=='B') 
			foreight(k,l)
				if(ok(i+k,j+l)) sz[i+k][j+l]=1;

		if(s[i][j]=='b') {
			if(i-1==kx&&(j-1==ky||j+1==ky)) { sx=i; sy=j; }
			sz[i-1][j-1]=sz[i-1][j+1]=1;
		}
	}
	if(ok(sx-1,sy-1)&&s[sx-1][sy-1]=='c'||ok(sx-1,sy+1)&&s[sx-1][sy+1]=='c') w=0;
	fornine(k,l) if(ok(kx+k,ky+l) && !(sz[kx+k][ky+l]||s[kx+k][ky+l]=='c')) w=0;
	return w;
}

bool ktest(int x, int y, int a, int b) {
	bool w=0;
	if(ok(x+a,y+b)&&(b==0&&s[x+a][y+b]=='.'||b!=0&&s[x+a][y+b]=='c'))
	{
		if(s[x+a][y+b]=='c')	s[x+a][y+b]='.'; 
		swap(s[x][y],s[x+a][y+b]);
		REPORT("po swapie");
		REPTAB(s);
		w=test();
	}
	return w;
}

int main()
{
	int z; scanf("%d", &z);
	while(z--)
	{
		bool sza=0;
		scanf("\n");
		for(int i=0; i<4; i++)
			fgets(t[i],6,stdin);
		foreach(i,j) if(t[i][j]=='C') {
			kx=i;
			ky=j;
		}
		foreach(i,j) {
			if(t[i][j]=='b')  {
				foreach(k,l) s[k][l]=t[k][l];
				if(ktest(i,j,-1,0)) sza=1;
				if(ok(i-1,j-1)&&s[i-1][j-1]=='c') {
					foreach(k,l) s[k][l]=t[k][l];
					if(ktest(i,j,-1,-1)) sza=1;
				}
				if(ok(i-1,j+1)&&s[i-1][j+1]=='c') {
					foreach(k,l) s[k][l]=t[k][l];
					if(ktest(i,j,-1,+1)) sza=1;
				}
			}
		}
		if(sza) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}

