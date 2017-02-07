#include <iostream>
using namespace std;
int main(){
ios_base::sync_with_stdio(0);
int p=2,d,w=1;
cin>>d;
while(d>0){
if(d%2==1)w*=p;
d/=2;
p*=p;
}
w-=1;
cout<<w<<endl;
return 0;
}
