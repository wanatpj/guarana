#include <iostream>
#include <vector>
using namespace std;

int z,n,it,x;
long long pot,k,m,mliczba;
bool ok;

int ile(long long x) {
	int l=0;
	while(x>0) {
		if(x%2)
			++l;
		x/=2;
	}
	return l;
}

int main() {
	scanf("%d", &z);
	while(z--) {
		scanf("%d", &n);
		int v[n+2][n+2];
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++) v[i][j]=0;
		for(int i=2; i<=n; i++) {
			scanf("%d", &it);
			for(int j=0; j<it; j++) {
				scanf("%d", &x);
				v[i][x]=v[x][i]=1;
			}
		}
		pot=1;
		for(int i=0; i<n; i++) pot*=2;
		k=1;
		m=0;
		while(k<pot) {
			for(int i=1; i<=n; i++) {
				ok=1;
				if(k&(1<<(i-1))) {
					for(int j=1; j<=n; j++) {
						if(i==j) continue;
						if(k&(1<<(j-1))) {
							if(!v[i][j]) {
								ok=0;
								break;
							}
						}
					}
				}
				if(!ok) break;
			}
			if(ok) {
				if(ile(mliczba)<ile(k)) {
					mliczba=k;
				}
			}
			++k;
		}
		printf("%d\n", ile(mliczba));
		it=1;
		while(mliczba>0) {
			if(mliczba%2) printf("%d ", it);
			mliczba/=2;
			++it;
		}
		printf("\n");
	}
	return 0;
}
