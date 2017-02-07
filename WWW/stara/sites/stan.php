<?php
    echo "<b>Stan serwera: </b><br>";
    echo "<pre>";
    $tab=shell_exec("w");
    echo $tab;
    echo "</pre>";
    echo "<b>Stan procesów: </b><br>";
    echo "<pre>";
    $tab=shell_exec("ps -A");
    echo $tab;
    echo "</pre>";
    echo "<b>Stan dysku serwera: </b><br>";
    echo "<pre>";
    $tab=shell_exec("df -hP");
    echo $tab;
    echo "</pre>";
    echo "<b>Stan użycia dysku i limit: </b><br>";
    echo "<pre>";
    $tab=shell_exec("quota");
    echo $tab;
    echo "</pre>";    
    echo "<b>Wersja g++: </b>";
    $tab=shell_exec("g++ -dumpversion");
    echo $tab;
?>