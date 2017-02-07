#include <iostream>
using namespace std;

int main() {
	int z,n,x,ile,c;
	scanf("%d", &z);
	while(z--) {
		scanf("%d", &n);
		ile=0;
		while(n--) {
			scanf("%d", &x);
			ile+=x;
		}
		scanf("%d", &c);
		if(ile) printf("%d\n", c%ile);
		else printf("%d\n", c);
	}
	return 0;
}
