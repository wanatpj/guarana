//generator grafów dwudzielnych
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<set>
#include<time.h>
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int x, int y){
	this->x=x;
	this->y=y;
    }
};
struct Cmp{
    bool operator()(const Point &A, const Point &B){
	if(A.x==B.x)
	    return A.y>B.y;
	return A.x>B.x;
    }
};
set<Point,Cmp> S;
vector<Point> V;
int main()
{
    srand(time(NULL));
    int V1,V2,E;
    scanf("%d%d%d", &V1, &V2, &E);
    printf("%d %d %d\n", V1, V2, E);
    while(S.size()!=E)
	S.insert(Point(rand()%V1+1,rand()%V2+1));
    for(set<Point>::iterator i = S.begin();i!=S.end();++i)
	V.push_back(Point(i->x,i->y));
    random_shuffle(V.begin(),V.end());
    for(vector<Point>::iterator i = V.begin();i!=V.end();++i)
	printf("%d %d\n", i->x, i->y);
    return 0;
}
