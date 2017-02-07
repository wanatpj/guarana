#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define VOLUMES 9
#define CVOLUMES 16
int length(int n){
    if(n<10) return 1;
    return length(n/10)+1;
}
char s[100];
int add(int it, int v){
    if(v<10){s[it]='0'+v; return 1;}
    int tmp = add(it,v/10);
    s[it+tmp]='0'+v%10;
    return tmp+1;
}
int adds(int it, char *c){
    int tmplen = strlen(c);
    for(int i=0;i<tmplen;++i)
	s[it+i]=c[i];
}
int main()
{
    char t[100] = "wget http://icpcres.ecs.baylor.edu/onlinejudge/external/";
    for(int i=0;i<100;++i)
	s[i]=t[i];
    int begin;
    for(int i=1;i<=VOLUMES;++i){
	add(56,i);
	begin=56+length(i);
	s[begin]='/';
	++begin;
	for(int j=0;j<100;++j){
	    add(begin,100*i+j);
	    adds(begin+length(100*i+j),".html");
	    s[begin+length(100*i+j)+5]=0;
	    system(s);
	    s[begin]='p';
	    add(begin+1,100*i+j);
	    adds(begin+1+length(100*i+j),".gif");
	    s[begin+length(100*i+j)+5]=0;
	    system(s);
	}
    }
    for(int i=0;i<CVOLUMES;++i){
	add(56,100+i);
	begin=56+length(100+i);
	s[begin]='/';
	++begin;
	for(int j=0;j<100;++j){
	    add(begin,100*(100+i)+j);
	    adds(begin+length(100*(100+i)+j),".html");
	    s[begin+length(100*(100+i)+j)+5]=0;
	    system(s);
	    s[begin]='p';
	    add(begin+1,100*(100+i)+j);
	    adds(begin+1+length(100*(100+i)+j),".gif");
	    s[begin+length(100*(100+i)+j)+5]=0;
	    system(s);
	}
    }
    system("wget http://icpcres.ecs.baylor.edu/onlinejudge/external/115/acmlogo.gif");
    return 0;
}
