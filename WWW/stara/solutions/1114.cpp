#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int z,d,s,t,p;
long long x,y;
int doch[30][10000];
int wynik[10000];
int new_wynik[10000];	
	struct point
	{	long long x,y;
	};
point pkt;
	struct kraw
	{	point a,b; // a.x<b.x
		int nr_d ;// dzialka do ktorej nalezy 0- nie nalezy do zadnej
		bool wyj; // czy idac do niego z dolu wychodzi sie z dzialki
	};
	struct skarb
	{	point pol;
		int t;		//czas wydobycia
		int war;	//wartosc
	};
	inline bool operator<(const skarb &a,const skarb &b)
	{	return a.pol.x < b.pol.x;
	}
	long long il_wek(point a,point b,point c)
	{	return (a.x-b.x)*(c.y-b.y) - (a.y-b.y)*(c.x-a.x);
	}
	inline bool cmp1(const kraw &a,const kraw &b)//koncowki musza byc takie same;
	{	if(a.a.x<b.a.x)
			return true;
		if( a.a.x==b.a.x )
		{	if(a.a.y<b.a.y)
				return true;
			if( a.a.y == b.a.y )
			{   if( a.b.x < b.b.x)
					return true;
				if( a.b.x == b.b.x && a.b.y<b.b.y)
					return true;
			}
		}
		return false;
	}
	inline bool cmp2(const kraw &a,const kraw &b)
	{	if( a.b.x < b.b.x)
			return true;
		if( a.b.x == b.b.x)
		{	if(a.b.y<b.b.y)
				return true;
			if( a.b.y==b.b.y)
			{	if(a.a.x<b.a.x)
					return true;
				if( a.a.x==b.a.x && a.a.y<b.a.y)
					return true;
			}
		}
		return false;
	}
	inline bool operator<(const kraw &a,const kraw &b)
	{	if(a.a.x == b.a.x && a.a.y == b.a.y && a.b.y == b.b.y && a.b.x == b.b.x)
			return false;
		if(a.a.x == a.b.x && a.a.y == a.b.y)
			return !(b < a);
 		return (il_wek(a.b, a.a ,b.a) >= 0 && b.a.x >= a.a.x && b.a.x<=a.b.x) || (il_wek(a.b, a.a ,b.b) >= 0 && b.b.x >= a.a.x && b.b.x<=a.b.x) ;
	}
