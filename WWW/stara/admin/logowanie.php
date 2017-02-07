<?PHP
    if(!function_exists(used)) include('fun.php');
    session_start();
include('naglowek.php');
    if(!isset($_SESSION['logi'])||($_SESSION['logi']=='`'))
    {
	if(!isset($_POST['login']))
	{
	    echo "	<table><tr><td colspan=2>Logowanie</td></tr>
			<form method=post action=logowanie.php>
			<tr><td>Login: </td><td><input type=text name=login maxlength=100></td></tr>
			<tr><td>Hasło: </td><td><input type=password name=pass maxlength=40></td></tr>
			<tr><td colspan=2><center><input type=submit value= Zaloguj ></td></tr></table>
		 ";
	}
	else
	{
	    $poz=used($_POST['login']);
	    if($poz===false) echo "Podany login nie istnieje";
	    else
	    {
		$tablica = file("data.txt");
		$exp=explode('`',$tablica[$poz]);
		if(md5($_POST['pass'])!=$exp[2]) echo "Niepoprawne hasło.";
		else
		{
		    echo "Zostałeś poprawnie zalogowany.";
		    session_register('logi');
                    session_register('sdir');
                    $_SESSION['sdir']=getcwd()."/";
		    $_SESSION['logi']=$_POST['login'];
		} 
	    }
	}
    }
    else
    {
	echo "Jesteś zarejestrowany jako: ".nl2br(htmlspecialchars(trim($_SESSION['logi'])));
	echo "	<br>
		<form method=post action=wyloguj.php>
		<input type=submit value= Wyloguj >
	    ";
    }
    include('return2sender.php');
?>