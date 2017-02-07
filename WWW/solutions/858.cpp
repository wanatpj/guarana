#include <iostream>
using namespace std;


int d, n, a;
int naws;
int tab[201];
int dlugosc[201][201];
int sajz[201][201];
int nawiasy[201][201];

void wczytaj()
{
   cin>>n;
   for(int i=0; i<n; i++)
   cin>>tab[i];
}

void inicjuj()
{
   for(int i=0; i<201; i++)
   for(int j=0; j<201; j++)
   {
      nawiasy[i][j]=2000000000;
      dlugosc[i][j]=2000000000;
   }
   for(int j=0; j<n; j++)
   {
      dlugosc[j][1]=0;
      nawiasy[j][1]=0;
   }
   for(int j=0; j<n-1; j++)
   {
      dlugosc[j][2]=tab[j]+tab[j+1];
      nawiasy[j][2]=0;
   }
   for(int i=0; i<n; i++)
   sajz[i][1]=tab[i];
   for(int i=2; i<=n; i++)
   for(int j=0; j<=n-1; j++)
   sajz[j][i]=sajz[j][i-1]+tab[j+i-1];
   
}

void optymal()
{
   for(int i=3; i<=n; i++)
   {
      for(int j=0; j<=n-i; j++)
      {
         for(int k=1; k<i; k++)
         {
            if(k==i-1)
            a=0;
            else
            a=1;
            if((dlugosc[j][i]>dlugosc[j][k]+dlugosc[j+k][i-k]+sajz[j][k]+sajz[j+k][i-k])||(dlugosc[j][i]==dlugosc[j][k]+dlugosc[j+k][i-k]+sajz[j][k]+sajz[j+k][i-k])&&nawiasy[j][i]>nawiasy[j][k]+nawiasy[j+k][i-k]+a)
            {
               dlugosc[j][i]=dlugosc[j][k]+dlugosc[j+k][i-k]+sajz[j][k]+sajz[j+k][i-k];
               nawiasy[j][i]=nawiasy[j][k]+nawiasy[j+k][i-k]+a;
            }
         }
      }
   }
}   

main()
{
   int z;
   cin>>z;
   for(int i=0; i<z; i++)
   {
      wczytaj();
      inicjuj();
      optymal();
      cout<<dlugosc[0][n]<<' '<<nawiasy[0][n]<<endl;
   }
}
