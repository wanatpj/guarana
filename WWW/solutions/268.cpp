#include <cstdio>
using namespace std;
int d,n,m,a,s;
int main()
{
scanf("%d", &d);
while(d--) {
    scanf("%d", &n);
    s=0;
    while(n--) {
        scanf("%d", &a);
        s+=a;
    }
    scanf("%d", &m);
    if (s==0) printf("%d\n", m);
    else printf("%d\n", m%s);
}

return 0;
}
