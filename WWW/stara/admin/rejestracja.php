<?PHP
    include('naglowek.php');
    function used($x)
    {
	$s="users.txt";
	$t="a+";
	$d=fopen($s, $t);
	flock($d,2);
	$u=0;
	while(true)
	{
	    $l=fgets($d);
	    if($l==FALSE) break;
	    if(strpos($l, $x)!==false) $u=1;
 	}
	flock($d,3);
	fclose($d);
	if($u==1) return true;
	else return false;
    }
    if(!isset($_POST['login']))
    {
	echo "	<table><tr><td colspan=2>Rejestracja</td></tr>
		<form method=post action=rejestracja.php>
		<tr><td>Login: </td><td><input type=text name=login maxlength=100></td></tr>
		<tr><td>E-mail: </td><td><input type=text name=email maxlength=40></td></tr>
		<tr><td>Hasło: </td><td><input type=password name=pass maxlength=40></td></tr>
		<tr><td>Powtórz hasło: </td><td><input type=password name=pass2 maxlength=40></td></tr>
		<tr><td colspan=2><center><input type=submit value= Wyślij > <input type=reset value= Wyczyść ></td></tr>
	     ";
    }
    else
    {
	if(strlen($_POST['login'])>50) echo "Za długi login";
	elseif(strlen($_POST['email'])>40) echo "Za długi e-mail";
	elseif(strlen($_POST['pass'])>40) echo "Za długie hasło";
	elseif(empty($_POST['pass'])) echo "Uzupełnij wszystkie pola.";
	elseif(empty($_POST['email'])) echo "Uzupełnij wszystkie pola.";
	elseif(empty($_POST['login'])) echo "Uzupełnij wszystkie pola.";
	elseif($_POST['pass']!=$_POST['pass2']) echo "Wprowadzone hasła się różnią";
	elseif(strpos($_POST['login'], '\n')!==false) echo "Błędny login.";
	elseif(strpos($_POST['login'], '`')!==false) echo "Błędny login.";
	elseif(strpos($_POST['email'], '\n')!==false) echo "Błędny e-mail.";
	elseif(strpos($_POST['email'], '`')!==false) echo "Błędny e-mail.";
	elseif(strpos($_POST['email'], '@')===false) echo "Błędny e-mail.";
	elseif(strpos($_POST['email'], '.')===false) echo "Błędny e-mail.";
	elseif(strpos($_POST['pass'], '\n')!==false) echo "Błędne hasło.";
	elseif(strpos($_POST['pass'], '`')!==false) echo "Błędne hasło.";	
	elseif(used($_POST['login'])===true) echo "Podany login jest już zajęty.";
	else
	{
	    $sciezka="data.txt";
	    $tryb="a+";
	    $dane=fopen($sciezka, $tryb);
	    flock($dane,2);
	    fwrite($dane, $_POST['login'].'`'.$_POST['email'].'`'.md5($_POST['pass'])."`u\n");
	    flock($dane,3);
	    fclose($dane);
	    $sciezka="users.txt";
	    $dane=fopen($sciezka, $tryb);
	    flock($dane,2);
	    fwrite($dane, $_POST['login']."\n");
	    flock($dane,3);
	    fclose($dane);	    
	    echo "Rejestracja przebiegła pomyślnie.";
	}
    }
    include('return2sender.php');
?>