//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

#define null NULL
#define iget(exp) scanf("%d",&exp);
#define uget(exp) scanf("%u",&exp);
#define gets(exp) scanf("%s",exp);
#define idefget(exp) int exp;scanf("%d",&exp);
#define udefget(exp) unsigned int exp;scanf("%u",&exp);
#define dataset() udefget(z);while(z--)
#define release true;
#define cindex(exp) exp+1000000000
#define until(exp1, exp2) for(int exp1 = 0;exp1 < exp2;exp1++)

using namespace std;

struct POINT{
	int x, y;

	POINT(unsigned int x, unsigned int y){
		this->x = x;
		this->y = y;
		}

	POINT(){
		x = 0;
		y = 0;
		}

	POINT operator+(int x){
		if(x > 9)return POINT(this->x+1, this->y);
		else return POINT(this->x, this->y+1);
		}

	POINT operator-(int x){
		if(x > 9)return POINT(this->x-1, this->y);
		else return POINT(this->x, this->y-1);
		}

	bool operator==(POINT pt){
		return (this->x == pt.x && this->y == pt.y);
		}
	};

class Plane{
	char **table;
	unsigned short int size;

public:
	Plane(unsigned short int size){
		table = new char*[1000];
		until(i, size)table[i] = new char[1000];
		this->size = size;
		}
	
	char *operator[](int i){
		return table[size-1-i];
		}

	char &operator[](POINT pt){
		return table[size-1-pt.y][pt.x];
		}

	void clear(int size){
		until(i, size)strcpy(table[i], "");
		}
	};

queue<POINT> tmp, q[3];
vector<POINT> trasa;
Plane plane(1000);
bool koniec = false;
unsigned int n;
int ilosc = 1;

void doIt(POINT pt){
	if(plane[pt] == 'r')return;
	if(plane[pt] == 'g'){/*if(pt.y < n)*/tmp.push(pt+1);}
	else if(plane[pt] == 'd'){/*if(pt.y > 0)*/tmp.push(pt-1);}
	else if(plane[pt] == 'p'){/*if(pt.x < n)*/tmp.push(pt+10);}
	else if(plane[pt] == 'l'){/*if(pt.x > 0)*/tmp.push(pt-10);}
	else if(plane[pt] == 'k'){
		koniec = true;
		
		until(i, 3){
			if(q[i].empty())continue;
			if(q[i].back() == pt)while(!q[i].empty()){trasa.push_back(q[i].front());q[i].pop();}
			else while(!q[i].empty())q[i].pop();
			while(!tmp.empty())tmp.pop();
			}
		}
	else{
		until(i, 3){
			if(q[i].empty())continue;
			if(q[i].back() == pt)while(!q[i].empty()){trasa.push_back(q[i].front());q[i].pop();}
			else while(!q[i].empty())q[i].pop();
			while(!tmp.empty())tmp.pop();
			}

		ilosc = 0;
		
		if(pt.x+1 < n)if(plane[pt+10] != 'r'){tmp.push(pt+10);ilosc++;}
		if(pt.x-1 >= 0)if(plane[pt-10] != 'r'){tmp.push(pt-10);ilosc++;}
		if(pt.y+1 < n)if(plane[pt+1] != 'r'){tmp.push(pt+1);ilosc++;}
		if(pt.y-1 >= 0)if(plane[pt-1] != 'r'){tmp.push(pt-1);ilosc++;}
		}
	}

int iter = 0;

bool bfs(){  
	 
	POINT pt = tmp.front();
	tmp.pop();
	
	//if(pt.x < 0 || pt.x >= n || pt.y < 0 || pt.y >= n)return true;

	if(iter == ilosc)iter = 0;

	q[iter++].push(pt);
	doIt(pt);
	if(koniec)return false;

	plane[pt] = 'r';

	return true;
	}

int main(){
	dataset(){
		uget(n);

		plane.clear(1000);
		trasa.clear();
		while(!tmp.empty())tmp.pop();
		until(i, 3)while(!q[i].empty())q[i].pop();
		koniec = false;
		iter = 0;
		ilosc = 1;

		for(int i = n-1;i >= 0;i--)gets(plane[i]);
		
		tmp.push(POINT(0, 0));

		while(bfs());

		cout << trasa.size() << endl;
		until(i, trasa.size())cout << trasa[i].x+1 << " " << trasa[i].y+1 << endl;
		}

	return 0;
	}
