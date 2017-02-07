#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int d;
	scanf("%d",&d);
	while(d--){
		vector <int> os;
		int n, zo, la, ak, n1, n2;
		long long cz=0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &ak);
			os.push_back(ak);
		}
		if(n==1) printf("%d\n", ak);
		else{
			sort(os.begin(), os.end());
			zo = n-2;
			while(zo>1){
				if(os[0]+os[zo+1]+2*os[1] > 2*os[0]+os[zo+1]+os[zo]) break;
				cz += os[0] + os[zo+1] + 2*os[1];
				zo -=2;
			}
			cz += zo*os[0];
			while(zo>0) cz += os[zo--+1];
			printf("%lld\n", cz+os[1]);
		}
	}
	return 0;
}
l 
