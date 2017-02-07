#include <cstdio>
using namespace std;
int n,m,a,b,c;
int main()
{
scanf("%d %d", &n, &m);
while(n--) {
scanf("%d %d %d", &a, &b, &c);
if (m<a) printf("komin\n");
else if (m>=a && m<b) printf("okno\n");
else if (m>=a && m>=b && m<c) printf("drzwi\n");
else printf("brak\n");
}

return 0;
}