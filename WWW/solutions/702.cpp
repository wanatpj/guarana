#include <cstdio>
#include <algorithm>
#define MN 200

using namespace std;

int n;
int Best[MN][MN];
int Naw[MN][MN];
int Dlug[MN][MN];

int main()
{
	int lw;
	scanf("%d",&lw);

	while (lw--)
	{
		scanf("%d",&n);

		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				Best[i][j] = INT_MAX;

		for (int i=0;i<n;i++)
		{
			scanf("%d",&Dlug[i][i]);
			Naw[i][i] = Best[i][i] = 0;
		}

		for (int d=1;d<n;d++)
			for (int i=0;i<n-d;i++)
				Dlug[i][i+d] = Dlug[i][i+d-1] + Dlug[i+d][i+d];
		
		int New,NewN;

		for (int d=1;d<n;d++)
			for (int i=0;i<n-d;i++)
				for (int k=i;k<i+d;k++)
					if ( Best[i][i+d] > (New = Best[i][k]+Best[k+1][i+d]+Dlug[i][i+d]))
					{
						Best[i][i+d] = New;
						Naw[i][i+d] = Naw[i][k]+Naw[k+1][i+d]+((k+1<i+d)?(1):(0));
					}
					else
					if ( (Best[i][i+d] == New) &&
						(Naw[i][i+d] > (NewN = Naw[i][k]+Naw[k+1][i+d]+((k+1<i+d)?(1):(0)) )) )
						Naw[i][i+d] = NewN;
		printf("%d %d\n",Best[0][n-1],Naw[0][n-1]);
	}

	return 0;
}
