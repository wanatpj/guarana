#include<cstdio>
using namespace std;

int main() {
        int d,n,c,s,t;
        scanf("%d",&d);
        while(d--) {
                s = 0;
                scanf("%d",&n);
                while(n--) {
                      scanf("%d",&t);
                      s += t;  
                }       
                scanf("%d",&c);
                printf("%d\n",c%s);
        }       
}
