W Wielkiej Krainie Liczb (WKL) dzieją się straszne rzeczy. Kwadraty są przekształcane w inwersji, a odcinki przez funkcje nie ciągłe. To wszystko wina pojawienia się w tej krainie gangu - 'Lagrange i spółka z o.o.'. Ta zorganizowana grupa przestępcza jest znana ze zniszczenia Krainy Liczb Pierwszych, poprzez włamanie się do głównego rejestru i przemnożenie każdego mieszkańca przez 2.
Na szczęście WKL jest odporna na ataki mnożenia, lecz niestety to nie powstrzymało Gangu Lagrange'a, który poznał wielka tajemnicę WKL. Otóż jeśli się zada mieszkańcowi pytanie postaci: "Jaka jest maksymalna potęga liczby k dzielącej liczbę sposobów rozkładu talii n różnych kart pomiędzy m ludzi tak, by ustawieni w ustalonej kolejności dostali a1, a2, ..., am kart odpowiednio.", a ten na to nie odpowie to w jednej chwili znika (tak, że nawet Google go nie może znaleźć). Pomóż mieszkańcom ocaleć i napisz program, który będzie liczył za nich ten trudny problem.

<b>Wejście:</b>
Pierwsza linia wejścia zawiera jedna liczbę całkowitą dodatnią <b>o</b> - liczbę przypadków testowych. W każdym przypadku testowym w pierwszej linii znajdują się 3 liczby całkowite dodatnie <b>k, n, m</b> (n <= 10^18; k, m <= 10^6) oznaczające odpowiednio liczbę, której potęga jest szukaną, liczbę kart w talii, liczbę osób. Druga linia każdego przypadku testowego zawiera m liczb naturalnych (<= 10^18) oznaczające kolejno a1, a2, ..., am określone w treści zadania.
<b>Wyjście:</b>
Dla każdego przypadku testowego należy wypisać jedną linię - odpowiedź na niszczące pytanie zawarte w treści zadania. Jeśli nie da się tego określić wypisz -1.

<u>Przykład:</u>
IN:
1
5 11 1
11
OUT:
0