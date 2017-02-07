<?php 
    include("config.php");
    if(isset($_POST['npass']))
    {
	if(!isValid("pass",$_POST['npass'])||$_POST['npass2']!=$_POST['npass']) print 'Nieprawidłowe hasło.';
    	else
	{
		$mysql=mysqli_connect($mhost, $muser, $mpass);
		if(!$mysql)
		{
	    		print 'Brak połączenia z bazą danych.';
	    		exit;
		}
		$wybrana=mysqli_select_db($mysql, $mbase);
		if(!$wybrana)
		{
	    		print 'Błąd wyboru bazy danych.';
	    		exit;
		}
		$passwd=md5($_POST['pass']);
		$zapytanie="SELECT COUNT(*) FROM users WHERE users.login='".$_SESSION[SESSION_USER]."' AND users.pass='".$passwd."'";
		$wynik=mysqli_query($mysql,$zapytanie);
		if(!$wynik)
		{
	    		print 'Nie można wykonać zapytania.';
	    		exit;
		}
		$wiersz=mysqli_fetch_row($wynik);
		if($wiersz[0]!=1) print 'Nieprawidłowe hasło.';
		else
		{
			$passwd=md5($_POST['npass']);
			$zapytanie="UPDATE users SET pass='".$passwd."' WHERE login='".$_SESSION[SESSION_USER]."' LIMIT 1";
	    		$wynik=mysqli_query($mysql,$zapytanie);
	    		if(!$wynik)
	    		{
				print 'Nie można wykonać zapytania.';
				exit;
	    		}
			else print 'Hasło zostało zmienione.';
		}
	}
    }
    else if($_GET['pass']==1)
    {
	print '
	    <form action="index.php?whereAmI=edy" method=POST>
		<table>
		    <tr>
			<td>Stare hasło: </td>
			<td><input type="password" value="" name="pass"></td>
		    </tr>
		    <tr>
			<td>Nowe hasło: (minimum 6 znaków, litery, cyfry, "_")</td>
			<td><input type="password" value="" name="npass"></td>
		    </tr>
		    <tr>
			<td>Powtórz nowe hasło: </td>
			<td><input type="password" value="" name="npass2"></td>
		    </tr>
		</table>
		<input type="submit" value="Zmień">
	    </form>';
    }
    else if(!isset($_POST['email']))
    {
	$mysql=mysqli_connect($mhost, $muser, $mpass);
	if(!$mysql)
	{
	    print 'Brak połączenia z bazą danych.';
	    exit;
	}
	$wybrana=mysqli_select_db($mysql, $mbase);
	if(!$wybrana)
	{
	    print 'Błąd wyboru bazy danych.';
	    exit;
	}
	$zapytanie="SELECT users.email, users.gg FROM users WHERE users.login='".$_SESSION[SESSION_USER]."'";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik)
	{
	    print 'Nie można wykonać zapytania.';
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
        print '
	    <form action="index.php?whereAmI=edy" method=POST>
		<table>
		    <tr>
			<td>Login: </td>
			<td>'.$_SESSION[SESSION_USER].'</td>
		    </tr>
		    <tr>
			<td>E-mail: </td>
			<td><input type="text" value="'.$wiersz[0].'" name="email"></td>
		    </tr>
		    <tr>
			<td>Gadu-Gadu: </td>
			<td><input type="text" value="'.$wiersz[1].'" name="gg"></td>
		    </tr>
		</table>
		<input type="submit" value="Aktualizuj">
	    </form>
	    <br><a href="index.php?whereAmI=edy&pass=1">Zmień hasło</a>';
    }
    else
    {
	if((!isValid("email",$_POST['email'])&&!empty($_POST['email']))||(!isValid("gg",$_POST['gg'])&&!empty($_POST['gg']))) print 'Nieprawidłowe dane.';
	else
	{
	    $mysql=mysqli_connect($mhost, $muser, $mpass);
	    if(!$mysql)
	    {
		print 'Brak połączenia z bazą danych.';
		exit;
	    }
	    $wybrana=mysqli_select_db($mysql, $mbase);
	    if(!$wybrana)
	    {
		print 'Błąd wyboru bazy danych.';
		exit;
	    }
	    $zapytanie="UPDATE users SET email='".$_POST['email']."', gg='".$_POST['gg']."' WHERE login='".$_SESSION[SESSION_USER]."' LIMIT 1";
	    $wynik=mysqli_query($mysql,$zapytanie);
	    if(!$wynik)
	    {
		print 'Nie można wykonać zapytania.';
		exit;
	    }
	    else print 'Dane zostały zmienione.';
	}
    }	
?>
