#include <cstdio>
#include <algorithm>
using namespace std;

long long t[10000], temp, suma, z, n, l;

long long oblicz(int a){
   if (a==0 || a==1) return t[a];
   if (a==2) return t[0]+t[1]+t[2];
   else return min(oblicz(a-2)+t[0]+2*t[1]+t[a], oblicz(a-1)+t[0]+t[a]);
}

int main() {
   scanf("%d", &z);
   while(z--){
      scanf("%d", &n);
      for (int i=0; i<n; i++) scanf("%lld", &t[i]);
      sort(t, t+n);
      printf("%lld\n", oblicz(n-1));
   }
//system("pause");
return 0;
}
