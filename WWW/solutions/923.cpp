#include <cstdio>
using namespace std;
int T[202][202],N,Waga[202][202], Nawias[202][202];

void wagi()
{
	for (int i=1;i<=N;i++)
		T[i][i]=0;
	for (int i=1;i<N;i++)
		for (int y=i+1;y<=N;y++)
			Waga[i][y]=Waga[i][y-1]+Waga[y][y];

}

void fun (int dlugosc)
{
	int minimum,a,b;
	for (int i=1;i+dlugosc<=N;i++)
	{
		minimum=5000000;
		for (int y=i;y<i+dlugosc;y++)
		{
			a=T[i][y]+T[y+1][i+dlugosc];
			b=Nawias[i][y]+Nawias[y+1][i+dlugosc];
			if(minimum>a)
			{
				minimum=a;
				Nawias[i][i+dlugosc]=b;
				if (y+1!=i+dlugosc)
					Nawias[i][i+dlugosc]++;

			}
			else if (minimum==a)
			{
				if (y+1!=i+dlugosc)
					b++;
				if (Nawias[i][i+dlugosc]>b)
					Nawias[i][i+dlugosc]=b;
			}
		}
		T[i][i+dlugosc]=Waga[i][i+dlugosc]+minimum;
	}
}

int main()
{
	int D;
	scanf ("%d",&D);
	while (D>0)
	{
		scanf ("%d",&N);	
		for (int i=1;i<=N;i++)
		{
			scanf ("%d",&Waga[i][i]);
			Nawias[i][i]=0;
		}
		wagi();
		for (int i=1;i<N;i++)
			fun(i);
		printf ("%d %d\n",T[1][N],Nawias[1][N]);
		D--;
	}
	return 0;
}
