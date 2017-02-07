#include <iostream>
#include <queue>
#include <vector>
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
short int pl[MAXN][MAXN];
pnt skad[MAXN][MAXN];
bool vis[MAXN][MAXN];
short int kx,ky,z,n;
char in[MAXN];
int licznik;
queue<pnt> Q;
vector<pnt> P;
pnt tmp,tmp2;

void go() {
    //Q.clear();
    tmp.x=1;
    tmp.y=n;
    Q.push(tmp);
    while(!Q.empty()) {
		 //cout << "zdejmujemy" << endl;
        tmp=Q.front();
        Q.pop();
//cout << "X: " << tmp.x << " Y: " << tmp.y << "  ";
		  if(tmp.x<1||tmp.x>n||tmp.y<1||tmp.y>n) continue;
		  if(vis[tmp.y][tmp.x]) continue;
		  //if(tmp.x==kx&&tmp.y==ky) break;
        vis[tmp.y][tmp.x]=1;
        if(pl[tmp.y][tmp.x]==puste) {
//			  cout << "PUSTE!" << endl;
            if(tmp.y>1 && !vis[tmp.y-1][tmp.x]) {
                tmp2.x=tmp.x;
                tmp2.y=tmp.y-1;
					 skad[tmp2.y][tmp2.x]=tmp;
				Q.push(tmp2);
            }
            if(tmp.y<n && !vis[tmp.y+1][tmp.x]) {
					tmp2.x=tmp.x;
					tmp2.y=tmp.y+1;
					skad[tmp2.y][tmp2.x]=tmp;
				Q.push(tmp2);
				}
				if(tmp.x>1 && !vis[tmp.y][tmp.x-1]) {
					tmp2.x=tmp.x-1;
					tmp2.y=tmp.y;
					skad[tmp2.y][tmp2.x]=tmp;
				Q.push(tmp2);
				}
				if(tmp.x<n && !vis[tmp.y][tmp.x+1]) {
					tmp2.x=tmp.x+1;
					tmp2.y=tmp.y;
					skad[tmp2.y][tmp2.x]=tmp;
				Q.push(tmp2);
				}
        }
		  else {
//			  cout << "NIEPUSTE!" << endl;
				if(pl[tmp.y][tmp.x]==gora) {
					tmp2.y=tmp.y-1;
					tmp2.x=tmp.x;
				}
				else if(pl[tmp.y][tmp.x]==prawo) {
					tmp2.y=tmp.y;
					tmp2.x=tmp.x+1;
				}
				else if(pl[tmp.y][tmp.x]==dol) {
					tmp2.y=tmp.y+1;
					tmp2.x=tmp.x;
				}
				else if(pl[tmp.y][tmp.x]==lewo) {
					tmp2.y=tmp.y;
					tmp2.x=tmp.x-1;
				}
				if(!vis[tmp2.y][tmp2.x]) {
					skad[tmp2.y][tmp2.x]=tmp;
					Q.push(tmp2);
				}
		  }
    }   
}

void wypisz() {
	tmp.x=kx;
	tmp.y=ky;
	licznik=1;
	P.clear();
	P.push_back(tmp);
	while(tmp.x!=1 || tmp.y!=n) {
//		cout << tmp.x << " " << tmp.y << endl;
		++licznik;
		tmp2.x=tmp.x;
		tmp2.y=tmp.y;
		//printf("%hd %hd\n", tmp.x, n-tmp.y+1);
		tmp=skad[tmp2.y][tmp2.x];
		P.push_back(tmp);
	}
	printf("%d\n", licznik);
	for(int i=P.size()-1; i>-1; i--)
		printf("%hd %hd\n", P[i].x, n-P[i].y+1);
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
		go();
		/*cout << endl;
		for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(pl[i][j]==lewo) cout << "LEWO  ";
			if(pl[i][j]==prawo) cout << "PRAWO ";
			if(pl[i][j]==gora) cout << "GORA  ";
			if(pl[i][j]==dol) cout << "DOL   ";
			if(pl[i][j]==puste) cout << "PUSTE ";
		}
		cout << endl;
		}
		cout << "wypis" << endl;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cout << "(" << skad[i][j].x << "," << skad[i][j].y << ") ";
			cout << endl;
		}*/
		wypisz();
	}
	return 0;
}
