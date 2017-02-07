<?php
    if(isset($_POST['co']))
    {
	if($_POST['co']=="zabic")
	{
	    echo shell_exec("killall demon");
	    echo shell_exec("killall screen");
	    $tab=shell_exec("ps -A | grep demon");
	    $dokilla=explode("\n",$tab);
	    for($i=0;$i<sizeof($dokilla);$i++)
	    {
		$dobicia=explode(" ",$dokilla[$i]);
		echo shell_exec("kill -9 ".$dobicia[0]);
		echo shell_exec("kill -9 ".$dobicia[1]);
		echo "Killuje ".$dobicia[0]."<br>";
	    }
	    echo "<br>Demon został unicestwiony!";
	}
	else
	{
	    echo shell_exec("./bin/sdemon");
	    echo "<br>Demon został włączony!";
	}
    }
    else
    {
    $tab=shell_exec("ps -A | grep demon");
    if(empty($tab))
    { 
	echo "Demon jest wyłączony.";
	echo '	<br><br>
		<form action="index.php?whereAmI=apanel&me=demon" method="POST">
		<input type=hidden name=co value=zeslac>
		<input type=submit value="Ześlij DEMONA!!!">
	    </form>';
    }
    else
    { 
	echo $tab;
	echo '	<br><br>
		<form action="index.php?whereAmI=apanel&me=demon" method="POST">
		<input type=hidden name=co value=zabic>
		<input type=submit value="Zabij DEMONA!!!">
	    </form>';
    }
    }
?>