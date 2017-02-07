#include <cstdio>
//#include <iostream>
using namespace std;
struct wsp{int x,y;};
int m,zal,ll,wsk;
int z;
wsp koniec;
char tabela[52][52];
bool druga[52][52];
wsp duzystos[100000];
int x,y;
     
int main()
{
scanf("%d",&z);
while(z--)
   {for(int j=0;j<m;j++)
       for(int i=0;i<m;i++)druga[i][j]=0;
    m=0;  
   scanf("%d ",&m);
   for(int j=0;j<m;j++)
       for(int i=0;i<=m;i++)
           {scanf("%c",&tabela[i][j]);
            if(tabela[i][j]=='k')
               {koniec.x=i;
                koniec.y=j;
               }
            } 
            duzystos[0].x=koniec.x;
            duzystos[0].y=koniec.y;
            ll=0;
            zal=1;       
 do 
  {
       x=duzystos[ll].x;
       y=duzystos[ll].y;  
      // cout<<x<<" "<<y<<endl;         
     if(x+1<m && druga[x+1][y]==0 &&( tabela[x+1][y]=='l' || tabela[x+1][y]=='.' ))
          {//cout<<"*"<<endl;
          if(tabela[x+1][y]=='.')
                 tabela[x+1][y]='l';
           duzystos[zal].x=x+1;
           duzystos[zal++].y=y;
             druga[x+1][y]=1;
          }
      if(x-1>=0 && druga[x-1][y]==0 && (tabela[x-1][y]=='p'|| tabela[x-1][y]=='.'))
          {//cout<<"!"<<endl;
          if(tabela[x-1][y]=='.')
                 tabela[x-1][y]='p';
          duzystos[zal].x=x-1;
           duzystos[zal++].y=y;
           druga[x-1][y]=1;
          }    
      if(y-1>0 && druga[x][y-1]==0 && (tabela[x][y-1]=='d'|| tabela[x][y-1]=='.'))
          {//cout<<"-"<<endl;
          if(tabela[x][y-1]=='.')
                 tabela[x][y-1]='d';
          duzystos[zal].x=x;
           duzystos[zal++].y=y-1;
           druga[x][y-1]=1;
          }       
      if(y+1<m && druga[x][y+1]==0 && (tabela[x][y+1]=='g'|| tabela[x][y+1]=='.'))
          {//cout<<"+"<<endl;
          if(tabela[x][y+1]=='.')
                 tabela[x][y+1]='g';
          duzystos[zal].x=x;
           duzystos[zal++].y=y+1;
           druga[x][y+1]=1;
          }       
     ll++;
     }while(ll<zal);//while(x!=m-1 || y!=0);
    
    y=m-1;
    x=0;   
    int liczenie=1;   
  while(x!=koniec.x || y!=koniec.y) 
    {if(tabela[x][y]=='g') y=y-1;
     else if(tabela[x][y]=='d') y=y+1;
     else if(tabela[x][y]=='p') x=x+1;
     else if(tabela[x][y]=='l') x=x-1;
    liczenie++; 
  // cout<<x<<" "<<y<<" "<<tabela[x][y]<<endl;                 
    }
  
   printf("%d\n",liczenie);
     y=m-1;
    x=0; 
    int a=x+1;
    int b=m-y;
  while(x!=koniec.x || y!=koniec.y) 
    {printf("%d %d\n",a,b);
    if(tabela[x][y]=='g') y=y-1;
     else if(tabela[x][y]=='d') y=y+1;
     else if(tabela[x][y]=='p') x=x+1;
     else if(tabela[x][y]=='l') x=x-1;
    //liczenie++; 
     a=x+1;
     b=m-y;
    
   }
   printf("%d %d\n",a,b);
}
//system ("pause");
return 0;         
}
