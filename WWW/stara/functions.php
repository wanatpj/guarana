<?php
//    function formatDateToACM($mtime){
//	$s=$mtime%60;
//	$mtime=(int)($mtime/60);
//	$m=$mtime%60;
//	$mtime
//    }
    function isValid($type, $var)
    {
        $valid=false;
	switch($type)
	{
	      case "login":
	      if(ereg("^[a-zA-Z0-9_]{3,30}$",$var)) $valid=true;
	      break;
	      case "pass":
	      if(ereg("^[a-zA-Z0-9_]{6,30}$",$var)) $valid=true;
	      break;
	      case "email":
	      if(ereg("^[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+.[a-zA-Z]$",$var)&&strlen($var)<40) $valid=true;
              break;
	      case "gg":
              if(ereg("^[0-9]{1,20}$",$var)) $valid=true;
              break;
         }
         return $valid;
     }
    function isContestOperator($user){
	$rf = file('data/contestOperators');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    if($user==trim($rf[$i]))
		return true;
	return false;
    }
    function isCreatorOfRanks($user){
	$rf = file('data/creatorsOfRanks');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    if($user==trim($rf[$i]))
		return true;
	return false;
    }
    function make_enter_on_the_EOF($file){
	$rf = file_get_contents($file);
	$rf = trim($rf)."\n";
	make_a_file_with($file, $rf);
    }
    function cutText($text, $nb){
	$n = min(strlen($text), $nb);
	$res = '';
	for($i=0;$i<$n;$i++)
	    $res.=$text[$i];
	return $res;
    }
    function is_active_task($task_id){
	$rf = file('tasks/.active');
	return (int)$rf[$task_id];
    }
    function owner_of_sol($solId){
	$rf = file('solutions/'.$solId.'.dt');
	return trim($rf[1]);
    }
    function pointsToACMRank($solId){
	if(!file_exists('solutions/'.$solId.'.re'))
	    return 0;
	$rf = file('solutions/'.$solId.'.re');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    $rf[$i]=explode(' ', $rf[$i]);
	$cnt=0;
	for($i=0;$i<$n;$i++)
	    if($rf[$i][0]=='1')
		$cnt++;
	if($cnt==$n)
	    return 1;
	return 0;
    }
    function nb_of_bombs($user, $task){
	$cts = file('data/ac');
	$ncts = count($cts);
	for($i=0;$i<$n;$i++)
	    $cts[$i]=trim($cts[$i]);
	$rf = file('solutions/currentID');
	$rf = trim($rf[0]);
	$cnt=0;
	$myb = true;
	for($i=0;$i<$rf;$i++){
	    $dt = file('solutions/'.($i+1).'.dt');
	    if(trim($dt[0])==$task&&trim($dt[1])==$user&&$cts[0]<=trim($dt[2])&&trim($dt[2])<=$cts[1]){
		if(pointsToACMRank($i+1)==0&&$myb)
		    $cnt++;
		else $myb=false;
	    }
	}
	if($myb)
	    return 0;
	return $cnt;
    }
    function pointsToRank($solId){
	if(!file_exists('solutions/'.$solId.'.re'))
	    return 0;
	$rf = file('solutions/'.$solId.'.re');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    $rf[$i]=explode(' ', $rf[$i]);
	$cnt=0;
	for($i=0;$i<$n;$i++)
	    if($rf[$i][0]=='1')
		$cnt++;
	return (int)(100*pow($cnt/$n, sqrt(3)));
    }
    function isLinksOperator($user){
	$rf = file('data/operatorsOfLinks');
	$n = count($rf);
	for($i=0;$i<$n;$i++)
	    if(trim($rf[$i])==$user)
		return true;
	return false;
    }
    function numberOfTasks(){
	$rf = file('tasks/.hashes');
	return count($rf);
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
    function get_name_of_task($task_id){
	$hash = getHashOfTask('tasks/', $task_id);
	$rf = file('tasks/'.$hash.'.dt');
	return trim($rf[0]);
    }
    function permission($user){//en to check
	$rf = file('kat/'.$user.'/user');
	return (int)$rf[1];
    }
    function nb_actived_tasks(){//etc
	$cnt=0;
	$n = numberOfTasks();
	for($i=0;$i<$n;$i++)
	    if(is_active_task($i)) $cnt++;
	return $cnt;
    }
    function userDeleteTask($user, $task){
	if(!file_exists('kat/'.$user.'/zad'))
	    return;
	$rf = file('kat/'.$user.'/zad');
	$rf = explode(' ', trim($rf[0]));
	$n = count($rf);
	$str='';
	for($i=0;$i<$n;$i++)
	    if($rf[$i]!=$task){
		$str.=$rf[$i].' ';
	    }
	make_a_file_with('kat/'.$user.'/zad', trim($str)."\n");
    }
//    function get_txtfile_par($taskID){
//	$hash = getHashOfTask($taskID);
//	
//    }
?>
