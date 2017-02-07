#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 1005

typedef pair<int, int> pii;

char T[MAXN][MAXN];
int S[MAXN][MAXN];
/*
	stan:
	-1: uninit
	0: odwiedzone
*/

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};
int n;
vector<pii > ans;

bool inbounds(int x, int y){
	if ( x <= 0 || y <= 0 ) return false;
	if ( x > n || y > n ) return false;
	return true;
}

bool proceed(int x, int y){
S[y][x] = 0;
//cout << "<"<<x << ' ' << y << ">" << endl;
		if ( T[y][x] == 'k' ){
			return true;
		} else if ( T[y][x] == 'l' ){
			x--;
		} else if ( T[y][x] == 'g' ){
			y++;
		} else if ( T[y][x] == 'd' ){
			y--;
		} else if ( T[y][x] == 'p' ){
			x++;
		} else if ( T[y][x] ==  '.' ){
		
		 for (int g=0; g<4; ++g){
		 //cout << "PUSTE " << g; cout << "<"<<x << ' ' << y << ">" << endl;
			if ( ! inbounds( x+mx[g], y+my[g] ) ) continue;//return false;
			if ( S[y+my[g]][x+mx[g]] == 0 ) continue;//return false;
			S[y+my[g]][x+mx[g]] = 0;
			bool state = proceed(x+mx[g], y+my[g]);
			if ( state ){
				S[y+my[g]][x+mx[g]] = 1;
				ans.push_back(pii(x+mx[g], y+my[g]));
				return true;
			} else {
				S[y+my[g]][x+mx[g]] = 2;
				continue;//return false;
			}
		}
		
		}
		
		//cout << "nowe: "<<x << ' ' << y ;
		
		if ( ! inbounds( x, y ) ) return false; //cout << "po inb";
		if ( S[y][x] == 0 ) return false; //cout << "po 0c" << endl;
		
		S[y][x] = 0;
		
		bool state = proceed(x, y);
		if ( state ){
			ans.push_back(pii(x, y));
			return true;
		} else {
			return false;
		}
}



int main(){

int d; scanf("%d", &d);

while(d--){

	scanf("%d", &n);
	for (int i=n; i>0; --i) scanf("%s", T[i]+1);
	for (int i=0; i<=n; ++i) for (int j=0; j<=n; ++j) S[i][j] = -1;
	
	//for (int i=1; i<=n; ++i) {for (int j=1; j<=n; ++j) cout << T[i][j]; cout << endl;}
	
	ans.clear();

	proceed(1, 1);
	
	int ss = ans.size();
	printf("%d\n", ss+1);
	printf("1 1\n");
	for (int i=ss-1; i>=0; --i){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	
}

return 0;
}

