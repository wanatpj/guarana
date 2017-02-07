#include<iostream>
#include<list>
using namespace std;
struct zeznanie{
	int p,k;
	char c;
};
zeznanie zez[20001];
list<int> przypadki[10001][2];
int przyp[10001];
// n numerujemy od 1
int d,n,z;
void zerujprzyp(int k){
	for(int i = 0 ; i <= k ; ++i)
		przyp[i] = 0;
}
void zerujprzypadki(int k){
	for(int i = 0 ; i <= k ; ++i){
		przypadki[i][0].clear();
		przypadki[i][1].clear();
	}
}
void renamezez(){
	for(int i = 1 ; i <= z ; ++i){
		if(zez[zez[i].k].c == 'W' || zez[zez[i].k].c == 'N' || zez[i].c == 'W'){
			//printf("tutaj\n");
			switch(zez[i].c){
				case 'P':
					if(zez[zez[i].k].c == 'W')
						zez[i].c = 'W';
					else zez[i].c = 'N';
					zez[i].k = zez[zez[i].k].k;
					break;
				case 'F':
					if(zez[zez[i].k].c == 'W')
						zez[i].c = 'N';
					else zez[i].c = 'W';
					zez[i].k = zez[zez[i].k].k;
					break;
				default:
					break;
			}
			if(zez[i].c == 'W')
				przypadki[zez[i].p][0].push_back(zez[i].k);
			else przypadki[zez[i].p][1].push_back(zez[i].k);
		}
	}
}
void fillprzyp(){
	for(int i = 1 ; i <= n ; ++i){
		przypadki[i][1].sort();
		przypadki[i][1].unique();
		przypadki[i][0].sort();
		przypadki[i][0].unique();
		if(przypadki[i][0].size() > 1) continue;
		if(przypadki[i][0].size() == 1){
			przyp[*przypadki[i][0].begin()]-=1;
			for(list<int>::iterator it = przypadki[i][1].begin() ; it != przypadki[i][1].end() ; ++it){
				if(*it == *przypadki[i][0].begin())
					przyp[*przypadki[i][0].begin()]+=1;
			}
			continue;
		}		
		for(list<int>::iterator it = przypadki[i][1].begin() ; it != przypadki[i][1].end() ; ++it){
			przyp[*it]+=1;
		}
	}
	int min = 1000000000;
	for(int i = 1 ; i <= n ; ++i){
		if(przyp[i] < min) min = przyp[i];
	}
	for(int i = 1 ; i <= n ; ++i){
		if(przyp[i] == min)
			printf("%d ",i);
	}
	//printf("min: %d\n",min);
	printf("\n");
}
int main(){
	scanf("%d",&d);
	while(d--){
		scanf("%d%d",&n,&z);
		for(int i = 1 ; i <= z ; ++i){
			char spacja;
			scanf("%d%c%c%d",&zez[i].p,&spacja,&zez[i].c,&zez[i].k);
//			printf("%d %c %d\n",zez[i].p,zez[i].c,zez[i].k);
		}
		zerujprzypadki(n);
		zerujprzyp(n);
		renamezez();
		fillprzyp();
	}
	return 0;
}

