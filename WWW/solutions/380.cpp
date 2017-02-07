#include <cstdio>
#include <queue>
//#include <iostream>
using namespace std;
struct wsp{int x,y;};
int m,zal,ll,a,b;
int z;
wsp bum;
wsp koniec;
char tabela[1002][1002];
bool druga[1002][1002];
queue <wsp> kolejka;
int x,y;
     
int main()
{
scanf("%d",&z);
while(z--)
   {
    m=0;  
   scanf("%d ",&m);
   for(int j=0;j<m;j++)
       for(int i=0;i<=m;i++)
           {druga[i][j]=0;
            scanf("%c",&tabela[i][j]);
            if(tabela[i][j]=='k')
               {koniec.x=i;
                koniec.y=j;
               }
            } 
           kolejka.push(koniec);
          //  ll=0;
          //  zal=1;       
 while(!kolejka.empty())
  {   //cout<<"x"<<endl;
       x=kolejka.front().x;
       y=kolejka.front().y; 
       kolejka.pop(); 
      // cout<<x<<" "<<y<<endl;         
     if(x+1<m && druga[x+1][y]==0 &&( tabela[x+1][y]=='l' || tabela[x+1][y]=='.' ))
          {//cout<<"*"<<endl;
          if(tabela[x+1][y]=='.')
              tabela[x+1][y]='l';
           bum.x=x+1;
           bum.y=y;
           kolejka.push(bum);
           druga[x+1][y]=1;
          }
      if(x-1>=0 && druga[x-1][y]==0 && (tabela[x-1][y]=='p'|| tabela[x-1][y]=='.'))
          {//cout<<"!"<<endl;
          if(tabela[x-1][y]=='.')
              tabela[x-1][y]='p';
          bum.x=x-1;
           bum.y=y;
           kolejka.push(bum);
           druga[x-1][y]=1;
          }    
      if(y-1>=0 && druga[x][y-1]==0 && (tabela[x][y-1]=='d'|| tabela[x][y-1]=='.'))
          {//cout<<"-"<<endl;
          if(tabela[x][y-1]=='.')
               tabela[x][y-1]='d';
           bum.x=x;
           bum.y=y-1;
           kolejka.push(bum);
           druga[x][y-1]=1;
          }       
      if(y+1<m && druga[x][y+1]==0 && (tabela[x][y+1]=='g'|| tabela[x][y+1]=='.'))
          {//cout<<"+"<<endl;
          if(tabela[x][y+1]=='.')
               tabela[x][y+1]='g';
           bum.x=x;
           bum.y=y+1;
           kolejka.push(bum);
           druga[x][y+1]=1;
          }       
    // ll++;
     }//while(ll<zal);//while(x!=m-1 || y!=0);
    
   y=m-1;
    x=0;   
    int liczenie=1;   
  while(x!=koniec.x || y!=koniec.y) 
    {if(tabela[x][y]=='g') y=y-1;
     else if(tabela[x][y]=='d') y=y+1;
     else if(tabela[x][y]=='p') x=x+1;
     else if(tabela[x][y]=='l') x=x-1;
    liczenie++;               
    }
   printf("%d\n",liczenie);
    y=m-1;
    x=0; 
    a=x+1;
    b=m-y;
  while(x!=koniec.x || y!=koniec.y) 
    {printf("%d %d\n",a,b);
     if(tabela[x][y]=='g') y=y-1;
     else if(tabela[x][y]=='d') y=y+1;
     else if(tabela[x][y]=='p') x=x+1;
     else if(tabela[x][y]=='l') x=x-1;
     a=x+1;
     b=m-y;
   }
   printf("%d %d\n",a,b);
}
//system ("pause");
return 0;         
}
