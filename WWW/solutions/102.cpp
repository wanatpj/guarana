#include<cstdio>
#include<iostream>
using namespace std;
int x=0;
long long pro[2]={0};
int p,q,k;
unsigned long long sok;

void krzesla(int a, int b, int c){
 
 if(a%b==0) x=1;
 if(a%c==0) x=0; 
  
  
}

int nwd(long long m, long long n)
{
  if(n==0) return m;
  return nwd(n, m%n);
}

int main(){
  int z; scanf("%d",&z);
  while(z--){

  x=0;
  pro[0]=0;
  pro[1]=0;
   scanf("%d %d", &p, &q);
   sok=p*q;
     
  for(int i=0;sok>0;i++){
    krzesla(i,p,q);
     if(x==0)
     { 
      pro[0]++;    
      sok--;
   } 
    else
    {  
      pro[1]++;
      sok--;  
    }
 
  } 
  k=nwd(pro[0], pro[1]);
  pro[0]/=k;
  pro[1]/=k;
  cout << pro[0] << " " << pro[1] << endl;
}
system("PAUSE");
 return 0 ; 
}
