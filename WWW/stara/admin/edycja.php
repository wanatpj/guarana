<?PHP
    session_start();
    include('fun.php');
    if(!isset($_SESSION['logi']))
    {
	include('logowanie.php');
    }
    else
    {
        include('naglowek.php');
	$poz=used($_SESSION['logi']);
	$tab=file('data.txt');
	$exp=explode('`',$tab[$poz]);
	if(trim($exp[3])!='a')
	{
	    echo "Sorry man, nie masz uprawnień administatora.";
	}
	else
	{
	    if(isset($_POST['pole']))
	    {
$_POST['src']=$_SESSION['sdir'].$_POST['source'];
		$_POST['pole']=ereg_replace("\r","",$_POST['pole']);
		$_POST['pole']=stripcslashes($_POST['pole']);
		$site=fopen($_POST['source'], "w");
		flock($site,2);
		fwrite($site, $_POST['pole']);
		flock($site,3);
		fclose($site);
		if(strpos($_POST['source'], '.htm')===false&&strpos($_POST['source'], '.html')===false)
		{
			echo "Plik został zapisany z chmod: 700.";
			chmod($_POST['source'], 0700);
		}
		else
		{	 	
			echo "Plik został zapisany z chmod: 705.";
			chmod($_POST['source'], 0705);
		}
	    }
	    elseif(!isset($_POST['src']))
	    {
		echo "Nic do roboty.";
	    }
	    elseif(empty($_POST['src']))
	    {
		echo "Błędna nazwa pliku.";
	    }						    
	    else
	    {
$_POST['src']=$_SESSION['sdir'].$_POST['src'];
		echo "Edycja pliku: ".$_POST['src']."<br><br>";
		$site=fopen($_POST['src'], "a+");
		@flock($site,2);
		@$tresc = fread($site, filesize($_POST['src']));
		@flock($site,3);
		@fclose($site);
		echo "
		<form method=post action=edycja.php>
		<input type=hidden name=source value=".$_POST['src'],">
		<textarea rows=50 cols=100 name=pole>"
		.htmlspecialchars($tresc).
		"</textarea>
		<br><input type=submit value= Zapisz >";
	    }
	}
	include('return2sender.php');
    }
?>