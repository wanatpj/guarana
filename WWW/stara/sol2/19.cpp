#include <iostream>

main()
{
  unsigned long long a,b;
  scanf("%llu",&a);
  b=(1<<a)-1;
  printf("%llu\n",b);
  return 0;
}
