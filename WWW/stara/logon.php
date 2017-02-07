<?php
    ob_start();
    session_start();
    unset($_SESSION);
    session_destroy();
    session_start();
    include('const.php');
    include('kat/functions.php');
    $user = trim($_POST['user']);
    $passwd = md5($_POST['passwd']);
    if(user_exists($user)&&check_pass($user, $passwd)){
	$_SESSION[SESSION_USER]=$user;
	$_SESSION[SESSION_PERMISSION]=permission($user);
	$_SESSION[SESSION_MY_NAME]=true;
    }
    header('Location: index.php');
    exit();
    ob_end_flush();
?>