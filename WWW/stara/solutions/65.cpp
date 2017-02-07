#include<cstdio>
#include<vector>
using namespace std;

#define PAII pair<int,int>
#define ST first
#define ND second
#define FOR(x,y,z) for(int x=y;x<=z;++x)

char tab[4][4];
char help[4][4];

bool szach[4][4];

PAII B,C;
PAII akt,akt2;

bool mat;

bool wspol(PAII a) {
    return a.ST >= 0 && a.ST < 4 && a.ND >= 0 && a.ND < 4;
}

bool jaki(PAII a, char co) {
     return help[a.ST][a.ND] == co;
}

void zmien(PAII a, char co) {
     help[a.ST][a.ND] = co;
}

void wroc() {
     FOR(i,0,3)
        FOR(j,0,3)
           help[i][j] = tab[i][j];
}

void generujSzach() {
     FOR(i,0,3)
       FOR(j,0,3)
          szach[i][j] = false;
    
    PAII temp;
    
    FOR(i,0,3)
    {
	   FOR(j,0,3)
	   {
	       if(help[i][j] == 'b') {
		     szach[i][j] = true;
	   	     temp = PAII(i-1,j+1);
    	     if(wspol(temp))
		        szach[temp.ST][temp.ND] = true;
             temp = PAII(i-1,j-1);
	         if(wspol(temp))
		        szach[temp.ST][temp.ND] = true;
	      }
	   }
    }
    
    FOR(i,0,3)
	   FOR(j,0,3)
	      if(help[i][j] == 'c')
		     szach[i][j] = true;
    
    FOR(i,-1,1)
    {
	   temp.ST = B.ST + i;
	   FOR(j,-1,1)
	   {
	       temp.ND = B.ND + j;
	       if(wspol(temp))
	          szach[temp.ST][temp.ND] = true;
	   }
    }
}

bool checkMat() {
     PAII gdzieC;
     FOR(i,0,3)
        FOR(j,0,3)
           if(help[i][j] == 'C') {
              gdzieC = PAII(i,j);
              break;
           }
     
     PAII temp;
     FOR(i,-1,1)
     {
        temp.ST = gdzieC.ST + i;
        FOR(j,-1,1)
        {
           temp.ND = gdzieC.ND + j;
           if(wspol(temp)) {
              if(!szach[temp.ST][temp.ND]) {
                 return false;
              }
           }
        }
     }
     return true;
}

void ratunekPrzedMatem() {
     bool czy = true;
     generujSzach();
     czy = czy && checkMat();
     
     PAII temp;
     
     if(akt.ND > C.ND) {
        temp = PAII(C.ST,C.ND + 2);
        if(wspol(temp) && jaki(temp,'c')) {
           zmien(temp,'.');
           zmien(akt,'c');
           generujSzach();
           czy = czy && szach[C.ST][C.ND];
           zmien(temp,'c');
           zmien(akt,'b');
        }
        zmien(akt,'C');
        zmien(C,'.');
        generujSzach();
        czy = czy && szach[akt.ST][akt.ND];
        zmien(C,'C');
        zmien(akt,'b');
     }
     else if(akt.ND == C.ND) {
        temp = PAII(akt.ST,akt.ND + 1);
        if(wspol(temp) && jaki(temp,'c')) {
           zmien(temp,'.');
           zmien(akt,'c');
           generujSzach();
           czy = czy && szach[C.ST][C.ND];
           zmien(temp,'c');
           zmien(akt,'b');
        }
        temp = PAII(akt.ST,akt.ND - 1);
        if(wspol(temp) && jaki(temp,'c')) {
           zmien(temp,'.');
           zmien(akt,'c');
           generujSzach();
           czy = czy && szach[C.ST][C.ND];
           zmien(temp,'c');
           zmien(akt,'b');
        }
        zmien(akt,'C');
        zmien(C,'.');
        generujSzach();
        czy = czy && szach[akt.ST][akt.ND];
        zmien(C,'C');
        zmien(akt,'b');
     }
     else if(akt.ND < C.ND) {
        temp = PAII(akt.ST,akt.ND - 2);
        if(wspol(temp) && jaki(temp,'c')) {
           zmien(temp,'.');
           zmien(akt,'c');
           generujSzach();
           czy = czy && szach[C.ST][C.ND];
           zmien(temp,'c');
           zmien(akt,'b');
        }
        zmien(akt,'C');
        zmien(C,'.');
        generujSzach();
        czy = czy && szach[akt.ST][akt.ND];
        zmien(C,'C');
        zmien(akt,'b');
     }
     wroc();
     if(czy)
        mat = true;
}

void ruchBpoC() {
     if(!wspol(akt2))
        return;
     if(!jaki(akt2,'b'))
        return;
     zmien(akt,'b');
     zmien(akt2,'.');
     ratunekPrzedMatem();
     wroc();
}

void ruchB() {
     if(!wspol(akt))
        return;
     if(jaki(akt,'.')) {
        akt2 = PAII(akt.ST+1,akt.ND);
        ruchBpoC();
     }
     else if(jaki(akt,'c')) {
        akt2 = PAII(akt.ST+1,akt.ND-1);
        ruchBpoC();
        akt2 = PAII(akt.ST+1,akt.ND+1);
        ruchBpoC();
     }
}

void policz() {
     akt = PAII(C.ST+1,C.ND+1);
     ruchB();
     akt = PAII(C.ST+1,C.ND-1);
     ruchB();
}

void vanish() {
    mat = false;
}

main() {
       int t;
       char ch;
       scanf("%d",&t);
       while(t--)
       {
          scanf("%c",&ch);
          vanish();
          FOR(i,0,3)
	      {
	         FOR(j,0,3)
	         {
		        scanf("%c",&tab[i][j]);
		        help[i][j] = tab[i][j];
    		    switch(tab[i][j])
		        {
		           case 'B':
                      B = PAII(i,j);
		           break;
                   case 'C':
                      C = PAII(i,j);
                   break;
                }
             }
             scanf("%c",&ch);
          }
          policz();
          printf("%s\n",mat ? "TAK" : "NIE");
       }
       return 0;
}
       
