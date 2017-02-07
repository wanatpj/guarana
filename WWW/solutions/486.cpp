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
                if (s!=0)
                printf("%d\n",c%s);
                else
                printf("%d\n",c);
        }       
}
