#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10010
int T[MAXN];

void testcase(){
    int n; scanf("%d", &n);
    for (int i=1; i<=n; ++i) scanf("%d", &T[i]);
    
    if ( n == 1 ){
    	printf("%d\n", T[1]);
    	return;
    }
    
    sort( T+1, T+n+1 );
    
    int ret = T[2], cnt = 2;
    
    if ( n == 2 ){
    	printf("%d\n", ret);
    	return;
    }
    
    if ( n % 2 ){
    	ret += T[3] + T[1];
    	++cnt;
    }
    
    while(cnt < n){
    	ret += min( 2*T[1] + T[cnt+1] + T[cnt+2], T[1] + 2*T[2] + T[cnt+2]);
    	cnt+=2;
    }

    printf("%d\n", ret);
}
int main(){
int d; scanf("%d", &d);
while(d--) testcase();
return 0;
}

