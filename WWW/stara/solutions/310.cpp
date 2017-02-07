#include <iostream>
#include <set>
#define MAX 10010
#define MAX2 20010
using namespace std;

struct wyp { int kogo; bool co; } wiersz[MAX2]; // 1-winny, 2-niewinny

set <int> NW[MAX];
int z,n,m,a,b,uznaje,mini;
char typ[10];
bool klamca[MAX];
int wsk[MAX], zlo[MAX], dobro[MAX], res[MAX];

int main()
{
	scanf("%d",&z);
	while(z--)
	{
		scanf("%d %d",&n,&m);
		uznaje=0;
		for(int i=1;i<=n;i++)
		{
			wsk[i]=0;
			klamca[i]=0;
			NW[i].clear();
			dobro[i]=zlo[i]=0;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d %s %d",&a,&typ,&b);
			if(typ[0]=='W')
			{
				wiersz[i].kogo=b;
				wiersz[i].co=1;
				if(wsk[a]==0)
				{
					wsk[a]=b;
				}
				else
				{
					if(wsk[a]!=b)
					{
						klamca[a]=1;
					}
				}
			}
			else if(typ[0]=='P')
			{
				wiersz[i]=wiersz[b];
				if(wiersz[i].co==1)
				{
					if(wsk[a]==0)
					{
						wsk[a]=wiersz[i].kogo;
					}
					else
					{
						if(wsk[a]!=wiersz[i].kogo)
						{
							klamca[a]=1;
						}
					}
				}
				else
				{
					NW[a].insert(wiersz[i].kogo);
				}
			}
			else
			{
				wiersz[i]=wiersz[b];
				if(wiersz[i].co==1) wiersz[i].co=0;
				else wiersz[i].co=1;
				if(wiersz[i].co==1)
				{
					if(wsk[a]==0)
					{
						wsk[a]=wiersz[i].kogo;
					}
					else
					{
						if(wsk[a]!=wiersz[i].kogo)
						{
							klamca[a]=1;
						}
					}
				}
				else
				{
					NW[a].insert(wiersz[i].kogo);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(wsk[i]!=0)
			{
				if(NW[i].find(wsk[i])!=NW[i].end()) klamca[i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(klamca[i]==0)
			{
				//printf("kl:%d\n",i);
				if(wsk[i]!=0)
				{
						uznaje++;
						zlo[wsk[i]]++;
				}
				else
				{
					for(set<int>::iterator it=NW[i].begin();it!=NW[i].end();it++)
					{
						dobro[*it]++;
					}
				}
			}
		}
		mini=MAX;
		//printf("uznaje:%d\n",uznaje);
		for(int i=1;i<=n;i++)
		{
			res[i]=uznaje-zlo[i]+dobro[i];
			if(res[i]<mini) mini=res[i];
		}
		for(int i=1;i<=n;i++)
		{
				//printf("res:%d\n",res[i]);
				if(res[i]==mini) printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}

