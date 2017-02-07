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
	elseif(isset($_POST['tresc']))
	{
	    $miesiace=array(
	    '01'=>'Styczeń',
	    '02'=>'Luty',
	    '03'=>'Marzec',
	    '04'=>'Kwiecień',
	    '05'=>'Maj',
	    '06'=>'Czerwiec',
	    '07'=>'Lipiec',
	    '08'=>'Sierpień',
	    '09'=>'Wrzesień',
	    '10'=>'Październik',
	    '11'=>'Listopad',
	    '12'=>'Grudzień'); 
	    $file=fopen('news.txt',"a+");
	    $zaw=fread($file,filesize('news.txt'));
	    fclose($file);
	    $file=fopen('news.txt',"w");
	    $data=date("d")." ".$miesiace[date("m")]." ".date("Y")." r."; 
	    $_POST['tresc']=ereg_replace("\n","", $_POST['tresc']);
	    $_POST['tresc']=stripcslashes($_POST['tresc']);
	    $zaw=$data."`".$_POST['autor']."`".$_POST['tresc']."\n".$zaw;
	    flock($file,2);
	    fwrite($file,$zaw);
	    flock($file,3);
	    fclose($file);
	    echo "News dodany!";
	}
	else echo "Nic do roboty.";
	include('return2sender.php');
    }
?>