#include<iostream>
#include<slist.h>
using namespace std;
const int SIZE = 205;
int m[SIZE][SIZE];
slist<int> s[SIZE][SIZE];
int slowa[SIZE];
int sumaslow[SIZE][SIZE];
int bestnaw[SIZE][SIZE];
int n,d;
void sumafill(){
	for(int i = 1 ; i <= n ; ++i){
		sumaslow[i][i] = slowa[i];
		for(int j = i+1 ; j <= n ; ++j){
			sumaslow[i][j] = sumaslow[i][j-1]+slowa[j];
		}
	}
}
void konorder(){
	for(int i = 1 ; i <= n ; ++i)
		m[i][i] = 0;
	for(int l = 2 ; l <= n ; ++l){
		for(int i = 1 ; i <= n-l+1 ; ++i){
			int j = i+l-1;
			m[i][j] = 2000000000;
			for(int k = i ; k <= j-1 ; ++k){
				int q = m[i][k] + m[k+1][j] + sumaslow[i][j];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j].clear();
					s[i][j].push_front(k);
				}					
				if(q == m[i][j]){
					s[i][j].push_front(k);
				}
			}
		}
	}
}
void zerujbestnaw(int n){
	for(int i = 0 ; i <= n ; ++i)
		for(int j = 0 ; j <= n ; ++j)
			bestnaw[i][j] = 1000000000;
	for(int i = 0 ; i <= n ; ++i)
		bestnaw[i][i] = 0;
}
int nawiasy(int a, int b){
	if(a == b)
		return 0;
	int best = 1000000000;
	for(slist<int>::iterator it = s[a][b].begin() ; it != s[a][b].end(); ++it){
		int k = *it;
		int first,second;
		if(bestnaw[a][k] == 1000000000)
			bestnaw[a][k] = nawiasy(a,k);
		if(bestnaw[k+1][b] == 1000000000)
			bestnaw[k+1][b] = nawiasy(k+1,b);
		first = bestnaw[a][k];
		second = bestnaw[k+1][b];
		if(k+1 < b) first+=1;
		if(best > first+second)
			best = first+second;
	}
	return best;
}
int main(){
	scanf("%d",&d);
	while(d--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d",&slowa[i]);
		}
		zerujbestnaw(n+1);
		sumafill();
		konorder();
		printf("%d %d\n",m[1][n],nawiasy(1,n));
	}
	return 0;
}

