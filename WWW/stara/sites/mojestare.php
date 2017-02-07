<?php
    $plik=fopen("./solutions/currentID","r");
    $id=fgets($plik, 10000);
    fclose($plik);
    echo '<CENTER>Moje zgłoszenia:<br><br><form action="index.php?whereAmI=moje" method="post">
    Do zadania: 
    <select name="zadanie"><option value="">wszystkie</option>';
    $n=numberOfTasks();
    for($i=0;$i<$n;$i++)
    {
	echo '<option value="'.$i.'">'.get_name_of_task($i).'</option>';
    }
    echo '</select>
	    <input value="Pokaż" type="submit">
	    </form>
		<br><table border=1>
	  <tr>
	    <td align=center>ID</td>
	    <td align=center>Kod</td>
	    <td align=center>Data</td>
	    <td align=center>Użytkownik</td>
	    <td align=center>Zadanie</td>
	    <td align=center>Nr testu</td>
	    <td align=center>Stan</td>
	    <td align=center>Czas[ms]</td>
	    <td align=center>Rozmiar[B]</td>
	  </tr>';
    for($i=$id;$i>=1;$i--)
    {
	$plik=fopen("./solutions/".$i.".dt","r");
	$tresc=fread($plik, filesize("./solutions/".$i.".dt"));
	fclose($plik);
	$dane=explode("\n",$tresc);
	if($dane[1]==$_SESSION[SESSION_USER])
	{
	    if($_POST['zadanie']==""||$_POST['zadanie']==$dane[0])
	    {
	    $plik=fopen("./tasks/".$dane[0]."/".$dane[0].".conf","r");
	    $tresc=fread($plik, filesize("./tasks/".$dane[0]."/".$dane[0].".conf"));
	    fclose($plik);
	    $ile=explode("\n",$tresc);
	    $ilosc=$ile[0];
	    @$plik=fopen("./solutions/".$i.".re","r");
	    @$tresc=fread($plik, filesize("./solutions/".$i.".re"));
	    @fclose($plik);
	    $testy=explode("\n",$tresc);
	    $zly=count($testy)-1;
	    $zly2=$zly;
	    $stan=1;
	    $czas=0;
	    $ok=1;
	    for($j=0;$j<$zly2;$j++)
	    {
		$tmp=explode(" ",$testy[$j]);
		$czas+=$tmp[1];
		if($tmp[0]!="1"&&$ok==1)
		{
		    $zly=$j;
		    $stan=$tmp[0];
		    $ok=0;
		}
	    }
	    if($stan!=2&&count($testy)-1<$ilosc) $stan=5;
	    if($stan==5) //running
	    {
	        echo "<tr bgcolor=#d0a0a0>";
	    }
	    else if($stan!=1)
	    { 
		if($i%2==0) echo "<tr bgcolor=#f4f2f0>";
		else echo "<tr bgcolor=#eceae8>";
	    }
	    else echo "<tr bgcolor=#d0f0d0>";
	    if($zly==0&&$stan==5) $zly="-";
	    echo "<td align=center>".$i."</td><td><a href=\"index.php?whereAmI=view&sol_id=".$i."\">click</a></td><td align=center>";
	    $data=explode(" ",$dane[2]);
	    echo $data[4]."-".$data[3]."-".$data[2]."<br>".$data[0].":".$data[1];
	    echo "</td><td align=center>".$dane[1]."</td><td align=center>$dane[0] - ".get_name_of_task($dane[0])."</td><td align=center>";
	    echo "<a href=index.php?whereAmI=details&id=".$i.">".$zly."</a></td><td align=center>";
	    if($stan==1) echo "Program zaakceptowany";
	    else if($stan==0) echo "Błędna odpowiedź";
	    else if($stan==3)echo "Limit pamięci przekroczony";
	    else if($stan==2)echo "Błąd kompilacji";
	    else if($stan==4) echo "Limit czasu przekroczony";
	    else if($stan==5) echo "Nie przetestowane";
	    else echo "Terefere (SYS)";
	    echo "</td><td align=center>".$czas."</td><td align=center>".filesize("./solutions/".$i.".cpp")."</td></tr>";
	    }
	}
    }
    echo "</table>";
?>