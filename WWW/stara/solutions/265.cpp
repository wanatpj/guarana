#include <iostream>
using namespace std;

int main() {
	int n,m,x1,x2,x3;
	scanf("%d%d", &n, &m);
	while(n--) {
		scanf("%d%d%d", &x1, &x2, &x3);
		if(m<x1) printf("komin\n");
		else if(m<x2) printf("okno\n");
		else if(m<x3) printf("drzwi\n");
		else printf("brak\n");
	}
	return 0;
}
