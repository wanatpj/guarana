#include<cstdio>
using namespace std;

int main() {
        int n,m,k,o,d;
        scanf("%d %d",&n,&m);
        while(n--) {
                scanf("%d %d %d",&k,&o,&d);
                if (k>m) 
                        printf("komin\n");
                else if (o>m)
                        printf("okno\n");
                else if (d>m)
                        printf("drzwi\n");
                else
                        printf("brak\n");
        }       
}
