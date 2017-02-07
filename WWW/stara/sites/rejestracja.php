<?php
    include("config.php");
    print '<center><br><br>';
    if(empty($_POST['login'])||empty($_POST['pass'])||empty($_POST['pass2']))
    {
        print '
	    <form action="index.php?whereAmI=rej" method=POST>
		<table>
		    <tr>
			<td>Login: </td>
			<td><input type="text" name="login"> (minimum 3 znaki, litery, cyfry, "_")</td>
		    </tr>
		    <tr>
		    <tr>
			<td>E-mail: </td>
			<td><input type="text" name="email"></td>
		    </tr>
		    <tr>
			<td>Hasło: </td>
			<td><input type="password" name="pass"> (minimum 6 znaków, litery, cyfry, "_")</td>
		    </tr>
		    <tr>
			<td>Powtórz hasło: </td>
			<td><input type="password" name="pass2"></td>
		    </tr>
		</table>
		<br>
		<input type="submit" value="Zarejestruj">
	    </form>';
    }
    else
    {
	if(!isValid("email",$_POST['email'])||!isValid("login",$_POST['login'])||!isValid("pass",$_POST['pass'])||$_POST['pass']!=$_POST['pass2']) print 'Nieprawidłowy login lub hasło.';
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
	    $zapytanie="SELECT COUNT(*) FROM users WHERE users.login='".$_POST['login']."'";
	    $wynik=mysqli_query($mysql,$zapytanie);
	    if(!$wynik)
	    {
		print 'Nie można wykonać zapytania.';
		exit;
	    }
	    $wiersz=mysqli_fetch_row($wynik);
	    if($wiersz[0]==1)
	    {
		print 'Podany login jest już zajęty.';
	    }
	    else
	    {	
		$zapytanie="INSERT INTO users (login, pass, email) VALUES('".$_POST['login']."', '".md5($_POST['pass'])."', '".$_POST['email']."')";
		mysqli_query($mysql,$zapytanie);
		print 'Konto zostało utworzone.<br>Poczekaj na aktywacje administratora.';
	    }    
	}
    }
    print '</center><br><br>';	
?>
