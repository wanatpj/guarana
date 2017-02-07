#include <iostream>
using namespace std;
struct queue{
 short x,y;
};
queue Q[1000001];
queue Q2[1000001];
queue S[1000001];
int QH,QT,QH2,QT2,SH;

char mc[1001][1001];
int size;
int get_x(int in) {
 return 1000-in;
}

int get_y(int in) {
 return in-1;
} 

void Q_add(int x1, int y1) {
   Q[QT].x=x1;
   Q[QT++].y=y1;
}
void Q2_add(int x1, int y1) {
   Q2[QT2].x=x1;
   Q2[QT2++].y=y1;
}
void S_add(int x1, int y1) {
   S[SH].x=x1;
   S[SH++].y=y1;
}

bool check( int xs,int ys ) {
  //cout<<"SPR"<<endl;
   
  SH=0;
  while(1) {
       char tmp=mc[ get_x( ys ) ][ get_y(xs) ];
       if((xs<1 || xs >size || ys<1 || ys>size || mc[ get_x( ys ) ][ get_y(xs) ] == 'o' ) && tmp!='k') return 0;
       S_add(xs,ys);
       //cout<<"ADD: "<<xs<<" "<<ys<<endl;
       mc[ get_x( ys ) ][ get_y(xs) ] = 'o';
       if( tmp == '.' || tmp == 'k' ) {
            int i=0;
            for(;i<SH-1;i++) {
                Q2_add(S[i].x,S[i].y);}
                Q_add(S[i].x,S[i].y);
                mc[ get_x( S[i].y) ][ get_y(S[i].x) ] = tmp;
                return 1;
        }else {
    
       // cout<<tmp<<" : "<<xs<<" "<<ys<<endl;
        if( tmp == 'g' ) ys++; 
        if( tmp == 'd' ) ys--; 
        if( tmp == 'p' ) xs++; 
        if( tmp == 'l' ) xs--; 
    
      }
  }
 
}

void wczytaj() {
  QT=0;QT2=0;QH=0;QH2=0;
  cin>>size;
  cin.get();
  for(int i=size;i>0;i--) {
    for(int j=1;j<=size; j++) {mc[ get_x(i) ][ get_y(j) ]=cin.get();}
    cin.get();
  }
  
  //cout<<mc[ get_x(1) ][ get_y(1) ]<<endl;
  if( mc[ get_x(1) ][ get_y(1) ]=='g' ) Q_add(1,2);
  if( mc[ get_x(1) ][ get_y(1) ]=='p' ) Q_add(2,1);
}

int main() {
 int Z;
 cin>>Z;
  while(Z--){
   wczytaj();
   while(QT!=QH) {
     int gx=Q[QH].x;
     int gy=Q[QH++].y;
     char tmp = mc[ get_x(gy) ][ get_y(gx) ]; 
     Q2_add(gx,gy);
   //  cout<<tmp<<endl;
     mc[ get_x( gy ) ][ get_y(gx) ] = 'o';
     if(tmp!='.') {
        
        if( tmp == 'g' ) Q_add(gx,gy+1); 
        if( tmp == 'd' ) Q_add(gx,gy-1);
        if( tmp == 'p' ) Q_add(gx+1,gy); 
        if( tmp == 'l' ) Q_add(gx-1,gy);
     }else {
 //       cout<<"Sprawdzamy"<<endl; 
        
        if(check( gx+1, gy ))  ;
        else if(check( gx, gy+1 ));
        else if(check( gx-1, gy ))  ;
        else if(check( gx, gy-1 ));

     }
   }
   cout<<QT2+1<<endl;
   cout<<1<<" "<<1<<endl;
   for(int i=0;i<QT2;i++) cout<<Q2[i].x<<" "<<Q2[i].y<<endl;
  }
 return 0;
}
