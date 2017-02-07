#include <cstdio>

using namespace std;

int main()
{
    int lw;
    scanf("%d",&lw);

    while (lw--)
    {
        int sum = 0, n;
        scanf("%d",&n);

        while (n--)
        {
            int a;
            scanf("%d",&a);
            sum += a;
        }
        int c;
        scanf("%d",&c);

        if (sum <= 0)
            printf("%d\n",c);
        else
            printf("%d\n",c%sum);
    }

    return 0;
}

