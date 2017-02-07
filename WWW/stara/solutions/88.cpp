#include <cstdio>
#include <vector>

using namespace std;

#define lli long long int

lli NWD(lli a, lli b)
{
    if(b==0) return a;
    if(a==b) return a;
    if(b>a) return NWD(b,a);
    return NWD(b, (a%b));
}
lli NWW(lli p, lli q)
{
    lli a=p*q;
    lli b=NWD(p,q);
    a/=b;
    return a;
}

lli wynikp(lli p, lli q)
{
    if(p==q) return p*q;
    else if(p<q) return p*(p+1)/2;
    else return (p*q - (q*(q-1)/2));
}

pair<lli, lli> Heureza(lli p, lli q)
{
    lli dz=NWD(p,q);
    lli wynikA = wynikp((p/dz), (q/dz));
    lli wynikB = (p/dz)*(q/dz)-wynikA;
    dz=NWD(wynikA, wynikB);
    wynikA/=dz;
    wynikB/=dz;
    return make_pair(wynikA, wynikB);
}


int main()
{
    int zw;
    scanf("%d", &zw);
    for(int i=0; i<zw; i++)
    {
        lli p,q;
        scanf("%Ld%Ld", &p, &q);
        pair<lli, lli> para = Heureza(p,q);
        printf("%Ld %Ld\n", para.first, para.second);
    }

    return 0;
}

