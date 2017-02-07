#define DBiG
// autor programu: Grzegorz Guspiel
// V LO im. Augusta Witkowskiego w Krakowie

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#ifdef DBG
#define REPORT(x) cout<<x<<endl
#else
#define REPORT(x)
#endif

/////////////////////////////////////////////////////////
int main()
{
	int n,m; scanf("%d%d", &n, &m);
	int x=0;
	int y=0;
	while(m--) {
		int a,b,c,d,e;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		if(d!=e) {
			if(d<e) x++;
			else y++;
		}
	}
	printf("%d\n", max(x,y));
	return 0;
}
