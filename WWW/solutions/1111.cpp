/*
rozwiazanie oparte na opracowaniu zadania "Most" z XI Olimpiady Informatycznej
*/

#include<cstdio>
#include<algorithm>
using namespace std;

const int N=10001;
long long t[N],d[N];

main()
{
    int l,n;
    scanf("%d",&l);
    while(l--)
    {
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld",&t[i]);
	sort(t,t+n);
	if(n==1) printf("%lld\n",t[0]);
	else if (n==2) printf("%lld\n",t[1]);
	else
	{
	    d[1]=t[1]; d[2]=t[0]+t[1]+t[2];
	    for(int i=3; i<n; i++)
	    d[i]=min(d[i-2]+t[0]+2*t[1]+t[i],d[i-1]+t[0]+t[i]);
	    printf("%lld\n",d[n-1]);
	}
    }
    return 0;
}