   1. #include <iostream>
   2. using namespace std;
   3. int main(){
   4. ios_base::sync_with_stdio(0);
   5. int p=2,d,w=1;
   6. cin>>d;
   7. while(d>0){
   8. if(d%2==1)w*=p;
   9. d/=2;
  10. p*=p;
  11. }
  12. w-=1;
  13. cout<<w<<endl;
  14. //system("pause");
  15. return 0;
  16. } 

