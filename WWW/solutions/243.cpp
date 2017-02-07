#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define duzo 100001
#define inf 2147483647
class Wierzcholek{
public:
int Nr,Odleglosc,NrStacjiBenz;
Wierzcholek(int num){Nr=num;}
Wierzcholek(int num,int odl){Nr=num;Odleglosc=odl;}
Wierzcholek(int num,int odl,int nrb){Nr=num;Odleglosc=odl;NrStacjiBenz=nrb;}
bool operator < (const Wierzcholek &X)const
{
if(Odleglosc==X.Odleglosc)
return NrStacjiBenz>X.NrStacjiBenz;
return Odleglosc>X.Odleglosc;
}
};
class Krawedz{
public:
int Dokad,Waga;
Krawedz(int A,int B){Dokad=A;Waga=B;}
};
priority_queue<Wierzcholek> Kol;
vector<Krawedz> Graf[duzo];
bool Roz[duzo];
int odl[duzo];
int num[duzo];
int n,m,r;
int A,B,C;
int q;
int w;
int main()
{
	scanf("%d%d%d",&n,&m,&r);
	vector<int> Benz;
	for(int i=1;i<=n;i++)
	{
		odl[i]=inf;
		Roz[i]=false;
	}	
	for(int fr=0;fr<r;fr++)
	{
		scanf("%d",&w);
		odl[w]=0;
		num[w]=w;
		Benz.push_back(w);
		Kol.push(Wierzcholek(w,0,w));
	}
	for(int fm=0;fm<m;fm++)
	{
		scanf("%d%d%d",&A,&B,&C);
		Graf[A].push_back(Krawedz(B,C));
		Graf[B].push_back(Krawedz(A,C));
	}
	while(!Kol.empty())
	{
		Wierzcholek X = Kol.top();
		Kol.pop();
		if(Roz[X.Nr]==true)continue;
		Roz[X.Nr]=true;
		for(int i=0;i<Graf[X.Nr].size();i++)
		{
			int S=Graf[X.Nr][i].Dokad;
			int D=Graf[X.Nr][i].Waga;
			if(odl[X.Nr]+D<odl[S])
			{
				odl[S]=odl[X.Nr]+D;
				Kol.push(Wierzcholek(S,odl[S],X.NrStacjiBenz));
				num[S]=X.NrStacjiBenz;
			}
		}
	}
	scanf("%d",&q);
	for(int fq=0;fq<q;fq++)
	{
		scanf("%d",&A);
		if(odl[A]==inf)
			printf("BRAK\n");
		else
			printf("%d %d\n",num[A],odl[A]);
	}
	


	return 0;
}
