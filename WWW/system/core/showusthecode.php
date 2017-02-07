<?php
session_start();
$code=$_GET["code"];
if(!is_numeric($code)) {
	print("Nieprawidlowy numer submita\n");
	exit();
}
include("config.php");
$mysql=mysqli_connect($mhost,$muser,$mpass);
if(!$mysql) {
	print("Brak polaczenia z baza\n");
	exit();
}
$temp=mysqli_select_db($mysql,$mbase);
if(!$temp) {
	print("Nie udalo sie wybrac tabeli\n");
	exit();
}
$zapytanie=mysqli_query($mysql,"SELECT `user ID` FROM solutions WHERE ID=".mysqli_real_escape_string($mysql,$code));
if(!$zapytanie) {
    print("Pobranie zgloszenia nie powiodlo sie\n");
	exit();
}
$row=mysqli_fetch_row($zapytanie);
if($row[0]==$_SESSION[SESSION_USER] || $_SESSION[SESSION_PERMISSION]>=ADMIN) {
	$handle=fopen("./solutions/".$code.".cpp","r");
	if(!$handle) {
			print("Nie ma takiego submitu\n");
			exit();
	}
	while(!feof($handle)) {
		$line=fgets($handle);
		print($line."<br>");
	}
}
mysqli_close($mysql);
?>
