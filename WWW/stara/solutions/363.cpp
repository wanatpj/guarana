#include <iostream>
#include <queue>
using namespace std;

struct point
{
   int x;
   int y;
};

int kx, ky;
int ile;
int c, n;
int x, y;
char tab[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
queue<point> Q;
string s;
void wczytaj()
{
   ile=1;
   cin>>n;
   for(int i=n; i>0; i--)
   {
      cin>>s;
      for(int j=0; j<n; j++)
      {
         tab[i][j+1]=s[j];
         visited[i][j+1]=false;
         dist[i][j+1]=0;
         if(tab[i][j+1]=='k')
         {
            kx=j+1;
            ky=i;
         }
      }
   }
}
         
void odwiedz()
{
   point temp, temp2;
   temp.x=kx;
   temp.y=ky;
   Q.push(temp);
while(!Q.empty())
{
   temp=Q.front();
   Q.pop();
   x=temp.x;
   y=temp.y;
   visited[y][x]=true;
   if(x>1&&(tab[y][x-1]=='p'||tab[y][x-1]=='.')&&!visited[y][x-1])
   {
      temp2.x=x-1;
      temp2.y=y;
      Q.push(temp2);
      if(tab[y][x-1]=='.')
      tab[y][x-1]='p';
      dist[y][x-1]=dist[y][x]+1;
   }
   if(x<n&&(tab[y][x+1]=='l'||tab[y][x+1]=='.')&&!visited[y][x+1])
   {
      temp2.x=x+1;
      temp2.y=y;
      Q.push(temp2);
      if(tab[y][x+1]=='.')
      tab[y][x+1]='l';
      dist[y][x+1]=dist[y][x]+1;
   }
   if(y>0&&(tab[y-1][x]=='g'||tab[y-1][x]=='.')&&!visited[y-1][x])
   {
      temp2.x=x;
      temp2.y=y-1;
      Q.push(temp2);
      if(tab[y-1][x]=='.')
      tab[y-1][x]='g';
      dist[y-1][x]=dist[y][x]+1;
   }
   if(y<n&&(tab[y+1][x]=='d'||tab[y+1][x]=='.')&&!visited[y+1][x])
   {
      temp2.x=x;
      temp2.y=y+1;
      Q.push(temp2);      
      if(tab[y+1][x]=='.')
      tab[y+1][x]='d';
      dist[y+1][x]=dist[y][x]+1;
   }
}
}         

void fajnd()
{
   x=1;
   y=1;
   while(!(x==kx&&y==ky))
   {
      cout<<x<<' '<<y<<endl;
      if(tab[y][x]=='l')
      x--;
      else if(tab[y][x]=='p')
      x++;
      else if(tab[y][x]=='d')
      y--;
      else if(tab[y][x]=='g')
      y++;
   }
            
   
   
}   
   

main()
{
ios_base::sync_with_stdio(0);
   cin>>c;
   for(int ii=0; ii<c; ii++)
   {
           
      wczytaj();
      odwiedz();
      cout<<dist[1][1]+1<<endl;
      fajnd();     
      cout<<kx<<' '<<ky<<endl;
   }
}
