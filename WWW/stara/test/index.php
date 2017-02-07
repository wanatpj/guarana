<?php
    session_start();
    if(isset($_POST[id])) {
	print "login: $_POST[login]<br>id: $_POST[id]";
	$_SESSION[SESSION_USERID]=$_POST[id];
	$_SESSION[SESSION_USER]=$_POST[login];
	$_SESSION[SESSION_MY_NAME]=true;
    }
    else print "nic nie dostalem :("
?>