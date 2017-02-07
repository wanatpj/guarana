#include <cstdio>
#include <algorithm>
#define LLD long long int

using namespace std;

LLD Modulo;

class Matrix
{
public:
	LLD T[2][2];
	Matrix()
	{
		Clear();
		T[0][0] = T[1][1] = 1;
	}

	Matrix(LLD A,LLD B,LLD C,LLD D)
	{
		T[0][0] = A;
		T[0][1] = B;
		T[1][0] = C;
		T[1][1] = D;
	}

	void Clear()
	{
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				T[i][j] = 0;
	}

	Matrix operator * (const Matrix &X)const
	{
		Matrix Out;
		Out.Clear();
		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				for (int k=0;k<2;k++)
					Out.T[i][j] += T[i][k]*X.T[k][j];

		for (int i=0;i<2;i++)
			for (int j=0;j<2;j++)
				Out.T[i][j] %= Modulo;

		return Out;
	}
};

Matrix Podnies( Matrix Co, LLD N )
{
	if (N == 0)
		return Matrix();
	else
	if (N == 1)
		return Co;
	Matrix Half = Podnies(Co,N/2);
	if (N%2)
		return (Half*Half)*Co;
	return (Half*Half);
}

LLD NWD(LLD X,LLD Y,LLD &F,LLD &G)
{
	if (Y == 0)
	{
		F = 1; G = 0;
		return X;
	}
	LLD D,FT,GT;
	D = NWD(Y,X%Y,FT,GT);
	F = GT; G = FT - (X/Y)*GT;
	return D;
}

LLD Odw(LLD Cos)
{
	LLD F,G;
	NWD(Cos,Modulo,F,G);
	return F;
}

int main()
{
int lw;
scanf("%d",&lw);
while (lw--)
{
	Matrix Tran;
	LLD X,N;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&Modulo,&Tran.T[0][0],&Tran.T[0][1],&Tran.T[1][0],&Tran.T[1][1],&X,&N);

	Tran = Podnies(Tran,N);
	
	LLD Licz = (Tran.T[0][0]*X + Tran.T[0][1])%Modulo;
	LLD Mian = (Tran.T[1][0]*X + Tran.T[1][1])%Modulo;

	LLD Out = (Licz*Odw(Mian))%Modulo;
	if (Out<0)
		Out+=Modulo;
	printf("%lld\n",Out);
}
	return 0;
}
