<?php
session_start();
$mysql=sqlConnect();
$zapytanie=mysqli_query($mysql,"SELECT id,login FROM users ORDER BY id ASC");
if(!$zapytanie) {
    print("Pobranie uzytkownikow nie powiodlo sie\n");
    exit();
}
while(($row=mysqli_fetch_row($zapytanie))) $uzytkownicy[$row[0]]=$row[1];
$zapytanie=mysqli_query($mysql,"SELECT ID,name FROM tasks ORDER BY ID ASC");
if(!$zapytanie) {
    print("Pobranie zadan nie powiodlo sie\n");
	exit();
}
while(($row=mysqli_fetch_row($zapytanie))) $zadania[$row[0]]=$row[1];
$zapytanie=mysqli_query($mysql,"SELECT * FROM solutions ORDER BY ID DESC LIMIT 0,10");
if(!$zapytanie) {
	print("Nie udalo sie pobrac zgloszen\n");
	exit();
}

print("<table><tr>\n
		<td>ID</td>\n");
if($_SESSION[SESSION_PERMISSION]>=ADMIN) print("<td>Kod</td>\n");
print("<td>Data</td>\n
		<td>Użytkownik</td>\n
		<td>Zadanie</td>\n
		<td>Wynik</td>\n
		<td>Stan</td>\n
		<td>Czas[ms]</td>\n
		<td>Rozmiar[B]</td></tr>\n");
while(($row=mysqli_fetch_row($zapytanie))) {
	print("<tr><td>".$row[0]."</td>");
	if($_SESSION[SESSION_PERMISSION]>=ADMIN) print("<td><a href=\"index.php?whereAmI=showusthecode&code=".$row[0]."\">Kod</a></td>\n");
	print("<td>".date("H:i:s, j,m,Y",$row[3])."</td>");
	print("<td>".$uzytkownicy[$row[1]]."</td>");
	print("<td>".$zadania[$row[2]]."</td>");
	print("<td>".$row[5]."</td>");
	print("<td>Stan</td>");
	print("<td>".$row[4]."</td>");
	print("<td>Rozmiar</td></tr>");
}
mysqli_close($mysql);
?>
