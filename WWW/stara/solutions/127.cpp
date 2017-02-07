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

typedef long long lld;

lld nwd(lld a, lld b) {
	if(b==0) return a;
	return nwd(b, a%b);
}

int main()
{
	int n; scanf("%d", &n);
	while(n--)
	{
		lld p,q; scanf("%lld%lld", &p, &q);
		lld d = nwd(p,q);
		lld mp=p/d;
		lld mq=q/d;
		lld w;
		if(p<q) w=mp*(mp+1)/2;
		else w = mp*mq-mq*(mq-1)/2;
		REPORT("subw "<<w);
		w*=d*d;
		REPORT("w "<<w);
		lld dd = nwd(w,p*q-w);
		printf("%lld %lld\n", w/dd, (p*q-w)/dd);
	}
	return 0;
}
