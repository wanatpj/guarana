#include<cstdio>
#include<vector>
using namespace std;

#define PAII pair<int,int>
#define ST first
#define ND second
#define FOR(x,y,z) for(int x=y;x<=z;++x)

#define DBGa

char tab[4][4];

bool szach[4][4];

vector< PAII > b,c;

PAII B,C;
PAII Cruch;

bool ruszony;

bool wspol(PAII a) {
    return a.ST >= 0 && a.ST < 4 && a.ND >= 0 && a.ND < 4;
}
bool puste(PAII a) {
    return tab[a.ST][a.ND] == '.';
}
bool czarny(PAII a) {
    return tab[a.ST][a.ND] == 'c';
}
bool bialy(PAII a) {
    return tab[a.ST][a.ND] == 'b';
}


void zbudujSzach() {
     FOR(i,0,3)
       FOR(j,0,3)
          szach[i][j] = false;
    #ifdef DBG
    printf("przed szach\n");
    FOR(i,0,3)
    {
	FOR(j,0,3)
	    printf("%c",tab[i][j]);
	printf("\n");
    }
    printf("\n");
    #endif
    
    PAII akt;
    
    FOR(i,0,3)
    {
	FOR(j,0,3)
	{
	    if(tab[i][j] == 'b') {
		  szach[i][j] = true;
		  akt = PAII(i-1,j+1);
		  if(wspol(akt))
		     szach[akt.ST][akt.ND] = true;
          akt = PAII(i-1,j-1);
	      if(wspol(akt))
		      szach[akt.ST][akt.ND] = true;
	    }
	}
    }
    
    FOR(i,0,3)
    {
	FOR(j,0,3)
	    if(tab[i][j] == 'c')
		szach[i][j] = true;
    }
    
    FOR(i,-1,1)
    {
	akt.ST = B.ST + i;
	FOR(j,-1,1)
	{
	    akt.ND = B.ND + j;
	    if(wspol(akt))
	       szach[akt.ST][akt.ND] = true;
	}
    }
    
    #ifdef DBG
    
    FOR(i,0,3)
    {
	FOR(j,0,3)
	    printf("%d",szach[i][j]);
	printf("\n");
    }
    printf("\n");
    #endif
}

bool niematC() {
     zbudujSzach();
     FOR(i,0,3)
     {
        FOR(j,0,3)
        {
           if(tab[i][j] == 'C')
              return !szach[i][j];
        }
     }
}


bool niemat() {
    return niematC();
    zbudujSzach();
    //printf("Cruch: %d %d\n",Cruch.ST,Cruch.ND);
    PAII akt;
    FOR(i,-1,1)
    {
	akt.ST = C.ST + i;
	FOR(j,-1,1)
	{
	    akt.ND = C.ND + j;
	    if(wspol(akt)) {
		//if(tab[akt.ST][akt.ND] == 'C')
		    //continue;
		if(!szach[akt.ST][akt.ND]) //printf("omg !\n");
		    return true;
	    }
	}
    }
    return false;
}

