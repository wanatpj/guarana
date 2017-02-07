<?php
    print '<style><!--
	.my {border: 1px solid #000;}
	.my td {background: #cccccc;}
    --></style>';
    if(isset($_GET['what'])){
	$file = '<pre>';
	$id = $_GET['id'];
	$id_sol = $_GET['id_sol'];
	$rf = file('tasks/'.$id.'/'.$id.'.conf');
	$rf = explode(' ', $rf[$id_sol+1]);
	$file .= file_get_contents($rf[0+$_GET['what']]);
	$file .= '</pre>';
	print $file;
	exit();
    }
    print '<div style="float: right;"><a href="index.php?whereAmI=tests">Czyść stronę.</a></div>';
    if(isset($_GET['what'])){
	$file = '<pre>';
	$id = $_GET['id'];
	$id_sol = $_GET['id_sol'];
	$rf = file('tasks/'.$id.'/'.$id.'.conf');
	$rf = explode(' ', $rf[$id_sol+1]);
	$file .= file_get_contents($rf[0+$_GET['what']]);
	$file .= '</pre>';
	print $file;
	exit();
    }
    if(isset($_GET['nb'])){
	$n = numberOfTasks();
	print '<table class="my"><tr><td>Zadanie</td><td>Ilość testów.</td></tr>';
	for($i=0;$i<$n;$i++)
	    print '<tr><td>'.$i.' - '.get_name_of_task($i).'</td><td>'.(count(file('tasks/'.$i.'/'.$i.'.conf'))-1).'</td></tr>';
	print '</table>';
    }
    print '
	<a href="index.php?whereAmI=apanel&me=tests&nb=1">Pokaż ilości testów</a><hr>';
    if(!empty($_POST['zadanie'])){
	$z = $_POST['zadanie'] - 1;
	print 'Zadanie: '.$z.' - '.get_name_of_task($z);
	$rf = file('tasks/'.$z.'/'.$z.'.conf');
	$n = (int)$rf[0];
	for($i=1;$i<=$n;$i++)
	    $rf[$i]=explode(' ', $rf[$i]);
	print '<table class="my"><tr><td>IN:</td><td>OUT:</td><td>time</td><td>MEM</td></tr>';
	for($i=0;$i<$n;$i++){
	    $in = nl2br(file_get_contents($rf[$i+1][0]));
	    $out = nl2br(file_get_contents($rf[$i+1][1]));
	    print '<tr><td>';//.cutText($in, 500);
	    if(strlen($in)<500)
		print $in;
	    else print '<a href="index.php?whereAmI=apanel&me=tests&what=0&id='.$z.'&id_sol='.$i.'">Zobacz</a>';
	    print '</td><td>';//.cutText($out, 500).
	    if(strlen($out)<500)
		print $out;
	    else print '<a href="index.php?whereAmI=apanel&me=tests&what=1&id='.$z.'&id_sol='.$i.'">Zobacz</a>';
	    print '</td><td>'.$rf[$i+1][2].'</td><td>'.$rf[$i+1][3].'</td><tr/>';
	}
	print '</table>';
    }
    $n = numberOfTasks();
    print '
	<form action="index.php?whereAmI=apanel&me=tests" method="post">
	Wybierz zadanie: <select name="zadanie"><option value=""></option>';
    for($i=0;$i<$n;$i++)
	print '<option value="'.($i+1).'">Zadanie '.$i.' - '.get_name_of_task($i).'</option>';
    print '</select>
	<input type="submit" value="Pokaż testy">
	</form>
    ';
?>