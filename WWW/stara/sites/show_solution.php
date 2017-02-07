<?php
    $sol_id = $_GET['sol_id'];
    if($_SESSION[SESSION_PERMISSION]<HEAD_ADMIN&&$_SESSION[SESSION_USER]!=owner_of_sol($sol_id))
	exit('Nie masz uprawnień do przeglądania tego kodu.');
    $rf = file('solutions/'.$sol_id.'.dt');
    print '<div style="border: 1px solid #000;">';
    print '<table width=100%><tr><td>submit id: '
    .$sol_id.
    '</td><td><i>'.trim($rf[0])
    .'. '.
    get_name_of_task((int)trim($rf[0]))
    .'</i></td><td>by: '.$rf[1].'</td><td>date: '.$rf[2].'</td></tr></table>';
    print '</div>';
    if(!isset($noline)){
	print '<a href="index.php?whereAmI=view&sol_id='.$sol_id.'&noline=1">Pokaż bez numerów wierszy.</a>';
	print '<div style="border: 1px solid #000;"><ol type="1"><pre>';
	$rf = file('solutions/'.$sol_id.'.cpp');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    print '<li>'.htmlspecialchars($rf[$i]);
	print '</pre></ol></div>';
    }
    else {
	print '<a href="index.php?whereAmI=view&sol_id='.$sol_id.'">Pokaż z numerami wierszy.</a>';
	print '<div style="border: 1px solid #000;"><pre>';
	print htmlspecialchars(file_get_contents('solutions/'.$sol_id.'.cpp'));
	print '</pre></div>';
    }
?>