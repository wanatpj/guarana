#include <cstdio>



using namespace std;



struct map {

   char m;

   bool z;

};



map M[1000*1000];

int S[1000*1000],t;

bool k;



void load(int n) {       

    for(int i=n;i>=0;i--) {

       char c=0;

       for(int j=0;;j++) {

         scanf("%c",&c);

         if(c == '\n') break;

         M[i*n+j].m=c;

         M[i*n+j].z=false;

       }

    }

}



bool BFS(int n,int i) {

    int p0=t;

    bool b=true;

    S[t++]=i;

    while(M[i].m != 'k') {

       if(M[i].z) b=false;

       M[i].z=true;

       if(M[i].m == '.') {

         if((i%n != 0) && BFS(n,i-1)) return true;

         if(((i+1)%n != 0) && BFS(n,i+1)) return true;

         if((i+n < n*n) && BFS(n,i+n)) return true;

         if((i >= n) && BFS(n,i-n)) return true;                           

       }

       else {

         if(M[i].m == 'l') {

           if(i%n != 0) i-=1;

           else b=false;

         }

         else if(M[i].m == 'p') {

           if((i+1)%n != 0) i+=1;

           else b=false;

         }

         else if(M[i].m == 'g') {

           if(i+n < n*n) i+=n;

           else b=false;

         } 

         else if(M[i].m == 'd') {

           if(i >= n) i-=n;

           else b=false;

         }                 

       }

       if(b) S[t++]=i;

       else {

         t=p0;

         return false;

       }

    }

    return true;

}



int main() {

    int z,n;

    for(scanf("%d",&z);z>0;z--){

       scanf("%d",&n);

       load(n);

       t=0;

       BFS(n,0);
	  printf("%d\n",t);

       for(int i=0;i<t;i++) printf("%d %d\n",S[i]%n+1,S[i]/n+1);

    }

    return 0;

}
