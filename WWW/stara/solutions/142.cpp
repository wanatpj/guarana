#include <iostream>
using namespace std;

//     Piotr Bryniarski
// V Liceum Ogólnokształcące
// im. Augusta Witkowskiego
//       w Krakowie


long long p, q, suma, sumb;
bool gra;

long long nwd(long long a, long long b)
{
     long long c;
     while(b!=0)
     {
                c=a%b;
                a=b;
                b=c;
     }
     return a;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    int z;
    cin>>z;
    for (int i=0;i<z;i++)
    {
        cin>>p>>q;
        if (p==(q-1))
        suma=0; sumb=0; gra=true;
        if (p==(q-1))suma=sumb=p=q=1;
        while((suma+sumb)<p*q)
        {
                             if (gra)
                             {
                                     suma+=(((suma+sumb)/p+1)*p-(suma+sumb));
                                     if((suma+sumb)%q!=0) gra=false;
                             }
                             else 
                             {
                                  sumb+=(((suma+sumb)/q+1)*q-(suma+sumb));
                                  gra=true;
                             }
        }
        p=nwd(suma, sumb);
        suma/=p;
        sumb/=p;
        if (sumb==0) suma=1;
        if (suma==0) sumb=1;
        cout<<suma<<" "<<sumb<<endl;
    }
    
    //system("pause");
    return 0;
}


