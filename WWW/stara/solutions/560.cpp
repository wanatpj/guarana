#include<cstdio>
using namespace std;
const int size = 400;
int sum[ size ][ size ], naw[ size ][ size ],d,n;
int war[ size ];
void zeruj()
{	for(int i=0;i<=300;++i)
	{	war[i] = 0;
		for(int j=1;j<=300;++j)
		{	sum[i][j] = 0;
			naw[i][j] = 0;
		}
	}
}
void policz(int pocz,int kon)
{	int wyn = 1000000000,il_nw=size;
	int kand = 0,kand_n,
	old_kand = sum[kon][kon] + sum[pocz][kon-1],
	old_nw = naw[kon][kon] + naw[pocz][kon-1];
	for(int i = kon; i > pocz; --i)
	{	//printf("wszedlem do fora\n");
		kand = sum[i][kon] + sum[pocz][i-1];
		if(kand <= wyn)
		{	kand_n = naw[i][kon] + naw[pocz][i-1];
			if(old_kand != kand || old_nw != kand_n) 
				++kand_n;
			if(kand < wyn || kand_n < il_nw)
			{	wyn = kand;
				il_nw = kand_n;
			}
			old_nw = kand_n;
		}
		old_kand = kand;
	}
	//printf("[%d][%d] wyn=%d il_nw=%d\n",pocz,kon,wyn,il_nw);
	sum[pocz][kon] = wyn + war[kon]-war[pocz-1];
	naw[pocz][kon] = il_nw;
}
void wylicz(int dl)
{	for(int i=n;i-dl >= 0;--i)
		policz(i-dl+1,i);
}
int main()
{	scanf("%d",&d);
	while(d--)
	{	zeruj();
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{	scanf("%d",&war[i]);
			war[i] += war[i-1];
		}
		for(int i=2;i<=n;++i)
			wylicz(i);
		printf("%d %d\n",sum[1][n],naw[1][n]);
	}
	return 0;
}