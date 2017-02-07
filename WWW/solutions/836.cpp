#include <cstdio>
#include <algorithm>
#define INF 2000000000
using namespace std;
int n;
int tab2[201][201];
int ilosc[201][201];
int tab[201];
int sum[201];
void doit()
{
scanf("%d", &n);
for(int i=0; i<n; i++) for(int j=0; j<n; j++) {tab2[i][j]=INF; ilosc[i][j]=INF;}
for(int i=0; i<n; i++) {
    scanf("%d", &tab[i]);
    tab2[i][i]=0;   
    ilosc[i][i]=0;
}
sum[0]=tab[0];
for(int i=1; i<n; i++) {
    sum[i]=sum[i-1]+tab[i];
}
for(int i=1; i<n; i++) {
    for(int j=0; j<n; j++) {
	if (i+j>n) break;
	for(int k=0; k<i; k++) {
	    if (j==0) tab2[0][i]=min(tab2[0][i],tab2[0][k]+tab2[k+1][i]+sum[i]);
	    else tab2[j][j+i]=min(tab2[j][j+i],tab2[j][j+k]+tab2[j+k+1][j+i]+sum[j+i]-sum[j-1]);
	}
	for(int k=0; k<i-1; k++) {
	    if (j==0) {
		if (tab2[0][i]==tab2[0][k]+tab2[k+1][i]+sum[i]) ilosc[0][i]=min(ilosc[0][i],ilosc[0][k]+ilosc[k+1][i]+1);
	    } else {
		if (tab2[j][j+i]==tab2[j][j+k]+tab2[j+k+1][j+i]+sum[j+i]-sum[j-1]) ilosc[j][j+i]=min(ilosc[j][j+i],ilosc[j][j+k]+ilosc[j+k+1][j+i]+1);
	    }
	}
        if (j==0) {
    	    if (tab2[0][i]==tab2[0][i-1]+tab2[i][i]+sum[i]) ilosc[0][i]=min(ilosc[0][i],ilosc[0][i-1]+ilosc[i][i]);
	} else {
	    if (tab2[j][j+i]==tab2[j][j+i-1]+tab2[j+i][j+i]+sum[j+i]-sum[j-1]) ilosc[j][j+i]=min(ilosc[j][j+i],ilosc[j][j+i-1]+ilosc[j+i][j+i]);
	}

    }
}
//for(int i=0; i<n-1; i++) printf("%d\n", tab2[i][i+1]);
//printf("%d\n", tab2[1][4]);


printf("%d %d\n", tab2[0][n-1],ilosc[0][n-1]);
}



int main()
{
int z; scanf("%d", &z); while(z--) doit();
return 0;
}
