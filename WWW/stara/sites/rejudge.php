<?php
    echo "Rejudge zadań<br><br>";
    if($_POST['id']!="")
    {
	$tab=explode(" ",$_POST['id']);
	$plik=fopen("queue.dt", "a");
	flock($plik, LOCK_EX);
	for($i=0;$i<sizeof($tab);$i++)
	{ 
	    $plik2=fopen("./solutions/".$tab[$i].".dt", "r");
	    $dane=fread($plik2, filesize("./solutions/".$tab[$i].".dt"));
	    $tab2=explode("\n",$dane);
	    fclose($plik2);
	    fwrite($plik,$tab2[0]." ".$tab[$i]."\n");
	}
	flock($plik, LOCK_UN);
	fclose($plik);
	echo "Wykonane!<br>";
    }
    if($_POST['idz']!="")
    {
	$tab=explode(" ",$_POST['idz']);
	$queue=fopen("queue.dt", "a");
	flock($queue, LOCK_EX);
	$plik=fopen("./solutions/currentID", "r");
	$ilosc=fread($plik, filesize("./solutions/currentID"));
	fclose($plik);
	for($i=1;$i<=$ilosc;$i++)
	{
	    if(file_exists("./solutions/".$i.".dt"))
	    {
		$plik2=fopen("./solutions/".$i.".dt", "r");
		$dane=fread($plik2, filesize("./solutions/".$i.".dt"));
		$tab2=explode("\n",$dane);
		fclose($plik2);
		for($j=0;$j<sizeof($tab);$j++)
		{
		    if($tab[$j]==$tab2[0]) fwrite($queue,$tab2[0]." ".$i."\n");
		}
	    } 	   
	}
	flock($queue, LOCK_UN);
	fclose($queue);
	echo "Wykonane!<br>";
    }
    if($_POST['prz']!="")
    {
	$tab=explode(" ",$_POST['prz']);
	$plik=fopen("queue.dt", "a");
	flock($plik, LOCK_EX);
	for($i=$tab[0];$i<=$tab[1];$i++)
	{ 
	    $plik2=fopen("./solutions/".$i.".dt", "r");
	    $dane=fread($plik2, filesize("./solutions/".$i.".dt"));
	    $tab2=explode("\n",$dane);
	    fclose($plik2);
	    fwrite($plik,$tab2[0]." ".$i."\n");
	}
	flock($plik, LOCK_UN);
	fclose($plik);
	echo "Wykonane!<br>";    
    }
    echo '    
	    <form action="index.php?whereAmI=apanel&me=rejudge" method="post">
	    <table><tr><td>Wybrane rozwiązania (id po spacji):</td><td>
	    <input type="text" name="id">
	    <input type="submit" value="Rejudge"></td></tr><tr><td> 
	    Wybrane zadania (id po spacji):</td><td>
	    <input type="text" name="idz">
	    <input type="submit" value="Rejudge"></td></tr><tr><td>
	    Przedział domknięty rozwiązań (id od,do po spacji):</td><td>
	    <input type="text" name="prz">
	    <input type="submit" value="Rejudge"></td></tr></table></form>
	    ';

?>