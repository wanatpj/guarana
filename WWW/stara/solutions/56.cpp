#include <cstdio>

#define lli long long int

using namespace std;

int main()
{
    int zw;
    scanf("%d", &zw);
    char a='a';
    while(a!='\n')
        a=getchar();
    for(int i=0; i<zw; i++)
    {
        lli wyn;
        lli temp;
        wyn=temp=0;
        bool petla, mnoz;
        petla = true;
        mnoz=false;
        char c;
        while(petla)
        {

            if(scanf("%c", &c)==EOF)
            {
                petla=false;
                wyn+=temp;
                temp=0;
            }
            if(c>='1' && c<='9')
            {
                if(mnoz) temp*=(lli)(c-'0');
                else temp+=(lli)(c-'0');
            }
            else if(c=='+')
            {
                wyn+=temp;
                temp=0;
                mnoz=false;
            }
            else if(c=='*')
            {
                mnoz=true;
            }
            else
            {
                petla=false;
                wyn+=temp;
                temp=0;
            }

        }



        printf("%d\n", wyn);

    }


    return 0;
}

