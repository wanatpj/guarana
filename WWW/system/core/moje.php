<?php
//	print $mhost;
    $mysql=sqlConnect();    
    if(!isset($_GET['od'])) $od=-1;
    else $od=$_GET['od']; 
    if($od<0) $od=0;
    $zapytanie="SELECT `name`, `ID` FROM `tasks`";
    $wynik=mysqli_query($mysql,$zapytanie);
    if(!$wynik) {
	print "Błąd.";
	exit;
    }
    print '<form name=form_status_submit action="" method="get">
    <input name="whereAmI" value="moje" type="hidden">
    <center>Zadanie: <select name="zadanie" onchange="document.form_status_submit.submit();">
    <option value="all">Wszystkie</option>';
    while($row=mysqli_fetch_row($wynik)){
	if($row[1]==$_GET['zadanie']) echo '<option selected="selected" value="'.$row[1].'">'.$row[0].'</option>';
	else echo '<option value="'.$row[1].'">'.$row[0].'</option>';
    }
    $tab[0][0]="all"; $tab[0][1]="Wszystkie";
    $tab[1][0]="ac"; $tab[1][1]="Tylko zaakceptowane";
    //$tab[2][0]="wa"; $tab[2][1]="Błędna odpowiedź";
    //$tab[3][0]="tl"; $tab[3][1]="Limit czasu przekroczony";
    //$tab[4][0]="ml"; $tab[4][1]="Limit pamięci przekroczony";
    echo '</select> Stan: <select name="res" onchange="document.form_status_submit.submit();">';
    for($i=0;$i<2;$i++) {
	if($tab[$i][0]==$_GET['res']) echo '<option selected="selected" value="'.$tab[$i][0].'">'.$tab[$i][1].'</option>';
	else echo '<option value="'.$tab[$i][0].'">'.$tab[$i][1].'</option>';
    }
    echo '</select></form>';
								    
    $zapytanie=mysqli_query($mysql,"SELECT id,login FROM users ORDER BY id ASC");
    if(!$zapytanie) {
        print("Pobranie uzytkownikow nie powiodlo sie\n");
	exit();
    }
    while(($row=mysqli_fetch_row($zapytanie))) $uzytkownicy[$row[0]]=$row[1];
    $zapytanie=mysqli_query($mysql,"SELECT ID,name FROM tasks ORDER BY ID ASC");
    if(!$zapytanie) {
	print("Pobranie zadan nie powiodlo sie\n");
	exit();
    }
    while(($row=mysqli_fetch_row($zapytanie))) $zadania[$row[0]]=$row[1];
    $zapytanie="FROM solutions WHERE `user ID`=$_SESSION[SESSION_USERID] ";
    if(!isEmpty($_GET['zadanie'])&&$_GET['zadanie']!="all") {
	$zapytanie=$zapytanie."AND `task ID`=$_GET[zadanie] ";
    } 
    if(!isEmpty($_GET['res'])&&$_GET['res']!="all") {
	$zapytanie=$zapytanie."AND result=100 ";
    }    
    $ilosc="SELECT COUNT(*) ".$zapytanie;
    $ilosc=mysqli_query($mysql,$ilosc);
    if(!$ilosc) {
	print("Nie udalo sie pobrac ilosci\n");
	exit();
    }
    $ilosc=mysqli_fetch_row($ilosc);
    $id=$ilosc[0];    
    if(od==-1) $zapytanie=$zapytanie."ORDER BY ID DESC LIMIT 10";
    else $zapytanie=$zapytanie."ORDER BY ID DESC LIMIT $od,10";
    //print $zapytanie;
    
    $zapytanie="SELECT * ".$zapytanie;
    $zapytanie=mysqli_query($mysql,$zapytanie);
    if(!$zapytanie) {
	print("Nie udalo sie pobrac zgloszen\n");
	exit();
    }
    print '<table><tr>
    <td align=left><a href=index.php?whereAmI=moje&od='.($od - 10).'';
    if(!isEmpty($_GET['zadanie'])) print '&zadanie='.$_GET['zadanie'].'';
    if(!isEmpty($_GET['res'])) print '&res='.$_GET['res'].'';
    print '>wstecz</a></td>
    <td align=center>';
    $x=($od+10)/10;
    $f=$x;
    if($x-5<=0) $x=6;
    $y=$x+5;
    if($y*10-10>$id) $y=($id+10)/10;
    for($i=$x-5,$j=(($x-5)*10-10);$i<$y;$i++,$j+=10){
	print '<a href=index.php?whereAmI=moje&od='.$j.'';
	if(!isEmpty($_GET['zadanie'])) print '&zadanie='.$_GET['zadanie'].'';
	if(!isEmpty($_GET['res'])) print '&res='.$_GET['res'].'';
	print '>';
	if($i==$f) print '<b>'.$f.'</b>';
	else print $i;
	print '</a> ';
    }
    echo'</td>
    <td align=right><a href=index.php?whereAmI=moje&od='.($od + 10).'';
    if(!isEmpty($_GET['zadanie'])) print '&zadanie='.$_GET['zadanie'].'';
    if(!isEmpty($_GET['res'])) print '&res='.$_GET['res'].'';
    print '>dalej</a></td>
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
    $i=0;
    while($row=mysqli_fetch_row($zapytanie)) {
	$i++;	
	$plik=fopen("./tasks/".$row[2]."/".$row[2].".conf","r");
	$tresc=fread($plik, filesize("./tasks/".$row[2]."/".$row[2].".conf"));
	fclose($plik);
	$ile=explode("\n",$tresc);
	$ilosc=$ile[0];
	if($row[5]!=NULL) {
	    @$plik=fopen("./solutions/".$row[0].".re","r");
	    @$tresc=fread($plik, filesize("./solutions/".$row[0].".re"));
	    @fclose($plik);
	    $testy=explode("\n",$tresc);
	    $zly=count($testy)-1;
	    $zly2=$zly;
	    $stan=1;
	    $ok=1;
	    $dobre=0;
	    for($j=0;$j<$zly2;$j++){
		$tmp=explode(" ",$testy[$j]);
		if($tmp[0]=="1") $dobre++;
		if($tmp[0]!="1"&&$ok==1){
		    $zly=$j;
		    $stan=$tmp[0];
		    $ok=0;
		}
	    }
	}
	else $stan=5;
	if($stan!=2&&count($testy)-1<$ilosc) $stan=5;
	if($stan==5) { //running
	    echo "<tr bgcolor=#d0a0a0>";
	}
	else if($stan!=1) { 
	    if($i%2==0) echo "<tr bgcolor=#f4f2f0>";
	    else echo "<tr bgcolor=#eceae8>";
	}
	else echo "<tr bgcolor=#d0f0d0>";
	if($zly==0&&$stan==5) $zly="-";
	echo "<td align=center>".$row[0]."</td><td align=center>";
	if($_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN||ownerOfSolution($row[0])==$_SESSION[SESSION_USERID])
	    echo "<a href=index.php?whereAmI=view&sol_id=".$row[0].">
		 <img src=system/img/report.gif border=0 width=10 height=15></a>";
	else echo "-";
	echo "</td><td align=center>";
	$data=date("Y-m-d",$row[3]);
	$czas22=date("H:i:s",$row[3]);
	echo $data."<br>".$czas22;
	echo "</td><td align=center>".$uzytkownicy[$row[1]]."</td>
	<td align=center><a href=index.php?whereAmI=tasks&Rdef=$row[2]>$row[2] - ".$zadania[$row[2]]."</a></td>
	<td align=center><a href=index.php?whereAmI=details&id=".$row[0].">".$zly."</a></td>
	<td align=center>".$row[5]."</td><td align=center>";
	echo "<a href=index.php?whereAmI=details&id=".$row[0].">";
	if($stan==1) echo "OK";
	else if($stan==0) echo "WA";
	else if($stan==3)echo "MEM";
	else if($stan==2)echo "COM";
	else if($stan==4) echo "TLE";
	else if($stan==5) echo "QUE";
	else echo "SYS";
	echo "</a>";
	echo "</td><td align=center>".$row[4]."</td><td align=center>".@filesize("./solutions/".$row[0].".cpp")."</td></tr>";
    }
    echo "</table>";
?>
