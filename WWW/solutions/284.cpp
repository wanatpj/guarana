#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int n;
char t[1005][1005];
bool o[1005][1005];
int k[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int kier(char z){
	if(z=='l') return 0;
	if(z=='g') return 1;
	if(z=='p') return 2;
	if(z=='d') return 3;
	if(z=='.') return 4;
	return 5;
}

vector<pair<int, int> > sciezka;

bool bfs(int i, int j){
	if(i<0 || j<0 || i>=n || j>=n) return 0;
	if(o[i][j]) return 0;
	sciezka.push_back(pair<int, int>(i, j));
	o[i][j]=1;
	int ki = kier(t[i][j]);
	if(ki == 5) return 1;
	if(ki != 4){
		if(bfs(i+k[ki][0], j+k[ki][1])) return 1;
	}else{
		for(int x=0; x<4; x++){
			if(bfs(i+k[x][0], j+k[x][1])) return 1;
		}
	}
	sciezka.pop_back();
	o[i][j]=0;
	return 0;	
}

int main(){
	int d;
	scanf("%d", &d);
	while(d--){
		scanf("%d", &n);
		for(int i=n-1; i>=0; i--){
			scanf("%s", t[i]);
			for(int j=0; j<n; j++) o[i][j]=0;
		}
		bfs(0, 0);
		printf("%d\n", sciezka.size());
		for(int i=0; i<sciezka.size(); i++) printf("%d %d\n", sciezka[i].second+1, sciezka[i].first+1);
	}
	return 0;
}
