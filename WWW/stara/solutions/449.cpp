#include <set>
#include <cstdio>
using namespace std;

int Wynik[10001],P[20001],C[20001],K[20001];
bool Klamca[10001];int Oskarza[10001];
set <int> Oskarzajacy[10001];
set <int> Uniewinniajacy[10001];

int main()
{
	int D,N,Z,minimum;
	scanf ("%d",&D);
	while (D>0)
	{
		minimum=100000;
		scanf ("%d %d",&N, &Z);
		for (int i=1;i<=N;i++)
		{
			Klamca[i]=0;
			Oskarza[i]=0;
		}
		for (int i=1;i<=Z;i++)
		{
			scanf ("%d %c %d",&P[i],&C[i],&K[i]);
			if (C[i]=='P')
			{
				C[i]=C[K[i]];
				K[i]=K[K[i]];
			}
			if (C[i]=='F')
			{
				if (C[K[i]]=='W')
					C[i]='N';
				else
					C[i]='W';
				K[i]=K[K[i]];
			}
			if (C[i]=='W')
			{
				if (Oskarza[P[i]]!=0)
				{
					if (Oskarza[P[i]]!=K[i])
						Klamca[P[i]]=1;
				}
				else
					Oskarza[P[i]]=K[i];
			}
		}
		for (int i=1;i<=Z;i++)
			if (C[i]=='N')
				if (Oskarza[P[i]]==K[i])
					Klamca[P[i]]=1;
		for (int i=1;i<=Z;i++)
			if (C[i]=='N')
				if (Klamca[P[i]]==0 && Oskarza[P[i]]==0)
					Uniewinniajacy[K[i]].insert(P[i]);
		for (int i=1;i<=N;i++)
			if (Klamca[i]==0)
				if (Oskarza[i]!=0)
					Oskarzajacy[Oskarza[i]].insert(i);
		for (int i=1;i<=N;i++)
			Wynik[i]=Uniewinniajacy[i].size()-Oskarzajacy[i].size();
		for (int i=1;i<=N;i++)
			minimum=min(Wynik[i],minimum);
		for (int i=1;i<=N;i++)
			if (Wynik[i]==minimum)
				printf ("%d ",i);
		printf ("\n");
		for (int i=1;i<=N;i++)
		{
			Uniewinniajacy[i].clear();
			Oskarzajacy[i].clear();
		}
		D--;
	}
	return 0;
}
