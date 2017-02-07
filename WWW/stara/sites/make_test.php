<?php
    if(isset($_GET['send'])){
	$task = $_POST['task'];
	if(empty($task))
	    exit("Nie wybrano zadania.");
	$task--;
	print 'Test do zadania: '.$task.' - '.get_name_of_task($task).'<br>';
	$time = $_POST['time'];
	if(empty($time)) exit("time empty!");
	$mem = $_POST['mem'];
	if(empty($mem)) exit("mem empty!");
	$in = $_POST['in'];
	$out = $_POST['out'];
	if($_POST['czyIn']=='on'&&$_FILES['uncIn']['error']!=0)
	    exit('Problem with in $_FILES[\'uncIn\'][\'error\']=='.$_FILES['uncIn']['error']);
	if($_POST['czyOut']=='on'&&$_FILES['uncOut']['error']!=0)
	    exit('Problem with in $_FILES[\'uncOut\'][\'error\']=='.$_FILES['uncOut']['error']);
	$rf = file('tasks/'.$task.'/'.$task.'.conf');
	$k = $n = (int)trim($rf[0]);
	$k++;
	while(file_exists('tasks/'.$task.'/in/'.$task.$n.'.in')||file_exists('tasks/'.$task.'/out/'.$task.$n.'.out')) $n++;
	$rf[$k]="\n".'tasks/'.$task.'/in/'.$task.$n.'.in '.'tasks/'.$task.'/out/'.$task.$n.'.out '.$time.' '.$mem;
	$rf[0]=$k;
	if($k!=1) $rf[0].="\n";
	$wf='';
	for($i=0;$i<=$k;$i++)
	    $wf.=$rf[$i];
	make_a_file_with('tasks/'.$task.'/'.$task.'.conf', $wf);
	if($_POST['czyIn']!='on'){
	    make_a_file_with('tasks/'.$task.'/in/'.$task.$n.'.in', $in);
	    print 'In: textarea<br>';
	    if(is_uploaded_file($_FILES['uncIn']['tmp_name']))
		unlink($_FILES['uncIn']['tmp_name']);
	}
	else {move_uploaded_file($_FILES['uncIn']['tmp_name'], 'tasks/'.$task.'/in/'.$task.$n.'.in');
	make_enter_on_the_EOF('tasks/'.$task.'/in/'.$task.$n.'.in'); print 'In: file<br>';}
	if($_POST['czyOut']!='on'){
	    make_a_file_with('tasks/'.$task.'/out/'.$task.$n.'.out', trim($out)."\n");
	    print 'Out: textarea<br>';
	    if(is_uploaded_file($_FILES['uncOut']['tmp_name']))
		unlink($_FILES['uncOut']['tmp_name']);
	}
	else {move_uploaded_file($_FILES['uncOut']['tmp_name'], 'tasks/'.$task.'/out/'.$task.$n.'.out');
	make_enter_on_the_EOF('tasks/'.$task.'/out/'.$task.$n.'.out'); print 'Out: file<br>';}
	print '<fotn color="green">Test dodany.<br>Nie odświeżaj strony.</font>';
    }
    else{
	print '<form action="index.php?whereAmI=apanel&me=maketest&send=1" method="post" enctype="multipart/form-data">';
	$n = numberOfTasks();
	print '<select name="task"><option value="">Wybierz zadanie</option>';
	for($i=$n-1;$i>=0;$i--)
	    print '<option value="'.($i+1).'">'.$i.' - '.get_name_of_task($i).'</option>';
	print '</select>
	    <table><tr><td>time: </td><td><input type="text" name="time" size="20"> ms</td></tr>
	    <tr><td>MEM: </td><td><input type="text" name="mem" size="20"> B</td></tr>
	    </table>
	    <hr>In:<br>
	    <textarea col="80" row="5" name="in"></textarea><br>
	    <input type="checkbox" name="czyIn"> Zaznacz jeśli przesyłasz plik. (IN)<br>
	    <input type="file" name="uncIn" size="50"> (max size ~2MB) <hr>Out:<br>
	    <textarea col="80" row="5" name="out"></textarea><br>
	    <input type="checkbox" name="czyOut"> Zaznacz jeśli przesyłasz plik. (OUT)<br>
	    <input type="file" name="uncOut" size="50"> (max size ~2MB) <br>
	    <input type="submit" value="OK">
	';
	print '</form>';
    }
?>