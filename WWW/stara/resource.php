<?php
    //$this_link must finish with at least one attribute or with '?'//etoc
    //$my_dir must be ['{path}/']
    function get_res_data($my_dir){
	$hash = file($my_dir.'.hashes');
	$n = count($hash);
	for($i=0;$i<$n;$i++){
	    $rf = file($my_dir.trim($hash[$i]).'.dt');
	    for($j=0;$j<6;$j++)
		$rf[$j]=trim($rf[$j]);
	    $res['name'][$i]=$rf[0];
	    $res['source'][$i]=$rf[1];
	    $res['by'][$i]=$rf[2];
	    $res['text_file'][$i]=$rf[3];
	    $kot=trim($rf[4]);
	    $m=strlen($kot);
	    $res['time'][$i]=$rf[5];
	    $kot2 = file($my_dir.'.kot');
	    for($j=0;$j<$m;$j++)
		if(1==(int)$kot[$j])
		    $res['kot'][$i][$j]=$kot2[3*$j+2];
	}
	return $res;
    }
    function getHashOfTask($my_dir, $def){
	$rf = file($my_dir.'.hashes');
	return trim($rf[$def]);
    }
    function get_resource($this_link, $my_dir, $title, $hash){
	/*if(!file_exists($my_dir)){
	    mkdir($my_dir, 0700);
	    make_a_file_with($my_dir.'index.php', '');
	}
	if(!file_exists($my_dir.'.done'))
	    make_a_file_with($my_dir.'.done', '');
	if(!file_exists($my_dir.'.hashes'))
	    make_a_file_with($my_dir.'.hashes', '');
	if(!file_exists($my_dir.'.kot'))
	    make_a_file_with($my_dir.'.kot', '');
	if(!file_exists($my_dir.'my_add_task_script.php'))
	    make_a_file_with($my_dir.'my_add_task_script.php', '<?php'."\n".'?>');
	    
	    czy moglby ktos kompetentny to usunac, jesli nie jest potrzebne, a wydaje mi sie, ze nie jest - kait
	*/
	//print 'Check hashes!';
	//to do max_length in the textarea
	if(isset($_GET['Rdef'])&&is_numeric($_GET['Rdef'])){
	    if($_SESSION[SESSION_USER]!="Yacek"&&is_active_task($_GET['Rdef'])==0)
		exit("Brak wstępu!");
	    print '<div style="float: right"><a href='.$this_link.'&list'.$hash.'=1>'.BACK_TEXT.'</a></div>';
	    print '<center>'.$_GET['Rdef'].'. '.get_name_of_task($_GET['Rdef']).'</center>';
	    $l_hash = getHashOfTask($my_dir, $_GET['Rdef']);
	    print '<div>';
	    print stripslashes(file_get_contents($my_dir.$l_hash.'.com'));
	    print '<br/></div>';
	    print '<div><!--to do //const-->';
	    $rf = file($my_dir.$l_hash.'.dt');
	    if((int)$rf[3]==0){
		print '<div style=\'border: 1px solid #000; font-family: arial; \'>';
		print nl2br(stripslashes(file_get_contents($my_dir.$l_hash)));
		print '</div>';
		print '<hr/>';
	    }
	    else
		print '
		    <a href="'.$my_dir.$l_hash.'">URL</a> 
		';
	    print '</div>';
	    $add_news_condition = 1;
	    $del_news_condition = ($_SESSION[SESSION_PERMISSION]==2);
//	    get_form_with_news($this_link.'&def='.$_GET['def'], $mydir.'.news', $hash.'comment1', 1000, $add_news_condition, $del_news_condition);//e to ch
	}
	else if(isset($_GET['list'.$hash])){
	    //print '<div style="float: right"><a href='.$this_link.'>'.BACK_TEXT.'</a></div>';
	    print '<center><font size=><b>'.$title.'</b></center><br/>';//to do
	    $nr = count(file($my_dir.'.hashes'));
	    $data = get_res_data($my_dir);//e to ch
	    print '
		<table width=100%>
		<!--to do tr atr local, but global-->
		<tr>
		<td>ID:</td><!--to do-->
		<td>Nazwa:</td><!--to do-->
		<td>Źródło:</td><!--to do-->
		<td>Dodał:</td><!--to do-->
		<td>Data:</td>
		<!--to do \'kat\'-->
		<td>Zadanie z:</td>
	    ';
	    print '</tr>';
	    $rf=file($my_dir.'.done');
	    // wstawka japy
	    @$plic=fopen("kat/".$_SESSION[SESSION_USER]."/zad","r");
	    @$zrobione=fread($plic,filesize("kat/".$_SESSION[SESSION_USER]."/zad"));
	    @$zro=explode(" ",$zrobione);
	    @fclose($plic);
	    $ile=count($zro)-2;
	    $pliczek=fopen("tasks/.active","r");
	    $aktywnosc=fread($pliczek,filesize("tasks/.active"));
	    fclose($pliczek);
	    $tabeleczka=explode("\n",$aktywnosc);
	    for($i=$nr-1; $i>=0; $i--)
	    { 
		if(!$tabeleczka[$i]) continue;
		print '<tr';
		while($ile>=0&&$zro[$ile]>$i) $ile--;
		if($ile>=0&&$zro[$ile]==$i) print ' bgcolor="#d0f0d0"';
		// kóniec wstawki
		print '
		    >
		    <td>'/*bgcolor=';
		switch((int)trim($rf[$i])){//colors to do & check
		    case 0 : print '#ffffff';//'#0000ff style="color: #fff;"'; break;//ced
		    case 1 : print '#ffff00'; break;
		    case 2 : print '#ffffff'; break;
		    case 3 : print '#ff0000'; break;
		}
		print '>'*/.($i).'</td>
		<td><a href='.$this_link.'&Rdef='.$i.'>'.$data['name'][$i].'</a></td>
			    <td>'.$data['source'][$i].'</td>
			    <td>'.$data['by'][$i].'</td>
			    <td>'.date(DATE_FORMAT, $data['time'][$i]).'</td>
			    <td>';
		if(count($data['kot'][$i])>0)
		    foreach($data['kot'][$i] as $value)
			print $value.' ';
		print '</td></tr>
		';//tr-to delete
//			if($_SESSION[SESSION_TMP]==HEAD_ADMIN)//to do cond
//			print '</tr>';
//		    }
		}//}-tmp
		print '</table>';
	    }
	    else if(isset($_POST['addRButton'.$hash])){//to do //tabs
//size to ch
		if($_POST['text_file']=='on'&&$_FILES['unc']['error']!=0)
		    unlink($_FILES['unc']['tmp_name']);
		if($_POST['text_file']=='on'){
		    switch($_FILES['unc']['error']){
			case 1 :
			case 2 : header('Location: index.php?whereAmI=tasks'); exit();/*announce MEM*/ break;
			case 3 :
			case 4 : header('Location: index.php?whereAmI=tasks'); exit();/*announce a transmission fault*/ break;
		    }
		}
		//size to ch
		$kot = '';
		$n = count(file($my_dir.'.kot'));
		for($i=0; $i<$n; $i+=3)
		    if($_POST[$i]=='on')//to ch
			$kot .= '1';
		    else $kot .= '0';
		$rf = file($my_dir.'.hashes');
		$n = count($rf);
		while(true){
		    $rf = file($my_dir.'.hashes');
		    $n = count($rf);
		    $this_hash = md5(time());
		    $myb = true;
		    for($i=0;$i<$n;$i++)
			if(trim($rf[$i])==$this_hash) $myb=false;
		    if($myb) break;
		}
		add_to_file($my_dir.'.hashes', $this_hash."\n");
		if($_POST['text_file']=='on')
		    $text_file=1;
		else $text_file=0;
		include($my_dir.'my_add_task_script.php');
		make_a_file_with($my_dir.$this_hash.'.dt', $_POST['name']."\n".$_POST['source']."\n".$_SESSION[SESSION_USER]."\n".$text_file."\n".$kot."\n".time());
		make_a_file_with($my_dir.$this_hash.'.com', nl2br($_POST['comment']));
		add_to_file($my_dir.'.done', '0'."\n");
		add_to_file($my_dir.'.active', '0'."\n");
		if($text_file==0)
		    make_a_file_with($my_dir.$this_hash, $_POST['textarea_text']);
		else move_uploaded_file($_FILES['unc']['tmp_name'], $my_dir.$this_hash);//to ch
		chmod($my_dir.$this_hash, 0705);//to ch/le
		header('Location: '.$this_link);
		exit();
	    }
	    else if(isset($def)){
		mail('***e-mail***', 'bug', "There was find a bug in:\nWWW/maths/index.php?whereAmI=tasks\nconcerning variable def. It get value: ".$def."\nuser: ".$_SESSION[SESSION_USER]);
		print 'Bug. Błąd został zgłoszony.';//to do
	    }
	    else {
		print '
		    <a href="'.$this_link.'&list'.$hash.'=1">'.SHOW_RESOURCE_TEXT.'</a>
		    <hr/>
		    <form action="'.$this_link.'" method=post enctype="multipart/form-data">
		    <b>'.SOURCE_TEXT.'</b>: <input type=text name="source" size=80><br/>
		    <input type=checkbox name=text_file> <b><i>'.SUBMIT_FILE_INSTEAD_OF_TEXTAREA_TEXT.'</i></b><br/>
		    <b><u>'.TASK_OF_TEXT.'</u></b>:<br/><!--to do-->
		    ';
		$kindsOfTasks = file($my_dir.'.kot');
		$n = count($kindsOfTasks);
		for($i=0;$i<$n;$i+=3)
		    print '
			<input type=checkbox name='.$i.' /> '.$kindsOfTasks[$i].' ('.trim($kindsOfTasks[$i+2]).')<br/>
		    ';
		print '
		    <b>'.NAME_OF_TASK_TEXT.'</b>: <input type=text name="name" size=20>
		    <br/><!--to do-->
		    <b>Treść lub plik (Jeżeli plik graficzny to najlepiej pod postacią .pdf)</b>:
		    <textarea cols=80 rows=5 name="textarea_text"></textarea><br/><!--to do-->
		    <input type="file" name="unc" size=70><br/>
		    <!--komentarz to do-->
		    <b>Komentarz do zadania</b>:<br/>
		    <textarea cols=80 rows=3 name="comment"></textarea>
		    <input type=submit value="Wyślij" name="addRButton'.$hash.'">
		    </form>
		    Limit pamięci: 100KB<!--to do-->
		';
	    }
    }
?>
