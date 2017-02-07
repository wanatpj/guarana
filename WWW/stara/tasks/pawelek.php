<?php
    if(!isset($_POST['wynik']))
    {
    $k=rand()%100+1;
    print '<b>Pawełek:</b> <i>Pomnóż numer dnia twoich urodzin przez 20. Następnie dodaj '.$k.'. Sumę tą pomnóż przez 5 a następnie dodaj liczbę oznaczającą miesiąc twoich urodzin. Wynik pomnóż przez 20 i po raz kolejny dodaj '.$k.'. pomnóż wszystko przez 5, dodaj do tego dwie ostatnie cyfry roku twoich urodzin. <br>Proszę podaj mi wynik!</i>';
    print '<br><br><form method="POST" action=http://users.v-lo.krakow.pl/~guarana/index.php?whereAmI=show&co=pawelek><b>'.$_SESSION[SESSION_USER].':</b>
	   <input type="text" name="wynik" value="tutaj wpisz wynik">
	   <input type="hidden" name="liczba" value="'.$k.'">
	   <input type="submit" value="Powiedz"></form>';
    }
    else
    {
    if(ereg("^[0-9]{1,20}$",trim($_POST['wynik'])))
    {
    print '<b>Pawełek:</b> <i>Pomnóż numer dnia twoich urodzin przez 20. Następnie dodaj '.$_POST['liczba'].'. Sumę tą pomnóż przez 5 a następnie dodaj liczbę oznaczającą miesiąc twoich urodzin. Wynik pomnóż przez 20 i po raz kolejny dodaj '.$_POST['liczba'].'. pomnóż wszystko przez 5, dodaj do tego dwie ostatnie cyfry roku twoich urodzin. <br>Proszę podaj mi wynik!</i>';
    print '<br><br><b>'.$_SESSION[SESSION_USER].': </b><i>'.$_POST['wynik'].'</i>';
    print '<br><br>(Pawełek dopisał do swojej długiej listy: <i>'.$_SESSION[SESSION_USER].' '.$_POST['liczba'].' '.$_POST['wynik'].'</i>)';
    }
    else print '<b>Pawełek: </b><i>Naucz się liczyć !</i>';
    print '<br><br><a href=index.php?whereAmI=tasks&Rdef=16>Wróć do zadania</a>';
    }
?>