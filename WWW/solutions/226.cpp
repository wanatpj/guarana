#include <iostream>
using namespace std;

#define REP(x,n) for(int x = 0; x < (n); ++x)
#define FOR(x,b,e) for (int x = (b); x <= (e); ++x)
const int N = 4;
const int P = 0;
const int K = 1;
const int W = 0;
const int B = 1;
const int E = 2;
int b[N][N], c[N][N];

inline bool isg(int i, int j) { return 0 <= i && i < N && 0 <= j && j < N; }
inline bool ise(int i, int j) { return isg(i,j) && b[i][j] == E; }
inline bool isp(int i, int j, int p, int cl) { return isg(i,j) && b[i][j] == p && c[i][j] == cl; }

int chk[N][N];
inline void mc(int i, int j) { if (isg(i,j)) chk[i][j] = 1; }
inline bool ic(int i, int j) { return (!isg(i,j)) || chk[i][j] == 1; }
bool check_board() {
	REP(i,N) REP(j,N) chk[i][j] = 0;
	REP(i,N) REP(j,N)
		if (isp(i,j,P,W)) {
			mc(i-1,j-1);
			mc(i-1,j+1);
		}
		else if (isp(i,j,K,W)) {
			FOR(x,-1,1) FOR(y,-1,1) if (x != 0 || y != 0) {
				mc(i+x,j+y);
			}
		}
	REP(i,N) REP(j,N) if (isp(i,j,K,B)) {
		int a = 0;
		if (i == N-1) return 0;
		FOR(x,-1,1) FOR(y,-1,1) if (x != 0 || y != 0) {
			if (ic(i+x,j+y) == 0 && isp(i+x,j+y,P,B) == 0 ) return 0;
		}
		if (isp(i+1,j-1,P,W) == 0 && isp(i+1,j+1,P,W) == 0) return 0;
		if (isp(i+1,j-1,P,W) && isp(i,j-2,P,B)) return 0;
		if (isp(i+1,j+1,P,W) && isp(i,j+2,P,B)) return 0;
		return 1;
	}
}
int tb[N][N], tc[N][N];

void make_move(int i, int j, int i2, int j2, int & r) {
	REP(x,N) REP(y,N) { tb[x][y] = b[x][y]; tc[x][y] = c[x][y]; }
	b[i2][j2] = P;
	c[i2][j2] = W;
	b[i][j] = E;
	r |= check_board();
	REP(x,N) REP(y,N) { b[x][y] = tb[x][y]; c[x][y] = tc[x][y]; }
}

bool solve() {
	int r = 0;
	REP(i,N) REP(j,N) if (isp(i,j,P,W)) {
		if (ise(i-1,j)) make_move(i,j,i-1,j,r);
		if (isp(i-1,j-1,P,B)) make_move(i,j,i-1,j-1,r);
		if (isp(i-1,j+1,P,B)) make_move(i,j,i-1,j+1,r);
	}
	return r;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		REP(i,N) {
			string s;
			cin >> s;
			REP(j,N) {
				if (s[j] == '.') b[i][j] = E;
				else if (s[j] == 'C') { b[i][j] = K; c[i][j] = B; }
				else if (s[j] == 'c') { b[i][j] = P; c[i][j] = B; }
				else if (s[j] == 'B') { b[i][j] = K; c[i][j] = W; }
				else if (s[j] == 'b') { b[i][j] = P; c[i][j] = W; }
			}
		}
		if (solve()) printf("TAK\n");
		else printf("NIE\n");
	}

	return 0;
}
