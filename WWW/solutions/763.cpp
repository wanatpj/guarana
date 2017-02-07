#include <iostream>
using namespace std;

#define gora 1
#define prawo 2
#define dol 3
#define lewo 4
#define puste 5
#define koniec 6

const int MAXN=1005;
int licznik;
short int z,n,kx,ky,x2,y2;
short int tox[MAXN][MAXN],toy[MAXN][MAXN],pl[MAXN][MAXN];
bool vis[MAXN][MAXN];
char in[MAXN];

bool go(short int x, short int y) {
//cout << "X: "<< x << " Y: " << y << endl;
	if(x<1||x>n||y<1||y>n)
		return false;
	if(vis[y][x]!=0) return false;
	vis[y][x]=1;
	if(y==ky&&x==kx) {
		++licznik;
	//	cout << "rozwazamy: " << x << " " << y << " ";
	//	cout << "doszlismy do konca" << endl;
		return true;
	}
	else if(pl[y][x]==puste) {
	if(go(x,y-1)) {
		++licznik;
		tox[y][x]=x;
		toy[y][x]=y-1;
		return true;
	}
	else if(go(x,y+1)) {
		++licznik;
		tox[y][x]=x;
		toy[y][x]=y+1;
		return true;
	}
	else if(go(x-1,y)) {
		++licznik;
		tox[y][x]=x-1;
		toy[y][x]=y;
		return true;
	}
	else if(go(x+1,y)) {
		++licznik;
		tox[y][x]=x+1;
		toy[y][x]=y;
		return true;
	}
	}
	else {
	if(pl[y][x]==gora && go(x,y-1)) {
		++licznik;
		tox[y][x]=x;
		toy[y][x]=y-1;
		return true;
	}
	else if(pl[y][x]==prawo && go(x+1,y)) {
		++licznik;
		tox[y][x]=x+1;
		toy[y][x]=y;
		return true;
	}
	else if(pl[y][x]==dol && go(x,y+1)) {
		++licznik;
		tox[y][x]=x;
		toy[y][x]=y+1;
		return true;
	}
	else if(pl[y][x]==lewo && go(x-1,y)) {
		++licznik;
		tox[y][x]=x-1;
		toy[y][x]=y;
		return true;
	}
	}
	//cout << "rozwazamy: " << x << " " << y << " ";
	//cout << "to pole nie lezy na sciezce" << endl;
	return false;
}

void wypisz(short int x, short int y) {
	printf("%hd %hd\n", x, n-y+1);
	while(x!=kx || y!=ky) {
		x2=x; y2=y;
		x=tox[y2][x2];
		y=toy[y2][x2];
		printf("%hd %hd\n", x, n-y+1);
	}
}

int main() {
	scanf("%hd", &z);
	while(z--) {
		scanf("%hd", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) vis[i][j]=0;
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
		licznik=0;
		go(1,n);
		/*for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cout << c[i][j] << " ";
			cout << endl;
		}*/
		printf("%d\n", licznik);
		wypisz(1,n);
	}
	return 0;
}
