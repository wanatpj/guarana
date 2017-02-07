#include <iostream>

main()
{
 int pid=fork();
if(pid==0)
{
 printf("0");
}
else
{
printf("ble ble");
}
 return 0;
}