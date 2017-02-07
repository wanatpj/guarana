#include <iostream>
using namespace std;

bool sbw[4][4];
char szach[4][4];
char temp[4][4];

bool mat(char tab[4][4])
{
   for(int k=0; k<=3; k++)
   for(int l=0; l<=3; l++)
   sbw[k][l]=false;
   int xk, yk, xp, yp;
   for(int i=0; i<=3; i++)
   {
       for(int j=0; j<=3; j++)
       {
           if(i>0&&tab[i][j]=='b')
           {
              if(j!=3)
              sbw[i-1][j+1]=true;
              if(j!=0)
              sbw[i-1][j-1]=true;
           }
           if(tab[i][j]=='B')
           {
              if(i!=0)
              {
                  if(j!=0)
                  sbw[i-1][j-1]=true;
                  if(j!=3)
                  sbw[i-1][j+1]=true;
                  sbw[i-1][j]=true;
              }
              if(i!=3)
              {
                  if(j!=0)
                  sbw[i+1][j-1]=true;
                  if(j!=3)
                  sbw[i+1][j+1]=true;
                  sbw[i+1][j]=true;
              }
              if(j!=0)
              sbw[i][j-1]=true;
              if(j!=3)
              sbw[i][j+1]=true;
           }
       }
   }
   for(int i=0; i<=3; i++)
   {
       for(int j=0; j<=3; j++)
       {
          if(tab[i][j]=='C')
          {
              xk=j;
              yk=i;
              xp=j+1;
              yp=i+1;
              if(j>0&&tab[i+1][j-1]=='b')
              xp=j-1;
          }
       }
   }
   if(yk!=0)
   {
     if(xk!=0)
     if(xk!=0&&!sbw[yk-1][xk-1]&&(tab[yk-1][xk-1]=='.'||tab[yk-1][xk-1]=='b'))
     return false;
     if(xk!=3)
     if(xk!=3&&!sbw[yk-1][xk+1]&&(tab[yk-1][xk+1]=='.'||tab[yk-1][xk+1]=='b'))
     return false;;
     if(!sbw[yk-1][xk]&&(tab[yk-1][xk]=='.'||tab[yk-1][xk]=='b'))
     return false;
   }
   if(xk!=0)
   if(xk!=0&&!sbw[yk][xk-1]&&(tab[yk][xk-1]=='.'||tab[yk][xk-1]=='b'))
   return false;
   if(xk!=3)
   if(xk!=3&&!sbw[yk][xk+1]&&(tab[yk][xk+1]=='.'||tab[yk][xk+1]=='b'))
   return false;
   if(!sbw[yk+1][xk]&&(tab[yk+1][xk]=='.'||tab[yk+1][xk]=='b'))
   return false;   
   if(xk!=3)
   if(xk!=3&&!sbw[yk+1][xk+1]&&(tab[yk+1][xk+1]=='.'||tab[yk+1][xk+1]=='b'))
   return false;
   if(xk!=0)
   if(xk!=0&&!sbw[yk+1][xk-1]&&(tab[yk+1][xk-1]=='.'||tab[yk+1][xk-1]=='b'))
   return false;
   if(xp!=3)
   if(xp!=3&&tab[yp-1][xp+1]=='c')
   return false;
   if(xp!=0)
   if(xp!=0&&tab[yp-1][xp-1]=='c')
   return false;
   
   return true;   
}


main()
{
int z;
cin>>z;
for(int i=0; i<z; i++)
{
   bool tak=false;
   string s;
   for(int k=0; k<=3; k++)
   {
       cin>>s;
       for(int j=0; j<=3; j++)
       szach[k][j]=s[j];
   }
   for(int ii=2; ii<=3; ii++)
   {
       for(int j=0; j<=3; j++)
       {
           if(szach[ii][j]=='b')
           {
               for(int k=0; k<=3; k++)
               for(int l=0; l<=3; l++)
               temp[k][l]=szach[k][l];
               
               if(j<3)
               {
                  if(szach[ii-2][j+1]=='C'&&szach[ii-1][j]=='.')
                  {
                      temp[ii][j]='.';
                      temp[ii-1][j]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j]='.';
                  }
                }
                if(j>1)
                {
                   if(szach[ii-2][j-2]=='C'&&szach[ii-1][j-1]=='c')
                   {
                      temp[ii][j]='.';
                      temp[ii-1][j-1]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j-1]='c';
                   }
                }
                if(j>0)
                {
                   if(szach[ii-2][j-1]=='C'&&szach[ii-1][j]=='.')
                   {
                      temp[ii][j]='.';
                      temp[ii-1][j]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j]='.';
                   }
                }
                if(j<2)
                {
                   if(szach[ii-2][j+2]=='C'&&szach[ii-1][j+1]=='c')
                   {
                      temp[ii][j]='.';
                      temp[ii-1][j+1]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j+1]='c';
                   }
                }
                if(j>0)
                {
                   if(szach[ii-2][j]=='C'&&szach[ii-1][j-1]=='c')
                   {
                      temp[ii][j]='.';
                      temp[ii-1][j-1]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j-1]='c';
                   }
                }
                if(j<3)
                {
                   if(szach[ii-2][j]=='C'&&szach[ii-1][j+1]=='c')
                   {
                      temp[ii][j]='.';
                      temp[ii-1][j+1]='b';
                      if(mat(temp)==true)
                      tak=true;
                      temp[ii][j]='b';
                      temp[ii-1][j+1]='c';
                   }
                }
           }
       }
   }
   if(tak==true)
   cout<<"TAK"<<endl;
   else
   cout<<"NIE"<<endl;
}
}
