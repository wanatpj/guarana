<?php
    $QNA_WARNING = "Błąd połączenia z baza danych.";
    if(isset($_POST['zadane'])){print $_POST['pytanie'];
	if($_POST['topic']=='') exit('Nie wybrano rodzaju pytania!');
	if(empty($_POST['pytanie'])) exit('Puste pytanie!');
	if(!isValid('db_value', $_POST['pytanie'])) exit('Zły format pytania lub przekroczony limit znaków! (200)');
	$mysqli = mysqli_connect($mhost, $muser, $mpass, $mbase);
	$pytanie = mysqli_real_escape_string($mysqli, $_POST['pytanie']);
	if(!$mysqli) print QNA_WARNING;
	if($_POST['topic']=='tech') {
	    $zapytanie = "INSERT INTO QNA (Q) VALUES ('$pytanie')";
	}
	else $zapytanie = "INSERT INTO QNA (Q,zad) VALUES ('$pytanie', '".$_POST['topic']."')";
	mysqli_query($mysqli, $zapytanie);
	mysqli_close($mysqli);
	header('Location: index.php?whereAmI=QNA');
	exit();
    }
    else if($_GET['zadaj']=='OK'){
	print '<form action="" method="post">
	    <textarea name="pytanie" cols="100" rows="8"></textarea><br>
	    <select name="topic">
	    <option value=""></option>
	    <option value="tech">Techniczne</option>
	    ';
	$mysqli = mysqli_connect($mhost, $muser, $mpass, $mbase);
	if(!$mysqli) print $QNA_WARNING;
	$wynik = mysqli_query($mysqli, "SELECT ID, name FROM tasks WHERE active=2");
	while($row = mysqli_fetch_row($wynik))
	    print '<option value="'.$row[0].'">'.$row[0].'. '.$row[1].'</option>';
	print '
	    </select><br>
	    <input type="submit" name="zadane" value="Zadaj pytanie.">
	</form>';
	mysqli_close($mysqli);
    }
    else{
	print '<center><a href="?whereAmI=QNA&zadaj=OK">Zadaj pytanie.</a>';
	print '<table border="1"><tr><td style="border: 1px solid #000;">Pytanie</td><td style="border: 1px solid #000;">Odpowiedź</td><td style="border: 1px solid #000;">Zadanie</td></tr>';
	$mysqli = mysqli_connect($mhost, $muser, $mpass, $mbase);
	if(!$mysqli) print '<h2>'.$QNA_WARNING.'</h2>';
	$zapytanie = "SELECT Q, A, zad FROM QNA";
	$wynik = mysqli_query($mysqli, $zapytanie);
	while($row = mysqli_fetch_row($wynik))
	    print '<tr><td>'.nl2br(htmlspecialchars($row[0])).'</td><td>'.(empty($row[1])?'<font color="red">Oczekiwanie na odpowiedź</font>':'<font color="green">'.nl2br($row[1]).'</font>').'</td><td>'.(empty($row[2])?'tech':$row[2]).'</td></tr>';
	print '</table></center>';
	mysqli_close($mysqli);
    }
?>
