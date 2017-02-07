<?php
    if(isset($_POST['zadane'])){
	if(strlen($_POST['pytanie'])<=500){
	    $n = count(file('QNA/.inf'));
	    while(file_exists('QNA/'.$n)) ++$n;
	    make_a_file_with('QNA/'.$n, '[by '.$_SESSION[SESSION_USER].'] '.trim($_POST['pytanie']));
	    add_to_file('QNA/.inf', $n."\n");
	}
	header('Location: index.php?whereAmI=QNA');
	exit();
    }
    else if($_GET['zadaj']=='OK'){
	print '<form action="" method="post">
	    <textarea name="pytanie" cols="100" rows="8"></textarea><br>
	    <input type="submit" name="zadane" value="Zadaj pytanie.">
	</form>';
    }
    else{
	print '<center><a href="?whereAmI=QNA&zadaj=OK">Zadaj pytanie.</a>';
	$rf = file('QNA/.inf');
	$n = count($rf);
	print '<table><tr><td style="border: 1px solid #000;">Pytanie</td><td style="border: 1px solid #000;">Odpowiedź</td></tr>';
	for($i=0;$i<$n;++$i){
	    print '<tr><td>';
	    print file_get_contents('QNA/'.trim($rf[$i]));
	    print '</td><td>';
	    if(file_exists('QNA/'.trim($rf[$i]).'.r'))
		print file_get_contents('QNA/'.trim($rf[$i]).'.r');
	    else print '<font color="red">Oczekiwanie na odpowiedź!</font>';
	    print '</td></tr>';
	}
	print '</table></center>';
    }
?>