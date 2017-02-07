#include <cstdio>
#include <algorithm>
#define LLD long long int
#define MK 1001

using namespace std;

LLD Pas[MK][MK];
LLD B[MK][2];

int main()
{
    LLD n,k,m;
    scanf("%Ld%Ld%Ld",&n,&k,&m);

    for (int i=0;i<MK;i++)
        Pas[1][0] = 1;

    for (int i=1;i<MK;i++)
        for (int j=1;j<=i;j++)
            Pas[i][j] = (Pas[i-1][j]+Pas[i-1][j-1])%m;


    int Co = 0;

    for (int i=0;i<k;i++)
        B[i][0] = Pas[k-1][i]%m;

    int Iter = k-1;
    n++;
    while (Iter <= n )
    {
        int P = 1-Co;
        for (int i=0;i<k;i++)
            B[i][P] = (B[i][Co] + B[ (i-1>=0)?(i-1):(k-1) ][Co])%m;
        Co = P;
        Iter++;
    }

    for (int i=1;i<k;i++)
        printf("%Ld\n",B[i][Co]);
    printf("%Ld\n",B[0][Co]);
    return 0;
}
