<?php
    $plik=fopen("./solutions/".$_GET['id'].".dt","r");
    $dane=fread($plik,filesize("./solutions/".$_GET['id'].".dt"));
    $tab2=explode("\n",$dane);
    $idz=$tab2[0];
    fclose($plik);
    $plik=fopen("./tasks/".$idz."/".$idz.".conf","r");
    $dane=fread($plik,filesize("./tasks/".$idz."/".$idz.".conf"));
    $tab2=explode("\n",$dane);
    $testy=$tab2[0];
    fclose($plik);    
    @$plik=fopen("./solutions/".$_GET['id'].".re","r");
    @$dane=fread($plik,filesize("./solutions/".$_GET['id'].".re"));
    @$tab=explode("\n",$dane);
    @fclose($plik);
    $ilosc=count($tab)-1;
    if($ilosc<0) $ilosc=0;
    echo "<center>Szczegóły zgłoszenia: (ID zgłoszenia: ".$_GET['id']." - zadanie: ".get_name_of_task($idz).")";
    echo "<br><br><table border=1><tr><td align=center>Nr testu</td><td align=center>Odpowiedź</td><td align=center>Czas/Limit [ms]</td><td align=center>Limit pamięci [KB]</td></tr>";
    for($i=0;$i<$ilosc;$i++)
    {
	$tresc=explode(" ",$tab[$i]);
	if($tresc[0]==1) echo "<tr bgcolor=#d0f0d0>";
	else if($i%2) echo "<tr bgcolor=#f4f2f0>";
	else echo "<tr bgcolor=#eceae8>";
	echo "<td align=center>".$i."</td><td align=center>";
	if($tresc[0]==0) echo "Błędna odpowiedź";
	else if($tresc[0]==1) echo "Program zaakceptowany";
	else if($tresc[0]==2) echo "Błąd kompilacji";
	else if($tresc[0]==3) echo "Limit pamięci przekroczony";
	else if($tresc[0]==4) echo "Limit czasu przekroczony";
	else echo "Terefere (SYS)";
	$tresc2=explode(" ",$tab2[$i+1]);
	echo "</td><td align=center>".$tresc[1]." / ".$tresc2[2]."</td><td align=center>".round($tresc2[3]/1024,0)."</td></tr>";
    }
    for($i=$ilosc;$i<$testy;$i++)
    {
	$tresc2=explode(" ",$tab2[$i+1]);
	echo "<tr bgcolor=#d0a0a0><td align=center>".$i."</td><td align=center>Nie przetestowane</td>
	      <td align=center>- / ".$tresc2[2]."</td><td align=center>".round($tresc2[3]/1024,0)."</td></tr>";
    }
    echo "</table>";


?>