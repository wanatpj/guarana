#include <mysql/mysql.h>
#include <sys/user.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <unistd.h>
#include <sys/ptrace.h> 
#include <signal.h>
#include <sys/times.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100
#define HOST "mysql.v-lo.krakow.pl"
#define USER "guarana"
#define PASS "***db-password***"
#define BASE "guarana"
using namespace std;

long long czas, aktczas;
struct rusage usage;
struct user_regs_struct uregs;

int sys[300], TIME, RES;
bool acc, zlo;
int i, id, idz, tim, tim2, mem, pid, sygnal, status, x, new_in, new_out, new_err, ilosc;
fstream plik, file;
ofstream plik2;
rlimit limit;
string dane[MAX], ree[MAX], tmp, ids, idsz, in, out, wyk, login, zapytanie, helpik;
MYSQL *conn; // wskaźnik na obiekt/uchwyt połączenia
MYSQL_RES* res; // dane odebrane
MYSQL_ROW  row; // pojedynczy wiersz

bool file_exists(string filename) {
    bool flag=false;
    fstream fin;
    fin.open(&filename[0], ios::in);
    if(fin.is_open()) flag=true;
    fin.close();
    return flag;
}

void check_includes(string filename) {
	string content, run, tmp;
	run="cpp -MM < ./solutions/"+filename+".cpp > compile.out";
	system(&run[0]);
	plik.open("compile.out",ios::in);
	while(plik >> tmp) content+=tmp;
	plik.close();
	remove("compile.out");
	if(content!="-:") { 
		remove("pro");
		printf("Includuje cos w stylu: #include \"/home/ble/ble.cpp\".\n");
	}
}

string itoa(int a) {
    string res;
    ostringstream ss;
    ss << a;
    res = ss.str();
    return res;
}

