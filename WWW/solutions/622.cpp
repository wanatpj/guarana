#include<iostream>
using namespace std;

const int SIZE = 1005;
int c,n;
char pola[SIZE][SIZE];
bool good[SIZE][SIZE];
void zerujgood(int n){
	for(int i = 0 ; i <= n ; ++i)
		for(int j = 0 ; j <= n ; ++j)
			good[i][j] = 0;
}
bool check(int x,int y){
	if(x<1 || x > n || y < 1 || y > n) return false;
	return true;
}
bool lewy(int x, int y){
	if(check(x-1,y)) return true;
	return false;
}
bool prawy(int x, int y){
	if(check(x+1,y)) return true;
	return false;
}
bool gora(int x, int y){
	if(check(x,y+1)) return true;
	return false;
}
bool dol(int x, int y){
	if(check(x,y-1)) return true; 
	return false;
}
int xk,yk;
//funkcja sprawdza, czy dane pole jest poprawne
bool allcheck(int x, int y){
	//printf("rekurencja %d %d %c\n",x,y,pola[x][y]);
	if(good[x][y] == 1) return false;
	if(good[x][y] == 2) return false;
	good[x][y] = 1;
	switch(pola[x][y]){
		case 'k':
			good[x][y] = 0;
			return true;
			break;
		case '.':
			good[x][y] = 0;
			return true;
			break;
		case 'l':
			if(lewy(x,y)){
				if(allcheck(x-1,y)){
					good[x][y] = 0;
					return true;
				}
			}
			break;
		case 'p':
			if(prawy(x,y)){
				if(allcheck(x+1,y)){
					good[x][y] = 0;
					return true;
				}
			}
			break;
		case 'g':
			if(gora(x,y)){
				if(allcheck(x,y+1)){
					good[x][y] = 0;
					return true;
				}
			}
			break;
		case 'd':
			if(dol(x,y)){
				if(allcheck(x,y-1)){
					good[x][y] = 0;
					return true;
				}
			}
			break;
		default:
			break;
	}
	return false;
}
bool eq(int x,int y,int a,int b){
	if(x == a && y ==b) return true;
	return false;
}
int way(){
	int xa,ya,xo,yo;
	xa=ya=1;
	xo=yo=1;
	int ile = 0;
	while(xa != xk || ya != yk){
//	fprintf(stderr,"tutaj %d %d %d %d %c\n",xa,ya,xo,yo,pola[xa][ya]);
		while(pola[xa][ya]!='.' && pola[xa][ya] != 'k'){
			good[xa][ya] = 2;
			++ile;
			xo=xa;
			yo=ya;
			switch(pola[xa][ya]){
				case 'l':
					xa-=1;
					break;
				case 'p':
					xa+=1;
					break;
				case 'g':
					ya+=1;
					break;
				case 'd':
					ya-=1;
					break;
				default:
					break;
			}
		}
		good[xa][ya] = 2;
		if(pola[xa][ya]	== 'k')
			return ile;
		if(!eq(xa-1,ya,xo,yo)){
			if(lewy(xa,ya)){
				if(allcheck(xa-1,ya)){
					++ile;
					pola[xa][ya] = 'l';
					xo = xa;
					yo = ya;
					xa -= 1;
					continue;
				}
			}
		}
		if(!eq(xa+1,ya,xo,yo)){
			if(prawy(xa,ya)){
				if(allcheck(xa+1,ya)){
					++ile;
					pola[xa][ya] = 'p';
					xo = xa;
					yo = ya;
					xa += 1;
					continue;
				}
			}
		}//*/
		if(!eq(xa,ya-1,xo,yo)){
			/*if(xa == 3 && ya == 2)
				printf("tutaj\n");//*/
			if(dol(xa,ya)){
				if(allcheck(xa,ya-1)){
					++ile;
					pola[xa][ya] = 'd';
					yo = ya;
					yo = ya;
					ya -= 1;
					continue;
				}
			}
		}
		if(!eq(xa,ya+1,xo,yo)){
			if(gora(xa,ya)){
				if(allcheck(xa,ya+1)){
					++ile;
					pola[xa][ya] = 'g';
					yo = ya;
					yo = ya;
					ya += 1;
					continue;
				}
			}
		}//*/
	}
	return ile;
}

int main(){
	scanf("%d",&c);
	char tmp[1010];
	while(c--){
		scanf("%d",&n);
		zerujgood(n+1);
		//printf("%d\n",n);
		for(int i = n ; i >= 1 ; --i){
			//printf("tmp: %c\n",tmp);
			scanf("%s",tmp);
			//printf("%s\n",tmp);
			for(int j = 1 ; j <= n ; ++j){
				pola[j][i]=tmp[j-1];
				//fprintf(stderr,"%c",pola[j][i]);
				if(pola[j][i] == 'k'){
					xk = j;
					yk = i;
				}
			}
		}
		int ile = way();
		int xa = 1, ya = 1;
		printf("%d\n",ile+1);
		while(xa != xk || ya != yk){
			printf("%d %d\n",xa,ya);
			switch(pola[xa][ya]){
				case 'l':
					xa-=1;
					break;
				case 'p':
					xa+=1;
					break;
				case 'g':
					ya+=1;
					break;
				case 'd':
					ya-=1;
					break;
				default:
					break;
			}
		}
		printf("%d %d\n",xk,yk);
	}
	return 0;
}

