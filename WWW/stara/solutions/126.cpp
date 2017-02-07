#include <cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    int del=0, add=0;
    for(int i=0; i<m; i++)
    {
        int a,b,c,f1,f2;
        scanf("%d%d%d%d%d", &a, &b, &c, &f1, &f2);
        if(f1!=f2)
        {
            if(f1==0)
                add++;
            else
                del++;
        }
    }
    if(add==del) printf("%d\n", add);
    else printf("NIE\n");


    return 0;
}               

