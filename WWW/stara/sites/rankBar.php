<?php
    print '<center><a href="index.php?whereAmI=ranking">Zawody Stałe</a> |';//add 'Zawody Stałe' to const.php
//    print ' <a href="index.php?whereAmI=ranking&kind=acm">ACM</a> ';
    $rf = file('ranks/.names');
    $n = count($rf);
    for($i=0;$i<$n;$i++)
	print '| <a href="index.php?whereAmI=ranking&nb='.$i.'">'.$rf[$i].'</a>';
    print '</center>'
?>