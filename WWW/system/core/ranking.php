<?php
session_start();
include_once("config.php");
$mysql=mysqli_connect($mhost,$muser,$mpass);
if(!$mysql) {
	print("Brak polaczenia z baza\n");
	exit();
}
$temp=mysqli_select_db($mysql,$mbase);
if(!$temp) {
	print("Nie udalo sie wybrac bazy\n");
	exit();
}
$_POST[ZADANIA]="1 18 20";
$zadania = explode(" ", $_POST[ZADANIA]);
$query = "SELECT `user ID`,`task ID`,MAX(result) AS wynik FROM solutions WHERE `task ID` IN (";
$i=0;
foreach($zadania as $zad) {
	if($i>0)
		$query=$query.",";
	$query=$query.$zad;
	$i++;
}
$query = $query.") GROUP BY `user ID`,`task ID` ORDER BY `user ID` ASC";
$kolejnosc = "SELECT `user ID`,SUM(wynik) AS suma FROM ($query) AS query GROUP BY `user ID` ORDER BY suma DESC";
$wyniki = "SELECT `task ID`,wynik FROM ($query) AS query WHERE `user ID`=";
$zapytanie=mysqli_query($mysql,$kolejnosc);
if(!$zapytanie) {
    print("Pobranie zgloszen nie powiodlo sie\n");
	exit();
}
for($i=0;($row=mysqli_fetch_row($zapytanie));$i++) $rank[$i]=$row;
print("<table width=\"100%\"><tr>\n
		<td>User</td>\n");
foreach($zadania as $nr) {
	print("<td>$nr</td>\n");
}
print("<td>Suma</td></tr>\n");

foreach($rank as $miejsce) {
	print("<tr><td>".$miejsce[0]."</td>\n");
	unset($res);
	$zapytanie=mysqli_query($mysql,$wyniki.$miejsce[0]);
	if(!$zapytanie) {
    print("Pobranie uzytkownikow nie powiodlo sie\n");
	exit();
	}
	while($row=mysqli_fetch_row($zapytanie)) {$res[$row[0]]=$row[1];}
	foreach($zadania as $zad)
		print("<td>".$res[$zad]."</td>\n");
	print("<td>".$miejsce[1]."</td></tr>");
}
print("</table>");
mysqli_close($mysql);
?>
