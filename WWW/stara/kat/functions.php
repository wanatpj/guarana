<?php
    //const.php must be included
    function user_exists($user){
	$u = file('data/users');
	$n = count($u);
	for($i=0;$i<$n;$i++)
	    if($user==trim($u[$i]))
		return true;
	return false;
    }
    function check_pass($user, $passwd){
	$rf = file('kat/'.$user.'/user');
	if(trim($rf[0])==$passwd)
	    return true;
	return false;
    }
    function permission($user){
	$rf = file('kat/'.$user.'/user');
	return (int)$rf[1];
    }
?>