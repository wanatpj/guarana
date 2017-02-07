#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long LL;
#define SIZE(c) int((c).size())
int main() {
	int t;
	scanf("%d",&t);
	while (t--) {
		LL r = 0;
		string w;
		cin >> w;
		w += '+';
		LL tr = 0;
		for (int i = 0; i < SIZE(w); i += 2) {
			int d = w[i]-'0';
			if (w[i+1] == '*') {
				if (tr == 0) tr = d;
				else tr *= d;
			}
			else {
				if (tr > 0) { r += tr*d; tr = 0; }
				else r += d;
			}
		}
		printf("%lld\n",r);
	}
	return 0;
}
