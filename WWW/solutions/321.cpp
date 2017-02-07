#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct zez{
   int kt;
   bool tak;     
};

struct vert{
  int w;
  set<int> unguilty;
};

const int N = 10000;
const int K = 20011;
zez zeznania[K];
bool klamie[K];
vert winny[K];
int deg[K];
int n,k;
vector<int> naj;

void zeruj(){
  for(int i=1;i<=n;i++){
    winny[i].unguilty.clear();
    klamie[i]=deg[i]=winny[i].w = 0;
  }
  for(int i=1;i<=k;i++)
    zeznania[i].kt = zeznania[i].tak = 0;
  naj.clear();
}

main(){
  int t;
  int a , b;
  char u;
  set<int>::iterator p;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
      scanf("%d %c %d",&a,&u,&b);
      if(u == 'W'){
//        printf("W\n");
        zeznania[i].kt = b;
        zeznania[i].tak = true;
        if(!klamie[a]){
          p = winny[a].unguilty.find(b);
          if((winny[a].w != 0 && winny[a].w!=b) || p!=winny[a].unguilty.end())
            klamie[a] = true;
          else{
            winny[a].w = b;
          }
        }
      }
      else if(u == 'P'){
//        printf("P\n");
        zeznania[i].kt = zeznania[b].kt;
        zeznania[i].tak = zeznania[b].tak;
        if(!klamie[a]){
           p = winny[a].unguilty.find(zeznania[i].kt);
          if(zeznania[i].tak == true){
            if((winny[a].w != 0 && winny[a].w!=zeznania[i].kt) || p!=winny[a].unguilty.end())
              klamie[a] = true;
            else
              winny[a].w = zeznania[i].kt;
          }
          else{
            if(zeznania[i].kt==winny[a].w) klamie[i] = true;
            else{ if(p==winny[a].unguilty.end()) winny[a].unguilty.insert(zeznania[i].kt); }
          }
        }
      }
      else{
//        printf("F\n");
        zeznania[i].kt = zeznania[b].kt;
        zeznania[i].tak = !zeznania[b].tak;
        if(!klamie[a]){
          p = winny[a].unguilty.find(zeznania[i].kt);
          if(zeznania[i].tak == true){
            if((winny[a].w != 0 && winny[a].w!=zeznania[i].kt) || p!= winny[a].unguilty.end())
              klamie[a] = true;
            else
              winny[a].w = zeznania[i].kt;
          }
          else{
            if(zeznania[i].kt == winny[a].w) klamie[a] = true;
            else{ if(p==winny[a].unguilty.end()) winny[a].unguilty.insert(zeznania[i].kt); }
          }
        }
      }
    }
    for(int i=1;i<=n;i++){
      if(!klamie[i])
        deg[winny[i].w]++;
    }
    for(int i=1;i<=n;i++){
      if((winny[i].w == 0) && winny[i].unguilty.size() <n){
        for(set<int>::iterator p = winny[i].unguilty.begin();p!=winny[i].unguilty.end();p++)
          deg[*p]--;
      }
    }
    int maks = -1;
    for(int i=1;i<=n;i++){
      if(deg[i] > maks){
        naj.clear();
        maks = deg[i];
        naj.push_back(i);
      }
      else if(deg[i] == maks)
        naj.push_back(i);
    }
    for(vector<int>::iterator p = naj.begin();p!=naj.end();p++)
      printf("%d ",*p);
    printf("\n");
    zeruj();
  }
  return 0;
}
