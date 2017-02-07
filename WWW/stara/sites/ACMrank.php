<?php
    class contestant{
	var $points;
	var $mtime;
	var $name;
	function contestant($a, $b, $c){
	    $this->points = $a;
	    $this->mtime = $b;
	    $this->name = $c;
	}
    }
    $cts = file('data/ac');
    $ncts = count($cts);
    for($i=0;$i<$ncts;$i++)
	$cts[$i]=trim($cts[$i]);
    print '<center><h3>Ranking</h3>';
    $rf = file('solutions/currentID');
    $n = (int)$rf[0];
    $k = numberOfTasks();
    for($i=1;$i<=$n;$i++){
	if(!file_exists('solutions/'.$i.'.dt'))
	    continue;
	$rf = file('solutions/'.$i.'.dt');
	if(is_active_task((int)$rf[0])==0||trim($rf[2])>$cts[1]||trim($rf[2])<$cts[0]) continue;
	for($j=0;$j<$k;$j++)
	    $rank[trim($rf[1])][$j]=0;
	$sort[trim($rf[1])] = new contestant(0,0,trim($rf[1]));
    }
    for($i=1;$i<=$n;$i++){
	if(!file_exists('solutions/'.$i.'.dt'))
	    continue;
	$rf = file('solutions/'.$i.'.dt');
	if(is_active_task((int)$rf[0])==0||trim($rf[2])>$cts[1]||trim($rf[2])<$cts[0]) continue;
	$pc = pointsToACMRank($i);
	$user_name = trim($rf[1]);
	if($rank[$user_name][trim($rf[0])]<$pc){
	    $rank[$user_name][trim($rf[0])] = $pc;
	    $sort[$user_name]->mtime += trim($rf[2])-$cts[0];
	}
    }
    if(count($sort)>0){
	foreach($sort as $arg => $val)
	    for($j=0;$j<$k;$j++){
		if(is_active_task((int)$rf[0])==1){
		    $sort[$arg]->points+=$rank[$arg][$j];
		    $sort[$arg]->mtime+=$cts[2]*nb_of_bombs($val->name, $j);
		}
	    }
	    rsort($sort);//tdc
	    $n = count($sort);
    }
    $mystring .= '<style>
    <!--
	.my2 {border: 1px solid #000;}
	.my2 td{background: #cccccc;}
	.my2 th{border: 1px solid #000;}
    -->
    </style>';
    $mystring .= '<table class="my2"><tr><th colspan="2"></th><td colspan="'.(nb_actived_tasks()).'">Zadanie (łącznie: '.nb_actived_tasks().')</td></tr><tr><td>Msc</td><td>Użytkownik</td>';
    for($i=0;$i<$k;$i++)
	if(is_active_task($i))
	    $mystring .= '<td>'.$i.'</td>';
    $mystring .= '<td>Suma:</td><th>Czas:</th></tr>';
    $cnt=1;
    if(count($sort)>0)
	foreach($sort as $arg => $val){
	    $mystring .= '<tr><td>'.$cnt.'</td><td>'.$val->name;
	    $cnt++;
	    for($j=0;$j<$k;$j++)
		if(is_active_task($j))
		    $mystring .= '</td><td>'.$rank[$val->name][$j];
	    $mystring .= '</td><td>'.$val->points.'</td><th>'.($val->mtime).'</th></tr>';
	}
    $mystring .= '</table>';
?>