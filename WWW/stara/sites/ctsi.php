<?php
    $rf = file('data/ac');
    $x = trim($rf[2]);
    print 'Rozpoczęcie: '.date(DATE_FORMAT, trim($rf[0])).'<br>';
    print 'Zakończenie: '.date(DATE_FORMAT, trim($rf[1])).'<br>';
    print 'Wartość bomby: '.(int)($x/3600).'h '.(((int)($x/60))%60).'m '.($x%60).'s';
?>