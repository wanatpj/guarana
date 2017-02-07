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
	elseif(!isset($_POST['src']))
	{
	    echo "Nic do roboty.";
	}
else
{
$_POST['src']=$_SESSION['sdir'].$_POST['src'];
	if(is_file($_POST['src'])===false&&is_dir($_POST['src'])===false)
	{
	    echo "Podany plik/folder nie istnieje.";
	}
	elseif(filetype($_POST['src'])=='file')
	{
	    unlink($_POST['src']);
	    echo "Plik: ".$_POST['src']." został usunięty.";
	}
	elseif(filetype($_POST['src'])=='dir')
	{
	    echo "Jeśli folder jest pusty, to zostanie usunięty.";
	    rmdir($_POST['src']);
	}
	else
	{
	    echo "?";
	}
}
	include('return2sender.php');
    }
?>