bool matruch() {
     bool ruszony = false;
    Cruch.ST = 0;
    Cruch.ND = 0;
    #ifdef DBG
    printf("matruch\n");
    FOR(i,0,3)
    {
	FOR(j,0,3)
	    printf("%c",tab[i][j]);
	printf("\n");
    }
    printf("\n");
    #endif
    
    PAII akt;
    //FOR(i,0,(int)c.size()-1)
    //for(int i=0;i<c.size();++i)
    FOR(i,0,3)
    FOR(j,0,3)
    {
	if(tab[i][j] != 'c')
	    continue;
	akt = PAII(i,j);
	#ifdef DBG
	printf("ruch czarny: %d %d\n",akt.ST,akt.ND);
	#endif
	++akt.ST;
	
	if(wspol(akt) && puste(akt)) {
	    tab[akt.ST][akt.ND] = 'c';
	    tab[akt.ST-1][akt.ND] = '.';
	    if(niemat()) {
	    tab[akt.ST][akt.ND] = '.';
	    tab[akt.ST-1][akt.ND] = 'c';
		return false;
	    }
	    tab[akt.ST][akt.ND] = '.';
	    tab[akt.ST-1][akt.ND] = 'c';
	}
	
	++akt.ND;
	if(wspol(akt) && bialy(akt)) {
	    tab[akt.ST][akt.ND] = 'c';
	    tab[akt.ST-1][akt.ND-1] = '.';
	    if(niemat()) {
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST-1][akt.ND-1] = 'c';
		return false;
	    }
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST-1][akt.ND-1] = 'c';
	    
	}
	
	akt.ND -= 2;
	if(wspol(akt) && bialy(akt)) {
	    tab[akt.ST][akt.ND] = 'c';
	    tab[akt.ST-1][akt.ND+1] = '.';
	    if(niemat()) {
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST-1][akt.ND+1] = 'c';
		return false;
	    }
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST-1][akt.ND+1] = 'c';
	}
    }
    tab[C.ST][C.ND] = 'C';
    char bylo;
    #ifdef DBG
    //printf("matruch przed C\n");
    FOR(i,0,3)
    {
	FOR(j,0,3)
	    printf("%c",tab[i][j]);
	printf("\n");
    }
    printf("\n");
    #endif
    /*
    FOR(i,-1,1)
    {
	akt.ST = C.ST + i;
	FOR(j,-1,1)
	{
	    if(i == 0 && j == 0)
		continue;
	    akt.ND = C.ND + j;
	    #ifdef DBG
	    printf("akt %d %d\n",akt.ST,akt.ND);
	    #endif
	    if(wspol(akt)) {
		bylo = tab[akt.ST][akt.ND];
		tab[akt.ST][akt.ND] = 'C';
		tab[C.ST][C.ND] = '.';
		if(niemat()) {//printf("%d %d\n",i,j);
		    tab[akt.ST][akt.ND] = bylo;
		    return false;
		}
		tab[akt.ST][akt.ND] = bylo;
		tab[C.ST][C.ND] = 'C';
	    }
	}
    }*/
    FOR(i,-1,1)
    {
       akt.ST = C.ST + i;
       FOR(j,-1,1)
       {
          akt.ND = C.ND + j;
          if(wspol(akt)) {
             #ifdef DBG
             printf("niematC akt %d %d\n",i,j);
             #endif
             bylo = tab[akt.ST][akt.ND];
             zbudujSzach();
             if(szach[akt.ST][akt.ND])
                continue;
	         tab[C.ST][C.ND] = '.';
		     tab[akt.ST][akt.ND] = 'C';
		     if(niematC()) {//printf("%d %d\n",i,j);
                tab[akt.ST][akt.ND] = bylo;
		        tab[C.ST][C.ND] = 'C';
		        return false;
		    }
		    tab[akt.ST][akt.ND] = bylo;
		    tab[C.ST][C.ND] = 'C';
          }
       }
    }
    return true;
}


void policz() {
    PAII akt;
    //FOR(i,0,(int)b.size()-1)
    //printf("size: %d\n",b.size());
    for(int i=0;i<b.size();++i)
    {
	akt = b[i];
	//printf("bialy ruch %d %d\n",akt.ST,akt.ND);
	--akt.ST;
	
	if(wspol(akt) && puste(akt)) {
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST+1][akt.ND] = '.';
	    if(matruch()) {
		printf("TAK\n");
		return;
	    }
	    tab[akt.ST][akt.ND] = '.';
	    tab[akt.ST+1][akt.ND] = 'b';
	}
	
	++akt.ND;
	if(wspol(akt) && czarny(akt)) {
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST+1][akt.ND-1] = '.';
	    if(matruch()) {
		printf("TAK\n");
		return;
	    }
	    tab[akt.ST][akt.ND] = 'c';
	    tab[akt.ST+1][akt.ND-1] = 'b';
	    
	}
	
	akt.ND -= 2;
	if(wspol(akt) && czarny(akt)) {
	    tab[akt.ST][akt.ND] = 'b';
	    tab[akt.ST+1][akt.ND+1] = '.';
	    if(matruch()) {
		printf("TAK\n");
		return;
	    }
	    tab[akt.ST][akt.ND] = 'c';
	    tab[akt.ST+1][akt.ND+1] = 'b';
	}
    }
    printf("NIE\n");
}

void vanish() {
    c.clear();
    b.clear();
}

main() {
    char ch;
    int t;
    scanf("%d%c",&t,&ch);
    while(t--)
    {
	vanish();
	FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
		scanf("%c",&tab[i][j]);
		//szach[i][j] = tab[i][j];
    		switch(tab[i][j])
		    {
		    case 'B':
			B.ST = i;
			B.ND = j;
		    break;
		    case 'C':
		        C.ST = i;
			C.ND = j;
		    break;
		    case 'c':
			c.push_back(PAII(i,j));
		    break;
		    case 'b':
			b.push_back(PAII(i,j));
		    break;
            }
	    }
	    scanf("%c",&ch);
	}
	scanf("%c",&ch);
	policz();
    }
    
    return 0;
}
