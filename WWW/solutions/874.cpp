#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
const int Size = 100010;
void wypisznumerygrup(int a, int b);
int n,d;
//void printgraf();
struct node{
	bool klika;
	int nr;
	int nrwtablicy;
	int nrgrupy;
	int spojna;
	vector<node*> sasiedzi;
};
node* graf[Size]; 
int fgrouptmp[Size];
void cleargraf(int n){
	for(int i = 0 ; i <= n ; ++i){
		graf[i]->klika = 0;
		graf[i]->nr = i;
		graf[i]->nrwtablicy = i;
		graf[i]->nrgrupy = -1;
		graf[i]->spojna = 0;
		graf[i]->sasiedzi.clear();
	}
}
void zamien(int a, int b){
	node* tmp = graf[a];
	graf[a] = graf[b];
	graf[b] = tmp;
	graf[a]->nrwtablicy = a;
	graf[b]->nrwtablicy = b;
}
//zwraca ilosc spojnych skladowych i uzupelnia graf o ich numerki
int spojne(int a, int b){
	int spojna = 0;
	int where = 0;
	for(int i = a ; i <= b ; ++i)
		graf[i]->spojna = -1;
	for(int i = a ; i <= b ; ++i){
		if(graf[i]->spojna == -1){
			//printf("i: %d, graf[i]->nr: %d\n",i,graf[i]->nr);
			graf[i]->spojna = spojna;
			where = i+1;
			spojna+=1;
			queue<node*> q;
			q.push(graf[i]);
			while(!q.empty()){
				node* ptr = q.front();
				q.pop();
				//fprintf(stderr,"nr: %d\n",ptr->nr);
				for(vector<node*>::iterator it = ptr->sasiedzi.begin(); it != ptr->sasiedzi.end() ; ++it){
					if((*it)->spojna != spojna-1){
						(*it)->spojna = spojna-1;
						zamien(where,(*it)->nrwtablicy);	
						++where;
						q.push(*it);
					}
				}
			}
		}
	}
	//for(int i = a ; i <= b ; ++i) fprintf(stderr,"spojna[%d]: %d\n",i,graf[i]->spojna);
	return spojna;
}
//umieszcza pierwsze elementy grup na poczatku i zwraca ich ilosc
int makefirstgroup(int a, int b){
	int size = b-a+1;
	int ile = 2;
	node* first;
	node* second;
	for(int i = a; i <= b ; ++i){
			//fprintf(stderr,"tutaj graf[i]->sasiedzi.size(): %d, size: %d\n", graf[i]->sasiedzi.size(),size);
		if(graf[i]->sasiedzi.size() < size-1){
			first = graf[i];
			break;
		}
	}
	for(int i = first->nrwtablicy+1 ; i <= b ; ++i){
		bool war = true;
		for(vector<node*>::iterator it = graf[i]->sasiedzi.begin() ; it != graf[i]->sasiedzi.end() ; ++it){
			if(*it == first) war = false;
		}
		if(war){
			second = graf[i];
			break;
		}
	}
	first->nrgrupy = second->nrgrupy = 0;
	//fprintf(stderr,"dziala first->nrwtablicy: %d second->nrwtablicy: %d a: %d, b: %d\n",first->nrwtablicy,second->nrwtablicy,a,b);
	zamien(a,first->nrwtablicy);zamien(a+1,second->nrwtablicy);
	for(int i = a ; i <= b ; ++i) fgrouptmp[i] = 0;
	for(vector<node*>::iterator it = first->sasiedzi.begin() ; it!= first->sasiedzi.end() ; ++it){
		fgrouptmp[(*it)->nrwtablicy]++;
	}
	for(vector<node*>::iterator it = second->sasiedzi.begin() ; it!= second->sasiedzi.end() ; ++it){
		fgrouptmp[(*it)->nrwtablicy]++;
	}
	for(int i = a+2 ; i <= b ; ++i){
		if(fgrouptmp[i] == 0) continue;
		if(fgrouptmp[i] == 1)
			graf[i]->nrgrupy = 0;
		else graf[i]->nrgrupy = 1;
		zamien(i,a+ile);
		++ile;
	}
	//wypisznumerygrup(a, b);
	return ile;	
}

