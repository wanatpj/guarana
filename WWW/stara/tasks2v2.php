<?php
include("system/core/functions.php");
$mysql=sqlConnect();
$tasks="/home/guarana/WWW/tasks/";
$newtasks="/home/guarana/WWW/v2/tasks/";
$handle = fopen($tasks.".hashes","r");
if(!$handle) {
	printf("syf\n");
	exit();
}
$nrzad=0;
while(!feof($handle)) {
	$line = fgets($handle);
	$line = trim($line);
	if(empty($line)) continue;
	if($nrzad==0) {
		$nrzad++;
		continue;
	}
	$tresc = "";
	$fdtresc = fopen($tasks.$line,"r");
	while(!feof($fdtresc)) $tresc.=fgets($fdtresc);
	fclose($fdtresc);
	$komentarz="";
	$fdcom = fopen($tasks.$line.".com","r");
	while(!feof($fdcom)) $komentarz.=fgets($fdcom);
	fclose($fdcom);
	$fdconf=fopen($tasks.$line.".dt","r");
	$nazwazad = trim(fgets($fdconf));
	$zrodlo = trim(fgets($fdconf));
	$dodal = trim(fgets($fdconf));
	$kijbywyczul = trim(fgets($fdconf));
	$kategoria = trim(fgets($fdconf));
	$czasdodania = trim(fgets($fdconf));
	fclose($fdconf);
	mkdir($newtasks.$nrzad);
	$fdtresc = fopen($newtasks.$nrzad."/".$nrzad.".php","w");
	fwrite($fdtresc,$tresc);
	fclose($fdtresc);
	$fdcom = fopen($newtasks.$nrzad."/".$nrzad.".com","w");
	fwrite($fdcom,$komentarz);
	fclose($fdcom);
	copy($tasks.$nrzad."/".$nrzad.".conf",$newtasks.$nrzad."/".$nrzad.".conf");
	system("cp -r ".$tasks.$nrzad."/in ".$newtasks.$nrzad."/in");
	system("cp -r ".$tasks.$nrzad."/out ".$newtasks.$nrzad."/out");
	$zapytanie = "INSERT INTO tasks (ID,name,date,`from`,author,category,active,memory,time) VALUES "."(";
	$zapytanie.=mysqli_real_escape_string($mysql,$nrzad."").",'";
	$zapytanie.=mysqli_real_escape_string($mysql,$nazwazad)."',";
	$zapytanie.=mysqli_real_escape_string($mysql,$czasdodania).",'";
	$zapytanie.=mysqli_real_escape_string($mysql,$zrodlo)."',";
	$zapytanie.=mysqli_real_escape_string($mysql,idOfUser($dodal)."").",'";
	$slash=0;
	for($i=0;$i<=strlen($kategoria);$i++) {
		if($kategoria[$i]==="1") {
			if($slash==1) $zapytanie.=" ";
			$zapytanie.=($i+2);
			$slash=1;
		}
	}
	$zapytanie.="',1,10000000,1000)";
	mysqli_query($mysql,$zapytanie);
	printf("%s\n", $zapytanie);
	printf("%s\n", $line);
	$nrzad++;
}
exit();
?>
