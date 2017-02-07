#include <cstdio>
unsigned int czasy [10000];
void scal(unsigned int l , unsigned int s, unsigned int p){
    unsigned int i=l, j=s+1, it=l;
    unsigned int *temp= new unsigned int [p+1];
    while(i <= s && j <= p){
        if(czasy[i] <= czasy[j]){ temp[it] = czasy[i];++it;++i;}
        else { temp[it] = czasy[j];++it; ++j;}
    }
    while(i <= s){temp[it] = czasy[i];++it;++i;}
    while(j <= p){temp[it] = czasy[j];++it;++j;}
    for (int i=l; i<=p; ++i) czasy[i]=temp[i];
    delete [] temp;
}
void msort(unsigned int l , unsigned int p){
    if(l==p) return;
    unsigned int s = (l+p) / 2;
    msort(l,s);
    msort(s+1,p);
    scal(l,s,p);
    return;
}
int main(){
    unsigned int z, n, i;
    unsigned long long x, w, bl, bp, bs, k;
    scanf ("%u", &z);
    while (z--){
        scanf ("%u", &n);
        for (i=0; i<n; ++i){
            scanf ("%u", &czasy[i]);
            }
        msort (0, n-1);
        if (n==1){printf ("%u", czasy[0]); continue;}
        if (n==2){printf ("%u", czasy[0]+czasy[1]); continue;}
        x=2*czasy[1]-czasy[0];
        bl=0;
        bp=n;
        while (bl<bp-1){
                  bs=(bl+bp)/2;
                  ((czasy[bs-1]<=x)?bl:bp)=bs;
                  }
        k=(n-bl)/2;
        //printf (" Pierwszy większy: %u Pierwszy mniejsz lub równy %u bl: %u, k: %u\n", czasy[bl], czasy[bl-1],bl, k);
        w=(n-k-2)*czasy[0]+(2*k+1)*czasy[1];
        for (i=3; i<=n-2*k; ++i)w+=czasy[i-1];
        if (k>0)for (i=0; i<=k-1; ++i)w+=czasy[n-2*i-1];
        printf ("%llu\n", w);
        }
    return 0;
    }
