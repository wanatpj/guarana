#include <iostream>
#include <queue>
using namespace std;


int kx, ky;
int ile, o;
int c, n;
int x, y;
char tab[1001][1001];
bool visited[1001][1001];
bool visited1[1001][1001];
bool toend[1001][1001];
queue<int>Qx;
queue<int>Qy;
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
         toend[i][j+1]=false;
         visited[i][j+1]=false;
         visited1[i][j+1]=false;
         if(tab[i][j+1]=='k')
         {
            kx=j+1;
            ky=i;
         }
      }
   }
}
         
void odwiedz(int x, int y)
{
   toend[y][x]=true;
   visited1[y][x]=true;
   if(x>1&&(tab[y][x-1]=='p'||tab[y][x-1]=='.')&&!visited1[y][x-1])
   {
      visited1[y][x-1]=true;
      odwiedz(x-1, y);
      if(tab[y][x-1]=='.')
      tab[y][x-1]='p';
   }
   if(x<n&&(tab[y][x+1]=='l'||tab[y][x+1]=='.')&&!visited1[y][x+1])
   {
      visited1[y][x+1]=true;
      odwiedz(x+1, y);
      if(tab[y][x+1]=='.')
      tab[y][x+1]='l';
   }
   if(y>0&&(tab[y-1][x]=='g'||tab[y-1][x]=='.')&&!visited1[y-1][x])
   {
      visited1[y-1][x]=true;
      odwiedz(x, y-1);
      if(tab[y-1][x]=='.')
      tab[y-1][x]='g';
   }
   if(y<n&&(tab[y+1][x]=='d'||tab[y+1][x]=='.')&&!visited1[y+1][x])
   {
      visited1[y+1][x]=true;
      odwiedz(x, y+1);       
      if(tab[y+1][x]=='.')
      tab[y+1][x]='d';
   }
}         

void fajnd()
{
   x=1;
   y=1;
   while(!(x==kx&&y==ky))
   {
      visited[y][x]=true;
      Qx.push(x);
      Qy.push(y);
      ile++;
      if(x>1&&tab[y][x]=='l'&&toend[y][x-1]&&!visited[y][x-1])
      x--;
      else if(x<n&&tab[y][x]=='p'&&toend[y][x+1]&&!visited[y][x+1])
      x++;
      else if(y>0&&tab[y][x]=='d'&&toend[y-1][x]&&!visited[y-1][x])
      y--;
      else if(y<n&&tab[y][x]=='g'&&toend[y+1][x]&&!visited[y+1][x])
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
      odwiedz(kx, ky);
      fajnd();     
      cout<<ile<<endl;
      while(!Qx.empty())
      {
         o=Qx.front();
         Qx.pop();
         cout<<o<<' ';
         o=Qy.front();
         Qy.pop();
         cout<<o<<endl;
      }
      cout<<kx<<' '<<ky<<endl;
   }
}
