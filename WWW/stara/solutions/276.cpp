#include <cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    while (n--)
    {
        int k,o,d;
        scanf("%d%d%d",&k,&o,&d);
        if (m<k) printf("komin\n"); else
        if (m<o) printf("okno\n"); else
        if (m<d) printf("drzwi\n"); else
                 printf("brak\n");
    }

    return 0;
}

