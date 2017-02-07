#include <iostream>
#include <vector>
using namespace std;

struct zdarz
{
   int kto;
   int number;
   bool winny;
};
int n, z;
int p, k;
char c;

bool cmp(zdarz a, zdarz b) { return a.number<b.number||(a.number==b.number&&a.winny>b.winny)||(a.number==b.number&&a.winny==b.winny&&a.kto>b.kto); }

zdarz tab[20001];
int skaz[10001];
int ile[10001];


void wczytaj()
{
   cin>>n>>z;
   for(int i=1; i<=z; i++)
   {
      cin>>p>>c>>k;
      tab[i].kto=p;
      if(c=='W')
      {
         tab[i].winny=true;
         tab[i].number=k;
      }
      else if(c=='P')
      {
         tab[i].winny=tab[k].winny;
         tab[i].number=tab[k].number;
      }
      else
      {
         tab[i].winny=!tab[k].winny;
         tab[i].number=tab[k].number;
      }
   }
}

void zeznaj()
{
   for(int i=1; i<=z; i++)
   {
      if(tab[i].winny)
      {
         if(skaz[tab[i].kto]==0)
         skaz[tab[i].kto]=tab[i].number;
         else if(skaz[tab[i].kto]>0)
         skaz[tab[i].kto]=-1;
      }
   }
}

main()
{
int zz;
cin>>zz;
for(int ii=1; ii<=zz; ii++)
{
wczytaj();
sort(tab+1, tab+z+1, cmp);
zeznaj();
for(int i=1; i<=z; i++)
{
   if(tab[i].number!=tab[i-1].number||tab[i].winny!=tab[i-1].winny||tab[i].kto!=tab[i-1].kto)
   {
      if(skaz[tab[i].kto]>0)
      {
         if(tab[i].winny)
         ile[tab[i].number]++;
         else
         {
            if(skaz[tab[i].kto]==tab[i].number)
            ile[tab[i].number]--;
         }
            
      }
      if(skaz[tab[i].kto]==0)
      {
         ile[tab[i].number]--;
      }
   }
}   
int maks=0;
for(int i=1; i<=n; i++)
if(ile[i]>maks)
maks=ile[i];
for(int i=1; i<=n; i++)
if(ile[i]==maks)
cout<<i<<' ';
if(ii!=zz)
cout<<endl;
for(int i=1; i<=n; i++)
{
   ile[i]=0;
   skaz[i]=0;
} 
}
}
