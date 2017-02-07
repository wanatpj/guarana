#include <iostream>
using namespace std;

long long suma, mtemp;
char tab[40];
int t;

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        for(int i=0; i<40; i++) tab[i]='0';
        scanf("%s", tab);
        suma=0;
        int it=1;
        mtemp=(long long)(tab[0]-'0');   
        while(it < strlen(tab))
        {
            while(tab[it]=='*' && it < strlen(tab))
            {
                mtemp*=(long long)(tab[it+1]-'0');
                it+=2;
            }  
            suma+=mtemp;
            //cout << suma << endl;
            mtemp=(long long)(tab[it+1]-'0');
            it+=2;
        }
        suma+=mtemp;
        printf("%lld\n", suma);
    }
    return 0;   
}
