<?php
    $plik=fopen("tasks/.hashes","r");
    $tresc=fread($plik, filesize("tasks/.hashes"));
    fclose($plik);
    $tab=explode("\n",$tresc);
    $plik=fopen("tasks/.active","r");
    $tresc=fread($plik, filesize("tasks/.active"));
    fclose($plik);
    $tab2=explode("\n",$tresc);
    if($_GET['akt']!="")
    {
	$tab2[$_GET['akt']]=($tab2[$_GET['akt']]+1)%2;
	$plik=fopen("tasks/.active","w");
	for($i=0;$i<numberOfTasks();$i++)
	fwrite($plik, $tab2[$i]."\n");
	fclose($plik);
    }
    echo "<center><table border=1><tr>
    <td align=center>ID</td>
    <td align=center>Nazwa</td>
    <td align=center>Aktywne</td>
    <td align=center>Edycja treści</td>
    <td align=center>Edycja komentarzy</td>
    <td align=center>Edycja danych</td>
    <td align=center>Edycja conf</td></tr>";
    for($i=0;$i<numberOfTasks();$i++)
    {
	echo "	<tr><td aling=center>$i</td><td>".get_name_of_task($i)."</td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&akt=$i>$tab2[$i]</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=$i>click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=$i.com>click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=$i.dt>click</a></td>
		<td align=center><a href=index.php?whereAmI=apanel&me=edytor&co=edycja&url=$i.conf>click</a></td></tr>";

    }
    echo "</table><br><br>";
    if(isset($_GET['co']))
    {
       	    if(isset($_GET['url'])&&isset($_POST['pole']))
	    {
		$typ=explode(".",$_GET['url']);
		if($typ[1]=="conf") $url="tasks/".$typ[0]."/".$typ[0].".conf";
		else if($typ[1]!="") $url="tasks/".$tab[$typ[0]].".".$typ[1];
		else $url="tasks/".$tab[$typ[0]];
		$_POST['pole']=ereg_replace("\r","",$_POST['pole']);
		$_POST['pole']=stripcslashes($_POST['pole']);
		$site=fopen($url, "w");
		flock($site,2);
		fwrite($site, $_POST['pole']);
		flock($site,3);
		fclose($site);
		if(strpos($url, '.htm')===false&&strpos($url, '.html')===false)
		{
			echo "Plik został zapisany z chmod: 700.";
			chmod($url, 0700);
		}
		else
		{	 	
			echo "Plik został zapisany z chmod: 705.";
			chmod($url, 0705);
		}
	    }
	    elseif(!isset($_GET['url']))
	    {
		echo "Nic do roboty.";
	    }					    
	    else
	    {
		$typ=explode(".",$_GET['url']);
		if($typ[1]=="conf") $url="tasks/".$typ[0]."/".$typ[0].".conf";
		else if($typ[1]!="") $url="tasks/".$tab[$typ[0]].".".$typ[1];
		else $url="tasks/".$tab[$typ[0]];
		echo "Edycja pliku: ".$url."<br><br>";
		$site=fopen($url, "a+");
		@flock($site,2);
		@$tresc = fread($site, filesize($url));
		@flock($site,3);
		@fclose($site);
		echo "
		<form method=post action=index.php?whereAmI=apanel&me=edytor&co=edycja&url=".$_GET['url'].">
		<input type=hidden name=source value=".$url,">
		<textarea rows=30 cols=70 name=pole>"
		.htmlspecialchars($tresc).
		"</textarea>
		<br><input type=submit value= Zapisz >";
	    }



    }
?>