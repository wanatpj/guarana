#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

char wrz[4][6];
char b[4][6];
char c[4][6];

bool szach(){
    int pozi, pozj;
    for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
        if(c[i][j]=='C'){pozi=i; pozj=j; break;}

    int i=pozi; int j=pozj;
        if(i!=3){
            if(j!=0){
                if(c[i+1][j-1]=='b' || c[i+1][j-1]=='B') return 1;
            }
            if(j!=3){
                if(c[i+1][j+1]=='b' || c[i+1][j+1]=='B') return 1;
            }
                if(c[i+1][j]=='B') return 1;
        }
        if(j!=0){
            if(c[i][j-1]=='B') return 1;
        }
        if(j!=3){
            if(c[i][j+1]=='B') return 1;
        }
        if(i!=0){
            if(j!=0){
                if(c[i-1][j-1]=='B') return 1;
            }
            if(j!=3){
                if(c[i-1][j+1]=='B') return 1;
            }
            if(c[i-1][j]=='B') return 1;
        }
    return 0;
}

void wyczyscc(){
    for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
        c[i][j]=b[i][j];
}

bool sprawdz(){
    wyczyscc();
    if(szach()==0) return 0;
    for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
        wyczyscc();
            if(b[i][j]!='c' && b[i][j]!='C') continue;
            if(b[i][j]=='c' && i!=3){
                if(j!=0){
                    if(b[i+1][j-1]=='b'){
                        c[i+1][j-1]='c';
                        c[i][j]='.';
                        if(szach()==0) return 0;
                    }
                }
                wyczyscc();
                if(j!=3){
                    if(b[i+1][j+1]=='b'){
                        c[i+1][j+1]='c';
                        c[i][j]='.';
                        if(szach()==0) return 0;
                    }
                }
                wyczyscc();
                    if(b[i+1][j]=='.'){
                        c[i+1][j]='c';
                        c[i][j]='.';
                        if(szach()==0) return 0;
                    }
            }
            wyczyscc();
            if(b[i][j]=='C'){
                if(i!=0) if(b[i-1][j]!='c'){
                    c[i-1][j]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(i!=3) if(b[i+1][j]!='c'){
                    c[i+1][j]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(j!=0) if(b[i][j-1]!='c'){
                    c[i][j-1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(j!=3) if(b[i][j+1]!='c'){
                    c[i][j+1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(i!=0 && j!=0) if(b[i-1][j-1]!='c'){
                    c[i-1][j-1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(i!=3 && j!=3) if(b[i+1][j+1]!='c'){
                    c[i+1][j+1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                if(i!=0 && j!=3) if(b[i-1][j+1]!='c'){
                    c[i-1][j+1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }
                wyczyscc();
                    if(i!=3 && j!=0) if(b[i+1][j-1]!='c'){
                    c[i+1][j-1]='C';
                    c[i][j]='.';
                    if(szach()==0) return 0;
                }

            }
        }
    }
    return 1;
}

void wyczyscb(){
    for(int i=0; i<4; i++)
    for(int j=0; j<4; j++)
        b[i][j]=wrz[i][j];
}

int main(){
    int il; scanf("%d", &il);
    while(il--){
        scanf("%s", wrz[0]);
        scanf("%s", wrz[1]);
        scanf("%s", wrz[2]);
        scanf("%s", wrz[3]);

        bool wyn=0;

        for(int i=1; i<4; i++){
            for(int j=0; j<4; j++){
                if(wrz[i][j]=='b'){
                    wyczyscb();
                    if(j!=0){
                        if(wrz[i-1][j-1]=='c'){
                            b[i-1][j-1]='b';
                            b[i][j]='.';
                            wyn=sprawdz();
                            if(wyn) break;
                        }
                    }
                    wyczyscb();
                    if(j!=3){
                        if(wrz[i-1][j+1]=='c'){
                            b[i-1][j+1]='b';
                            b[i][j]='.';
                            wyn=sprawdz();
                            if(wyn) break;
                        }
                    }
                    wyczyscb();
                        if(wrz[i-1][j]=='.'){
                            b[i-1][j]='b';
                            b[i][j]='.';
                            wyn=sprawdz();
                            if(wyn) break;
                        }
                }
            }
            if(wyn) break;
        }
        if(wyn) printf("TAK\n"); else printf("NIE\n");
    }
    return 0;
}
