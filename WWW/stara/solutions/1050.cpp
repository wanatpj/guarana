#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
long long inf = 1000000000000000002ll;
const int size=131072;
int d,n,m;
long long k;
	struct edge
	{	int val,t,id;
		long long il_pod; 
	};	
	inline bool operator<(const edge &a,const edge &b)
	{	if (a.val<b.val)
			return true;
		else if(a.val == b.val && a.t<b.t)
			return true;
		return false;
	}
set<edge> dlug[size];	//zbior poczatkow wsp ciagow danej dlugosci
vector<int> wyn;
vector<long long> sum[size]; //suma roznych podciagow  danej dlugosci na określonym przedziale
vector<int> l_syn[size];	//lewy syn w sum
vector<int> p_syn[size];	//prawy syn w sum
int drz[2*size+7];//ciag maxymalnej dlugosci na zadanym przedziale
	struct pozycje
	{	int val,poz;
	};	
	inline bool operator<(const pozycje &a,const pozycje &b)
	{	return a.val<b.val;
	}
pozycje kol[size];
pozycje stos[size];
pozycje kol_s[size];
void zeruj()
{	for(int i = 1; i <= 2*size+1; ++i)
		drz[i]=0;
	for(int i = 1;i<=n;++i)
	{	kol[i].val=0;
		kol_s[i].val=0;
		stos[i].val=0;
		dlug[i].clear();
		sum[i].clear();
		l_syn[i].clear();
		p_syn[i].clear();
	}
	wyn.clear();
}
int ciag_max(int p,int k,int pocz,int kon,int id)
{	int ret = 0;
	if(p<=pocz && k>=kon)
		return drz[id];
	if(p<=(kon+pocz)/2)
		ret = max(ret, ciag_max(p, k, pocz, (pocz+kon)/2, id*2) );
	if(k>(kon+pocz)/2)
		ret = max(ret, ciag_max( p, k, (pocz+kon)/2+1, kon, id*2+1) );
return ret;
}
long long il_podz(int p,int k,int pocz,int kon,int id,int dl)
{	long long ret = 0;
	//printf("p=%d,k=%d,pocz=%d,kon=%d\n",p,k,pocz,kon);
	//printf("l_syn=%d p_syn=%d\n",l_syn[dl][id],p_syn[dl][id]);
	if(p<=pocz && k>=kon)
	{	return sum[dl][id];
		//printf("zwracam %d\n",sum[dl][id]);
	}
	if(l_syn[dl][id] && p<=(kon+pocz)/2)
		ret += il_podz( p, k, pocz, (pocz+kon)/2, l_syn[dl][id], dl) ;
	if(p_syn[dl][id] && k>(kon+pocz)/2)
		ret += il_podz( p, k, (pocz+kon)/2+1, kon, p_syn[dl][id], dl) ;
//printf("p=%d,k=%d,pocz=%d,kon=%d\n",p,k,pocz,kon);
//printf("zwracam %d\n",ret);
return min(ret,inf);
}
void utworz_v(int roz)
{	sum[roz].push_back(0);
	l_syn[roz].push_back(0);
	p_syn[roz].push_back(0);
}
void dodaj_pod(int mjs,int pocz,int kon,int id,int dl,long long il_pod)
{	sum[dl][id] += il_pod;
	sum[dl][id] = min(inf,sum[dl][id]);
 //	printf("mjs=%d pocz=%d kon=%d\n",mjs,pocz,kon);
	if(pocz!=kon)
	{	if(mjs<=(pocz+kon)/2)
		{	if(!l_syn[dl][id])
			{	l_syn[dl][id] = sum[dl].size();
				utworz_v(dl);
			}
			dodaj_pod(mjs,pocz, (pocz + kon)/2, l_syn[dl][id], dl, il_pod);	
		}
		else
		{	if(!p_syn[dl][id])
			{	p_syn[dl][id] = sum[dl].size();
				utworz_v(dl);
			}
			dodaj_pod(mjs,(pocz+kon)/2+1, kon, p_syn[dl][id], dl, il_pod);	
		}
	}
}
void powieksz_ciag(int mjs,int wiel ,int pocz,int kon, int id)
{	drz[id] = max(drz[id],wiel);
	if(pocz!=kon)
	{	if(mjs<=(pocz+kon)/2 )
			powieksz_ciag(mjs , wiel, pocz, (pocz+kon)/2, id*2);
		else
			powieksz_ciag(mjs , wiel, (pocz+kon)/2+1, kon, id*2+1);
	}
}
void wykonaj()
{	edge edg;
	set<edge>::iterator szuk;
	for(int i=m;i>=1;--i)
	{	int id = lower_bound(kol_s+1,kol_s+n+1,stos[i])-kol_s;
		if( kol_s[id].val == stos[i].val)
		{	id = kol_s[id].poz;
			edg.val = kol[id].val;
			edg.t = i;
 			edg.id=id;
 			int roz = ciag_max(id+1,n,1,size,1)+1;
 			if(!sum[roz-1].size())
				utworz_v(roz-1);
			edg.il_pod = il_podz(id+1,n,1,size,0,roz-1);
			edg.il_pod = max(edg.il_pod,1ll);
			if(!sum[roz].size())
				utworz_v(roz);
			szuk = dlug[roz].upper_bound(edg);
			if( szuk->val != edg.val )//chyba ok moga byc błedy
			{	dodaj_pod(id,1,size,0,roz,edg.il_pod);
				powieksz_ciag(id,roz,1,size,1);
			}
			else
			{	dodaj_pod(id,1,size,0,roz,edg.il_pod - szuk->il_pod);
				powieksz_ciag(id,roz,1,size,1);
			}
			dlug[roz].insert(edg);
			//TO NIE DZIALA JAK POWINNO
		}
	};
	int dlg = 0;
	for(int i=1;i<=n;++i)
		if(dlug[i].size())
			dlg=i;
	int old_dlug = dlg;
	int glob_id=0;
	int global_t=0;
	while(dlg)	//topewnie jest źle
	{	long long ilosc = 0;
		bool znal=false;
		for(set<edge>::iterator it = dlug[dlg].begin();it!=dlug[dlg].end();++it)
  		{	szuk = it;
  			while( szuk!=dlug[dlg].end() && it->val == szuk->val )
  				++szuk;	
  			it = --szuk;
  			if(it->t > global_t && it->id > glob_id)
			{	ilosc += it->il_pod;
				if(ilosc >= k) 
 				{	global_t = it->t;
 					glob_id = it->id;
					wyn.push_back(it->val);
					k -= (ilosc - it->il_pod);
					znal=true;
					break;
				}
			}
		}
		--dlg;
	}
	printf("%d\n",old_dlug);
	if(wyn.size()==old_dlug && wyn.size())
		for(vector<int>::iterator it = wyn.begin();it!=wyn.end();++it)
			printf("%d ",*it);
	else
		printf("-1");
	printf("\n");
}
int main()	//jeszcze nieodporny na nieistniejące
{	scanf("%d",&d);
	while(d--)
	{	scanf("%d%d%lld",&n,&m,&k);//sprawdz co najpierw wczytac
		for(int i=1;i<=n;++i)
		{	scanf("%d",&kol[i].val);
			kol_s[i].val = kol[i].val;
			kol_s[i].poz = i;
		}
		for(int i=1;i<=m;++i)
			scanf("%d",&stos[i].val);
		sort(kol_s+1,kol_s+n+1);
		wykonaj();
		zeruj();
	}
return 0;
}