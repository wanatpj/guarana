<?php	
    session_start();
    unset($_SESSION);
    session_destroy();
    session_start();
    if(empty($_POST['login'])||empty($_POST['pass']))
    {
        print '
	    <form action=index.php method=POST>
		<table>
		    <tr>
			<td>Login: </td>
			<td><input type="text" name="login"></td>
		    </tr>
		    <tr>
			<td>Hasło: </td>
			<td><input type="password" name="pass"></td>
		    </tr>
		</table>
		<input type="submit" value="Zaloguj">
	    </form>
	    <br>Nie masz konta? <a href=index.php?whereAmI=rej>Zarejestruj się!</a>';
    }
    else
    {
	if(!isValid("login",$_POST['login'])||!isValid("pass",$_POST['pass'])) print 'Nieprawidłowy login lub hasło.';
	else
	{
	    $mysql=sqlConnect();
	    $passwd=md5($_POST['pass']);
	    $zapytanie="SELECT COUNT(*) FROM users WHERE users.login='".$_POST['login']."' AND users.pass='$passwd'";
	    $wynik=mysqli_query($mysql,$zapytanie);
	    if(!$wynik) {
		print 'Nie można wykonać zapytania.';
		exit;
	    }
	    $wiersz=mysqli_fetch_row($wynik);
	    if($wiersz[0]!=1) {
		print 'Nieprawidłowy login lub hasło.';
	    }
	    else {	
		$_SESSION[SESSION_USER]=$_POST['login'];
		
		$zapytanie="SELECT privileges FROM users WHERE users.login='".$_POST['login']."'";
		$wynik=mysqli_query($mysql,$zapytanie);
		if(!$wynik) {
		    print 'Nie można pobrać uprawnień.';
		    $_SESSION[SESSION_PERMISSION]=0;
		}
		else {
		    $wiersz=mysqli_fetch_row($wynik);
		    $_SESSION[SESSION_PERMISSION]=$wiersz[0];
		    //int 'Zostałeś poprawnie zalogowany.';
		}
		$zapytanie="SELECT id FROM users WHERE users.login='".$_POST['login']."'";
		$wynik=mysqli_query($mysql,$zapytanie);
		if(!$wynik) {
		    print 'Nie można pobrać ID użytkownika.';
		    $_SESSION[SESSION_USERID]=-1;
		    unset($_SESSION);
		    session_destroy();
		}
		else {
		    $wiersz=mysqli_fetch_row($wynik);
		    $_SESSION[SESSION_USERID]=$wiersz[0];
		}
		$zapytanie="SELECT active FROM users WHERE users.login='".$_POST['login']."'";
		$wynik=mysqli_query($mysql,$zapytanie);
		if(!$wynik) {
		    print 'Nie można pobrać stanu.';
		    unset($_SESSION);
		    session_destroy();
		}
		else {
		    $wiersz=mysqli_fetch_row($wynik);
		    if($wiersz[0]=="0") 
		    {
		        unset($_SESSION);
			session_destroy();
			print 'Twoje konto nie zostało jeszcze aktywowane.';
		    }
		    else
		    { 
			$zapytanie="UPDATE users SET last='".time()."' WHERE users.login='".$_POST['login']."'";
			$wynik=mysqli_query($mysql,$zapytanie);
			if(!$wynik)
			{
			    print 'Nie można wykonać zapytania.';
			}
			else
			{
			    $_SESSION[SESSION_MY_NAME]=true;
			    header('Location: index.php');
			    exit();
			}
		    }
		}
	    }    
	}
    }	
?>
