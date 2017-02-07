<?php
    //1000000000000000 to define
    $rf = file('data/ac');
    $x = time()-trim($rf[0]);
    $y = trim($rf[1]);
    if($y<time()||$rf[1]==1000000000000000){
	if($rf[1]==1000000000000000)
	    print 'Zawody Stałe dostępne | ';
	else print 'Zawody Stałe niedostępne. | ';
	print '<font color="green">Konkurs zakończony</font> | ';
	print '<a href="index.php?whereAmI=apanel&me=cts&shutdown=true">Usuń konkurs.</a>';
    }
    else {
        print 'Konkurs trwa od: ';
	$s = $x%60;
	$x = (int)($x/60);
	$m = $x%60;
	$x = (int)($x/60);
	$h = $x%24;
	$x = (int)($x/24);
	print $x.' dni '.$h.'h '.$m.'m '.$s.'s<br>';
	print 'i potrwa jeszcze: ';
	print '('.$y.'s) ';
	$x=$y-time();
	$s = $x%60;
	$x = (int)($x/60);
	$m = $x%60;
	$x = (int)($x/60);
	$h = $x%24;
	$x = (int)($x/24);
	print $x.' dni '.$h.'h '.$m.'m '.$s.'s<br>';
    }
    print '
	<div style="border: 1px solid #000; width: 450;">
	<form action="" method="post">
	Czas trwania konkursu:<br><table><tr><td style="border: 1px solid #000;">
	<input type="text" name="dni" size="10" value="0">dni<br>
	<input type="text" name="h" size="10" value="0">godzin<br>
	<input type="text" name="m" size="10" value="0">minut<br>
	<input type="text" name="s" size="10" value="0">sekund<br>
	</td><td style="border: 1px solid #000;"><table><tr><td>Wartość bomby: </td><td>
	<input type="text" name="bdni" size="10" value="0">dni<br>
	<input type="text" name="bh" size="10" value="0">godzin<br>
	<input type="text" name="bm" size="10" value="0">minut<br>
	<input type="text" name="bs" size="10" value="0">sekund<br>
	</td></tr></table>
	<td><table><tr><td></td><><></tr></table></td>
	</td></tr></table>
	<input type="submit" name="button1" value="Rozpocznij nowy konkurs.">'.(!($y<time()||$rf[1]==1000000000000000)?'<font color="red">UWAGA!</font> Istnieje trwający konkurs.':'').'
	</form>
	</div>
    ';
    if(isset($_GET['shutdown'])){
	make_a_file_with('data/ac', "0\n1000000000000000\n0");
	header('Location: index.php?whereAmI=apanel&me=cts');
	exit();
    }
    if(isset($_POST['button1'])){
	make_a_file_with('data/ac', time()."\n".(time()+60*(60*(24*$_POST['dni']+$_POST['h'])+$_POST['m'])+$_POST['s'])."\n".(60*(60*(24*$_POST['bdni']+$_POST['bh'])+$_POST['bm'])+$_POST['bs']));
	header('Location: index.php?whereAmI=apanel&me=cts');
	exit();
    }
?>