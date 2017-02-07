<?php
echo '<center><font size=4><b>Informacje</b></font></center>';


/*echo '<a name="TYP"></a>';
echo '<ul><font size=3><li><b>Typy zadań:</font><font size=2></b><br>';
$rf = file('./tasks/.kot');
$n = count($rf);
for($i=0;$i<$n;$i+=3)
print '<b>'.$rf[$i].' ('.trim($rf[$i+2]).')</b> - '.$rf[$i+1].'<br/>'."\n";*/
echo '</li><br><br><font size=3><li><b>Środowisko testowania:</font><font size=3></b>';
echo '	<br>Przesyłane źródła problemów powinny być napisane w <b>C++</b>.
	<br>Do kompilacji system używa: <b>GNU GCC 4.3.2</b>. 
	<br>Każde rozwiązanie musi być pojedyńczym plikiem źródłowym. Wszelkie operacje na plikach zewnętrznych są zabronione. W szczególności nie można odczytywać, ani tworzyć plików tymczasowych. Program musi być tak napisany, aby czytał dane ze standardowego wejścia, a zapisywał na standardowe wyjście. Na każde zadanie przewidziane są limity czasowe oraz limity na użytą pamięć. Maksymalny rozmiar wysłanego kodu źródłowego to 100kB.';
echo '</li><br><br><br></font><font size=3><li><b>Możliwe odpowiedzi serwera</b></font><font size=3><br>
Po wysłaniu rozwiązania można sprawdzić jego status. 

<ul><li>QUE - Kolejka - program został odebrany i czeka w kolejce,
</li><li>COM - Błąd kompilacji - m.in. przekroczony czas kompilacji, zbędne nagłówki,
</li><li>SYS - Niedozwolona operacja - np. system("rm *"),
</li><li>RTE - Błąd wykonania - m.in. kopanie po nie swojej pamięci,
</li><li>TLE - Limit czasu przekroczony - przekroczony limit czasu nałożony na zadanie,
</li><li>MEM - Limit pamięci przekroczony - przekroczony limit pamięci,
</li><li>WA - Zła odpowiedź - program nie przeszedł wszystkich testów wejściowych,
</li><li>AC - Program zaakceptowany - program poprawnie przeszedł przez wszystkie testy,
</li></ul></font>

<br><br>
</li><font size=3><li><b>Współpraca</b></font><font size=3>
<br>
Zachęcamy do współpracy z nami, przy tworzeniu tego serwisu.
<br>Mile widziane pomysły, sugestie, treści nowych zadań, artykuły i linki do stron algorytmicznych.

<br><br><br>
</li><font size=3><li><b>Czym jest guarana?</b></font><font size=3>
<br>
Słynie z największych dotąd poznanych wśród roślin zdolności syntezy kofeiny, której zawiera kilkakrotnie więcej (4 razy) niż ziarna kawowca. Właściwości rośliny znane są od dawna ludom tubylczym Amazonii, które zażywają ją w różnych postaciach dla podniesienia sprawności fizycznej i psychicznej w stanach wzmożonego wysiłku. Dla świata zachodniego gatunek odkryty został na przełomie XVII i XVIII wieku i nazwany na cześć niemieckiego lekarza Christiana Franza Paullini. Indianie, zamieszkujący amazońskie lasy deszczowe, od tysięcy lat czerpią korzyści zdrowotne z guarany, nazywanej przez nich "darem od Boga", czy też "eliksirem młodości". W Europie uznano te walory guarany a niektórzy sprzedawcy reklamowali ją nawet jako afrodyzjak. Znane są również doniesienia o wykorzystywaniu w dorzeczu Amazonki guarany jako środka płatniczego używanego w handlu.
</li></ul></font>';
?>					 
