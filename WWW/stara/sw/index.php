<?php
    ob_start();
    session_start();
    include('STL.php');
    include('const.php');
    include('functions.php');
    include('basic_forms.php');
    include('news.php');
    //color td
?>
<!DOCTYPE HTML if_hacker_then_disconnect>
<html>
<head>
<meta http-equiv=content-type content="text/html; charset=UTF-8">
<title>Szmigiel & Wanat</title>
</head>
<body link=#0000ff vlink=#0000ff>
<div align=right><?php if(isset($_SESSION[SESSION_MY_NAME])) print USER_TEXT.': '.$_SESSION[SESSION_USER]?></div>
<center><h1 style="background: #f90">Strona Jacka Szmigla i Pawła Wanata<br/>testerka i zbiór algorytmów</h1></center>
<?php
    if(isset($_SESSION[SESSION_MY_NAME])){
	print '<center>';
	include('bar.php');
	print '</center><hr/>';
	$wmI=$_GET['whereAmI'];
	if(!isset($wmI)||$wmI=='home'){
	    $bool1 = isset($_SESSION[SESSION_MY_NAME]);//to do for less users//etoc
	    $bool2 = isset($_SESSION[SESSION_MY_NAME]);//to do for less users//etoc
	    get_form_with_news('index.php', 'data/news', 'm_news000', 1000, $bool1, $bool2);
	}
	else if($wmI=='tasks'){//to do // translation
	    //print 'Check hashes!';
	    //to do max_length in the textarea
	    if(isset($def)&&is_numeric($def)){
		print '<div style="float: right"><a href=index.php?whereAmI=tasks&my_atr=1>Powrót<!--to do--></a></div>';
		//permission
		$hash = getHashOfTask($def);
		print '<div>';
		print '<br/></div>';
		//isPDF($def); //to check if isPDF() xor is_PDF() xor another one function exists. // english to check
		print '
		    <div align=center><!--to do //const-->
		';
		print '
		    <iframe src="tasks/'.$hash.'" width=100% height=200><!--to do-->
			Zmień przeglądarkę. Ta nie obsługuje ramek. <!--to do-->
		    </iframe>
		';
		print '</div>';
		get_weak_form_with_news('tasks/'.$hash);//e to ch
	    }
	    else if(isset($_GET['my_atr'])){
		print '<div style="float: right"><a href=index.php?whereAmI=tasks>Powrót<!--to do--></a></div>';
		print '<center><font size=4><b>'.TASKS_TEXT.'</b></font><br/></center>';//to do
		$nr = numberOfTasks();
		$data = getDataOfTasks();//e to ch
		print '
		    <table width=100%>
		    <!--to do tr atr local, but global-->
		    <tr>
		    <td>ID:</td><!--to do-->
		    <td>Name:</td><!--to do-->
		    <td>Source:</td><!--to do-->
		    <td>By:</td><!--to do-->
		    <!--to do \'kat\'-->
		    <td>Zadanie z:</td>
		';
		print '</tr>';
		for($i=$nr-1; $i>=0; $i--){//{-tmp
			print '
			    <tr>
			    <td>'.($i+1).'</td>
			    <td><a href=index.php?whereAmI=tasks&def='.$i.'>'.$data['name'][$i].'</a></td>
			    <td>'.$data['source'][$i].'</td>
			    <td>'.$data['by'][$i].'</td>
			    <td>';
			$kappa = kindsOfTask($i);
			foreach($kappa as $value)
			    print $value.' ';
			print'</td>
			    </tr>
			';//tr-to delete
		}
		print '</table>';
	    }
	    else if(isset($_POST['addTaskButton'])){
		if($_FILES['unc']['error']!=0)
		    unlink($_FILES['unc']['tmp_name']);
		if($_POST['text_file']=='on'){
		    switch($_FILES['unc']['error']){
			case 1 :
			case 2 : header('Location: index.php?whereAmI=tasks'); exit();/*announce MEM*/ break;
			case 3 :
			case 4 : header('Location: index.php?whereAmI=tasks'); exit();/*announce a transmission fault*/ break;
		    }
		}
		$kot = '';
		$n = count(file('data/kindsOfTasks'));
		for($i=0; $i<$n; $i+=2)
		    if($_POST[$i]=='on')//to ch
			$kot .= '1';
		    else $kot .= '0';
		$hash = make_a_hash_for_a_next_task();
		if($_POST['text_file']=='on')
		    $txtfile=1;
		else $txtfile=0;
		mail('***e-mail***', 'Nowe zadanie na sw!', 'by: '.$_SESSION[SESSION_USER]);
		make_a_file_with('tasks/'.$hash.'.kot', $kot);
		make_a_file_with('tasks/'.$hash.'.dt', $_POST['name']."\n".$_POST['source']."\n".$_SESSION[SESSION_USER]."\n".$txtfile);
		add_to_file('tasks/.done', '0'."\n");
		if(!($_POST['text_file']=='on'))
		    make_a_file_with('tasks/'.$hash, $_POST['textarea_text']);
		else move_uploaded_file($_FILES['unc']['tmp_name'], 'tasks/'.$hash);//to ch
		chmod('tasks/'.$hash, 0705);//to ch/le
		header('Location: index.php?whereAmI=tasks');
		exit();
	    }
	    else if(isset($def)){
		mail('***e-mail***', 'bug', "There was find a bug in:\nWWW/maths/index.php?whereAmI=tasks\nconcerning variable def. It get value: ".$def."\nuser: ".$_SESSION[SESSION_USER]);
		print 'Bug. Błąd został zgłoszony.';//to do
	    }
	    else {
		print '
		    <a href=index.php?whereAmI=tasks&my_atr=1>'.SHOW_TASKS_TEXT.'</a>
		    <hr/>
		    <form action=index.php?whereAmI=tasks method=post enctype="multipart/form-data">
		    <b>'.SOURCE_TEXT.'</b>: <input type=text name=source size=80><br/>
		    <input type=hidden name=MAX_FILE_SIZE value=204800>
		    <input type=checkbox name=text_file> <b><i>'.SUBMIT_FILE_INSTEAD_OF_TEXTAREA_TEXT.'</i></b><br/>
		    <b><u>'.TASK_OF_TEXT.'</u></b>:<br/><!--to do-->
		    ';
		$kindsOfTasks = file('data/kindsOfTasks');
		$n = count($kindsOfTasks);
		for($i=0;$i<$n;$i+=2)
		    print '
			<input type=checkbox name='.$i.' /> '.$kindsOfTasks[$i].' ('.trim($kindsOfTasks[$i+1]).')<br/>
		    ';
		print '
		    <b>'.NAME_OF_TASK_TEXT.'</b>: <input type=text name=name size=20>
		    <br/><!--to do-->
		    <b>Treść lub plik (Jeżeli plik graficzny to najlepiej pod postacią .gif)</b>:<br/>	
		    <textarea cols=80 rows=5 name=textarea_text></textarea><br/><!--to do-->
		    <input type="file" name="unc" size=70><br/>
		    <input type=submit value="'.SEND_TEXT.'" name=addTaskButton>
		    </form>
		    Limit pamięci: 200KB<!--to do-->
		';
	    }
	}

	else if($wmI=='submit'){
	}
	else if($wmI=='submissions'){
	}
	else if($wmI=='tech'){
	    $rf = file('data/kindsOfTasks');
	    $n = count($rf);
	    for($i=0;$i<$n;$i+=2)
		print '<b>'.$rf[$i].' ('.trim($rf[$i+1]).')</b><br/>'."\n";
	}
	else print BUG_WARNING_TEXT;
    }
    else{
	print '
	    Nie jestes zalogowany.<br/>
	    Narazie nie istnieją żadne opcje dla uzytkowników nie zalogowanych.<br/>
	    <br/><center>
	';
	login_form();//etoc -> basic_forms.php
	print '</center>';
    }
    print '<hr/><center>Powered by: '.ADMINS.'</center>';//etoc
?>
</body>
</html>
<?php
    ob_end_flush();
?>
