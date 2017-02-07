<?php
if(isset($_POST['isSend'])&&isActiveTask($_POST['idOfTask'])) {
    $mysql=sqlConnect();
    $id=GetNextAutoInc("solutions", $mysql);
    if($_POST['source']=="") { 
	$file = $HTTP_POST_FILES["file"]["tmp_name"];
	$zapisz_jako = "./solutions/".$id.".cpp";
	if (!copy($file, $zapisz_jako)) die ("Kopiowanie pliku nie powiodło się...<br>\n"); 
    }
    else {
	$wsk=fopen("./solutions/".$id.".cpp",'w');
	flock($wsk,1);
	fwrite($wsk, stripslashes($_POST['source']));
	fclose($wsk);	
    }
    $rozm=filesize("./solutions/".$id.".cpp");
    $zapytanie="INSERT INTO `solutions` (`ID`, `user ID`, `task ID`, `date`, `time`, `result`)
    VALUES (NULL, '$_SESSION[SESSION_USERID]', '$_POST[idOfTask]', '".time()."', NULL, NULL)";
    $wynik=mysqli_query($mysql,$zapytanie); 
    if(!$wynik) {
	print 'Nie można wykonać zapytania do bazy danych - spróbuj później.';
	exit;
    }
    print "<center>Zgłoszenie przyjęte.";
    print "<BR>ID pliku: ".$id;
    print "<BR>Rozmiar pliku: ".$rozm." bajtów";
    print '<br><b><a href=index.php?whereAmI=details&id='.$id.'>Zobacz raport</a></b>';
    $zapytanie="INSERT INTO queue (`submit`, `task`) VALUES('$id', '$_POST[idOfTask]')";
    $wynik=mysqli_query($mysql,$zapytanie); 
    if(!$wynik) {
	print 'Nie można wykonać zapytania do bazy danych - spróbuj później.';
	exit;
    }
}
else print 'terefere i parirura';
?> 
