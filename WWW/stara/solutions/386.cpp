#include<cstdio>
#include<algorithm>
using namespace std;
struct mys{
  int p,k;
  char c;
};
mys t[20000];
int res[10000];
int nw[10000];
int wi[10000];
bool Cmp(mys A, mys B){
  if(A.p==B.p){
    if(A.c==B.c)
      return A.k<B.k;
    return A.c>B.c;
  }
  return A.p<B.p;
}
bool Cmpp(mys A, mys B){
  if(A.p==B.p)
    if(A.k==B.k)
        return A.c>B.c;
    return A.k<B.k;
  return A.p<B.p;
}
bool pr[10000];
bool npowi[10000];
int main()
{
  int D,N,Z,mysum,j,cnt;
  scanf("%d", &D);
  while(D--){
    scanf("%d%d", &N, &Z);
    for(int i=0;i<N;i++){
      res[i]=0;
      nw[i]=0;
      wi[i]=0;
      pr[i]=1;
      npowi[i]=1;
    }
    for(int i=0;i<Z;++i){
      scanf("%d %c%d", &t[i].p, &t[i].c, &t[i].k);//
      --t[i].k;
      --t[i].p;
    }
    for(int i=0;i<Z;++i){
      if(t[i].c=='P'){
        t[i].c=t[t[i].k].c;
      t[i].k=t[t[i].k].k;
    }
      else if(t[i].c=='F'){
        if(t[t[i].k].c=='W')
          t[i].c='N';
        else t[i].c='W';
      t[i].k=t[t[i].k].k;
      }
    }
//    for(int i=0;i<Z;++i)
//      printf("->%d %c %d\n", t[i].p, t[i].c, t[i].k);
    sort(t,t+Z,Cmpp);
    for(int i=1;i<Z;++i)
        if(t[i].p==t[i-1].p&&t[i].k==t[i-1].k&&t[i].c!=t[i-1].c)
            pr[t[i].p]=0;
    for(int i=1;i<Z;++i)
        if('W'==t[i-1].c&&t[i].c=='W'&&t[i].p==t[i-1].p&&t[i].k!=t[i-1].k)
            pr[t[i].p]=0;
    sort(t,t+Z,Cmp);
    j=0;
    for(int i=1;i<Z;++i)
        if(t[i].p!=t[j].p||t[i].k!=t[j].k||t[i].c!=t[j].c){
            ++j;
            t[j]=t[i];
        }
    Z=j+1;
    mysum=0;
    for(int i=0;i<Z;++i)
        if(t[i].c=='W')
            npowi[t[i].p]=0;
//    printf("pr: ");
//    for(int i=0;i<N;++i)
//      printf("%d ", pr[i]);
//    printf("\n");
    for(int i=0;i<Z;++i)
      if(pr[t[i].p]){
        if(t[i].c=='W'){
            ++mysum;
            ++wi[t[i].k];
        }
        else if(npowi[t[i].p]){
            ++nw[t[i].k];
        }
      }
    for(int i=0;i<N;++i)
        res[i]=nw[i]+mysum-wi[i];
    int mini=res[0];
    cnt=1;
    for(int i=1;i<N;++i)
        if(mini>res[i]){
            mini=res[i];
            cnt=1;
        }
        else if(mini==res[i])
            ++cnt;
//    printf("%d %d\n", cnt, mini);
//    for(int i=0;i<N;++i)
//      printf("(%d,%d,%d) ", res[i], nw[i], wi[i]);
//    printf("\n");
    for(int i=0;i<N;++i)
        if(res[i]==mini)
            printf("%d ", i+1);
    printf("\n");
  }
  return 0;
}