int main() {
    while(true) {
	sleep(1);
	conn=mysql_init(NULL); // allokuje, inicializuje i zwraca nowy obiekt(uchwyt) połączenia
	if (!mysql_real_connect(conn,HOST,USER,PASS,BASE,0,NULL,0)) {
	    cout << "Nie udało się połączyć z bazą.\n";
	    sleep(10);
	}
	else {
	    //cout << "Połączenie z bazą powiodło się\n";
	    mysql_query(conn,"SELECT * FROM queue ORDER BY submit ASC LIMIT 1"); // tworzymy zapytanie
	    res=mysql_store_result(conn); // pobieramy wynik poprzedniego zapytania
	    if(res){
		if(row=mysql_fetch_row(res)) { /* zwraca tablicę numeryczną, która odpowiada pobranemu wierszowi i
		    przesuwa do przodu wewnętrzny wskaźnik danych; "przechodzenie po wierszach"*/
		    mysql_query(conn,"DELETE FROM queue LIMIT 1");
		    RES=0;
		    TIME=0;
		    istringstream strin(row[0]);
		    strin >> idz;
		    istringstream strin2(row[1]);
		    strin2 >> id;
		    istringstream strins(row[0]);
		    strins >> idsz;
		    istringstream strins2(row[1]);
		    strins2 >> ids;
		    limit.rlim_cur=10000000; 
		    limit.rlim_max=15000000;
		    setrlimit(RLIMIT_FSIZE, &limit); // Limit na rozmiar binarki (bajty)
		    limit.rlim_cur=10;
		    limit.rlim_max=15;
		    setrlimit(RLIMIT_CPU, &limit); // Limit na czas CPU kompilacji (sekundy)
		    acc=1;
		    cout << "\nWykonuje: " << id << " " << idz << endl;
		    wyk="g++ -H -w -O2 --static ./solutions/"+idsz+".cpp -lm -o pro >& kom";
		    system(&wyk[0]);
		    remove("kom");
		    check_includes(idsz);
		    limit.rlim_cur=limit.rlim_max=RLIM_INFINITY;
		    setrlimit(RLIMIT_FSIZE, &limit);
		    limit.rlim_cur=limit.rlim_max=RLIM_INFINITY;
		    setrlimit(RLIMIT_CPU, &limit);
		    if(!file_exists("pro")) {  
			wyk="./solutions/"+idsz+".re";
			do {
			    plik.open(&wyk[0],ios::out);
			} while(!plik.is_open());
			plik << "2 0\n"; 
			plik.close();
		    }
		    else{
		    tmp="./tasks/"+ids+"/"+ids+".conf";
		    plik.open(&tmp[0],ios::in);
		    i=0;
		    while(getline(plik,dane[i])) i++;
		    plik.close();
		    istringstream strin3(dane[0]);
		    strin3 >> ilosc;
		    for(int j=0;j<=ilosc;j++) {
			if(j==0) x=j+1;
			else x=j;
			stringstream numer;
			numer << x-1;
			istringstream strin4(dane[x]);
			strin4 >> in >> out >> tim >> mem;
			if(tim<1000) { 
			    tim2=tim;
			    tim=1000;
			}
			else tim2=tim;
			if(j!=0) cout << in << " " << out << " " << tim2 << " " << mem << endl;
			getrusage(RUSAGE_CHILDREN, &usage);
			czas=usage.ru_stime.tv_usec+usage.ru_utime.tv_usec+1000000*(usage.ru_stime.tv_sec+usage.ru_utime.tv_sec);
			do {
			    pid=fork();
			} while(pid==-1);
			if(pid==0) {
			    limit.rlim_cur=30000000; 
			    limit.rlim_max=40000000;
			    setrlimit(RLIMIT_FSIZE, &limit); // Limit na rozmiar pliku (bajty)
			    limit.rlim_cur=tim/1000;
			    limit.rlim_max=2*(tim/1000);
			    setrlimit(RLIMIT_CPU, &limit); // Limit na czas CPU (sekundy)
			    limit.rlim_cur=mem;
			    limit.rlim_max=2*mem;
			    setrlimit(RLIMIT_DATA, &limit); // Limit na pamięć (bajty)
			    new_in=open(&in[0], O_RDONLY);
			    new_out=open("out", O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
			    // Redirect standard input
			    if (new_in >= 0) {
				close(STDIN_FILENO);
				dup2(new_in, STDIN_FILENO);
			    }
			    // Redirect standard output
			    if (new_out >= 0) {
				close(STDOUT_FILENO);
				dup2(new_out, STDOUT_FILENO);
			    }
			    // Execute the command 
			    ptrace(PTRACE_TRACEME,0,0,0);
			    execv("./pro", NULL);
			}
			else {
			    for(int cal=0;cal<300;cal++) sys[cal]=0;
			    sygnal=0; zlo=0;
			    wait(&status);
			    ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
			    while(true) {
				wait(&status);
				if(WIFSTOPPED(status)) sygnal=WSTOPSIG(status);
				if(sygnal==5) { 
				    ptrace(PTRACE_GETREGS, pid, 0, &uregs);
				    switch(uregs.orig_eax) {
					case 3: { sys[3]++; break; }
					case 125: { sys[125]++; break; }
					case 11: { sys[11]++; break; }
					case 122: { sys[122]++; break; }
					case 4: { sys[4]++; break; }
					//case 5: { sys[5]++; break; }
					//case 6: { sys[6]++; break; }
					case 33: { sys[33]++; break; }
					case 45: { sys[45]++; break; }
					case 91: { sys[91]++; break; }
					case 192: { sys[192]++; break; }
					case 197: { sys[197]++; break; }
					//case 240: { sys[240]++; break; } //nie wiem co to id: 790
					case 243: { sys[243]++; break; }
					case 252: { sys[252]++; break; }
					default: { zlo=1; break; }
				    }
				    if(zlo==1) {
					printf("Syscall: %d\n",uregs.orig_eax);
					sygnal=777;
					uregs.orig_eax = 1;
					ptrace(PTRACE_SETREGS, pid, 0, &uregs);
					ptrace(PTRACE_CONT, pid, 0, 0);
					//ptrace(PTRACE_KILL, pid, NULL, NULL);
					break;
				    }
				}
				else { 
				    ptrace(PTRACE_KILL, pid, NULL, NULL); 
				    break;
				}
				sygnal=0;
				ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
			    }
			    //limit.rlim_cur=limit.rlim_max=RLIM_INFINITY;
			    //setrlimit(RLIMIT_NOFILE, &limit); // Limit na otwarte pliki 
			    //for(int cal=0;cal<300;cal++) if(sys[cal]!=0) printf("%d. %d\n",cal,sys[cal]);
			    cout << "Signal: " << sygnal;
			
			    getrusage(RUSAGE_CHILDREN, &usage);
			    aktczas=(usage.ru_stime.tv_usec+usage.ru_utime.tv_usec+1000000*(usage.ru_stime.tv_sec+usage.ru_utime.tv_sec)-czas)/1000;
			    cout << " | Time: " << aktczas << " | ";
			    TIME+=aktczas;
			    if(aktczas>tim2) sygnal=24;
			
			    if(sygnal!=0&&j!=0) acc=0;
			    if(sygnal==11) {
				cout << "MEM" << endl;
				wyk="3 ";
			    }
			    else if(sygnal==24) {
				cout << "TLE" << endl;
				aktczas=tim2+1;
				wyk="4 ";
			    }
			    else if(sygnal!=5&&sygnal!=0) {
				cout << "SYS" << endl;
				wyk="6 ";
			    }
			    else {
				wyk="diff -w -b -B -p out "+out+" > dif";
				system(&wyk[0]);
				do {
				    plik.open("dif",ios::in);
				}
				while(!plik.is_open());
				if(getline(plik,tmp)) { 
				    cout << "WA" << endl;
				    wyk="0 ";
				    acc=0;
				}
				else { 
				    if(j!=0) RES++;
			    	    cout << "OK" << endl;
				    wyk="1 ";
				}
				remove("dif");
				plik.close();
			    }
			    stringstream wyj;
			    wyj << aktczas;
			    wyk+=(wyj.str()+"\n");
			    ree[j]=wyk;
			    remove("out");
			    
 			}
		    }
		    
		    tmp="./solutions/"+idsz+".re";
		    plik2.open(&tmp[0]);
		    for(int j=1;j<=ilosc;j++) plik2 << ree[j];
		    plik2.close();
		    remove(&idsz[0]);
		    remove("pro");
		    }
		    helpik=itoa(TIME);
		    zapytanie="UPDATE `solutions` SET `time`="+helpik;
		    zapytanie+=" WHERE `ID`=";
		    zapytanie+=idsz;
		    //cout << zapytanie << endl;
		    mysql_query(conn,&zapytanie[0]);
		    if(RES!=0) RES=(int)((double)RES/(double)ilosc*(double)100);
		    helpik=itoa(RES);
		    zapytanie="UPDATE `solutions` SET `result`="+helpik;
		    zapytanie+=" WHERE `ID`=";
		    zapytanie+=idsz;
		    //cout << zapytanie << endl;
		    mysql_query(conn,&zapytanie[0]);		
		}		    
		mysql_free_result(res); // zwalnia pamieć zajeta przez res
	    }
	    
	    //cout << "Zamykam połączenie.\n";         
	    mysql_close (conn); // zamyka połączenie z bazą, zwalnia pamiec po uchwycie
	}
    }
    return 0;
}

