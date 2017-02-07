
#include<cstdio>
#include<vector>

using namespace std;

const int RM=1009;

#define lli long long int


const int mRM=1000000; // CZY NIE TRZEBA WIECEJ ?
const int m2RM=1200000;
bool liczby[mRM];
vector<int> pier;
int rozklad[m2RM];
int actSize;
bool debug=false;

void sito()
{
if(debug)    printf("akunamatata\n");


    for(int i=0; i<mRM; i++)
        liczby[i]=true;
                                // ROZKLAD LICZBY N PO K ZEROWANY

    for(int i=0; i<m2RM; i++)
        rozklad[i]=0;
    actSize=0;
    liczby[0]=liczby[1]=false;
    for(int i=2; i<mRM; i++)
    {
        if(liczby[i])
        {
            pier.push_back(i);
            lli temp=2*i;
            while(temp<mRM)
            {
                liczby[temp]=false;
                temp+=i;
            }
        }
    }
    return;
}
void rozloz(lli a, bool plus)
{
    int s=pier.size();
    for(int i=0; i<s; i++)
    {
        if(a==1) break;
        while(a%pier[i]==0)
        {
            if(plus) rozklad[i]++;
            else rozklad[i]--;
            a/=pier[i];
            if(actSize<i) actSize=i;
        }
    }
    if(a!=1)
    {
        pier.push_back(a);
        actSize=pier.size()-1;
        if(plus) rozklad[actSize]++;
        else rozklad[actSize]--;
    }
    return;
}
lli zloz(lli m)
{
    lli wyn=1;
    for(int i=0; i<=actSize; i++)
    {
        for(int j=0; j<rozklad[i]; j++)
            {wyn*=pier[i]; wyn%=m;}
    }
    return wyn;
}
lli pot(lli a,lli b, lli c)
{
    if(b==0)
    {
        if(1>c) return 0;
        else return 1;
    }
    if(b==1)
    {
        if(a>c) return a%c;
        else return a;
    }
    lli wyn=pot(a, (b/2), c);
    if(b%2==0) return ((wyn*wyn)%c);
    else
    {
        wyn*=wyn;
        wyn%=c;
        wyn*=a;
        if(wyn>=c)
            wyn-=c;
        return wyn;
    }
}

vector<lli> Licz(lli n, lli k, lli m)
{
    vector<lli> Wynik;
    if(k==1)
    {
        Wynik.push_back(pot(2,n,m));
        return Wynik;
    }
    else if(k==2)
    {
        lli tempwyn=pot(2,n-1,m);
        Wynik.push_back(tempwyn);
        Wynik.push_back(tempwyn);
        return Wynik;
    }
    if(debug) printf("licze\n");

    vector<lli> liczby[RM];
    for(int i=0; i<k; i++)
        liczby[i].clear();

    liczby[0].push_back(zloz(m));
if(debug)    printf("dodalem %d\n", zloz(m));
    for(lli i=1; i<=n; i++)
    {
        lli now=i%k;
        lli prev=now-1;
        if(prev<0) prev=k-1;
        rozloz(n-i+1, true);
if(debug)
{
        for(int j=0; j<10; j++)
            printf("%d ", rozklad[j]);
        printf("ajaja %d\n", zloz(m));
}
        rozloz(i, false);
        liczby[now].push_back(zloz(m));
if(debug)       printf("dodalem %d\n", zloz(m));
    }
    Wynik.clear();
    for(lli i=0; i<k; i++)
    {
        lli temp=0;
        int s=liczby[i].size();
        for(int j=0; j<s; j++)
        {
            temp+=liczby[i][j];
            while(temp>=m)
                temp-=m;
        }
        Wynik.push_back(temp);
    }
    return Wynik;
}


int main()
{
    lli n,k,m;
    scanf("%Ld%Ld%Ld", &n, &k, &m);
    sito();
    vector<lli> Wynik=Licz(n,k,m);
    int s=Wynik.size();
    for(int i=0; i<s; i++)
        printf("%Ld\n", Wynik[i]);

    return 0;
}
