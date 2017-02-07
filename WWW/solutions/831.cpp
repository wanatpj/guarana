#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct w {
        int nr,grupa,spojna;
        bool pelny;
        vector< w* > lista;
} *wierzcholek[100004];

bool porgr(const w* a, const w* b) {
        return a->grupa > b->grupa;
}
bool pornr(const w* a, const w* b) {
        return a->nr < b->nr;
}

void dziel_na_grupy(int p, int k, int &p1, int &k1, int &p2, int &k2) {
//        printf("przed podzialem: (%d,%d)\n",p,k);
/*        for (int i=p; i<=k; i++) {
                printf("sasiedzi %d: ",wierzcholek[i]->nr);
                for (int j = 0; j<wierzcholek[i]->lista.size(); j++)
                        printf("%d ",wierzcholek[i]->lista[j]->nr);
                printf("\n");
        }//*/
        int a = p,b=p;
        int ileA = 0, ileB = 0;
        int A = 2,krA,krB;
        for (int i=p+1; i<=k; i++)
                if (wierzcholek[i]->lista.size() < wierzcholek[a]->lista.size())
                        a = i;
        for (int i=p; i<=k; i++)
                wierzcholek[i]->grupa = 0;
        wierzcholek[a]->grupa = 1;
        for (vector< w* >::iterator vi = wierzcholek[a]->lista.begin(); vi!=wierzcholek[a]->lista.end(); vi++)
                (*vi)->grupa++;
        for (int i=p; i<=k; i++)
                if (wierzcholek[i]->grupa == 0) {
                        b = i;
                        break;       
                }
        wierzcholek[b]->grupa = 1;
//        printf("dziele wzgledem %d i %d\n",a,b);
        for (vector< w* >::iterator vi = wierzcholek[b]->lista.begin(); vi!=wierzcholek[b]->lista.end(); vi++)
                (*vi)->grupa += 2;
        for (int i=p; i<=k; i++)
                if (wierzcholek[i]->grupa == 1 || wierzcholek[i]->grupa == 2) { //ma polaczenie do jednego
                        wierzcholek[i]->grupa = A;
                        ileA++;
                }
                else if (wierzcholek[i]->grupa == 3) {
                        wierzcholek[i]->grupa = A-1;
                        ileB++;
                }
        for (int i=p; i<=k; i++) 
                if (wierzcholek[i]->grupa == 0) {
//                        printf("rozpatrujemy wierzcholek %d\n",i);
                        krA = krB = 0;
                        for (vector< w* >::iterator vi = wierzcholek[i]->lista.begin(); vi!=wierzcholek[i]->lista.end(); vi++) {
                                if ((*vi)->grupa == A)
                                        krA++;
                                else if ((*vi)->grupa != 0)
                                        krB++;
                        }
                        
                        if (krA == ileA) {
                                wierzcholek[i]->grupa = A-1;
                                ileB++;
                        }
                        else if (krB == ileB) {
                                wierzcholek[i]->grupa = A;
                                ileA++;
                        }
                        else if (krA) {
                                int newIleA = 0;
                                for (vector< w* >::iterator vi = wierzcholek[i]->lista.begin(); vi!=wierzcholek[i]->lista.end(); vi++)
                                        if ((*vi)->grupa == A) {
                                                (*vi)->grupa++;
                                                newIleA++;
                                        }
                                A++;
                                ileB += ileA;
                                ileA = newIleA;
                        } else {
                                int newIleA = 0;
                                for (vector< w* >::iterator vi = wierzcholek[i]->lista.begin(); vi!=wierzcholek[i]->lista.end(); vi++)
                                        if (((*vi)->grupa < A) && ((*vi)->grupa != 0)) {
                                                (*vi)->grupa = A+1;
                                                newIleA++;
                                        }
                                A++;                      
                                ileB +=ileA;
                                ileA = newIleA;          
                        }
                }
        sort(wierzcholek+p,wierzcholek+k+1,porgr);        
        for (int i=p+1; i<=k; i++)
                if (wierzcholek[i]->grupa != wierzcholek[i-1]->grupa) {
                        p1 = p;
                        k1 = i-1;
                        p2 = i;
                        k2 = k;
                        break;
                }
  //      printf("podzielilem grupe na pozycji %d\n",k1);
        for (int i=p1; i<=k1; i++)
                for (int j=0; j<wierzcholek[i]->lista.size(); j++)
                        if (wierzcholek[i]->lista[j]->grupa != A) {
//                                printf("chce usunac %d z listy %d ktora ma dlugosc %d\n",wierzcholek[i]->lista[j]->nr,wierzcholek[i]->nr,wierzcholek[i]->lista.size());                                
                                swap(wierzcholek[i]->lista[j],wierzcholek[i]->lista[wierzcholek[i]->lista.size()-1]);
                                wierzcholek[i]->lista.pop_back();     
                                j--;                                  
                        }
      //                  else
    //                            printf("nie chce usuwac %d z listy %d\n",wierzcholek[i]->lista[j]->nr,wierzcholek[i]->nr);                                                        
        for (int i=p2; i<=k2; i++)
                for (int j=0; j<wierzcholek[i]->lista.size(); j++)
                        if (wierzcholek[i]->lista[j]->grupa == A) {
        //                        printf("chce usunac %d z listy %d\n",wierzcholek[i]->lista[j]->nr,wierzcholek[i]->nr);
                                swap(wierzcholek[i]->lista[j],wierzcholek[i]->lista[wierzcholek[i]->lista.size()-1]);
                                wierzcholek[i]->lista.pop_back();                                       
                                j--;
                        }                        
/*        printf("po podziale1: (%d,%d)\n",p1,k1);
        for (int i=p1; i<=k1; i++) {
                printf("sasiedzi %d: ",wierzcholek[i]->nr);
                for (int j = 0; j<wierzcholek[i]->lista.size(); j++)
                        printf("%d ",wierzcholek[i]->lista[j]->nr);
                printf("\n");
        }
        printf("\n\n");                        
        printf("po podziale2: (%d,%d)\n",p2,k2);
        for (int i=p2; i<=k2; i++) {
                printf("sasiedzi %d: ",wierzcholek[i]->nr);
                for (int j = 0; j<wierzcholek[i]->lista.size(); j++)
                        printf("%d ",wierzcholek[i]->lista[j]->nr);
                printf("\n");
        }
        printf("\n\n");     //*/
}
int rekNSP(int p, int k);
int rekSP(int p, int k,int n, int m) {
/*        printf("rekSP: (%d,%d) n=%d m=%d\n",p,k,n,m);
        for (int i=p; i<=k; i++) {
                printf("sasiedzi %d: ",wierzcholek[i]->nr);
                for (int j = 0; j<wierzcholek[i]->lista.size(); j++)
                        printf("%d ",wierzcholek[i]->lista[j]->nr);
                printf("\n");
        }
        printf("\n\n");//*/

        if (n == 1) {
        //        printf("jupi! 1 wierzcholek o nr %d, zwracam 1\n",wierzcholek[p]->nr);
                wierzcholek[p]->pelny = 1;
                return 1;
        }
        if (n == 2) {
      //          printf("jupi! 2 wierzcholki o nr %d i %d, zwracam 2\n",wierzcholek[p]->nr,wierzcholek[k]->nr);
                wierzcholek[p]->pelny = wierzcholek[k]->pelny = 1;
                return 2;       
        }
        if (m == (n*(n-1)/2)) {
//                printf("jo! graf pelny o %d wierzcholkach\n",n);
                for (int i=p; i<=k; i++)
                        wierzcholek[i]->pelny = 1;
                return n;       
        }
        if (n == 3) {
  //              printf("graf o 3w niepelny\n");
                for (int i=p+1; i<=k; i++)
                        if (wierzcholek[i]->lista.size() == 2) //pierwszy ma dwoch sasiadow
                                swap(wierzcholek[i],wierzcholek[p]);
                wierzcholek[p]->pelny = 1;
                wierzcholek[p+1]->pelny = wierzcholek[p+1]->nr < wierzcholek[p+2]->nr;
                wierzcholek[p+2]->pelny = wierzcholek[p+2]->nr < wierzcholek[p+1]->nr;                
                return 2;
        }
        
        int p1,p2,k1,k2;
        dziel_na_grupy(p,k,p1,k1,p2,k2);
//        printf("wchodze do rekNSP(%d,%d) i rekNSP(%d,%d)\n",p1,k1,p2,k2);
        return rekNSP(p1,k1) + rekNSP(p2,k2);
}

