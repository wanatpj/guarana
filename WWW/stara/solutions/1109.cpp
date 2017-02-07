#include<cstdio>
#include<vector>
using namespace std;

vector<pair<long long, long long> >rozklad; //rozklad liczby n, first=p, second=p^k
vector<int>P; //3432 liczby pierwsze
const int S=32000;
bool h[S];
void sito()
{
    for(int i=2; i<S; ++i) h[i]=true;
    for(int i=2; i<S; ++i) if(h[i])
    {
	for(int j=i*2; j<S; j+=i) h[j]=false;
	P.push_back(i);
    }
}

void rozloz(int n, vector<pair<long long,long long> >&v)
{
    long long temp;
    vector<int>::iterator it=P.begin();
    for(; (*it)*(*it)<=n; ++it)
    {
        if(n%(*it)==0)
        {
    	    temp=1;
    	    while(n%(*it)==0) {n/=(*it); temp*=(*it);}
    	    v.push_back(make_pair((*it),temp));
        }
    }
    if(n!=1) v.push_back(make_pair(n,n));
}

int f(long long mod)
{
    long long L=1,q,Q;
    int p_licznik=0;
    for(int i=0; i<rozklad.size(); ++i)
    {
	q=rozklad[i].first; Q=rozklad[i].second*q;
	--q; --Q;
	while(q%mod==0) {q/=mod; p_licznik--;}
	while(Q%mod==0) {Q/=mod; p_licznik++;}
        L*=Q/q;
	L%=mod;
    }
    if(p_licznik>0) return 0;
    return (L%mod+mod)%mod;
}

int main()
{
    int c;
    long long temp,mod,res,modulo;
    int n;
    sito();
    scanf("%d %lld",&c,&mod);
    while(c--)
    {
	rozklad.clear();
	scanf("%d",&n);
	rozloz(n,rozklad);
	printf("%d\n",f(mod));
    }
    return 0;
}
