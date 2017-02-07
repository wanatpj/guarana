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
	elseif(isset($_FILES['plik']['tmp_name']))
	{
	    $max_rozmiar = 1024*1024;
	    if (is_uploaded_file($_FILES['plik']['tmp_name'])) 
	    {
		if ($_FILES['plik']['size'] > $max_rozmiar) 
		{
		    echo "Błąd! Plik jest za duży!";
		} 
		else 
		{
		    echo "Odebrano plik. Początkowa nazwa:   ".$_FILES['plik']['name']."<br/>";
		    if (isset($_FILES['plik']['type'])) 
		    {
			echo "Typ: ".$_FILES['plik']['type']."<br/>";
		    }
		    $nazwa=$_FILES['plik']['name'];
		    while(file_exists($_SESSION['sdir'].$nazwa)) $nazwa=$nazwa."a";
		    move_uploaded_file($_FILES['plik']['tmp_name'],$_SESSION['sdir'].$nazwa);
		    echo "Plik został umieszczony w: ".$_SESSION['sdir']." nazwa: ".$nazwa;
		}
	    } 
	    else 
	    {
		echo "Błąd przy przesyłaniu danych!";
	    }
	}
	else
	{
	    echo "Nic do roboty.";
	}
	include('return2sender.php');
    }
?>