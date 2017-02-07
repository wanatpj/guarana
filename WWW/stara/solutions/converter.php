<?php
include("/home/guarana/WWW/system/core/functions.php");

function parseresult($nr, &$query) {
	$handle=fopen($nr.'.re',"r");
	if(!$handle) return 0;
	$il=0;
	$wynik=0;
	$time=0;
	while(!feof($handle)) {
		$row=fgets($handle);
		$row=trim($row);
		if($row==="")
			continue;
		$rzad=explode(" ",$row);
		if($rzad[0]==1) $wynik+=1;
		$time+=(int)$rzad[1];
		$il++;
	}
	$query.=$time.',';
	$query.=(int)(((double)$wynik/(double)$il)*100).')';
	if(!is_numeric($time) || !is_numeric($wynik)) return 0;
	return 1;
}

function parsedt($nr, &$query, $mysql) {
	$handle=fopen($nr.'.dt',"r");
	if(!$handle) {
		printf("Bug: %d\n", $nr);
		return 0;
	}
	$task=trim(fgets($handle));
	$user=trim(fgets($handle));
	$time=trim(fgets($handle));
	if(!is_numeric($task) || $user==="" || !is_numeric($time))
		return 0;
	if(idOfUser(mysqli_real_escape_string($mysql,$user))==-1)
		return 0;
	$query.=idOfUser(mysqli_real_escape_string($mysql,$user)).',';
	$query.=$task.',';
	$query.=$time.',';
	if($task==0) return 0;
	return 1;
}

$next=1;
$il=1;

function copyfiles($nr) {
	global $next;
	system('cp '.$nr.'.cpp /home/guarana/WWW/solutions/'.$next.'.cpp');
	system('cp '.$nr.'.re  /home/guarana/WWW/solutions/'.$next.'.re');
	$next++;
}

function handlesol($nr) {
	$query="INSERT INTO solutions (`user ID`,`task ID`,date,time,result) VALUES (";
	$mysql=sqlConnect();
	if(!parsedt($nr,$query,$mysql)) return;
	if(!parseresult($nr,$query)) return;
	copyfiles($nr);
	//printf("%s\n", $query);
	global $il;
	$il++;
	$result = mysqli_query($mysql,$query);
	if(!$result) print $nr;
}

//handlesol(142);
for($i=1;$i<=1142;$i++) handlesol($i);
print($next." ".$il);
?>
