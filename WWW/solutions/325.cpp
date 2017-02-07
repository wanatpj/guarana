
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int RM = 10009;

class wskazanie
{
	public:
	int skad, gdzie;
	bool winny;

	bool operator < (const wskazanie & A) const
	{
		if(winny!=A.winny)
			return winny;
		return gdzie<A.gdzie;
	}
	bool operator == (const wskazanie & A) const
	{
		if(winny==A.winny && skad==A.skad && gdzie==A.gdzie)
			return true;
		return false;
	}
};

int globWsk;
int ileWsk[RM];
int ileUn[RM];
vector<wskazanie> oskarzenia[RM];
vector<wskazanie> osk;

int main()
{
	int zw;
	scanf("%d", &zw);
	while(zw--)
	{
		int peo, que; //people, questions (peoni ;d)
		scanf("%d%d", &peo, &que);
		for(int i=0; i<peo; i++)
		{
			oskarzenia[i].clear();
			ileWsk[i]=0;
			ileUn[i]=0;
		}
		globWsk=0;
		osk.clear();
		for(int i=0; i<que; i++)
		{
			int a, b;
			char C;
			scanf("%d", &a);
			C = getchar();
			while(C!='W' && C!='F' && C!='P')
				C = getchar();
			scanf("%d", &b);
			wskazanie temp;
			a--; b--;
			temp.skad = a;
			if(C=='W')
			{
				temp.gdzie = b;
				temp.winny = true;
			}
			if(C=='P')
			{
				temp.gdzie = osk[b].gdzie;
				temp.winny = osk[b].winny;
			}
			if(C=='F')
			{
				temp.gdzie = osk[b].gdzie;
				temp.winny = !osk[b].winny;
			}
			oskarzenia[a].push_back(temp);
			osk.push_back(temp);
		}
		for(int i=0; i<peo; i++)
		{		
			sort(oskarzenia[i].begin(), oskarzenia[i].end());
			vector<wskazanie>::iterator newend = unique(oskarzenia[i].begin(), oskarzenia[i].end());	
			int numend = newend - oskarzenia[i].begin();
			if(numend>1 && oskarzenia[i][1].winny==true)
				oskarzenia[i].clear();
			if(oskarzenia[i].size()>0 && oskarzenia[i][0].winny==true)
			{
				int s = oskarzenia[i].size();
				bool blad = false;
				wskazanie T = oskarzenia[i][0];
				T.winny=false; // teraz jesli go tez tam mam to jest zle 
			    if(lower_bound(oskarzenia[i].begin(), newend, T) != newend)
					if(T == *lower_bound(oskarzenia[i].begin(), newend, T))
						blad = true;

				if(blad) oskarzenia[i].clear();
				else
				{
						globWsk++;
						ileWsk[oskarzenia[i][0].gdzie]++;
				}
			}
			else if(oskarzenia[i].size()>0)
			{
				for(int p=0; p<numend; p++)
					ileUn[oskarzenia[i][p].gdzie]++;
			}			
		}
		int actmin = globWsk - ileWsk[0] + ileUn[0];
		vector<int> wyn;
		wyn.clear();
		for(int i=0; i<peo; i++)
		{
			int temp = globWsk - ileWsk[i] + ileUn[i];
			if(temp<actmin)
			{
				actmin = temp;
				wyn.clear();
				wyn.push_back(i);
			}
			else if(temp==actmin)
			{
				wyn.push_back(i);		
			}
		}
		int S = wyn.size();
		for(int i=0; i<S; i++)
		{
			printf("%d", wyn[i]+1);
			if(i!=S-1) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}