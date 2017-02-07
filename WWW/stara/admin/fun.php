<?PHP
    function used($x)
    {
	    $s="users.txt";
	    $t="a+";
	    $d=fopen($s, $t);
	    flock($d,2);
	    $u=-1;
	    $i=0;
	    while(true)
	    {
		$l=fgets($d);
		if($l===false) break;
		$u=strpos($l, $x);
		if($u!==false)
		{
		    $u=$i;
		    break;
		}
		$i++;
	    }
	    flock($d,3);
	    fclose($d);
	    if($u!=-1) return $u;
	    else return false;
    }
?>