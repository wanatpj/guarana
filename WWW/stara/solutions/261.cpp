#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string mie[] = {"komin", "okno", "drzwi", "brak"};

int main(){
	int d, om, ok, oo, od;
	scanf("%d %d", &d, &om);
	int wyn;
	while(d--){
		scanf("%d %d %d", &ok, &oo, &od);
		if(om < ok) wyn = 0;
		if(om >= ok && om < oo) wyn = 1;
		if(om >= ok && om >= oo && om < od) wyn = 2;
		if(om >= ok && om >= oo && om >= od) wyn = 3;
		printf("%s\n", mie[wyn].c_str());
	}
	return 0;
}
