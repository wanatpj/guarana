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
	elseif(!isset($_POST['src1']))
	{
	    echo "Nic do roboty.";
	}
else
{
$_POST['src1']=$_SESSION['sdir'].$_POST['src1'];
$_POST['src2']=$_SESSION['sdir'].$_POST['src2'];
	if(file_exists($_POST['src1'])===false)
	{
	    echo "Podany plik nie istnieje.";
	}
	else
	{
	    rename($_POST['src1'],$_POST['src2']);
	    echo "Operacja zakończona sukcesem."; 
	}
}
	include('return2sender.php');
    }
?>