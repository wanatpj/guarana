#include<cstdio>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int size=40000;    
    struct zez
    {	int id;		//kto zeznaje
	char typ;	//typ zeznania
	bool osk;	//czy oskarza;
	int oskar;	//kogo oskarza;
	int nr;		//nr zeznania
    };
queue<zez> kol;
vector<int> adj[size];
int osk[size]; //kto wg tego jest winny
int d,n,z,b,il_klam[size],mn,winni;
char a[7];
bool klamca[size];
set<int> niew[size]; //lista niewinnych dla konkretego podejrzanego
zez zezn[size],zn;
void zeruj()
{	
    mn=1000000;	
    for(int i=1;i<=20008;++i)
    {	zezn[i] = zn;
	osk[i] = 0;
	klamca[i] = false;
	niew[i].clear();
	adj[i].clear();
	il_klam[i] = 0;
    }
}
void bfs()
{	
    zez a;
    while(kol.size())
    {	a=kol.front();
	kol.pop();
	if( a.osk && !osk[a.id])
	    osk[a.id] = a.oskar;
	else if(!a.osk) 
	    niew[a.id].insert(a.oskar);
	else if(osk[a.id] && a.oskar != osk[a.id])
	    klamca[a.id] = true;
	for(vector<int>::iterator it=adj[a.nr].begin() ; it!=adj[a.nr].end(); ++it)
	{
	    zezn[ *it ].oskar = a.oskar;
	    if( zezn[*it].typ == 'P')
		zezn[*it].osk = a.osk;
	    else
		zezn[*it].osk = !a.osk;
	    kol.push(zezn[*it]);
	}
    }
    for(int i=1;i<=n;++i)
	if( niew[i].find(osk[i]) != niew[i].end() )
		klamca[i]=true;
}
void wyznacz_klamcow()
{
    for(int i=1;i<=n;++i)
	if(!klamca[i] && !osk[i])
    	    for(set<int>::iterator it=niew[i].begin();it!=niew[i].end();++it)
	    	++il_klam[*it];    
	else if(!klamca[i])
	    for(int j=1;j<=n;++j)
		if(j!=osk[i])
		    ++il_klam[j];
    for(int i=1;i<=n;++i)
	mn = min(mn,il_klam[i]);
    for(int i=1;i<=n;++i)
	if(mn == il_klam[i])
	    printf("%d ",i);
    printf("\n");
}
int main()
{	
    scanf("%d",&d);
    while(d--)
    {	zeruj();
	scanf("%d%d",&n,&z);
	for(int i=1;i<=z;++i)
	{
	    zezn[i].osk=true;	
	    zezn[i].nr=i;	
	    scanf("%d%s%d",&zezn[i].id,a+1,&b);
	    zezn[i].typ = a[1];
	    if(zezn[i].typ == 'W')
	    {	zezn[i].oskar = b;
		kol.push(zezn[i]);
	    }
	    else
		adj[b].push_back(i);		
	}
	bfs();
	wyznacz_klamcow();
    }
    return 0;
}