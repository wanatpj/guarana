Masz dany multigraf <i>G=(V,E)</i>. Znajdź w nim <u>cykl Eulera</u> (tj. cykl przechodzący przez każdą krawędź dokładnie raz), bądź stwierdź, że nie istnieje.<br>
<br>
<b>Wejście:</b><br>
W pierwszej linii wejścia znajdują się 2 liczby całkowite |V| <= 100000 i |E| - odpowiednio: ilość wierzchołków grafu G i ilość jego krawędzi. Kolejne E linii wejścia zawiera po dwie liczby całkowite a, b z przedziału <1,|V|> oddzielone spacją. Każda taka para liczb (a,b) opisuje jedną krawędź nieskierowaną G.<br>
<b>Wyjście:</b><br>
W jedynej linii wyjścia należy wypisać: -1, jeżeli nie istnieje Cykl Eulera w G, a w przeciwnym wypadku: ciąg liczb oznaczający <u>kolejne wierzchołki</u> przy przechodzeniu G Cyklem Eulera. Jeżeli istnieje więcej niż jedno rozwiązanie należy wypisać to, które w <u>porządku leksykograficznym</u> jest <u>najmniejsze</u>.<br>
<br>
<u>Przykład</u><br>
<b>Wejście:</b><br>
6 7<br>
1 2<br>
2 3<br>
3 4<br>
4 1<br>
3 5<br>
6 5<br>
3 6<br>
<b>Wyjście:</b><br>
1 2 3 5 6 3 4 1<br>
<br>
<u>Uwaga</u>: Należy posługiwać się standardowym wejściem i standardowym wyjściem.