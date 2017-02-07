#include <iostream>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

rlimit rlim;
struct rusage usage;
int pid, err;

int main()
{
    pid=fork();
    if(pid==0)
    {
	rlim.rlim_cur=1;
	rlim.rlim_max=2;
	err=setrlimit(RLIMIT_CPU, &rlim);
	execlp("./program",NULL); 
    }
    else
    {
	wait(0);
	err=getrusage(RUSAGE_CHILDREN, &usage); 
	std::cout << err << "\n";
	double usertime = (double)usage.ru_utime.tv_sec + ((double)usage.ru_utime.tv_usec / 1000000.0);
	double systime = (double)usage.ru_utime.tv_sec + ((double)usage.ru_utime.tv_usec / 1000000.0);
	std::cout << "Czas: " << usage.ru_stime.tv_usec << " mikrosekund.\n";
	std::cout << "Czas: " << usage.ru_stime.tv_sec << " sekund.\n";
	std::cout << systime+usertime << "\n";
    }
    return 0;
}	     
