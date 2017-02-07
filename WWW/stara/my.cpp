#include <mysql/mysql.h>
#include <iostream>
#define HOST "localhost"
#define PASS "***password***"
#define USER "root"
#define BAZA "guarana"
using namespace std;

MYSQL *conn; // wskaźnik na obiekt/uchwyt połączenia
MYSQL_RES* res; // dane odebrane
MYSQL_ROW  row; // pojedynczy wiersz

int main(){

conn = mysql_init (NULL); // allokuje, inicializuje i zwraca nowy obiekt(uchwyt) połączenia
if (!mysql_real_connect ( // nawiązuje połaczenie z bazą danych, w razie problemów zwraca błędy (false)
    conn, // wskażnik na obiekt
    HOST, // nazwa hosta do ktorego chcemy się podłączyć (localhost == 127.0.0.1)
    USER, // nazwa uzytkownika
    PASS, // haslo do bazy
    BAZA, // nazwa bazy do ktorej pragniemy nawiazac polaczenie
    0, // port (0 oznacza uzycie domyslnego)
    NULL, // socket (brak)
    0) // flagi (brak)
) {
     cout << "Nie ma takiej bazy, lub podane dane są niepoprawne";
}

else{
       cout << "Połączenie z bazą powiodło się\n";
       mysql_query(conn,"SELECT * FROM users"); // tworzymy zapytanie
       res = mysql_store_result(conn); // pobieramy wynik poprzedniego zapytania
       // wypisywanie wyniku
       if (res) { // Jesli res zawiera jakieś wpisy
            unsigned long num_fields = mysql_num_fields(res); // liczba pol w wierszu
            while ( (row = mysql_fetch_row(res)) ) { /* zwraca tablicę numeryczną, która odpowiada pobranemu wierszowi i
przesuwa do przodu wewnętrzny wskaźnik danych; "przechodzenie po wierszach"*/
                 unsigned long *lengths;
                 lengths = mysql_fetch_lengths(res); // pobiera długości pól wiersza wynikowego

                 // wyswietlanie
                 printf("|");
                 for(unsigned long i = 0; i < num_fields; i++) {

                    printf(" %s |",row[i]); //
                 }
                 printf("\n");
                 // --wyswietlanie
            }//while
            mysql_free_result(res); // zwalnia pamieć zajeta przez res
       }//if          
mysql_close (conn); // zamyka połączenie z bazą, zwalnia pamiec po uchwycie
}
return 0;
}

