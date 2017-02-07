<?PHP
    session_start();
    include('fun.php');
    if(!isset($_SESSION['logi'])) include('logowanie.php');
    else
    {
        include('naglowek.php');
	$poz=used($_SESSION['logi']);
	$tab=file('data.txt');
	$exp=explode('`',$tab[$poz]);
	if(trim($exp[3])!='a') echo "Sorry man, nie masz uprawnień administatora.";
	else
	{
	    if(!isset($_POST['imie']))
	    {
		echo "<b>Edycja księgi gości</b><br>Zamiast enter użyj: |<br>";
		$plik=fopen('ksiega.txt',"a+");
		$tresc=fread($plik,filesize('ksiega.txt'));
		fclose($plik);
		$tab=file('ksiega.txt');
		$q=0;
		while($q<sizeof($tab))
		{
		    $exp=explode('`',$tab[$q]);
		    echo "
			    <hr><form method=post action=editbook.php>
			    <input type=hidden name=wsk value=".$q." >
			    <table><tr><td>Imię: </td><td>
			    <textarea name=imie rows=1 cols=60>".$exp[0].
			    "</textarea></td></tr><tr><td>E-mail: </td><td>
			    <textarea name=email rows=1 cols=60>".$exp[1].
			    "</textarea></td></tr><tr><td>WWW: </td><td>
			    <textarea name=www rows=1 cols=60>".$exp[2].
			    "</textarea></td></tr><tr><td>GG: </td><td>
			    <textarea name=gg rows=1 cols=60>".$exp[3].
			    "</textarea></td></tr><tr><td>Wpis: </td><td>
			    <textarea name=wpis rows=5 cols=100>".$exp[4].
			    "</textarea></td></tr>
			    <tr><td><input type=submit value= Edytuj ></form></td>
			    <form method=post action=editbook.php>
			    <input type=hidden name=wsk value=".$q." >
			    <input type=hidden name=imie value='' >
			    <td><input type=submit value= Usuń ></form></td></tr></table>
			";
			$q++;
		} 
	    }	    
	    elseif($_POST['imie']!='')	    
	    {		
		$_POST['wpis']=ereg_replace("\n","",$_POST['wpis']);
		$_POST['wpis']=ereg_replace("\r","",$_POST['wpis']);
		$_POST['www']=ereg_replace("\n","",$_POST['www']);
		$_POST['www']=ereg_replace("\r","",$_POST['www']);
		$_POST['gg']=ereg_replace("\n","",$_POST['gg']);
		$_POST['gg']=ereg_replace("\r","",$_POST['gg']);
		$_POST['email']=ereg_replace("\n","",$_POST['email']);
		$_POST['email']=ereg_replace("\r","",$_POST['email']);
		$_POST['imie']=ereg_replace("\n","",$_POST['imie']);
		$_POST['imie']=ereg_replace("\r","",$_POST['imie']);
		$_POST['wpis']=stripcslashes($_POST['wpis']);
		$_POST['imie']=stripcslashes($_POST['imie']);
		$_POST['gg']=stripcslashes($_POST['gg']);
		$_POST['www']=stripcslashes($_POST['www']);
		$_POST['email']=stripcslashes($_POST['email']);
		$_POST['wpis']=htmlspecialchars($_POST['wpis']);
		$_POST['imie']=htmlspecialchars($_POST['imie']);
		$_POST['gg']=htmlspecialchars($_POST['gg']);
		$_POST['email']=htmlspecialchars($_POST['email']);
		$_POST['www']=htmlspecialchars($_POST['www']);
		$zamiana=$_POST['imie']."`".$_POST['email']."`".$_POST['www']."`".$_POST['gg']."`".$_POST['wpis']."\n";
		$tab=file('ksiega.txt');
		$tab[$_POST['wsk']]=$zamiana;
		file_put_contents('ksiega.txt', $tab);
		echo "Wpis do księgi gości został zedytowany.";
	    }
	    else
	    {
		$lines = file('ksiega.txt');
		unset($lines[$_POST['wsk']]);
		file_put_contents('ksiega.txt', $lines);
		echo "Wpis został usunięty.";
	    }	
	}
	include('return2sender.php');
    }
?>