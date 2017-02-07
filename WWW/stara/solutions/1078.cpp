//Maksymilian Pasek
#include <cstdio>
#include <iostream>
#include <stack>
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
	int x,y;
	POINT(int x, int y){
		this->x = x;
		this->y = y;
		}
	};

class Plane{
	char **plane;
	unsigned int size;

public:
	unsigned int x,y, lastX, lastY;

	Plane(){
		this->size = 0;
		this->plane = null;
		this->x = 0;
		this->y = 0;
		}

	Plane(unsigned int size){
		this->size = size;
		plane = new char*[size];
		for(unsigned int i = 0;i < size;i++)plane[i] = new char[size];
		this->x = 0;
		this->y = 0;
		}

	char *operator[](unsigned int x){
		return plane[x];
		}

	bool canGoLeft(){
		return (x > 0 && x-1 != lastX);
		}
	bool canGoRight(){
		return (x < size-1 && x+1 != lastX);
		}
	bool canGoUp(){
		return (y > 0 && y-1 != lastY);
		}
	bool canGoDown(){
		return (y < size-1 && y+1 != lastY);
		}

	char left(){
		return plane[y][x-1];
		}
	char right(){
		return plane[y][x+1];
		}
	char up(){
		return plane[y-1][x];
		}
	char down(){
		return plane[y+1][x];
		}
	char center(){
		return plane[y][x];
		}

	void goUp(){
		lastY = y;
		lastX = x;
		y--;
		}
	void goDown(){
		lastY = y;
		lastX = x;
		y++;
		}
	void goLeft(){
		lastX = x;
		lastY = y;
		x--;
		}
	void goRight(){
		lastX = x;
		lastY = y;
		x++;
		}
	void setStartPoint(unsigned int x, unsigned int y){
		this->x = x;
		this->y = y;
		}
	bool isStart(){
		return (x == 0 && y == size-1);
		}
	};

stack<POINT> trasa;
Plane plane(1002);

bool dfs(Plane *plane){
	//system("PAUSE");
	trasa.push(POINT(plane->x, plane->y));
	if(plane->center() == 'k')return true;
	if(plane->center() == 'g' && plane->canGoUp()){plane->goUp();bool a = dfs(plane);if(!a){trasa.pop();return false;}else return true;}
	else if(plane->center() == 'd' && plane->canGoDown()){plane->goDown();bool a = dfs(plane);if(!a){trasa.pop();return false;}else return true;}
	else if(plane->center() == 'l' && plane->canGoLeft()){plane->goLeft();bool a = dfs(plane);if(!a){trasa.pop();return false;}else return true;}
	else if(plane->center() == 'p' && plane->canGoRight()){plane->goRight();bool a = dfs(plane);if(!a){trasa.pop();return false;}else return true;}
	else if(plane->center() == '.'){
		unsigned int tmpX, tmpY, tmpLastX, tmpLastY;
		tmpX = plane->x;
		tmpY = plane->y;
		tmpLastX = plane->lastX;
		tmpLastY = plane->lastY;

		if(plane->canGoDown()){
			plane->goDown();
			if(!dfs(plane)){
			plane->x = tmpX;
			plane->y = tmpY;
			plane->lastX = tmpLastX;
			plane->lastY = tmpLastY;
			goto next1;}
			else return true;
			}
next1:
		if(plane->canGoUp()){
			plane->goUp();
			if(!dfs(plane)){
			plane->x = tmpX;
			plane->y = tmpY;
			plane->lastX = tmpLastX;
			plane->lastY = tmpLastY;
			goto next2;}
			else return true;
			}
next2:
		if(plane->canGoLeft()){
			plane->goLeft();
			if(!dfs(plane)){
			plane->x = tmpX;
			plane->y = tmpY;
			plane->lastX = tmpLastX;
			plane->lastY = tmpLastY;
			goto next3;}
			else return true;
			}
next3:
		if(plane->canGoRight()){
			plane->goRight();
			if(!dfs(plane)){
			plane->x = tmpX;
			plane->y = tmpY;
			plane->lastX = tmpLastX;
			plane->lastY = tmpLastY;}
			else return true;
			}
		}
	trasa.pop();
	return false;
	}

int main(){
	dataset(){
		udefget(n);

		until(i, n)gets(plane[i]);

		plane.setStartPoint(0, n-1);

		dfs(&plane);

		unsigned int len = 0;
		stack<POINT> tmp;
		while(!trasa.empty()){
			tmp.push(trasa.top());
			trasa.pop();
			len++;
			}

		cout << len << endl;
		while(!tmp.empty()){
			cout << tmp.top().x+1 << " " << n-tmp.top().y << endl;
			tmp.pop();
			}

	}

	return 0;
	}