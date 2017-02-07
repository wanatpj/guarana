#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
using namespace std;
const int size = 100040;
int A=2,B=1,b_size,a_size,pom=0;
int d,z,a,n;
int zbior[size];
int poz[ size ];	//pozycje wierzchołkow
int wier[ size ];	//wierzcholki na konkretnych pozycjach;
bool jest[ size ];
queue<int> kol;
queue<int> kol_z;	//kolejka wierzcholków do zmiany
vector<int> adj[size];
	struct wyn
	{	int pocz,kon;
	};
wyn wynik,wn;
void zeruj()
{	for(int i=0;i<=n+2;++i)
	{	wier[i]=i;
		poz[i]=i;
		zbior[i]=0;
		adj[i].clear();
		jest[i]=false;
	}
}
int bfs(int pcz)//to powinno byc dobre
{	kol.push(pcz);
	jest[pcz] = true;
	int it = poz[pcz]+1;
	while(kol.size())
	{	int id = kol.front();
		kol.pop();
		for(vector<int>::iterator it = adj[id].begin();it!=adj[id].end();++it)
			if(!jest[*it])
			{	jest[*it] = true;
				kol.push(*it);
				kol_z.push(*it);
			}
	}
	int kn = poz[pcz] + kol_z.size();
	while(kol_z.size())
	{	int id = kol_z.front();
		kol_z.pop();
		if(poz[id] > kn)
		{	while(it <= kn && jest[wier[it]])
			{	jest[wier[it]]=false;
				++it;
			}
			swap( poz[id],poz[wier[it]] );
			swap( wier[poz[id]],wier[poz[wier[it]]] ); 
			++it;
		}
		jest[id] = false;
	}
	jest[pcz] = false;
return kn;
}
int leks(const int &pocz,const int &kon)
{	int mn = n+3;
	for(int i = pocz;i <= kon;++i)
		mn=min(mn,wier[i]);
return mn;
}
bool klika(int *tab,int roz)
{	for(int i=0;i<=roz;++i,++tab)
		if( adj[*tab].size() < roz)
			return false;
return true;
}
void wyznacz_zbiory_pocz(int *tab,int roz,int *pocz) //chyba dobrze
{	int a, b;
	for(int i=0;i<=roz;++i,++tab)
		if(adj[*tab].size()<roz)
		{	a = *tab;
			break;
		}
	tab = pocz;
	for(int i=0;i<=roz;++i,++tab)
		if(*tab!=a && !binary_search(adj[a].begin(),adj[a].end(),*tab) )
		{	b = *tab;
			break;
		}
	tab=pocz;
	zbior[a]=B;
	zbior[b]=B;
	for(int i=0;i<=roz;++i,++tab)
	{	if(*tab!=a && binary_search(adj[a].begin(),adj[a].end(),*tab) )
		{	if(*tab!=b && binary_search(adj[b].begin(),adj[b].end(),*tab) )
			{	zbior[*tab] = A;
				++a_size;
			}
			else
			{	zbior[*tab] = B;
				++b_size;
			}
		}
		else if(*tab!=b && binary_search(adj[b].begin(),adj[b].end(),*tab) )
		{	zbior[*tab] = B;
			++b_size;
		}
	}
}
void wyznacz_zbior(int id,int ilosc)
{	int il_a=0, il_b=0;
	for(vector<int>::iterator it=adj[id].begin();it!=adj[id].end();++it)
	{	if(zbior[*it])
		{	if(zbior[*it] == A)
				++il_a;
			else
				++ il_b;
		}
	}
	if(a_size == il_a)
	{	++ b_size;
		zbior[id] = B;
	}
	else if ( b_size == il_b )
	{	++ a_size;
		zbior[id] = A;
	}
	else if ( il_a )
	{	a_size=0;
		zbior[id] = B;
		for(vector<int>::iterator it=adj[id].begin();it!=adj[id].end();++it)
			if(zbior[*it] == A)
			{	++zbior[*it];
				++a_size;
			}
		++A;
	}
	else
	{	++A;	a_size = 0;
		for(vector<int>::iterator it=adj[id].begin();it!=adj[id].end();++it)
			if(zbior[*it])
			{	zbior[*it] = A;
				++a_size;
			}
	}
	b_size = ilosc+1 - a_size;
}
int podziel(int *pocz,int * kon,int *odj) // tu musi być coś jeszcze źle
{	//printf("pocz=%d kon=%d\n",*pocz,*kon);
	while( (kon-pocz)>0 )
	{	//printf("pocz=%d kon=%d\n",*pocz,*kon);
		while(zbior[*pocz] == A)
			++pocz;
		while(zbior[*kon] !=A && kon!=odj)
			--kon;
		if( (kon-pocz)>0 && zbior[*pocz] !=A && zbior[*kon] == A)
		{	swap(poz[*pocz],poz[*kon]);
			swap(wier[poz[*pocz]],wier[poz[*kon]]);
			++pocz;
			--kon;
		}
	}
	if( zbior[*pocz]!=A)
		return pocz-odj;
return pocz-odj+1;
}
int polacz(int *pocz,int *kon,int dl)// Juz dobre
{	//printf("lacze dl=%d\n",dl);
	for(int i=1; i <=dl;++i,++pocz,++kon)
	{	swap(poz[*pocz],poz[*kon]);
		swap(wier[poz[*pocz]],wier[poz[*kon]]);
	}
	//printf("kon-wier=%d\n",kon-wier);
return pocz-wier-1;	// NIE WIEM CZY DOBRZE
}
void nowe_krawedzie(int id)//powinno dzialac
{	for(vector<int>::iterator it = adj[id].begin();it!=adj[id].end();++it)
	{	if(zbior[*it] != A && zbior[id] !=A)
			kol.push(*it);
		else if(zbior[*it] == zbior[id])
			kol.push(*it);
	}
	adj[id].clear();
	while(kol.size())
	{	adj[id].push_back(kol.front());
		kol.pop();
	}
	sort(adj[id].begin(),adj[id].end());
}
wyn kliki(int pocz,int kon,bool spojne)
{	bool ok=false;
	wyn ret = wn , w = wn;
	if(!spojne)
		while(pocz <= kon)
		{	ok=true;
			int new_pocz = bfs( wier[pocz] );
			w = kliki(pocz,new_pocz,true);
			if(w.kon-w.pocz > ret.kon-ret.pocz)
				ret = w;
			else if( (w.kon - w.pocz) == (ret.kon - ret.pocz) && leks( w.pocz, w.kon) < leks( ret.pocz, ret.kon) )
				ret = w;
			pocz = new_pocz+1;
		}
	else
	{	ok=true;
		if(klika(wier+pocz,kon-pocz))//dobrze
		{	
			ret.pocz = pocz;
			ret.kon = kon;
			return ret;
		}
		A = 2;
		a_size = 0;		b_size = 2;
		wyznacz_zbiory_pocz(wier+pocz,kon-pocz,wier+pocz);
		for(int i = pocz; i<=kon;++i)
			if(!zbior[wier[i]])
				wyznacz_zbior(wier[i],a_size + b_size);
		for(int i = pocz; i<=kon;++i)
			nowe_krawedzie(wier[i]);
		int k = pocz+podziel(wier+pocz,wier+kon,wier+pocz)-1; //bylo bez pocz
		for(int i=pocz;i<=kon;++i)
			zbior[wier[i]] = 0;
		ret = kliki(pocz,k,false);
		w = kliki(k+1,kon,false);
		ret.kon = polacz(wier+ret.kon+1,wier+w.pocz,w.kon-w.pocz+1);
	}
return ret;
}
int main()
{	scanf("%d",&d);
	wn.kon=-2;
	while(d--)
	{	scanf("%d",&n);
		zeruj();
		for(int i=2;i<=n;++i)
		{	scanf("%d",&z);
			for(int j=1;j<=z;++j)
			{	scanf("%d",&a);
				adj[i].push_back(a);
				adj[a].push_back(i);
			}
		}
		wynik = kliki(1,n,true);
		sort(wier+wynik.pocz,wier+wynik.kon+1);
		printf("%d\n",wynik.kon-wynik.pocz+1);
		for(int i = wynik.pocz;i<=wynik.kon;++i)
			printf("%d ",wier[i]);
		printf("\n");
	}
return 0;
}