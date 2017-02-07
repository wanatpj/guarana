#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define VAR(x,n) __typeof(n) x = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i<(c).end();i++)
#define PD pair<long double,long double>
#define st first
#define nd second

PD p[2][3];
vector <PD> v;

long double il_wekt(PD p1, PD p2)
{
	return p2.st*p1.nd-p1.st*p2.nd;
}

void przeciecie(PD p1, PD k1, PD p2, PD k2)
{
	//printf("%lf %lf %lf %lf %lf %lf %lf %lf\n", p1.st, p1.nd, k1.st, k1.nd, p2.st, p2.nd, k2.st, k2.nd);
	if(il_wekt(PD(k1.st-p1.st,k1.nd-p1.nd),PD(k2.st-p2.st,k2.nd-p2.nd))==0)
		return;
	//printf("a\n");
	long double A1, A2, B1, B2, C1, C2;
	if(k1.st-p1.st==0)
	{
		B1=0;
		A1=1;
		C1=-A1*p1.st;
	}
	else if(k1.nd-p1.nd==0)
	{
		A1=0;
		B1=1;
		C1=-B1*p1.nd;
	}
	else
	{
		A1=p1.nd-k1.nd;
		B1=k1.st-p1.st;
		C1=-A1*p1.st-B1*p1.nd;
	}
	if(k2.st-p2.st==0)
	{
		B2=0;
		A2=1;
		C2=-A2*p2.st;
	}
	else if(k2.nd-p2.nd==0)
	{
		A2=0;
		B2=1;
		C2=-B2*p2.nd;
	}
	else
	{
		A2=p2.nd-k2.nd;
		B2=k2.st-p2.st;
		C2=-A2*p2.st-B2*p2.nd;
	}
	long double temp, temp2;
	temp=(B1*C2-B2*C1)/(A1*B2-A2*B1);
	if(B1!=0)
		temp2=-(C1+A1*temp)/B1;
	else
		temp2=-(C2+A2*temp)/B2;
	//printf("%lf %lf %lf %lf %lf %lf\n%lf %lf\n", A1, B1, C1, A2, B2, C2, temp, temp2);
	bool ok1=0, ok2=0;
	if((p1.st-k1.st!=0)&&((p1.st<temp && temp<k1.st)||(p1.st>temp && temp>k1.st)))
		ok1=1;
	if((p1.nd-k1.nd!=0)&&((p1.nd<temp2 && temp2<k1.nd)||(p1.nd>temp2 && temp2>k1.nd)))
		ok1=1;
	if((p2.st-k2.st!=0)&&((p2.st<temp && temp<k2.st)||(p2.st>temp && temp>k2.st)))
		ok2=1;
	if((p2.nd-k2.nd!=0)&&((p2.nd<temp2 && temp2<k2.nd)||(p2.nd>temp2 && temp2>k2.nd)))
		ok2=1;
	if(ok1 && ok2)
		v.push_back(PD(temp,temp2));
}

bool check(PD c, PD a1, PD a2, PD a3)
{
	long double il1, il2, il3;
	il1=il_wekt(PD(a2.st-a1.st,a2.nd-a1.nd),PD(c.st-a1.st,c.nd-a1.nd));
	il2=il_wekt(PD(a3.st-a2.st,a3.nd-a2.nd),PD(c.st-a2.st,c.nd-a2.nd));
	il3=il_wekt(PD(a1.st-a3.st,a1.nd-a3.nd),PD(c.st-a3.st,c.nd-a3.nd));
	if(il1<=0 && il2<=0 && il3<=0)
		return true;
	if(il1>=0 && il2>=0 && il3>=0)
		return true;
	return false;
}

long double aval(long double v)
{
	if(v<0)
		return -v;
	return v;
}

PD punkt;
bool por(PD v1, PD v2)
{
	if(il_wekt(PD(v1.st-punkt.st,v1.nd-punkt.nd),PD(v2.st-punkt.st,v2.nd-punkt.nd))<=0)
		return true;
	return false;
}

int main()
{
	long double wynik=0, xt, yt;
	for(int i = 0;i<2;i++)
	{
		for(int j = 0;j<3;j++)
		{
			scanf("%Lf %Lf", &p[i][j].st, &p[i][j].nd);
		}
	}
	for(int i = 0;i<3;i++)
		for(int j = i+1;j<3;j++)
			for(int k = 0;k<3;k++)
				for(int l = k+1;l<3;l++)
					przeciecie(p[0][i],p[0][j],p[1][k],p[1][l]);
	for(int i = 0;i<3;i++)
	{
		if(check(p[0][i],p[1][0],p[1][1],p[1][2]))
			v.push_back(p[0][1]);
		if(check(p[1][i],p[0][0],p[0][1],p[0][2]))
			v.push_back(p[1][i]);
	}
	/*
	FOREACH(it,v)
	{
		printf("a:%lf %lf\n", it->st, it->nd);
	}
	*/
	punkt=PD(2000,2000);
	int pom;
	long double P=0;
	P=aval(il_wekt(PD(p[0][1].st-p[0][0].st,p[0][1].nd-p[0][0].nd),PD(p[0][2].st-p[0][0].st,p[0][2].nd-p[0][0].nd)));
	P+=aval(il_wekt(PD(p[1][1].st-p[1][0].st,p[1][1].nd-p[1][0].nd),PD(p[1][2].st-p[1][0].st,p[1][2].nd-p[1][0].nd)));
	P/=2;
	if(v.size()==0)
	{
		printf("%.5Lf\n", P);
		return 0;
	}
	FOREACH(it,v)
	{
		if(it->nd<punkt.nd)
		{
			pom=it-v.begin();
			punkt=*it;
		}
		else if(it->nd==punkt.nd && it->st<punkt.st)
		{
			pom=it-v.begin();
			punkt=*it;
		}
	}
	swap(v[pom],v[0]);
	sort(v.begin()+1,v.end(),por);
	/*
	FOREACH(it,v)
	{
		printf("b:%lf %lf\n", it->st, it->nd);
	}
	*/
	//printf("%lf\n", P);
	for(vector <PD>::iterator it = v.begin()+1;it!=v.end()-1;it++)
	{
		P-=aval(il_wekt(PD(it->st-punkt.st,it->nd-punkt.nd),PD((it+1)->st-punkt.st,(it+1)->nd-punkt.nd)))/2;
	}
	printf("%.5Lf\n", P);
	return 0;
}
