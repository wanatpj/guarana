<?php
    $n = file('solutions/currentID');
    $n = (int)$n[0];
    print '<table cellspacing=1 style={tr:hover td {background-color: #afa}}><tr></tr>';
    for($i=$n;$i>=0;$i++)
	if(file_exists('solutions/'.$i.'.cpp')){
	    $rf = file('solutions/'.$i.'.dt');
	    $n = count($rf);
	    print '<tr><td>'.$i.'</td>';
	    for($j=0;$j<$n;$j++)
		print '<td>'.trim($rf[$j]).'</td>';
	    print '</tr>
	    ';
	}
?>