<?php
    $mysql=sqlConnect();
	if($_SESSION[SESSION_PERMISSION]>=ADMIN && isset($_POST["news"])) {
		$tresc_query = 'INSERT INTO news (`user ID`,`time`,`active`,`tresc`) VALUES ('.
				mysqli_real_escape_string($mysql,$_SESSION[SESSION_USERID]).','
				.time().',1,\''.
				mysqli_real_escape_string($mysql,$_POST["news"]).'\')';
		$zapytanie=mysqli_query($mysql,$tresc_query);
		if(!$zapytanie) {
			print("Zapytanie nie powiodlo sie\n");
			exit();
		}
	}
	else if($_SESSION[SESSION_PERMISSION]>=ADMIN && isset($_POST["hide"])){
	    $query = "UPDATE `news` SET `active`=0 WHERE `ID`=".$_POST['##_hidden'];
	    mysqli_query($mysql, $query);
	    if(!$query) exit('Zapytanie nie powiodło się.');
	}
	if($_SESSION[SESSION_PERMISSION]>=ADMIN) {
		print('<form action="index.php?whereAmI=home" method="post">
				<textarea name="news" rows="5" cols="50"></textarea><br/>
				<input type="submit" value="Submit">
				</form>');
	}
	$zapytanie=mysqli_query($mysql,"SELECT `user ID`,`time`,`tresc`,`active`,`ID` FROM news WHERE `active`=1 ORDER BY ID DESC LIMIT 0,10");
	if(!$zapytanie) {
		print("Zapytanie nie powiodlo sie\n");
		exit();
	}
	print '<table border="1">';
	while(($row=mysqli_fetch_row($zapytanie))) {
		print '<tr>';
		if($_SESSION[SESSION_PERMISSION]>=ADMIN)
		    print '<td><form action="" method="POST"><input type="hidden" name="##_hidden" value="'.$row[4].'">
		    <input type="submit" value="Hide" name="hide"></form></td>';
		print '<td><div style="float: right; border: 1px solid #000;">Dodał '.nameofUser($row[0]).' '.date("H:i, j M Y",$row[1]).'</div>'.$row[2].'</td></tr>';
	}
	print '</table>';
	mysqli_close($mysql);
?>
