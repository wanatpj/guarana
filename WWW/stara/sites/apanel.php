<?php
    include('sites/bar2.php');
    print '<hr>';
    if($_GET['me']=='addtask'){
	get_resource('index.php?whereAmI=apanel&me=addtask', 'tasks/', 'Zadania', 'hash_euyrc27c082q');
    }
    else if($_GET['me']=='maketest'){
	include('sites/make_test.php');
    }
    else if($_GET['me']=='cts'&&isContestOperator($_SESSION[SESSION_USER])){
	include('sites/cts.php');
    }
    else if($_GET['me']=='tests'&&isContestOperator($_SESSION[SESSION_USER])){
	include('sites/tests.php');
    }
    else if($_GET['me']=='rejudge'&&isContestOperator($_SESSION[SESSION_USER])){
	include('sites/rejudge.php');
    }
    else if($_GET['me']=='edytor'&&$_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN){
	include('sites/edytor.php');
    }
    else if($_GET['me']=='queue'&&isContestOperator($_SESSION[SESSION_USER])){
	include('sites/queue.php');
    }
    else if($_GET['me']=='users'&&$_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN){
	include('sites/uzytkownicy.php');
    }
    else if($_GET['me']=='demon'&&$_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN){
	include('sites/demon.php');
    }
    else if($_GET['me']=='stan'&&$_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN){
	include('sites/stan.php');
    }
    else if($_GET['me']=='todo'&&$_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN){
	include('sites/todo.php');
    }
    else if($_GET['me']=='QNA'){
	include('sites/aQNA.php');
    }
    else {print '<center><h1>Panel Admina</h1><img src=data/admin.jpg><br>Admin dzisiejszy.</center>';}
?>
