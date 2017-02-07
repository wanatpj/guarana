<?php
	if(!isset($_GET["accept"])) {
		print("<form action=\"index.php?whereAmI=apanel&me=maketest&accept=1\" method=\"post\" enctype=\"multipart/form-data\">\n
				<table border=\"1\" align=\"center\">\n
				<tr><td><table><th>Zadanie</th><td>
				<select name=\"zadanie\"/>");
		$mysql=sqlConnect();
		$zapytanie=mysqli_query($mysql,"SELECT name,ID FROM tasks ORDER BY ID DESC");
		while($row=mysqli_fetch_row($zapytanie)) print('<option value="'.$row[1].'">'.$row[0].'('.$row[1].')</option>');
		print("</select>
				</td></table></td></tr>\n
				<tr><td><table><th>Time limit</th><td><input type=\"text\" name=\"timelimit\"/></td></table></td></tr>\n
				<tr><td><table><th>Memory limit</th><td><input type=\"text\" name=\"memorylimit\"/></td></table></td></tr>\n
				<tr><td><table><th>Wejście</th><tr><td>Treść</td><td><textarea name=\"input\" rows=\"5\"></textarea></td></tr>
				<tr><td>Plik</td><td><input type=\"file\" name=\"inputfile\"/><input type=\"hidden\" name=\"MAX_FILE_SIZE\" value=\"5000000\"/>\n
				</td></tr></table></td></tr>\n
				<tr><td><table><th>Wyjście</th><tr><td>Treść</td><td><textarea name=\"output\" rows=\"5\"></textarea></td></tr>
				<tr><td>Plik</td><td><input type=\"file\" name=\"outputfile\"/><input type=\"hidden\" name=\"MAX_FILE_SIZE\" value=\"5000000\"/>\n
				</td></tr></table></td></tr>\n
				<tr><td><input type=\"submit\"/></td></tr>\n
				</table></form>\n");
	}
	else if($_GET["accept"]==1){
		//sprawdzenie, czy to co przyszlo jest sensowne - moznaby w JS
		//TODO: podawanie, którym testem z kolei ma być
		$zadanie=$_POST["zadanie"];
		$timelimit=$_POST["timelimit"];
		$memory=$_POST["memorylimit"];
		$input=$_POST["input"];
		$output=$_POST["output"];
		if(!isset($_POST["zadanie"]) || !is_numeric($zadanie)) exit("Zadanie: ".$zadanie." nie jest liczbą.");
		if(!isset($_POST["timelimit"]) || !is_numeric($timelimit)) exit("Time limit: ".$timelimit." nie jest liczbą.");
		if(!isset($_POST["memorylimit"]) || !is_numeric($memorylimit)) exit("Memory limit: ".$memorylimit." nie jest liczbą.");
		if(!(isset($_POST["input"]) && !($input=="")) && !is_uploaded_file($_FILES["inputfile"]["tmp_name"])) {print("Nie ma input.");exit();}
		if(!(isset($_POST["output"]) && !($output=="")) && !is_uploaded_file($_FILES["outputfile"]["tmp_name"])) {print("Nie ma output.");exit();}
		$configpath="./tasks/".$zadanie."/".$zadanie.".conf";
		$handle=fopen($configpath,"r");
		if(!$handle) {print("Nie ma takiego zadania.");exit();}
		$line=fgets($handle);
		for($i=0;!feof($handle);$i++) {
			$line=fgets($handle);
			$line=explode(" ",$line);
			$line=pathinfo($line[0]);
			$test[$i]=$line["basename"];
		}
		$hipo=1;
		while(1) {
			$good=1;
			foreach($test as $elem) if($elem===$hipo.".in") {$good=0;break;}
			if($good==1) break;
			$hipo++;
		}
		fclose($handle);
		$confhandle=fopen($configpath,"r");
		$handle=tmpfile();
		$line=fgets($confhandle);
		$line=trim($line);
		$line++;
		fwrite($handle,$line."\n");
		while(!feof($confhandle)) {
			fwrite($handle,fgets($confhandle));
		}
		fclose($confhandle);
		$confhandle=fopen($configpath,"w");
		fseek($handle,0);
		while(!feof($handle)) {
			fwrite($confhandle,fgets($handle));
		}
		fclose($handle);
		$inputpath="./tasks/".$zadanie."/in/".$hipo.".in";
		$outputpath="./tasks/".$zadanie."/out/".$hipo.".out";
		fwrite($confhandle,$inputpath." ".$outputpath." ".$timelimit." ".$memorylimit."\n");
		fclose($confhandle);
		$handle=fopen($inputpath,"w");
		if(isset($_POST["input"]) && !($input=="")) fwrite($handle,$input);
		else {move_uploaded_file($_FILES["inputfile"]["tmp_name"],$inputpath);}
		fclose($handle);
		$handle=fopen($outputpath,"w");
		if(isset($_POST["output"]) && !($output=="")) fwrite($handle,$output);
		else move_uploaded_file($_FILES["outputfile"]["tmp_name"],$outputpath);
		fclose($handle);
		print("Dodano test: ".$inputpath." ".$outputpath." ".$timelimit." ".$memorylimit."<br>");
	}
	else if($_GET["accept"]==0){
	}
?>
