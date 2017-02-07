<?php
	//TODO: Kolorowanie zadan zrobionych, linkowanie do tresci zadan i do submitowania
    if(!isEmpty($_GET['Rdef'])) {
	include("./tasks/$_GET[Rdef]/$_GET[Rdef].php");
    }
    else {
    $mysql=sqlConnect();
	$kategorie=mysqli_query($mysql,"SELECT summary FROM categories ORDER BY ID ASC");
	if(!$kategorie) {
		print("Pobranie kategorii nie powiodlo sie\n");
		exit();
	}
	$il_kategori=mysqli_num_rows($kategorie);
	for($i=0;($kat=mysqli_fetch_row($kategorie));$i++) {
		$skrot[$i]=$kat[0];
	}
	$tabela_user=mysqli_query($mysql,"SELECT id,login FROM users ORDER BY id ASC");
	if(!$tabela_user) {
		print("Pobranie uzytkownikow nie powiodlo sie\n");
		exit();
	}
	while(($row=mysqli_fetch_row($tabela_user)))
		$uzytkownicy[$row[0]]=$row[1];
	$zadania=mysqli_query($mysql,"SELECT `ID`,`name`,`from`,`author`,`date`,`category`,`active`,`tresc` FROM tasks ORDER BY ID DESC");
	if(!$zadania) {
		print("Zapytanie nie powiodlo sie\n");
		exit();
	}

	print("<table width=\"100%\">\n");
	print("<tr><td>ID:</td>\n
			<td>Nazwa:</td>\n
			<td>Żródło</td>\n
			<td>Dodał:</td>\n
			<td>Data:</td>\n
			<td>Kategoria:</td>\n
			<td>Wynik:</td>\n");
	while(($row = mysqli_fetch_row($zadania))) {
		if(($_SESSION[SESSION_PERMISSION]>=ADMIN && $row[6]>=1) || $row[6]>=2) {
			$zapytanie="SELECT `result` FROM `solutions` WHERE `user ID`=$_SESSION[SESSION_USERID] AND `task ID`=$row[0] ORDER BY `result` DESC";
			$wyniki=mysqli_query($mysql,$zapytanie);
			//print $zapytanie;
			if($best=mysqli_fetch_row($wyniki));
			else $best[0]=-1;
			print('<tr onMouseOver="this.style.opacity=0.8;" onMouseOut="this.style.opacity=1;"');
			if($best[0]==100) print ' style="background-color:#B9E6AF"';//rgb(100, 220, 0)"';//#B9E6AF";
			else if($best[0]!=-1) print ' style="background-color:#F2FFBF"';//rgb('.(250-$best).',220,150)"';//#F2FFBF";
			print(">");
			print("<td>".$row[0]."</td>\n");
			print("<td><a href=index.php?whereAmI=tasks&Rdef=$row[0]>".$row[1]."</a></td>\n");
			print("<td>".$row[2]."</td>\n");
			print("<td>".$uzytkownicy[$row[3]]."</td>\n");
			print("<td>".date("H:i, j M Y",$row[4])."</td>\n");
			print("<td>");
			$slash=0;
			$tasks_kat = explode(' ',$row[5]);
			foreach($tasks_kat as $tasks_kategoria) {
				if($slash==1) print("/");
				print($skrot[$tasks_kategoria-1]);
				$slash=1;
			}
			print("</td><td>");
			if($best[0]==-1) print "-";
			else print $best[0];
			print("</td></tr>\n");
		}
	}
	print("</table>\n");
	mysqli_close($mysql);
    }
?>
