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
    int tmp;
    int btmp;
    for(int i=1;i<=VOLUMES;++i){
	add(56,i);
	begin=56+length(i);
	s[begin]='/';
	++begin;
	for(int j=0;j<100;++j)
	for(int k=1;;++k){
	    add(begin,100*i+j);
	    tmp = length(100*i+j);
	    adds(begin+tmp,"img");
	    add(begin+tmp+3,k);
	    tmp+=length(k);
	    adds(begin+tmp+3,".gif");
	    s[begin+tmp+7]=0;
	    btmp = true;
	    if(!system(s)) btmp = false;
	    adds(begin+tmp+3,".jpg");
	    s[begin+tmp+7]=0;
	    if(!system(s)) btmp = false;
	    if(btmp) break;
	}
    }
    for(int i=1;i<=VOLUMES;++i){
        add(56,i);
        begin=56+length(i);
        s[begin]='/';
        ++begin;
	s[begin]='p';
	++begin;
        for(int j=0;j<100;++j)
	for(int k=0;;++k){
	    add(begin,100*i+j);
	    tmp = length(100*i+j);
	    s[begin+tmp]='a'+(char)k;
	    adds(begin+tmp+1,".jpg");
	    s[begin+tmp+5]=0;
	    btmp = true;
	    if(!system(s)) btmp = false;
	    adds(begin+tmp+1,".gif");
	    s[begin+tmp+5]=0;
	    if(!system(s)) btmp = false;
	    if(btmp) break;
	}
    }
    for(int i=0;i<CVOLUMES;++i){
        add(56,100+i);
        begin=56+length(100+i);
        s[begin]='/';
        ++begin;
	s[begin]='p';
	++begin;
        for(int j=0;j<100;++j)
	for(int k=0;;++k){
	    add(begin,100*(100+i)+j);
	    tmp = length(100*(100+i)+j);
	    s[begin+tmp]='a'+(char)k;
	    adds(begin+tmp+1,".jpg");
	    s[begin+tmp+5]=0;
	    btmp = true;
	    if(!system(s)) btmp = false;
	    adds(begin+tmp+1,".gif");
	    s[begin+tmp+5]=0;
	    if(!system(s)) btmp = false;
	    if(btmp) break;
	}
    }
    return 0;
}
