#include<iostream>
using namespace std;
typedef long long ll;

ll nwd(ll a, ll b){return b==0 ? a : nwd(b,a%b); }

main(){
  int n;
  scanf("%d",&n);
  while(n--){
    ll p,q,wyn,temp,ileA,ileB;
    cin >> p >> q;
    ll dziel = nwd(p,q);
    p /= dziel; q /= dziel;
    if(p < q){
      ileA = (p*(p+1))/2;
      wyn = p*q;
      ileB = wyn - ileA;
    }
    else{
      ileB = (q*(q-1))/2;
      wyn = p*q;
      ileA = wyn - ileB;
    }
    dziel = nwd(ileA,ileB);
    ileA /= dziel; ileB /= dziel;
    cout << ileA << ' ' << ileB << endl;
  }
}
