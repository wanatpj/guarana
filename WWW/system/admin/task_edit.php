<?php
    $mysql=sqlConnect();
    if(isset($_GET['akt'])) {
	$zapytanie="SELECT `active` FROM `tasks` WHERE `ID`=$_GET[akt]";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik){
	    print 'Nie może wykonać zapytania do bazy danych.';
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	$wiersz[0]++;
	$wiersz[0]%=3;
	$zapytanie="UPDATE `tasks` SET `active`=$wiersz[0] WHERE `ID`=$_GET[akt]";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik){
	    print 'Nie może wykonać zapytania do bazy danych.';
	    exit;
	}
    }
    $zapytanie="SELECT * FROM `tasks`";
    $wynik=mysqli_query($mysql,$zapytanie);
    if(!$wynik){
	print 'Nie może wykonać zapytania do bazy danych.';
	exit;
    }
    echo "<center><table border=1><tr>
    <td align=center>ID</td>
    <td align=center>Nazwa</td>
    <td align=center>Aktywne</td>
    <td align=center>Edycja treści</td>
    <td align=center>Edycja komentarzy</td>
    <td align=center>Edycja danych</td>
    <td align=center>Edycja conf</td></tr>";
    while($wiersz=mysqli_fetch_row($wynik)) {
	echo "	<tr><td aling=center>".$wiersz[0]."</td><td>".$wiersz[1]."</td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&akt=".$wiersz[0].">".$wiersz[6]."</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$wiersz[0].".php>click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$wiersz[0].".com>click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$wiersz[0].">click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$wiersz[0].".conf>click</a></td></tr>";
    }
    echo "</table><br><br>";
    if(isset($_GET['co'])){
       	    if(isset($_GET['url'])&&isset($_POST['pole'])){
		$typ=explode(".",$_GET['url']);
		$url="tasks/".$typ[0]."/".$typ[0].".".$typ[1];
		$_POST['pole']=ereg_replace("\r","",$_POST['pole']);
		$_POST['pole']=stripcslashes($_POST['pole']);
		@$site=fopen($url, "w");
		@flock($site,2);
		@fwrite($site, $_POST['pole']);
		@flock($site,3);
		@fclose($site);
	    }
	    elseif(!isset($_GET['url'])){
		echo "Nic do roboty.";
	    }					    
	    else{
		$typ=explode(".",$_GET['url']);
		if($typ[1]=="") {
		    //zmiana danych w bazie
		}
		$url="tasks/".$typ[0]."/".$typ[0].".".$typ[1];
		echo "Edycja pliku: ".$url."<br><br>";
		@$site=fopen($url, "a+");
		@flock($site,2);
		@$tresc = fread($site, filesize($url));
		@flock($site,3);
		@fclose($site);
		echo "
		<form method=post action=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$_GET['url'].">
		<input type=hidden name=source value=".$url,">
		<textarea rows=30 cols=70 name=pole>"
		.htmlspecialchars($tresc).
		"</textarea>
		<br><input type=submit value= Zapisz >";
	    }
    }
?>