int ilewA(int a, int maxnrgrupy, int ile){
	int wynik = 0;
	for(int i = a ; i < a + ile ; ++i){
		if(graf[i]->nrgrupy < maxnrgrupy) ++wynik;
	}
	return wynik;
}//*/
//zwraca maxnrgrupy
int ileA,ileB;
int dodajelement(int a,int b,int el, int maxnrgrupy,int ile){
	//for(int i = a ; i <= b ; ++i) fgrouptmp[i] = 0;
	int A = 0, B = 0;
	for(vector<node*>::iterator it = graf[el]->sasiedzi.begin(); it!=graf[el]->sasiedzi.end() ; ++it){
		if((*it)->nrgrupy == maxnrgrupy) ++B;
		else if((*it)->nrgrupy > -1) ++A;
	}		
	if(A == ileA){
		graf[el]->nrgrupy = maxnrgrupy;
		++ileB;
	}
	else if(B == ileB){
		graf[el]->nrgrupy = 0;
		++ileA;
	}
	else if(B > 0){
		ileB = 0;
		for(vector<node*>::iterator it = graf[el]->sasiedzi.begin() ; it != graf[el]->sasiedzi.end() ; ++it){
			if((*it)->nrgrupy == maxnrgrupy){
				(*it)->nrgrupy++;
				++ileB;
			}
		}
		++maxnrgrupy;
		graf[el]->nrgrupy = 0;
		ileA=ile-ileB;
		++ileA;
	}
	else{
		ileB = 0;
		for(vector<node*>::iterator it = graf[el]->sasiedzi.begin() ; it != graf[el]->sasiedzi.end() ; ++it){
			if((*it)->nrgrupy < maxnrgrupy){
				(*it)->nrgrupy = maxnrgrupy + 1;
				ileB++;
			}
		}
		++maxnrgrupy;
		graf[el]->nrgrupy = 0;
		ileA = ile - ileB;
		++ileA;
	}
	//printgraf();
	//wypisznumerygrup(a,b);
	//fprintf(stderr,"dziala A: %d, B: %d ileA: %d, ileB: %d, maxnrgrupy: %d\n",A,B,ileA,ileB,maxnrgrupy);
	return maxnrgrupy;
}
int podzielgrupy(int a, int b, int maxnrgrupy){
	int where = a;
	for(int i = a ; i <= b ; ++i){
		if(graf[i]->nrgrupy < maxnrgrupy){
			zamien(where,i);
			where++;
		}
	}
	return where-1;
}
int klikaniespojna(int a, int b);
void zmniejszvectorysasiadow(int a, int b){
	//fprintf(stderr,"dziala1 %d %d\n",a,b );
	for(int i = a ; i <= b ; ++i){
		vector<node*>::iterator it = graf[i]->sasiedzi.begin();
		//vector<node*>::iterator tmp = it;
		while(it!=graf[i]->sasiedzi.end()){
		//	fprintf(stderr,"dziala2 %d\n",(*it)->nrwtablicy);
			if((*it)->nrwtablicy < a || (*it)->nrwtablicy > b){
		//		tmp = it;
				swap(*it,graf[i]->sasiedzi.back());
				graf[i]->sasiedzi.pop_back();	
			}
			else ++it;
		}
		//	fprintf(stderr,"tut\n");
	}
}
void ustawklike(int a, int b){
	for(int i = a ; i <= b ; ++i)
		graf[i]->klika = 1;
}
/*void wypisznumerygrup(int a, int b){
	for(int i = a ; i <= b ; ++i)
		fprintf(stderr,"nr: %d,graf[%d]->nrgrupy: %d\n",graf[i]->nr,i,graf[i]->nrgrupy);
}//*/
//funkcja liczy ilosc krawedzi w grafie
int nrofkrmoja(int a, int b){
	int wynik = 0;
	for(int i = a; i <= b ; ++i){
		wynik+=graf[i]->sasiedzi.size();
	}
	return wynik/2;
}
int klikaspojna(int a, int b){
	//	fprintf(stderr,"dziala1\n");
	int size = b-a+1;
	if(size == 1){ 
		ustawklike(a,b);
		return 1;
	}
	if(size == 2){
		ustawklike(a,b);
		return 2;
	}
	if(nrofkrmoja(a,b) == (size*(size-1))/2){
		ustawklike(a,b);
		return size;
	}
	//fprintf(stderr,"dziala size: %d\n",size);
	if(size == 3){
		int wybrany = a;
		for(int i = a ; i <= b ; ++i){
			if(graf[i]->sasiedzi.size() == 2) wybrany = i;
		}
		graf[wybrany]->klika = 1;
		vector<node*>::iterator it = graf[wybrany]->sasiedzi.begin();
		node* first = *it; it++;
		node* second = *it;
		if(first->nr < second->nr) 
			first->klika = 1;
		else second->klika = 1;
		return 2;
	}
	int ile = makefirstgroup(a,b);	
	ileA = ilewA(a,1,ile);
	ileB = ile - ileA;
	//fprintf(stderr,"ile: %d\n",ile);
	//wypisznumerygrup(a,b);
	int maxnrgrupy = 1;
	for(int i = a+ile ; i <= b ; ++i) graf[i]->nrgrupy = -1;
	for(int i = a+ile ; i <= b ; ++i){
		maxnrgrupy = dodajelement(a,b,i,maxnrgrupy,ile);
		++ile;
	}
	//fprintf(stderr,"dziala2\n");
//	fprintf(stderr,"dziala\n");
	int q = podzielgrupy(a,b,maxnrgrupy);
	//wypisznumerygrup(a,b);
	zmniejszvectorysasiadow(a,q);
	//printgraf();
	zmniejszvectorysasiadow(q+1,b);
	//fprintf(stderr,"dziala2\n");
	return klikaniespojna(a,q) + klikaniespojna(q+1,b);	
}
//sprawdza czy druga z rownolicznych klik w podanych przedzialach jest mniejsza od pierwszej
bool checkkliki(int a1, int b1, int a2, int b2){
	int min1 = 1000000000;
	int min2 = min1;
	for(int i = a1 ; i <= b1 ; ++i){
		if(graf[i]->klika)
			if(graf[i]->nr < min1)
				min1 = graf[i]->nr;
	}
	for(int i = a2 ; i <= b2 ; ++i){
		if(graf[i]->klika)
			if(graf[i]->nr < min2)
				min2 = graf[i]->nr;
	}
	//fprintf(stderr,"min1: %d,min2: %d\n",min1,min2);
	if(min1 < min2) return false;
	return true;
}//*/
int minkliki(int a, int b){
	int min1= 1000000000;
	for(int i = a; i <= b ; ++i){
		if(graf[i]->klika)
			if(graf[i]->nr < min1)
				min1 = graf[i]->nr;
	}
	return min1;
}
int klikaniespojna(int a, int b){
	//printgraf();
	int ile = spojne(a,b);
	int beg = a;
	int end = a;
	int begresult = 0;
	int endresult = 0;
	int max = -1;
	int min1;
	int min2;
	for(int i = 0 ; i < ile ; ++i){
		while(end <= b && graf[end]->spojna == i ){
			++end;
		}
		int wynik = 0;
		//wypisznumerygrup(a,b);
		//fprintf(stderr,"dziala a: %d b: %d beg: %d end: %d ile: %d, wynik: %d, max: %d\n",a,b,beg,end,ile,wynik,max);
		zmniejszvectorysasiadow(a,end-1);
		wynik = klikaspojna(beg,end-1);
		//printgraf();
		//fprintf(stderr,"dziala a: %d b: %d beg: %d end: %d ile: %d, wynik: %d, max: %d\n",a,b,beg,end,ile,wynik,max);
		if(wynik == max){
			min2 = minkliki(beg,end-1);
			if(checkkliki(begresult,endresult,beg,end-1)){//min2 < min1){
				begresult = beg;
				endresult = end-1;
			}
		}
		if(wynik > max){
			max = wynik;
			//min1 = minkliki(beg,end-1);
			begresult = beg;
			endresult = end-1;
		}
		beg = end;
	}
//	fprintf(stderr,"begresult: %d, endresult: %d\n",begresult,endresult);
	if(ile > 1){
		for(int i = a; i <= b ; ++i){
			if(i < begresult || i > endresult){
				graf[i]->klika = 0;
			}
		}
	}
	return max;
}
/*void printgraf(){
	for(int i = 1 ; i <= n ; ++i){
		fprintf(stderr,"nr: %d, nrwgrafie: %d:\n",graf[i]->nr,i);
		for(vector<node*>::iterator it = graf[i]->sasiedzi.begin() ; it != graf[i]->sasiedzi.end() ; ++it){
			fprintf(stderr,"%d ",(*it)->nr);
		}
		fprintf(stderr,"\n");
	}

}//*/
int main(){
	scanf("%d",&d);
	for(int i = 0 ; i < Size ; ++i)
		graf[i] = new node;
	while(d--){
//		fprintf(stderr,"d: %d\n\n",d);
		scanf("%d",&n);
		cleargraf(n+1);
		for(int i = 2 ; i <= n ; ++i){
			int m;
			scanf("%d",&m);
			//fprintf(stderr,"m: %d\n",m);
			while(m--){
				int sasiad;
				scanf("%d",&sasiad);
				//fprintf(stderr,"sasiad: %d\n", sasiad);
				graf[i]->sasiedzi.push_back(graf[sasiad]);
				graf[sasiad]->sasiedzi.push_back(graf[i]);
			}
			
		}
//		printgraf();
		int wynik = klikaspojna(1,n);
		list<int> results;
		for(int i = 1 ; i <= n ; ++i){
			if(graf[i]->klika)
				results.push_back(graf[i]->nr);
		}
		results.sort();
		printf("%d\n",wynik);
		for(list<int>::iterator it = results.begin() ; it != results.end() ; ++it)
			printf("%d ",*it);
		printf("\n");
	}
	return 0;
}

