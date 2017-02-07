<?php
    ob_start();
    session_start();
    print '<center>';
    $mysqli = mysqli_connect($mhost, $muser, $mpass, $mbase);
    if(isset($_POST['OK'])){
	if(!isValid('db_value', $_POST['odp']));
	$odp = mysqli_real_escape_string($mysqli, $_POST['odp']);
	mysqli_query($mysqli, "UPDATE QNA SET A='".$odp."' WHERE id='".$_POST['nr']."'");
	mysqli_close($mysqli);
	header('Location: index.php?whereAmI=apanel&me=aQNA');
	exit();
    }
    if(isset($_POST['bye'])){
	mysqli_query($mysqli, "DELETE FROM QNA WHERE id='".$_POST['nr']."'");
	mysqli_close($mysqli);
	header('Location: index.php?whereAmI=apanel&me=aQNA');
	exit();
    }
    print '<table><tr><td style="border: 1px solid #000;">Pytanie</td><td style="border: 1px solid #000;">Odpowiedź</td><td style="border: 1px solid #000;">Zadanie</td><td style="border: 1px solid #000;">Akcja</td></tr>';
    $zapytanie = "SELECT * FROM QNA";
    $wynik = mysqli_query($mysqli, $zapytanie);
    while($row = mysqli_fetch_row($wynik)){
	print '<tr><td>'.nl2br(htmlspecialchars($row[1])).'</td><form action="" method="POST">
	<input type="hidden" name="nr" value="'.$row[0].'"><td>';
	if(!empty($row[2]))
	    print $row[2].'</td><td>'.(empty($row[3])?'Techniczne':$row[3]).'</td><td>';
	else print '
	    <textarea name="odp" cols="10" rows="3">W treści</textarea>
	    </td><td>'.(empty($row[3])?'Techniczne':$row[3]).'</td><td>
	    <input type="submit" value="Odpowiedz" name="OK">
	';
	print '<input type="submit" value="Usuń" name="bye"></form></td></tr>';
    }
    print '</table></center>';
    mysqli_close($mysqli);
    ob_end_flush();
?>