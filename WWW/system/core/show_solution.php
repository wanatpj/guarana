<?php
    $submitID=$_GET['sol_id'];
    if($_SESSION[SESSION_PERMISSION]<HEAD_ADMIN&&$_SESSION[SESSION_USERID]!=ownerOfSolution($sol_id))
	exit('Nie masz uprawnień do przeglądania tego kodu.');
    $mysql=sqlConnect();
    $zapytanie="SELECT `user ID`, `date`, `task ID` FROM `solutions` WHERE `ID`=$submitID";
    $wynik=mysqli_query($mysql,$zapytanie);
    if(!$wynik){
	print "Błąd";
	exit;
    }
    $wiersz=mysqli_fetch_row($wynik);
    $taskID=$wiersz[2];
    print '<div style="border: 1px solid #000;">';
    print '<table width=100%><tr><td>ID zgłoszenia: '
    .$submitID.
    '</td><td>zadanie: <i>'.$taskID
    .'. '.
    nameOfTask($taskID)
    .'</i></td><td>autor: '.nameOfUser($wiersz[0]).'</td><td>data: '.date('jS F Y H:i:s',$wiersz[1]).'</td></tr></table>';
    print '</div>';
    if(!isset($_GET['noline'])){
	print '<a href="index.php?whereAmI=view&sol_id='.$submitID.'&noline=1">Pokaż bez numerów wierszy</a>';
	print '<div style="border: 1px solid #000;"><ol type="1"><pre>';
	$rf = file('solutions/'.$submitID.'.cpp');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    print '<li>'.htmlspecialchars($rf[$i]);
	print '</pre></ol></div>';
    }
    else {
	print '<a href="index.php?whereAmI=view&sol_id='.$submitID.'">Pokaż z numerami wierszy</a>';
	print '<div style="border: 1px solid #000;"><table CELLPADDING="10"><tr><td><pre>';
	print htmlspecialchars(file_get_contents('solutions/'.$submitID.'.cpp'));
	print '</pre></td></tr></table></div>';
    }
?>