<?php
    function get_form_with_links($table, $hash, $add_link_condition, $delete_link_condition){//e to c
	$mysqli = mysqli_connect($mhost, $muser, $mpass, $mbase);
	if(!$mysqli) exit('Błąd połączenia z bazą danych.');
//	if(!file_exists($file))//td
//	    make_a_file_with($file, '');
	if($delete_link_condition&&$_POST['delLi'.$hash]){
	    delete_stream_from_file($file, $_GET['def'], 2);//mail to do
	    header('Location: '.$this_link);
	    exit();
	}
	else if(isset($_POST['suLi'.$hash])&&(!isCorrectText($_POST['links'], $link_len)||!isCorrectText($_POST['nlinks'], $link_len))){
	    header('Location: '.$this_link);
	    exit();
	}//to do
	else if(isset($_POST['suLi'.$hash])&&(empty($_POST['link'])||empty($_POST['name'])))
	    print 'Za mało danych';//to do
	else if(isset($_POST['suLi'.$hash])&&$add_link_condition){
	    add_to_file($file, $_POST['link']."\n".$_POST['name']."\n");
	    header('Location: '.$this_link);
	    exit();
	}
	else if($add_link_condition){//to do max_size//to do c
	    print '
		<form action="index.php?whereAmI=links" method="post" style="margin-left: 10%">
		<table>
		<tr><td>link:</td>
		<td><input type="text" name="link" size="40" maxlength="300"/>
		</td></tr><tr><td>Nazwa pod jaka ma wystepować link</td>
		<td><input type="text" name="name" size="40" maxlength="300"/>
		</td></tr>
		</table>
		<input type="submit" value="submit" name="suLi'.$hash.'"/>
		</form>
	    ';
	    print '<hr/>'."\n";
	}
	print '<table>';
	for($i=0;$i<$n;$i+=2){
	    print '<tr><td><a href="'.$plik[$i].'" target=_blank>'.$plik[$i+1].'</a>'."\n";
	    if($delete_link_condition)
		print '</td><td>
		    <form action="'.$this_link.'?def='.$i.'" method=post>
		    <input type=submit name="delLi'.$hash.'" value="'.DELETE_LINK_TEXT.'">
		    </form>
		';
	    print '</td></tr>';
	}
	print '</table>';
	mysqli_close($mysqli);
    }
?>