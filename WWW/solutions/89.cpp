#include<iostream>
using namespace std;
typedef long long ll;

inline ll nwd(ll a, ll b){
  if(b==0)
    return a;
  else
    return nwd(b,a%b);
}

int main(){
  int n;
  ll p,q,nastp,nastq,ileA,ileB,dlu;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld %lld",&p,&q);
//    cin >> p >> q;
    ll dziel = nwd(p,q);
    p /= dziel; q /= dziel;
    nastp = p;
    nastq = q;
    dlu = p*q;
    ileA = ileB = 0;
    bool kto = false;
    /*
      kto = false; siedzi A
      kto = true;  siedzi B
    */
    ll c = 0; // ostatnia liczba
    while(nastp < dlu || nastq < dlu){
      if(nastp < nastq){
        if(kto == false){
          ileA += (nastp-c);
          c = nastp;
          kto = true;
        }
        nastp += p;
      }
      else if(nastq < nastp){
         if(kto == true){
           ileB += (nastq - c);
           c = nastq;
           kto = false;
         }
         nastq += q;
      }
      else{ // nastp==nastq
        if(kto == false)
          ileA += (nastp - c);
        else
          ileB += (nastp - c);
        c = nastp;
        kto = false;
      nastp += p;
      nastq += q;
      }
    }
    if(c < dlu){
      if(kto == false) ileA += (dlu-c);
      else  ileB += (dlu-c);
    }
    if(ileB == 0)
      printf("1 0\n");
    else{
      dziel = nwd(ileA,ileB);
      printf("%lld %lld\n",ileA/dziel,ileB/dziel);
//      cout << ileA << ' ' << ileB << endl;
    }
  }
  return 0;
}
