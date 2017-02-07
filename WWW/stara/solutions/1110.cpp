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

int n = 0;
 
struct POINT{
	int x, y, qID;

	POINT(int x, int y, int qID = 0){
		this->x = x;
		this->y = y;
		this->qID = qID;
		}

	POINT(){
		this->x = this->y = this->qID = 0;
		}
	};

struct Plane{
	char **plane;
	int size;

	Plane(){
		this->plane = null;
		this->size = 0;
		}
	Plane(int size){
		this->plane = new char*[size];
		for(int i = 0;i < size;i++)plane[i] = new char[size];
		}

	char & operator[](POINT pt){
		return plane[pt.y][pt.x];
		}
	char* operator[](int x){
		return plane[x];
		}
	};

Plane plane(1001);
queue<POINT> tmp, q[4], trasa;
int len = 0;

bool bfs(){
	POINT pt;
	pt = tmp.front();
	tmp.pop();

	if(pt.x < 0 || pt.y < 0 || pt.x == n || pt.y == n || plane[pt] == 1)return true;
	q[pt.qID].push(pt);


	if(plane[pt] == 'k'){
		until(i, 4){
			if(i == pt.qID){
				while(!q[i].empty()){
					trasa.push(q[i].front());
					len++;
					q[i].pop();
					}
				}
			else while(!q[i].empty())q[i].pop();
			}
		while(!tmp.empty())tmp.pop();
		return false;
		}

	if(plane[pt] == '.'){
/*
		cout << pt.x+1 << " " << n-pt.y << " ID: " << pt.qID << " odklada:" << endl;
		cout << "\t" << pt.x+2 << " " << n-pt.y << " ID: " << 0 << endl;
		cout << "\t" << pt.x << " " << n-pt.y << " ID: " << 1 << endl;
		cout << "\t" << pt.x+1 << " " << n-pt.y+1 << " ID: " << 2 << endl;
		cout << "\t" << pt.x+1 << " " << n-pt.y-1 << " ID: " << 3 << endl;*/

		until(i, 4){
			if(i == pt.qID){
				while(!q[i].empty()){
					trasa.push(q[i].front());
					len++;
					q[i].pop();
					}
				}
			else while(!q[i].empty())q[i].pop();
			}
		while(!tmp.empty())tmp.pop();

		tmp.push(POINT(pt.x+1, pt.y, 0));
		tmp.push(POINT(pt.x-1, pt.y, 1));
		tmp.push(POINT(pt.x, pt.y+1, 2));
		tmp.push(POINT(pt.x, pt.y-1, 3));
		plane[pt] = 1;

		return true;
		}

	//cout << pt.x+1 << " " << n-pt.y << " ID:" << pt.qID << " odklozy cokolwiek z ID: " << pt.qID << endl;
	if(plane[pt] == 'd')
		if(pt.y < n-1){tmp.push(POINT(pt.x, pt.y+1, pt.qID));plane[pt] = 1;return true;}

	if(plane[pt] == 'g')
		if(pt.y > 0){tmp.push(POINT(pt.x, pt.y-1, pt.qID));plane[pt] = 1;return true;}

	if(plane[pt] == 'p')
		if(pt.x < n-1){tmp.push(POINT(pt.x+1, pt.y, pt.qID));plane[pt] = 1;return true;}

	if(plane[pt] == 'l')
		if(pt.x > 0){tmp.push(POINT(pt.x-1, pt.y, pt.qID));plane[pt] = 1;return true;}


	return true;
	}

int main(){
	ios::sync_with_stdio(0);
	dataset(){
		uget(n);
		len = 0;

		until(i, n)gets(plane[i]);

		POINT pt(0, n-1);

		while(plane[pt] != '.'){
			trasa.push(pt);
			len++;
			if(plane[pt] == 'g'){plane[pt] = 1;pt.y--;}
			else if(plane[pt] == 'd'){plane[pt] = 1;pt.y++;}
			else if(plane[pt] == 'p'){plane[pt] = 1;pt.x++;}
			else if(plane[pt] == 'l'){plane[pt] = 1;pt.x--;}
			}

		pt.qID = 0;
		tmp.push(pt);

		while(bfs());

		cout << len << endl;
		while(!trasa.empty()){
			cout << trasa.front().x+1 << " " << n-trasa.front().y << endl;
			trasa.pop();
			}
		}
	return 0;
	}
