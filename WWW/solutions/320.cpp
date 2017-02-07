#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct zeznanie{
	int a, b;
	char typ;
};

struct osoba{
	bool falsz;
	int w;
	vector<int> uw;
};

struct oskarzony{
	int num, ilosk;
};

bool por(oskarzony a, oskarzony b){
	if(a.ilosk == b.ilosk) return a.num<b.num;
	return a.ilosk>b.ilosk;
}

char odwroc(char z){
	if(z=='W') return 'U'; return 'W';
}

	int d, n, z;
	zeznanie zez[20010];
	osoba osb[10010];
	oskarzony osk[10010];
	int a, b;
	char typ;
	int min;

int main(){
	scanf("%d", &d);
	while(d--){
		scanf("%d %d", &n, &z);
		for(int i=1; i<=n; i++){
			osk[i].ilosk=0;
			osk[i].num=i;
			osb[i].uw.clear();
			osb[i].w = -1;
			osb[i].falsz = 0;
		}
		for(int i=1; i<=z; i++){
			scanf("%d %c %d", &a, &typ, &b);
			zez[i].a=a;
			zez[i].typ=typ;
			zez[i].b=b;			
			if(typ == 'P'){
				zez[i].typ = zez[b].typ;
				zez[i].b = zez[b].b;
			}
			if(typ == 'F'){
				zez[i].typ = odwroc(zez[b].typ);
				zez[i].b = zez[b].b;
			}
			if(zez[i].typ == 'W'){
				if(osb[a].w!=zez[i].b){
				if(osb[a].w==-1) osb[a].w=zez[i].b; else osb[a].falsz=1;
				}
			}
			if(zez[i].typ == 'U'){
				osb[a].uw.push_back(zez[i].b);
			}
		}
		for(int i=1; i<=n; i++){
			if(osb[i].w != -1) for(int j=0; j<osb[i].uw.size(); j++) if(osb[i].uw[j]==osb[i].w) osb[i].falsz=1;
			if(osb[i].falsz) continue;
			sort(osb[i].uw.begin(), osb[i].uw.end());
			osb[i].uw.resize(unique(osb[i].uw.begin(), osb[i].uw.end()) - osb[i].uw.begin());
			if(osb[i].uw.size() == n) continue;
			
			//printf("%d\n", i);			
			if(osb[i].w != -1){ 
				osk[osb[i].w].ilosk++;
				//printf(" wini: %d", osb[i].w);
			}else{
				//printf(" uniewinnia: ");
				for(int j=0; j<osb[i].uw.size(); j++){
					osk[osb[i].uw[j]].ilosk--;
				//	printf("%d ", osb[i].uw[j]);
				}
			}
			//printf("\n");
		}
		sort(osk+1, osk+n+1, por);
		for(int i=1; i<=n && osk[i].ilosk==osk[1].ilosk; i++) printf("%d ", osk[i].num);
		printf("\n");
	}
	return 0;
}
