#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct Point{
    long double x,y;
    Point operator-(Point A){
        A.x=x-A.x;
        A.y=y-A.y;
        return A;
    }
    bool operator==(Point A){
        return this->x==A.x&&this->y==A.y;
    }
};
vector<Point> hull;
long double abs(long double x){
    if(x<0) return -x;
    return x;
}
long double ilWek(Point A, Point B){
    return A.x*B.y-A.y*B.x;
}
bool Cmp(Point A, Point B){
    return ilWek(A-hull[0],B-hull[0])>0;
}
bool CmpN(Point A, Point B){
    if(A.x==B.x)
        return A.y<B.y;
    return A.x<B.x;
}
Point A,B,C,D,E,F;
bool intersect__one(Point A1, Point A2, Point B1, Point B2){//
    return ilWek(B2-A1,A2-A1)*ilWek(B1-A1,A2-A1)<0&&ilWek(A1-B1,B2-B1)*ilWek(A2-B1,B2-B1)<0;
}
Point intersection_point(Point A1, Point A2, Point B1, Point B2){
    Point res;
    long double G=A1.y-A2.y,
        H=A2.x-A1.x,
        I=A1.y*A2.x-A1.x*A2.y,
        J=B1.y-B2.y,
        K=B2.x-B1.x,
        L=B1.y*B2.x-B1.x*B2.y;
    res.y=(I*J-G*L)/(H*J-G*K);
    res.x=(I*K-H*L)/(G*K-H*J);
    return res;
}
bool notBelongs(Point G){
    long double k = ilWek(G-A,B-A);
    if(k*ilWek(G-B,C-B)<0||k*ilWek(G-C,A-C)<0)
        return true;
    k = ilWek(G-D,E-D);
    if(k*ilWek(G-E,F-E)<0||k*ilWek(G-F,D-F)<0)
        return true;
    return false;
}
//void wypisz_hulla(){
//    printf("Hull:\n");
//    for(int i=0;i<hull.size();i++)
//      printf("(%lf,%lf) ", hull[i].x, hull[i].y);
//    printf("hull end.\n");
//}
void sudo_do_sth(){
    hull.push_back(A);
    hull.push_back(B);
    hull.push_back(C);
    hull.push_back(D);
    hull.push_back(E);
    hull.push_back(F);
//    wypisz_hulla();
    if(intersect__one(A,B,D,E))//{printf("11");
        hull.push_back(intersection_point(A,B,D,E));//}
    if(intersect__one(A,B,E,F))//{printf("22");
        hull.push_back(intersection_point(A,B,E,F));//}
    if(intersect__one(A,B,F,D))//{printf("33");
        hull.push_back(intersection_point(A,B,F,D));//}
    if(intersect__one(B,C,D,E))//{printf("44");
        hull.push_back(intersection_point(B,C,D,E));//}
    if(intersect__one(B,C,E,F))//{printf("55");
        hull.push_back(intersection_point(B,C,E,F));//}
    if(intersect__one(B,C,F,D))//{printf("66");
        hull.push_back(intersection_point(B,C,F,D));//}
    if(intersect__one(C,A,D,E))//{printf("77");
        hull.push_back(intersection_point(C,A,D,E));//}
    if(intersect__one(C,A,E,F))//{printf("88");
        hull.push_back(intersection_point(C,A,E,F));//}
    if(intersect__one(C,A,F,D))//{printf("99");
        hull.push_back(intersection_point(C,A,F,D));//}
//    wypisz_hulla();
    sort(hull.begin(),hull.end(),CmpN);
//    wypisz_hulla();
    int cnt=1;
    for(int i=1;i<hull.size();++i)
        if(!(hull[cnt-1]==hull[i]))
            hull[cnt++]=hull[i];
//    wypisz_hulla();
    while(hull.size()>cnt)
        hull.pop_back();
//    wypisz_hulla();
    for(int i=0;i<hull.size();++i)
        if(notBelongs(hull[i])){
            hull[i]=hull[hull.size()-1];
            hull.pop_back();
            --i;
        }
//    wypisz_hulla();
    for(int i=1;i<hull.size();i++)
        if(hull[i].y<hull[0].y||(hull[i].y==hull[0].y&&hull[i].x<hull[0].x))
            swap(hull[0],hull[i]);
    vector<Point>::iterator it = hull.begin();
//    wypisz_hulla();
    if(hull.size()<2) return;
    it++;
    sort(it,hull.end(),Cmp);//tc
//    wypisz_hulla();
}
long double the_area(){
    long double res=0;
//    printf("%d\n", hull.size());
    for(int i=0;i<(int)hull.size()-1;i++)
        res+=ilWek(hull[i],hull[i+1]);
//    printf("a\n");
    if(hull.size()>0)
        res+=ilWek(hull[hull.size()-1],hull[0]);
//    printf("b\n");
    return res;
}
int main()
{
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
    scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &D.x, &D.y, &E.x, &E.y, &F.x, &F.y);
    long double area=0;
    hull.push_back(A);
    hull.push_back(B);
    hull.push_back(C);
    area+=abs(the_area());
//    printf("%.5lf", area);
    hull.pop_back();
    hull.pop_back();
    hull.pop_back();
    hull.push_back(D);
    hull.push_back(E);
    hull.push_back(F);
    area+=abs(the_area());
//    printf("%.5lf", area);
    hull.pop_back();
    hull.pop_back();
    hull.pop_back();
    sudo_do_sth();
    area-=abs(the_area());
    printf("%.5Lf\n", area/2);
    return 0;
}
