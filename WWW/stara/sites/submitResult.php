<?php
if(isset($_POST['isSend'])&&is_active_task($_POST['idOfTask']))
{
    $wsk = fopen('./solutions/currentID', 'r+');
    flock($wsk,1);
    $id = (int) fgets($wsk, 1024);
    fclose($wsk);
    $id++;
    $wsk = fopen('./solutions/currentID', 'w+'); 
    flock($wsk,1);
    fwrite($wsk, $id);
    fclose($wsk);
    if($_POST['source']=="")
    { 
	$file = $HTTP_POST_FILES["file"]["tmp_name"];
	$zapisz_jako = "./solutions/".$id.".cpp";
	if (!copy($file, $zapisz_jako)) print ("Kopiowanie pliku nie powiodło się...<br>\n");
	$rozm=$HTTP_POST_FILES["file"]["size"]; 
	//print "<BR>Typ przesłanego pliku: ".$HTTP_POST_FILES["file"]["type"];
    }
    else
    {
	$wsk=fopen("./solutions/".$id.".cpp",'w');
	flock($wsk,1);
	fwrite($wsk, stripslashes($_POST['source']));
	fclose($wsk);
    }
    $wsk=fopen("./solutions/".$id.".dt",'w');
    flock($wsk,1);
    $info=$_POST['idOfTask']."\n".$_SESSION['SESSION_USER']."\n".time();
    fwrite($wsk, $info);
    fclose($wsk);
    print "<center>Zgłoszenie przyjęte.";
    print "<BR>ID pliku: ".$id;
    print "<BR>Rozmiar pliku: ".$rozm." bajtów";
    print '<br><b><a href=index.php?whereAmI=details&id='.$id.'>Zobacz raport</a></b>';
    $plik = fopen("queue.dt","a");
    flock($plik,2);
    fwrite($plik, $_POST['idOfTask']." ".$id."\n");
    fclose($plik);
}
else
{
    print 'terefere i parirura';
}
?> 
