#include<cstdio>
#include<algorithm>
char c[4][5];
inline bool isChbC(int r, int k){
    return r!=0&&((k!=0&&c[r-1][k-1]=='c')||(k!=3&&c[r-1][k+1]=='c'));
}
inline bool isChbB(int r, int k){
//    printf("^%d %d^", r, k);
    return r!=3&&((k!=0&&c[r+1][k-1]=='b')||(k!=3&&c[r+1][k+1]=='b'));
}
inline bool isFr(int r, int k){
    return 0<=r&&r<4&&0<=k&&k<4&&c[r][k]=='.';
}
inline bool fieFi(int r, int k, char ch){
    return 0<=r&&r<4&&0<=k&&k<4&&c[r][k]==ch;
}
bool pawn_protected(int r, int k){
    if(fieFi(r+1,k+1,'b')||fieFi(r+1,k-1,'b'))
        return true;
    for(int i=-1;i<2;i++)
    for(int j=-1;j<2;j++)
        if(i!=0||j!=0)
            if(fieFi(r+i,k+j,'B'))
                return true;
    return false;
}
bool check(int r, int k){
//    printf("|%d %d\n", r, k);
//    printf("a");
//    if(r<0||r>3||k<0||k>3||c[r][k]!='C')
//      return false;
//    printf("b");
    if(!isChbB(r,k))
        return false;
//    printf("c");
    if(fieFi(r+1,k-1,'b'))//{printf("jamnik kaita");
        if(isChbC(r+1,k-1))
            return false;//}
//    printf("d");
    if(fieFi(r+1,k+1,'b'))//{printf("jamnik kaita2}");
        if(isChbC(r+1,k+1))
            return false;//}
//    printf("e");
    for(int i=-1;i<2;i++)
    for(int j=-1;j<2;j++)
        if((i!=0||j!=0)&&0<=i+r&&i+r<4&&0<=j+k&&j+k<4){
            if(!pawn_protected(r+i,k+j)&&c[r+i][k+j]!='c')
                return false;
        }
//    printf("f");
    return true;
}
//void wypisz(){
//    for(int i=0;i<4;i++)
//      printf("%s\n", c[i]);
//}
int main()
{
    int t;
    int r,k;
    scanf("%d", &t);
    bool my;
    while(t--){
        my=0;
        for(int i=0;i<4;i++)
            scanf("%s", c[i]);
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)//{printf("%c", c[i][j]);
            if(c[i][j]=='C')
                {r=i;k=j;}//}
        for(int i=1;i<4;i++)
        for(int j=0;j<4;j++){
            if(c[i][j]!='b') continue;
//          printf("#%d %d#", i, j);
            if(c[i-1][j]=='.'){
//              printf("A");
                c[i][j]='.';
                c[i-1][j]='b';
//              wypisz();
                if(check(r,k)) my=1;// printf("1) %d %d\n", i, j);}
                c[i][j]='b';
                c[i-1][j]='.';
            }
            if(j>0&&c[i-1][j-1]=='c'){
//              printf("D");
                c[i-1][j-1]='b';
                c[i][j]='.';
//              wypisz();
                if(check(r,k)) my=1;// printf("2) %d %d\n", i, j);}
                c[i][j]='b';
                c[i-1][j-1]='c';
            }
            if(j<3&&c[i-1][j+1]=='c'){
//              printf("E");
                c[i-1][j+1]='b';
                c[i][j]='.';
                if(check(r,k)) my=1;// printf("3) %d %d\n", i, j);}
                c[i][j]='b';
                c[i-1][j+1]='c';
            }
        }
        if(my)
            printf("TAK\n");
        else printf("NIE\n");
    }
    return 0;
}
