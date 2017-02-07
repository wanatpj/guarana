#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
	int d, n, k;
	int t[100010];
	long long suma;
	scanf("%d", &d);
	while(d--){
		scanf("%d", &n);
		for(int i=1; i<=n; i++){
			scanf("%d", &t[i]);
		}
		if(n==1) printf("%d\n", t[0]);
		if(n==2) printf("%d\n", t[0]+t[1]);
		if(n>2){
			sort(t+1, t+(n+1));
			k=0;
			for(int i=1; 2*i<n; i++){
				if(2*t[2]-t[1]<t[n-2*i+1]) k=max(k, i);
			}
			suma=(n-k-2)*t[1]+(2*k+1)*t[2];
			for(int i=3; i<=n-2*k; i++) suma+=t[i];
			for(int i=0; i<=k-1; i++) suma+=t[n-2*i];
			printf("%lld\n", suma);
		}
		
	}
	return 0;
}
