#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int d, n, s, c, x;
	scanf("%d", &d);
	while(d--){
		scanf("%d", &n);
		s=0;
		for(int i=0; i<n; i++) {scanf("%d", &x); s+=x;}
		scanf("%d", &c);
		if(s == 0) printf("%d\n", c); else printf("%d\n", c%s);
	}
	return 0;
}
