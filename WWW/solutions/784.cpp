#include <iostream>
#include <stack>
using namespace std;

struct pnt{
	short int x,y;
};

#define gora 1
#define prawo 2
#define dol 3
#define lewo 4
#define puste 5
#define koniec 6

const int MAXN=1005;
int licznik;
short int z,n,kx,ky,x2,y2;
short int c[MAXN][MAXN],pl[MAXN][MAXN];
char in[MAXN];
pnt punkt;
stack<pnt> S;

void go(short int x, short int y) {
//cout << "X: "<< x << " Y: " << y << endl;
	c[y][x]=1;
	if(pl[y][x]==koniec) {
		c[y][x]=2;
	//	cout << "rozwazamy: " << x << " " << y << " ";
	//	cout << "doszlismy do konca" << endl;
	}
	else if(pl[y][x]==puste) {
		if(y>1) {
			go(x,y-1);
			if(c[y-1][x]==2) c[y][x]=2;
		}
		if(x>1) {
			go(x-1,y);
			if(c[y][x-1]==2) c[y][x]=2;
		}
		if(y<n) {
			go(x,y+1);
			if(c[y+1][x]==2) c[y][x]=2;
		}
		if(x<n) {
			go(x+1,y);
			if(c[y][x+1]==2) c[y][x]=2;
		}
	}
	else {
		if(pl[y][x]==gora) {
			if(y>1 && c[y-1][x]==0) {
				go(x,y-1);
				if(c[y-1][x]==2) c[y][x]=2;
			}
			else c[y][x]=3;
		}
		else if(pl[y][x]==prawo) {
			if(x<n && c[y][x+1]==0) {
				go(x+1,y);
				if(c[y][x+1]==2) c[y][x]=2;
			}
			else c[y][x]=3;
		}
		else if(pl[y][x]==dol) {
			if(y<n && c[y+1][x]==0) {
				go(x,y+1);
				if(c[y+1][x]==2) c[y][x]=2;
			}
			else c[y][x]=3;
		}
		else if(pl[y][x]==lewo) {
			if(x>1 && c[y][x-1]==0) {
				go(x-1,y);
				if(c[y][x-1]==2) c[y][x]=2;
			}
			else c[y][x]=3;
		}
	}
	if(c[y][x]==2) {
		punkt.x=x;
		punkt.y=y;
		S.push(punkt);
	}
	else if(c[y][x]==1) c[y][x]=3; //nie lezy na sciezce
	//cout << "rozwazamy: " << x << " " << y << " ";
	//cout << "to pole nie lezy na sciezce" << endl;
}

void wypisz() {
	printf("%d\n", S.size());
	while(!S.empty()) {
		punkt=S.top();
		S.pop();
		printf("%hd %hd\n", punkt.x, n-punkt.y+1);
	}
}

int main() {
	scanf("%hd", &z);
	while(z--) {
		scanf("%hd", &n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) c[i][j]=0;
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
		go(1,n);
		//cout << "!" << endl;
		/*for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cout << c[i][j] << " ";
			cout << endl;
		}*/
		wypisz();
	}
	return 0;
}
