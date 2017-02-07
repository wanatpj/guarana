<?php
    function numberOfTasks(){
	$rf = file('tasks/.nr');
	return (int)$rf[0];
    }
    function kindsOfTask($taskID){
	$hash = getHashOfTask($taskID);
	$rf = file('tasks/'.$hash.'.kot');
	$rf = trim($rf[0]);
	$kot = file('data/kindsOfTasks');
	$n = count($kot);
	for($i=0;2*$i<$n;$i++)
	    if(1==(int)$rf[$i])
		$res[$i]=$kot[2*$i+1];
	return $res;
    }
//    function get_txtfile_par($taskID){
//	$hash = getHashOfTask($taskID);
//	
//    }
?>