//generator plansz
#include <iostream>
#include <ctime>
#define MAX 4
using namespace std;

struct point { int x,y; } B;
char t[5][5];
int ab[5][5], ac[5][5];

inline void atakowa()
{     
      for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) ab[i][j]=ac[i][j]=0;
      for(int i=0;i<MAX;i++)
      {
             for(int j=0;j<MAX;j++)
             {
                    //biale pionki
                    if(i<3)
                    {
                            if(j>0)
                            {
                                   if(t[i+1][j-1]=='b')
                                   {
                                         ab[i][j]++;                    
                                   }
                            }
                            if(j<3)
                            {
                                   if(t[i+1][j+1]=='b')
                                   {
                                         ab[i][j]++;                    
                                   }       
                            }        
                    } 
                    //czarne pionki        
                    if(i>0)
                    {
                            if(j>0)
                            {
                                   if(t[i-1][j-1]=='c')
                                   {
                                         ac[i][j]=1;                    
                                   }
                            }
                            if(j<3)
                            {
                                   if(t[i-1][j+1]=='c')
                                   {
                                         ac[i][j]=1;                    
                                   }       
                            }        
                    }                              
             }        
     }
}

inline void atakowa2()
{     
      for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) ab[i][j]=ac[i][j]=0;
     //bialy krol 
     for(int i=0;i<MAX;i++)
             for(int j=0;j<MAX;j++)
                     if(t[i][j]=='B')
                     {
                            B.y=i;
                            B.x=j;                
                     }
     if(B.y>0)
     {
              if(B.x>0)
              {
                       ab[B.y-1][B.x-1]++;         
              }
              if(B.x<3)
              {
                       ab[B.y-1][B.x+1]++;
              }
              ab[B.y-1][B.x]++;         
     }
     if(B.y<3)
     {
              if(B.x>0)
              {
                       ab[B.y+1][B.x-1]++;         
              }
              if(B.x<3)
              {
                       ab[B.y+1][B.x+1]++;
              }
              ab[B.y+1][B.x]++;      
     }
     if(B.x>0) ab[B.y][B.x-1]++;
     if(B.x<3) ab[B.y][B.x+1]++;
     
     for(int i=0;i<MAX;i++)
     {
             for(int j=0;j<MAX;j++)
             {
                    //biale pionki
                    if(i<3)
                    {
                            if(j>0)
                            {
                                   if(t[i+1][j-1]=='b')
                                   {
                                         ab[i][j]++;                    
                                   }
                            }
                            if(j<3)
                            {
                                   if(t[i+1][j+1]=='b')
                                   {
                                         ab[i][j]++;                    
                                   }       
                            }        
                    } 
                    //czarne pionki        
                    if(i>0)
                    {
                            if(j>0)
                            {
                                   if(t[i-1][j-1]=='c')
                                   {
                                         ac[i][j]=1;                    
                                   }
                            }
                            if(j<3)
                            {
                                   if(t[i-1][j+1]=='c')
                                   {
                                         ac[i][j]=1;                    
                                   }       
                            }        
                    }                              
             }        
     }
}

int main()
{
      int z,ilb,ilc,x,y;
      scanf("%d",&z);
      printf("%d\n",z);
      srand(time(NULL));
      while(z--)
      {
         for(int i=0;i<4;i++) for(int j=0;j<4;j++) t[i][j]='.';
         ilb=rand()%5;
         ilc=rand()%5;
         for(int i=0;i<ilb;i++)
         {
                 do
                 {
                  x=rand()%4;
                  y=rand()%4;
                 }while(t[y][x]!='.');
                 t[y][x]='b';       
         }
         for(int i=0;i<ilc;i++)
         {
                 do
                 {
                  x=rand()%4;
                  y=rand()%4;
                 }while(t[y][x]!='.');
                 t[y][x]='c';       
         }
         atakowa();
         do
         {
           x=rand()%4;
           y=rand()%4;        
         }while(t[y][x]!='.'||ac[y][x]!=0);
         t[y][x]='B';
         atakowa2();
         do
         {
           x=rand()%4;
           y=rand()%4;        
         }while(t[y][x]!='.'||ab[y][x]!=0);
         t[y][x]='C';
         for(int i=0;i<4;i++)
         {
                 for(int j=0;j<4;j++) printf("%c",t[i][j]);
                 printf("\n");        
         }
         printf("\n");
      }
      return 0;      
}
