#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN=10005;
int in[MAXN], t[MAXN];
int z,n;

int main() {
	scanf("%d", &z);
	while(z--) {
		scanf("%d", &n);
		for(int i=1; i<=n; i++) scanf("%d", in+i);
		sort(in+1, in+n+1);
		t[1]=in[1];
		t[2]=in[2];
		t[3]=in[1]+in[2]+in[3];
		for(int i=4; i<=n; i++) t[i]=min(t[i-2]+in[1]+2*in[2]+in[i], t[i-1]+in[1]+in[i]);
		printf("%d\n", t[n]);
	}
	return 0;
}
