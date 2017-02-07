#include <cstdio>
#include<algorithm>
using namespace std;
int n,z;
unsigned long *turysci;
unsigned long zostalo; //ile osob zostalo nieprzeprowadzonych
unsigned long lastone; //pozycja ostatniego ktory nie przeszedl
unsigned long czas;

void przeprowadz_dwoma(void); /*przeprowadza przy uzyciu dwoch najszybszych*/
void przeprowadz_jednym(void); /*przeprowadza przy uzyciu tylko najszybszego*/

int main()
{scanf("%ld",&z);
while(z--){
 scanf("%ld",&n);
 turysci = new unsigned long[n];
 czas = 0;
 zostalo = n;
 lastone=(n-1);
 unsigned long *ptr = turysci;
 for(unsigned long i=0; i<n ;i++,ptr++) scanf("%ld",ptr);
 sort(turysci,turysci+n);
 przeprowadz_dwoma();
 printf("%ld\n",czas);
 delete[] turysci;
}
 return 0;
}

void przeprowadz_dwoma(void)
{
 if(n==1) {czas = turysci[0];  return;}

 czas += turysci[1]; /*przeprowadzam dwoch najszybszych (dodaj czas gorszego czyli drugiego)*/
 zostalo -= 2;

 unsigned long tur0 = turysci[0]; //czas najszybszego
 unsigned long tur1 = turysci[1]; //czas drugiego najszybszego
 while(zostalo>1) //dopuki zostalo co najmniej dwoch
  {
   if((tur0+turysci[lastone]+2*tur1) > (2*tur0+turysci[lastone]+turysci[lastone-1]))
    { /*jak korzystniej przeprowadzac przy uzyciu jednego to przeprowadz z najszybszym*/
     break;
    }
   czas += tur0; //wraca najszybszy
   czas += turysci[lastone]; //idzie dwoch najgorszych co zostali
   czas += tur1; //waraca drugi najszybszy po najszybszego
   czas += tur1; //idzie dwoch najszybszych
   zostalo -= 2;
   lastone-=2;
  }
 przeprowadz_jednym(); //jak zostal ktos to przeprowadz jednym
}

void przeprowadz_jednym(void)
{
 czas += zostalo*turysci[0]; /*tyle razy musi wrocic sie najszybszy po tych co zostali*/
 while(zostalo>0)
  { /*dodaje czasy kazdego kto zostal bo idzie z najszybszym na druga strone*/
   czas += turysci[lastone--];
   zostalo--;
  }
}
