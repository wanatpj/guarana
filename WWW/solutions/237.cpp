#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define LL 1000000
#define POD 1000000

using namespace std;

double Det( double Ax, double Ay, double Bx, double By, double Cx, double Cy)
{
    return Ax*By+Bx*Cy+Cx*Ay - Ax*Cy-Bx*Ay-Cx*By;
}

int Sgn(double X)
{
    return (X>0)?(1):(-1);
}

bool IsIn( double X, double Y, double Ax, double Ay, double Bx, double By, double Cx, double Cy)
{
    double D1 = Det( Ax, Ay, Bx, By, X, Y );
    double D2 = Det( Bx, By, Cx, Cy, X, Y );
    double D3 = Det( Cx, Cy, Ax, Ay, X, Y );
    if (D1 == 0 || D2 == 0 || D3 == 0)
        return false;
    return (Sgn(D1) == Sgn(D2)) && (Sgn(D2) == Sgn(D3));
}

double Pole( double FAx, double FAy, double FBx, double FBy, double FCx, double FCy,
             double SAx, double SAy, double SBx, double SBy, double SCx, double SCy )
{
    double Lx = min( min( min(FAx,FBx), FCx ), min( min(SAx,SBx), SCx ) );
    double Rx = max( max( max(FAx,FBx), FCx ), max( max(SAx,SBx), SCx ) );

    double Ly = min( min( min(FAy,FBy), FCy ), min( min(SAy,SBy), SCy ) );
    double Ry = max( max( max(FAy,FBy), FCy ), max( max(SAy,SBy), SCy ) );

    double All = 0;
    double Good = 0;

    for (int i=0;i<LL;i++)
    {
        double X = (Rx-Lx)*( ((double)(rand()%POD))/POD ) + Lx;
        double Y = (Ry-Ly)*( ((double)(rand()%POD))/POD ) + Ly;

        if ( IsIn( X,Y, FAx, FAy, FBx, FBy, FCx, FCy ) ||
             IsIn( X,Y, SAx, SAy, SBx, SBy, SCx, SCy ) )
            Good++;
        All++;
    }
    return (Good / All)*(Rx-Lx)*(Ry-Ly);
}

double Norma(double MP)
{
    return round(MP*10)/10;
}

int main()
{
    srand(time(NULL));
    double X[2][3];
    double Y[2][3];
    for (int i=0;i<3;i++)
        scanf("%lf%lf",&X[0][i],&Y[0][i]);

    for (int i=0;i<3;i++)
        scanf("%lf%lf",&X[1][i],&Y[1][i]);

    double MP = Pole(X[0][0],Y[0][0],X[0][1],Y[0][1],X[0][2],Y[0][2],X[1][0],Y[1][0],X[1][1],Y[1][1],X[1][2],Y[1][2]);
    printf("%.5lf\n",Norma(MP));

    return 0;
}

