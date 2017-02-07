<?php
    $mysql=sqlConnect();
	$zapytanie=mysqli_query($mysql,"SELECT * FROM queue LIMIT 0,30");
	if(!$zapytanie) {
		print("Zapytanie nie powiodlo sie\n");
		exit();
	}
	print('<center>Ilość zgłoszeń aktualnie w kolejce: '.mysqli_num_rows($zapytanie)."\n");
	print('<table border="1">');
	while(($row=mysqli_fetch_row($zapytanie))) {
		$szczegoly=mysqli_query($mysql,"SELECT * FROM solutions WHERE ID=".mysqli_real_escape_string($mysql,$row[0]));
		if(mysqli_num_rows($szczegoly)!=1) {
			exit("Blad\n");
		}
		$szczegoly=mysqli_fetch_row($szczegoly);
		print('<tr><td>'.$row[0].'</td><td>'.nameofUser($szczegoly[1]).'('.$szczegoly[1].')</td>
				<td>'.nameofTask($row[1]).'('.$row[1].')</td><td>'.date("H:i, j M Y",$szczegoly[3]).'</td></tr>'."\n");
	}
	print( '</table></center>');
?>
