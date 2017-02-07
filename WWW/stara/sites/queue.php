<?php
    $plik=fopen("queue.dt","r");
    @$tmp=fread($plik,filesize("queue.dt"));
    fclose($plik);
    $dane=explode("\n",$tmp);
    
    echo "<center>Stan kolejki<br><br>";
    $ilosc=count($dane)-1;
    if($ilosc==0) echo "Kolejka jest aktualnie pusta.";
    else
    {
	echo "<table border=1><tr><td align=center>ID zgłoszenia</td><td align=center>Zadanie</td><td align=center>Użyszkodnik</td></tr>";
	for($i=0;$i<$ilosc;$i++)
	{
	    $costam=explode(" ",$dane[$i]);
	    $plik=fopen("solutions/".$costam[1].".dt","r");
	    $tmp2=fread($plik,filesize("solutions/".$costam[1].".dt"));
	    fclose($plik);
	    $usersi=explode("\n",$tmp2);
	    echo "<tr><td align=center>".$costam[1]."</td><td align=center>".$costam[0]." - ".get_name_of_task($costam[0])."</td><td align=center>"
	    .$usersi[1]."</td></tr>";
	}
	echo "</table>";
    }
?>