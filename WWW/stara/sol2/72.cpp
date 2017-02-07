//Algorytm Manachera dla palindromów nieparzystych
#include <iostream>
#define MAX 1000005
using namespace std;

char t[MAX];
int res[MAX];
int dl, last, lastp;

int main()
{
   scanf("%s",&t[1]);
   dl=strlen(t+1);
   t[0]='#';
   last=0;
   for(int i=0;i<=dl;i++)
   {   
      if(last>i)
      {
         res[i]=res[lastp-(i-lastp)];
         if(res[i]+i>=last)
         {
            res[i]=last-i;
            for(int j=last+1;j<=dl;j++)
            {
               if(t[j]==t[i-res[i]-1]) res[i]++;
               else
               {
                  last=j-1;
                  lastp=i;
                  break;
               }
            }
         }
      }
      else
      {
         for(int j=i+1;j<=dl;j++)
         {
            if(t[j]==t[i-res[i]-1]) res[i]++;
            else
            {
               last=j-1;
               lastp=i;
               break;
            }
         }
      }   
   }
   for(int i=1;i<=dl;i++) printf("%d ",res[i]);
   return 0;
}
