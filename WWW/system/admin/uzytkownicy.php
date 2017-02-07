<?php 
    print "<center><b>Użytkownicy</b><br><br>";
    $mysql=sqlConnect();
    if(isset($_GET['act']))
    {
	$zapytanie="SELECT users.active FROM users WHERE users.id = '".$_GET['act']."'";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik)
	{
	    print 'Nie można wykonać zapytania.<br><br>';
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	$stan=($wiersz[0]+1)%2;
	$zapytanie="UPDATE users SET active='".$stan."' WHERE id='".$_GET['act']."' LIMIT 1";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik)
	{
	    print 'Nie można wykonać zapytania.<br><br>';
	    exit;
	}
    }
    if(isset($_GET['era']))
    {/*
	if($_GET['era']=="1"||$_GET['era']=="3") print "Nie da rady bracie.<br><br>";
	else
	{
	    $zapytanie="DELETE FROM users WHERE id='".$_GET['era']."'";
	    $wynik=mysqli_query($mysql,$zapytanie);
	    if(!$wynik)
	    {*/
		print 'Nie można usunąć gościa - ma szczęście...<br><br>';
		/*exit;
	    }
	}*/
    }
    $zapytanie="SELECT users.id, users.login, users.email, users.gg, users.active, users.privileges, users.last FROM users ORDER BY users.privileges DESC, users.id ASC";
    $wynik=mysqli_query($mysql,$zapytanie);
    if(!$wynik)
    {
	print 'Nie można wykonać zapytania.';
	exit;
    }
    $wiersz=mysqli_fetch_row($wynik);
    print '<center><table border=1><tr><td align=center>ID</td><td align=center>Login:</td>
	    <td align=center>E-mail:</td><td align=center>GG:</td>
	    <td align=center>Prawa:</td><td align=center>Aktywny:</td>
	    <td align=center>Ostatnie logowanie:</td><td align=center>Usuń:</td></tr>';
    do
    {
	print '<tr><td align=center>'.$wiersz[0].'</td><td align=center>'.$wiersz[1].'</td><td align=center>'.$wiersz[2].'</td>
		<td align=center>'.$wiersz[3].'</td><td align=center>'.$wiersz[5].'</td>
		<td align=center><a href=index.php?whereAmI=apanel&me=users&act='.$wiersz[0].'>'.$wiersz[4].'</a></td>
		<td align=center>'.date('l jS F Y h:i:s A',$wiersz[6]).'</td><td align=center>';
	if($wiersz[5]==2) print '-';
	else print '<a href=index.php?whereAmI=apanel&me=users&era='.$wiersz[0].'>click</a>'; 
	print '</td></tr>';
    $wiersz=mysqli_fetch_row($wynik);
    }while(!empty($wiersz));
    print '</table><br>';	
?>
