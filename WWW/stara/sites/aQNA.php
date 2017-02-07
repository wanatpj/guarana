<?php
    ob_start();
    session_start();
    print '<center><form action="" method="post">';
    $rf = file('QNA/.inf');
    $n = count($rf);
    for($i=0;$i<$n;++$i){
	if(isset($_POST['OK'.$i])){
	    if(!file_exists('QNA/'.trim($rf[$i]).'.r'))
		make_a_file_with('QNA/'.trim($rf[$i]).'.r', $_POST['odp'.$i]);
	    header('Location: index.php?whereAmI=apanel&me=QNA');
	    exit();
	}
	if(isset($_POST['bye'.$i])){
	    unlink('QNA/'.trim($rf[$i]));
	    unlink('QNA/'.trim($rf[$i]).'.r');
	    delete_stream_from_file('QNA/.inf', $i, 1);//tc
	    header('Location: index.php?whereAmI=apanel&me=QNA');
	    exit();
	}
    }
    print '<table><tr><td style="border: 1px solid #000;">Pytanie</td><td style="border: 1px solid #000;">Odpowiedź</td><td style="border: 1px solid #000;">Akcja</td></tr>';
    for($i=0;$i<$n;++$i){
	print '<tr><td>';
	print file_get_contents('QNA/'.trim($rf[$i]));
	print '</td><td>';
	if(file_exists('QNA/'.trim($rf[$i]).'.r'))
	    print file_get_contents('QNA/'.trim($rf[$i]).'.r').'</td><td>';
	else print '
	    <textarea name="odp'.$i.'" cols="10" rows="3">W treści</textarea>
	    </td><td>
	    <input type="submit" value="Odpowiedz" name="OK'.$i.'">
	';
	print '<input type="submit" value="Usuń" name="bye'.$i.'"></form></td></tr>';
    }
    print '</table></center>';
    ob_end_flush();
?>