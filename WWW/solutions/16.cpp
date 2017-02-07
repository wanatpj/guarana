#include <iostream>
#define MAX 4
using namespace std;

struct point { int x,y; } C, B, ata;
point Ba,Ca;
point cz[MAX], bi[MAX];
int ilb, ilc;
int ab[5][5], ac[5][5];
int z, res;
bool odp;
char t[5][5], tmp;

inline void atakowa()
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

int sprawdz()
{
     int ile=0;
     for(int i=0;i<4;i++)
     {
             for(int j=0;j<4;j++) 
                     if(t[i][j]=='C')
                     {
                          C.x=j;
                          C.y=i;                
                     }        
     }
     atakowa();
     
     //czy jego pozycja jest atakowana
     if(ab[C.y][C.x]==0) return 0;
     
     //sprawdzam czy moze czarny krol sie ruszyc na bezpieczne miejsce
     bool moze=0;
     if(C.y>0)
     {
              if(C.x>0)
              {
                       if(ab[C.y-1][C.x-1]==0&&t[C.y-1][C.x-1]!='c') moze=1;      
              }
              if(C.x<3)
              {
                       if(ab[C.y-1][C.x+1]==0&&t[C.y-1][C.x+1]!='c') moze=1;
              }
              if(ab[C.y-1][C.x]==0&&t[C.y-1][C.x]!='c') moze=1;         
     }
     if(C.y<3)
     {
              if(C.x>0)
              {
                       if(ab[C.y+1][C.x-1]==0&&t[C.y+1][C.x-1]!='c') moze=1;         
              }
              if(C.x<3)
              {
                       if(ab[C.y+1][C.x+1]==0&&t[C.y+1][C.x+1]!='c') moze=1;
              }
              if(ab[C.y+1][C.x]==0&&t[C.y+1][C.x]!='c') moze=1;      
     }
     if(C.x>0) if(ab[C.y][C.x-1]==0&&t[C.y][C.x-1]!='c') moze=1;
     if(C.x<3) if(ab[C.y][C.x+1]==0&&t[C.y][C.x+1]!='c') moze=1;
     if(moze==1) return 0;
     
     if(ab[C.y][C.x]>1) return 1;
     
     if(C.x>0)
     {
         if(t[C.y+1][C.x-1]=='b')
         {
                if(ac[C.y+1][C.x-1]==0) return 1;                        
         }     
     }
     if(C.x<3)
     {
         if(t[C.y+1][C.x+1]=='b')
         {
                if(ac[C.y+1][C.x+1]==0) return 1;                        
         }     
     }
     return 0;     
}

inline void krol(const point &k, const point &z)
{
       atakowa();
       if(ac[z.y][z.x]==0)
       {
        tmp=t[z.y][z.x];
        t[z.y][z.x]='B';
        t[k.y][k.x]='.';
                          
        if(sprawdz()==1) odp=1;
                          
        t[z.y][z.x]=tmp;
        t[k.y][k.x]='B';
       }       
}

main()
{
      scanf("%d",&z);
      while(z--)
      {
                ilc=ilb=0;
                for(int i=0;i<MAX;i++) scanf("%s",&t[i]);          
                for(int i=0;i<MAX;i++)
                {
                        for(int j=0;j<MAX;j++)
                        {
                                if(t[i][j]=='b')
                                {
                                     bi[ilb].x=j;
                                     bi[ilb].y=i;
                                     ilb++;                
                                }
                                else if(t[i][j]=='c')
                                {
                                     cz[ilc].x=j;
                                     cz[ilc].y=i;
                                     ilc++;
                                }
                                else if(t[i][j]=='B')
                                {
                                     Ba.x=j;
                                     Ba.y=i;     
                                }
                                else if(t[i][j]=='C')
                                {
                                     Ca.x=j;
                                     Ca.y=i;     
                                }
                        }        
                }
                odp=0;
                //ruchy pionkow
                for(int i=0;i<ilb;i++)
                {
                      if(bi[i].y>0)
                      {
                            //w gore
                            if(t[bi[i].y-1][bi[i].x]=='.')
                            {
                             t[bi[i].y-1][bi[i].x]='b';
                             t[bi[i].y][bi[i].x]='.';
                            
                             res=sprawdz();
                             if(res==1) { odp=1; break; }
                             
                             t[bi[i].y-1][bi[i].x]='.';
                             t[bi[i].y][bi[i].x]='b';
                            }
                            //w prawo
                            if(bi[i].x<3)
                            {
                             if(t[bi[i].y-1][bi[i].x+1]=='c')
                             {
                               t[bi[i].y-1][bi[i].x+1]='b';
                               t[bi[i].y][bi[i].x]='.';
                            
                               res=sprawdz();
                               if(res==1) { odp=1; break; }
                            
                               t[bi[i].y-1][bi[i].x+1]='c';
                               t[bi[i].y][bi[i].x]='b';                              
                             }
                            }
                            //w lewo
                            if(bi[i].x>0)
                            {
                             if(t[bi[i].y-1][bi[i].x-1]=='c')
                             {
                               t[bi[i].y-1][bi[i].x-1]='b';
                               t[bi[i].y][bi[i].x]='.';
                            
                               res=sprawdz();
                               if(res==1) { odp=1; break; }
                            
                               t[bi[i].y-1][bi[i].x-1]='c';
                               t[bi[i].y][bi[i].x]='b';                              
                             }
                            }              
                      }          
                }
                //ruch krola
                point ble;
                int wyn=0;
                if(Ba.y>0)
                {
                 ble.y=Ba.y-1;
                 if(Ba.x>0)
                 {
                       ble.x=Ba.x-1;
                       krol(Ba,ble);     
                 }
                 if(Ba.x<3)
                 {
                       ble.x=Ba.x+1;
                       krol(Ba,ble);
                 }
                 ble.x=Ba.x;
                 krol(Ba,ble);         
                }
                if(Ba.y<3)
                {
                 ble.y=Ba.y+1;
                 if(Ba.x>0)
                 {
                       ble.x=Ba.x-1;
                       krol(Ba,ble);       
                 }
                 if(Ba.x<3)
                 {
                       ble.x=Ba.x+1;
                       krol(Ba,ble); 
                 }
                 ble.x=Ba.x;
                 krol(Ba,ble);      
                }
                ble.y=Ba.y;
                if(Ba.x>0)
                { 
                          ble.x=Ba.x-1;
                          krol(Ba,ble);
                }
                if(Ba.x<3)
                {
                          ble.x=Ba.x+1;
                          krol(Ba,ble);          
                }      
                if(odp==0) printf("NIE\n");
                else printf("TAK\n");
      }
      return 0;
}
