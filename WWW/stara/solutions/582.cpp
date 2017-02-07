#include <iostream>
using namespace std;

#define gora 1
#define prawo 2
#define dol 3
#define lewo 4
#define puste 5
#define koniec 6
#define idziemy 1
#define zla 2
#define dobra 3

const int MAXN=1005;
short int pl[MAXN][MAXN], skady[MAXN][MAXN], skadx[MAXN][MAXN], dokadx[MAXN][MAXN], dokady[MAXN][MAXN];
short int x2,y2, xtmp, ytmp, kx,ky,z,n;
char in[MAXN];

bool go(short int y, short int x) {
	while(y>0 && y<=n && x>0 && x<=n && pl[y][x]!=puste && pl[y][x]!=koniec && !skadx[y][x]) {
		skadx[y][x]=x2;
		skady[y][x]=y2;
		x2=x;
		y2=y;
		if(pl[y][x]==gora) --y;
		else if(pl[y][x]==prawo) ++x;
		else if(pl[y][x]==dol) ++y;
		else if(pl[y][x]==lewo) --x;
	}
	if(y<1 || y>n || x<1 || x>n || pl[y][x]==koniec || skadx[y][x]) {
		if(pl[y][x]==koniec) {
			skadx[y][x]=x2;
			skady[y][x]=y2;
			return true;
		}
		else {
		return false;
		}
	}
	else {
		skadx[y][x]=x2;
		skady[y][x]=y2;
		if(y>1 && !skadx[y-1][x] && go(y-1,x)) {
			skadx[y-1][x]=x;
			skady[y-1][x]=y;
			return true;
		}
		else if(y<n && !skadx[y+1][x] && go(y+1,x)) {
			skadx[y+1][x]=x;
			skady[y+1][x]=y;
			return true;
		}
		else if(x>1 && !skadx[y][x-1] && go(y,x-1)) {
			skadx[y][x-1]=x;
			skady[y][x-1]=y;
			return true;
		}
		else if(x<n && !skadx[y][x+1] && go(y,x+1)) {
			skadx[y][x+1]=x;
			skady[y][x+1]=y;
			return true;
		}
	}
	return false;
}

void wypisz() {
	short int x=kx, y=ky;
	int licznik=1;
	while(x!=1 || y!=n) {
		++licznik;
		x2=x;
		y2=y;
		x=skadx[y2][x2];
		y=skady[y2][x2];
		dokadx[y][x]=x2;
		dokady[y][x]=y2;
	}
	printf("%d\n", licznik);
	while(x!=kx || y!=ky) {
		printf("%hd %hd\n", x, n-y+1);
		x2=x;
		y2=y;
		x=dokadx[y2][x2];
		y=dokady[y2][x2];
	}
	printf("%hd %hd\n", x, n-y+1);
}

int main() {
	scanf("%hd", &z);
	while(z--) {
		scanf("%hd", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) pl[i][j]=skadx[i][j]=skady[i][j]=dokadx[i][j]=dokady[i][j]=0;
		for(int i=1; i<=n; i++) {
			scanf("%s", in);
			for(int j=1; j<=n; j++) {
				if(in[j-1]=='g') pl[i][j]=gora;
				else if(in[j-1]=='p') pl[i][j]=prawo;
				else if(in[j-1]=='d') pl[i][j]=dol;
				else if(in[j-1]=='l') pl[i][j]=lewo;
				else if(in[j-1]=='k') { pl[i][j]=koniec; kx=j; ky=i; }
				else pl[i][j]=puste;
			}
		}
		go(n,1);
		/*for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cout << "(" <<skadx[i][j] << ","<<skady[i][j]<<") ";
			cout << endl;
		}*/
		wypisz();
	}
	return 0;
}