bool porspojna(const w* a, const w* b) {
        return a->spojna > b->spojna;
}

int numeruj(w *v, int nrS) {
        int wynik = 0;
        v->spojna = nrS;
        for (vector< w* >::iterator vi = v->lista.begin(); vi!= v->lista.end(); vi++)
                if ((*vi)->spojna == 0)
                       wynik += numeruj(*vi,nrS)+1;
        return wynik;
}

int rekNSP(int p, int k) {
        if (p == k) {
                wierzcholek[p]->pelny = 1;
                return 1;       
        }
        
        for (int i=p; i<=k; i++)
                wierzcholek[i]->spojna = 0;
        int nr = 1;
        for (int i=p; i<=k; i++)
                if (wierzcholek[i]->spojna == 0)
                        numeruj(wierzcholek[i],nr++);
        sort(wierzcholek+p,wierzcholek+k+1,porspojna);
        int pp = p;
        int pw=p,kw=p,mw,aw,ilekr;
        mw = 0;
        ilekr = wierzcholek[p]->lista.size();
        for (int i=p+1; i<=k+1; i++)
                if ((i==k+1) || (wierzcholek[i]->spojna != wierzcholek[i-1]->spojna)) {
/*                        printf("spojna nr %d, wierzcholki: ",wierzcholek[i-1]->spojna);
                        for (int j=pp; j<i; j++)
                                printf("%d ",wierzcholek[j]->nr);
                        printf("\n");//*/

                        aw = rekSP(pp,i-1,i-pp,ilekr/2);
                        ilekr = 0;
                        if (aw > mw) { // jezeli ta spojna ma wiekszy podgraf pelny
                                mw = aw;
                                pw = pp;
                                kw = i-1;       
                        }
                        else if (aw == mw) { // jazeli maja rowny podgraf pelny, bierzemy lex mniejszy
                                int min1, min2;
                                min1 = wierzcholek[pw]->nr; // sprawdzamy najmniejszy nr pierwszego
                                for (int j=pw; j<=kw; j++)
                                        min1 <?= wierzcholek[j]->nr;
                                min2 = wierzcholek[pp]->nr; // sprawdzamy najmniejszy nr drugiego
                                for (int j=pp; j<i; j++)
                                        min2 <?= wierzcholek[j]->nr;
                                if (min2 < min1) {
                                        mw = aw;
                                        pw = pp;
                                        kw = i-1;
                                }
                        }
                        pp = i;
                              
                } else
                        ilekr += wierzcholek[i]->lista.size();


        
        for (int i=p; i<pw; i++)
                wierzcholek[i]->pelny = 0;                                
        for (int i=kw+1; i<=k; i++)
                wierzcholek[i]->pelny = 0;

/*        printf("rekNSP: p=%d k=%d\n",p,k);
        for (int i=p; i<=k; i++) {
                printf("sasiedzi %d: ",wierzcholek[i]->nr);
                for (int j = 0; j<wierzcholek[i]->lista.size(); j++)
                        printf("%d ",wierzcholek[i]->lista[j]->nr);
                printf("\n");
        }
        printf("\n\n");        //*/
                        
    //    for (int i=p; i<=k; i++)
  //              if (wierzcholek[i]->pelny)
//                printf("wierzcholek[%d] nalezy do grafu pelnego\n",wierzcholek[i]->nr);
        return mw;
}

int main() {
        int D,N,l,s,kr;
        scanf("%d",&D);
        while(D--) {
                scanf("%d",&N);
                for (int i=0; i<=N; i++)
                        wierzcholek[i] = new w();
                for (int i=1; i<=N; i++) {
                        wierzcholek[i]->lista.clear();
                        wierzcholek[i]->nr = i;
                        wierzcholek[i]->grupa = wierzcholek[i]->spojna = 0;
                }
                kr = 0;
                for (int i=2; i<=N; i++) {
                        scanf("%d",&l);
                        for (int j=1; j<=l; j++) {
                                scanf("%d",&s);
                                wierzcholek[i]->lista.push_back(wierzcholek[s]);
                                wierzcholek[s]->lista.push_back(wierzcholek[i]);
                        }
                        kr += l;
                }
                printf("%d\n",rekSP(1,N,N,kr));
//              printf("%d\n",rekNSP(1,N));                
                sort(wierzcholek+1,wierzcholek+N+1,pornr);
                for (int i=1; i<=N; i++)
                        if (wierzcholek[i]->pelny)
                                printf("%d ",wierzcholek[i]->nr);
                printf("\n");
                for (int i=0; i<=N; i++)
                        delete wierzcholek[i];                
        }       
}
