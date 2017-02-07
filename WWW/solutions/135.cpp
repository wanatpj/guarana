#include <iostream>
using namespace std;

long long p, q, k;
long long a, b;

long long NWD(long long a, long long b) 
{
if(b)
return NWD(b, a%b);
return a;
} 


main()
{
long long z;
cin>>z;
for(long long i=0; i<z; i++)
{
    cin>>p>>q;
    k=NWD(p, q);
    p/=k;
    q/=k;
    if(p==q) 
    cout<<"1 0"<<endl;
    else if(p>q)
    {
       if(p%q==0) 
       cout<<"1 0"<<endl;
       else
       {
          b=(q*(q-1))/2;    
          a=p*q-b;
          k=NWD(a, b);
          cout<<a/k<<' '<<b/k<<endl;
       }
    }
    else if(p<q)
    {
       if(q%p==0)
       {
          a=p;
          b=q-p;
          k=NWD(a, b);
          cout<<a/k<<' '<<b/k<<endl;
       }    
       else
       {   
          a=((1+p)*p)/2;
          b=p*q-a;
          k=NWD(a, b);
          cout<<a/k<<' '<<b/k<<endl;             
       }
    }
      
}
}
