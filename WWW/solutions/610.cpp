#include<iostream>
using namespace std;
const int SIZE = 205;
int m[SIZE][SIZE];
int s[SIZE][SIZE];
int slowa[SIZE];
int sumaslow[SIZE][SIZE];
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
					s[i][j] = k;
				}					
			}
		}
	}
}
int nawiasy(int a, int b){
	if(a == b)
		return 0;
	int k = s[a][b];
	if(k+1 < b){
		return 1 + nawiasy(a,k) + nawiasy(k+1,b);
	}
	else return nawiasy(a,k);
}
int main(){
	scanf("%d",&d);
	while(d--){
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d",&slowa[i]);
		}
		sumafill();
		konorder();
		printf("%d %d\n",m[1][n],nawiasy(1,n));
	}
	return 0;
}

