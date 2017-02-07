#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <sys/ptrace.h> 
#include <fcntl.h>
#include <unistd.h>
//#include <iomanip.h>   // format manipulation
#define MAX 100
using namespace std;

int file_exists(string filename)
{

    FILE * fp;
    fp = fopen(&filename[0], "r");
    if(fp != NULL) return 1;
    return 0;		       
}

main()
{
    int i, id, idz, tim, mem, pid, sygnal, new_in, new_out, new_err;
    fstream plik, plik2;
    rlimit limit;
    string dane[MAX], tmp, ids, idsz, in, out, wyk;
    while(true)
    {    
	sleep(1);	
	plik.open("queue.dt",ios::in);
	if(plik.good()==true)
	{
	    plik << noskipws;
	    i=0;
	    while(getline(plik,dane[i]))
	    {
		i++;
	    }
	    plik.close();
	    if(i>0)
	    { 
		do
		{
		    plik.open("queue.dt",ios::out);
		}
		while(plik.good()!=true);
		for(int j=1;j<i;j++)
		{
		    plik << dane[j] << endl;
		}
		plik.close();
	    
		istringstream strin(dane[0]);
		strin >> id >> idz;
		istringstream strin2(dane[0]);
		strin2 >> ids >> idsz;
		
		cout << "Wykonuje: " << id << " " << idz << endl;
		wyk="g++ -O2 --static ./solutions/"+idsz+".cpp -lm -o"+idsz;
		system(&wyk[0]);
		if(!file_exists(idsz)) 
		{  
		    FILE *plik2;
		    wyk="./solutions/"+idsz+".re";
		    plik2=fopen(&wyk[0], "w");
		    wyk="2 0\n";
		    fputs(&wyk[0],plik2); 
		    fclose(plik2);
		    continue;
		}
		tmp="./tasks/"+ids+"/"+ids+".conf";
		plik.open(&tmp[0],ios::in);
		i=0;
		while(getline(plik,dane[i]))
		{
		    i++;
		}
		plik.close();
		for(int j=1;j<i;j++)
		{
		    stringstream numer;
		    numer << j-1;
		    istringstream strin3(dane[j]);
		    strin3 >> in >> out >> tim >> mem;
		    cout << in << " " << out << " " << tim << " " << mem << endl;
		    /*int setrlimit(int resource, const struct rlimit *rlim);  
		    struct rlimit {
			rlim_t rlim_cur;   /* Soft limit 
			rlim_t rlim_max;   /* Hard limit (ceiling for rlim_cur)
		    };
		    */
		    do
		    {
			pid=fork();
		    }while(pid==-1);
		    if(pid==0)
		    {
			limit.rlim_cur=tim/1000;
			limit.rlim_max=2*tim/1000;
			if(setrlimit(RLIMIT_CPU, &limit)==0); //cout << "Limit na czas: ok" << endl;
			//else cout << "Limit na czas: error!" << endl;
			limit.rlim_cur=mem;
			limit.rlim_max=2*mem;
			if(setrlimit(RLIMIT_DATA, &limit)==0); //cout << "Limit na pamiec: ok" << endl;
			//else cout << "Limit na pamiec: error!" << endl;
			new_in = open(&in[0], O_RDONLY);
			wyk=numer.str()+".out";
			new_out = open(&wyk[0], O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
			new_err = open("err.txt", O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
			// Redirect standard input
			if (new_in >= 0) 
			{
			    close(STDIN_FILENO);
			    dup2(new_in, STDIN_FILENO);
			}
			// Redirect standard output
			if (new_out >= 0) 
			{
			    close(STDOUT_FILENO);
			    dup2(new_out, STDOUT_FILENO);
			}
			// Redirect standard error
			if (new_err >= 0) 
			{
			    close(STDERR_FILENO);
			    dup2(new_err, STDERR_FILENO);
			}
			// Execute the command
			wyk="./"+idsz;
			ptrace(PTRACE_TRACEME,0,0,0);
			execv(&wyk[0], NULL);
			exit(0);
		    }
		    else
		    {
			int status;
			wait(&status);
			ptrace(PTRACE_CONT, pid, NULL, NULL);
			while(true)
			{
			    wait(&status);
			    if(WIFSTOPPED(status))
			    {
				sygnal=WSTOPSIG(status);
				//cout << "Signal: " << sygnal << endl;
			    }
			    if(sygnal==5) ptrace(PTRACE_CONT, pid, NULL, NULL);
			    else { ptrace(PTRACE_KILL, pid, NULL, NULL); break; }
			    sygnal=0;
			}
			//sprawdzenie uzytych zasobow
			struct rusage usage;
			if(getrusage(RUSAGE_CHILDREN, &usage)==0)
			{
			    cout << "Time: " << usage.ru_stime.tv_usec << endl;
			}
			wyk=numer.str()+".out";
			if(sygnal==11)
			{
			    cout << "MEM" << endl;
			    stringstream out;
			    out << usage.ru_stime.tv_usec/1000;
			    wyk="./solutions/"+idsz+".re";
			    FILE *plik2;
			    if(j==1) plik2 = fopen(&wyk[0], "w");
			    else plik2 = fopen(&wyk[0], "a+");
			    wyk="3 "+out.str()+"\n";
			    fputs(&wyk[0],plik2);
			    fclose(plik2);
			}
			else if(sygnal==24)
			{
			    cout << "TLE" << endl;
			    stringstream out;
			    out << usage.ru_stime.tv_usec/1000;
			    wyk="./solutions/"+idsz+".re";
			    FILE *plik2;
			    if(j==1) plik2 = fopen(&wyk[0], "w");
			    else plik2 = fopen(&wyk[0], "a+");
			    wyk="4 "+out.str()+"\n";
			    fputs(&wyk[0],plik2);
			    fclose(plik2);
			}
			else
			{
			    wyk="diff -w -b -B -p "+numer.str()+".out "+out+" > dif";
			    system(&wyk[0]);
			    wyk="./solutions/"+idsz+".re";
			    FILE *plik2;
			    if(j==1) plik2 = fopen(&wyk[0], "w");
			    else plik2 = fopen(&wyk[0], "a+");
			    do
			    {
				plik.open("dif",ios::in);
			    }
			    while(plik.good()==false);
			    if(getline(plik,tmp)) 
			    { 
				cout << "Wrong Answer" << endl;
				stringstream out;
				out << usage.ru_stime.tv_usec/1000;
				wyk="0 "+out.str()+"\n";
				fputs(&wyk[0],plik2); 
			    }
			    else
			    { 
			        cout << "OK" << endl;
				stringstream out;
				out << usage.ru_stime.tv_usec/1000;
				wyk="1 "+out.str()+"\n";
				fputs(&wyk[0],plik2); 
			    }
			    plik.close();
			    fclose(plik2);
			}
			if(file_exists("dif"))
			{
			    system("rm dif");
			}
			wyk=numer.str()+".out";
			if(file_exists(wyk))
			{
			    wyk="rm "+numer.str()+".out";
			    system(&wyk[0]);
			}
		    }
		}
		remove(&idsz[0]);
	    }
	}
    }
    return 0;
}	
