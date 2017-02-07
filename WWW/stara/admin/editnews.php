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
	    if(!isset($_POST['autor']))
	    {
		echo "Edycja newsów<br>";
		$plik=fopen('news.txt',"a+");
		$tresc=fread($plik,filesize('news.txt'));
		fclose($plik);
		$tab=file('news.txt');
		for($i=0;$i<sizeof($tab);$i++)
		{
		    $exp=explode('`',$tab[$i]);
		    echo"
			    <hr><form method=post action=editnews.php>
			    <input type=hidden name=wsk value=".$i." >
			    <table><tr><td>Autor: </td><td>
			    <textarea name=autor rows=1 cols=20>".htmlspecialchars($exp[1]).
			    "</textarea></tr><tr><td>Data: </td><td><textarea name=data rows=1 cols=20>"
			    .htmlspecialchars($exp[0])."</textarea></td></tr><tr><td>Treść: </td><td>
			    <textarea name=nius rows=5 cols=100>".htmlspecialchars($exp[2]).
			    "</textarea></td></tr><tr><td><input type=submit value= Edytuj ></form></td>
			    <form method=post action=editnews.php><input type=hidden name=wsk value=".$i." >
			    <input type=hidden name=autor value='' ><td><input type=submit value= Usuń >
			    </form></td></tr></table>
			";
		}
	    }
	    elseif($_POST['autor']!='')
	    {
		$_POST['nius']=ereg_replace("\n","",$_POST['nius']);
		$_POST['nius']=stripcslashes($_POST['nius']);
		$zamiana=$_POST['data']."`".$_POST['autor']."`".$_POST['nius']."\n";
		$tab=file('news.txt');
		$tab[$_POST['wsk']]=$zamiana;
		file_put_contents('news.txt', $tab);
		echo "News został zedytowany.";
	    }
	    else
	    {
		$lines = file('news.txt');
		unset($lines[$_POST['wsk']]);
		file_put_contents('news.txt', $lines);
		echo "News został usunięty.";
	    }
	}
	include('return2sender.php');
    }
?>