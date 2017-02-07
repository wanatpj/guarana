<?php
    include('bar.php');
    print '<hr>';
    if($_GET['me']=='addtask'){
	include('task_add.php');
    }
    else if($_GET['me']=='maketest'){
	include('make_test.php');
    }
    else if($_GET['me']=='cts'){
	include('cts.php');
    }
    else if($_GET['me']=='tests'){
	include('tests.php');
    }
    else if($_GET['me']=='rejudge'){
	include('rejudge.php');
    }
    else if($_GET['me']=='edytor'){
	include('task_edit.php');
    }
    else if($_GET['me']=='queue'){
	include('queue.php');
    }
    else if($_GET['me']=='users'){
	include('uzytkownicy.php');
    }
    else if($_GET['me']=='aQNA'){
	include('aQNA.php');
    }
    else if($_GET['me']=='demon'){
	include('demon.php');
    }
    else if($_GET['me']=='stan'){
	include('stan.php');
    }
    //else {print '<center><h1>Panel Admina</h1><img src=data/admin.jpg><br>Admin dzisiejszy.</center>';}
?>