kraw kr;
set<kraw,bool (*)(const kraw &, const kraw &)> krw_p(cmp1);	//krawedzie posortowane po poczatkach
set<kraw,bool (*)(const kraw &, const kraw &)> krw_k(cmp2);	//krawedzie posortowane po koncach
set<kraw> wyj;			//kraw którymi wychodzi z działek
set<kraw> wej;			//kraw którymi się wchodzi do działek
set<kraw>::iterator it_wej,it_wyj;
vector<point> dz[300];
vector<skarb> sk[300];	//skarby w dzialce i;
skarb  skar[100000],zero;
int najnizszy(int id)
{	long long mn=INT_MAX;
	for(vector<point>::iterator it=dz[id].begin() ; it!=dz[id].end(); ++it)
		mn=min(mn,it->y);
return mn;
}
void wyznacz_kr_dz(int id,int dl)
{	int mn = najnizszy(id);
	bool kier = true;
	for(int i=0;i<dl;++i)
	{	if(dz[id][i+1].y == mn)
		{	if( il_wek( dz[id][(i+2)%dl],dz[id][(i+1)%dl] ,dz[id][i] ) < 0)
				kier = false;
			break;
		}
	}
	for(int i=0;i<dl;++i)
	{	if(kier)
		{	if(dz[id][i].x > dz[id][(i+1)%dl].x)
				kr.wyj = true;
			else
				kr.wyj = false;
		}
		else
		{	if(dz[id][i].x < dz[id][(i+1)%dl].x)
				kr.wyj = true;
			else
				kr.wyj = false;
		}
		kr.a = dz[id][i];
		kr.b = dz[id][(i+1)%dl];
		if(kr.a.x > kr.b.x) 
			swap(kr.a,kr.b);
		kr.nr_d = id;
		if((!kr.wyj && krw_p.find(kr)!=krw_p.end()) || kr.a.x == kr.b.x);
		else
		{	krw_p.insert(kr);
			krw_k.insert(kr);
		}
	}
}
void wyznacz_dzialke(skarb skr)
{
	set<kraw,bool (*)(const kraw &, const kraw &)>::iterator ws;
	while(krw_p.size() && krw_p.begin()->b.x <= skr.pol.x)
	{	ws = krw_p.begin();
		krw_k.erase(krw_k.find(*ws));
		krw_p.erase(krw_p.begin());
	}
	while(krw_k.size() && krw_k.begin()->b.x <= skr.pol.x)
	{	ws = krw_k.begin();
		if(ws->wyj)
		{	if( wyj.find(*ws) != wyj.end() )
				wyj.erase(wyj.find(*ws));
		}
		else
		{	if( wej.find(*ws)!=wej.end() )	
				wej.erase(wej.find(*ws));
		}
		if( krw_p.find(*ws)!=krw_p.end())
			krw_p.erase(krw_p.find(*ws));
		krw_k.erase(ws);
	}
	while(krw_p.size() && krw_p.begin()->a.x <= skr.pol.x)
	{	ws = krw_p.begin();
		if(krw_p.begin()->wyj)
			wyj.insert(*ws);
		else
			wej.insert(*ws);
		krw_p.erase(krw_p.begin());
	}
	while(krw_k.size() && krw_k.begin()->b.x <= skr.pol.x)
	{	ws = krw_k.begin();
		if(krw_k.begin()->wyj)
			wyj.erase(wyj.find(*ws));
		else
			wej.erase(wej.find(*ws));
		if( krw_p.find(*ws)!=krw_p.end())	//dodane powinno tylko pomagac
			krw_p.erase(krw_p.find(*ws));
		krw_k.erase(krw_k.begin());
	}
	kr.a = skr.pol;
	kr.b = skr.pol;
	it_wej = wej.upper_bound(kr);
	it_wyj = wyj.upper_bound(kr);
	if(it_wyj == wyj.end())
		sk[0].push_back(skr);
	else
	{	if( it_wej == wej.end() || (*it_wej) < kr || (*it_wyj) < (*it_wej) )
			sk[it_wyj->nr_d].push_back(skr);
		else
			sk[0].push_back(skr);
	}	
}
void wyznacz_doch_dzialki(int id)
{	for(vector<skarb>::iterator it = sk[id].begin();it!=sk[id].end();++it)
	{	for(int i = t - it->t;i>=0;--i)
			doch[id][i+it->t] = max(doch[id][i+it->t],doch[id][i]+it->war);
	}
	if(id)
	{	int mx = 0;
		int t_max=0;
		for(vector<skarb>::iterator it = sk[id].begin();it!=sk[id].end();++it)
		{	t_max +=it->t;
			mx += it->war;
		}
		mx *= (100+dz[id].size());
		if((mx%100))
			mx+=100;
		mx /= 100;
		for(int i = t_max;i<=t;++i)
			doch[id][i] = max(mx,doch[id][i]);
	}
}
void powieksz_wynik(int id)
{	for(int i=1;i<=t;++i)
	{	int dod = doch[id][i];
		for(int j=t-i ;j>=0;--j)
			new_wynik[j+i] = max(new_wynik[j+i],wynik[j] + dod); 
	}
	for(int i=1;i<=t;++i)
		wynik[i] = new_wynik[i];
}
void zeruj()
{	wyj.clear();
	wej.clear();
	krw_p.clear();
	krw_k.clear();
	for(int i=0;i<=d;++i)
	{	dz[i].clear();
		sk[i].clear();
		for(int j=0;j<=t;++j)
			doch[i][j] = 0;
	}
	for(int i=0;i<=s;++i)
		skar[i] = zero;
	for(int i=0;i<=t;++i)
		wynik[i]=0;
}
int main()
{	scanf("%d",&z);
	while(z--)
	{	scanf("%d%d",&d,&s);
		for(int i=1;i<=d;++i)
		{	scanf("%d",&p);
			for(int j=1;j<=p;++j)
			{	scanf("%lld%lld",&pkt.x,&pkt.y);
				dz[i].push_back(pkt);
			}
		}
		for(int i=1;i<=s;++i)
			scanf("%d%d%d%d", &skar[i].pol.x, &skar[i].pol.y, &skar[i].t, &skar[i].war);
		sort(skar+1 , skar+s+1);
		for(int i=1;i<=d;++i)
			wyznacz_kr_dz(i,dz[i].size());
		for(int i=1;i<=s;++i)
			wyznacz_dzialke(skar[i]);
		scanf("%d",&t);
		for(int i=0;i<=d;++i)
			wyznacz_doch_dzialki(i);
		for(int i=1;i<=t;++i)
			wynik[i]=doch[0][i];
		for(int i=1;i<=d;++i)
			powieksz_wynik(i);
		printf("%d\n",wynik[t]);
		void zeruj();
	}
return 0;
}