<?php    
    if(!isset($_GET['od'])) $od=0;
    else $od=$_GET['od']; 
    if($od<0) $od=0;
    $plik=fopen("./solutions/currentID","r");
    $idd=fread($plik, filesize("./solutions/currentID"));
    fclose($plik);
    $id2=explode("\n",$idd);
    $id=$id2[0];
    echo "<center>Ilość zgłoszeń: ".$id;
    print '<table><tr>
    <td align=left><a href=index.php?whereAmI=status&od='.($od - 10).'>wstecz</a></td>
    <td align=center>';
    $x=($od+10)/10;
    $f=$x;
    if($x-5<=0) $x=6;
    $y=$x+5;
    if($y*10-10>$id) $y=($id+10)/10;
    for($i=$x-5,$j=(($x-5)*10-10);$i<$y;$i++,$j+=10)
    {
	print '<a href=index.php?whereAmI=status&od='.$j.'>';
	if($i==$f) print '<b>'.$f.'</b>';
	else print $i;
	print '</a> ';
    }
    echo'</td>
    <td align=right><a href=index.php?whereAmI=status&od='.($od + 10).'>dalej</a></td>
    </tr></table>';
    echo "<br><br><table border=1>
	  <tr>
	    <td align=center>ID</td>
	    <td align=center>Kod</td>
	    <td align=center>Data</td>
	    <td align=center>Użytkownik</td>
	    <td align=center>Zadanie</td>
	    <td align=center>Nr testu</td>
	    <td align=center>Wynik</td>
	    <td align=center>Stan</td>
	    <td align=center>Czas[ms]</td>
	    <td align=center>Rozmiar[B]</td>
	  </tr>";
    $do=$id-$od-10;
    if($do<0) $do=0;
    for($i=$id-$od;$i>$do;$i--)
    {
	$plik=fopen("./solutions/".$i.".dt","r");
	$tresc=fread($plik, filesize("./solutions/".$i.".dt"));
	fclose($plik);
	$dane=explode("\n",$tresc);
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
	$dobre=0;
	for($j=0;$j<$zly2;$j++)
	{
	    $tmp=explode(" ",$testy[$j]);
	    $czas+=$tmp[1];
	    if($tmp[0]=="1") $dobre++;
	    if($tmp[0]!="1"&&$ok==1)
	    {
		$zly=$j;
		$stan=$tmp[0];
		//break;
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
	echo "<td align=center>".$i."</td><td align=center>";//Wanat start
	if($_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN||owner_of_sol($i)==$_SESSION[SESSION_USER])
	    print '<a href="index.php?whereAmI=view&sol_id='.$i.'"><img src=gfx/report.gif border=0 width=10 height=15></a>';
	else print '-';
	echo "</td><td align=center>";
	$data=date("Y-m-d",$dane[2]);
	$czas22=date("H:i:s",$dane[2]);
	echo $data."<br>".$czas22;
	echo "</td><td align=center>".$dane[1]."</td><td align=center><a href=index.php?whereAmI=tasks&Rdef=$dane[0]>$dane[0] - ".get_name_of_task($dane[0])."</a></td><td align=center>";
	echo "<a href=index.php?whereAmI=details&id=".$i.">".$zly."</a></td><td align=center>"./*Wanat start*/pointsToRank($i)/*Wanat end*//*round(($dobre/$ilosc*100),0)*/."</td><td align=center>";
	echo "<a href=index.php?whereAmI=details&id=".$i.">";
	if($stan==1) echo "OK";
	else if($stan==0) echo "WA";
	else if($stan==3)echo "MEM";
	else if($stan==2)echo "COM";
	else if($stan==4) echo "TLE";
	else if($stan==5) echo "QUE";
	else echo "SYS";
	echo "</a>";
	echo "</td><td align=center>".$czas."</td><td align=center>".@filesize("./solutions/".$i.".cpp")."</td></tr>";
    }
    echo "</table>";
?>