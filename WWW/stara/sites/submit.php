<?php
     print '
	    <center>
	    <form enctype="multipart/form-data" action="index.php?whereAmI=send" method="post">
	    <input name="isSend" value="1" type="hidden">
	    <table bgcolor="#f4f4f4" cellpadding="5" cellspacing="0">
	    <tbody><tr><td colspan="3"><center><B>Wysłanie rozwiązania</center></b><br>';
	    $il=0;
	    $pliczek=fopen("tasks/.active","r");
	    $aktywnosc=fread($pliczek,filesize("tasks/.active"));
	    fclose($pliczek);
	    $tabeleczka=explode("\n",$aktywnosc);
	    $realil=numberOfTasks();
	    for($i=0;$i<$realil;$i++) if($tabeleczka[$i]) $il++;
	    echo "<br>Ilość dostępnych zadań: ".$il;
	    print '</td></tr><tr><td colspan="3" height="7">
	    </td></tr><tr>
	    <td width="60">Zadanie:
	    
	    </td><td width="*">
	    <select name="idOfTask">';
	    
	    for($i=$realil-1;$i>=0;$i--)
	    {	
		if(!$tabeleczka[$i]) continue;
		echo "<option value=".$i.">".$i." - ".get_name_of_task($i)."</option>";
	    }
	    echo '</td><td width="50">
		  </td></tr><tr>
		  <td>Język programowania:
		  </td><td><select name="lang">
		  <option value="cpp" selected="selected">C++</option>';
		  //<option value="c">C</option>
		  //<option value="pas">Pascal</option></select>
	    echo '</td><td></td></tr><tr>
		  <td>Plik ze źródłem:
		  </td><td><input size="42" name="file" type="file">
		  </td><td valign="bottom"><input value="Wyślij plik" type="submit">    
		  </td></tr><tr>
		  <td valign="top">Kod źródłowy:
		  </td><td><textarea style="width: 464px;" name="source" rows="15" cols="50"></textarea>
		  </td><td valign="bottom"><input value="Wyślij kod" type="submit">
		  </td></tr><tr><td colspan="3" height="4"></td></tr></tbody></table></form>';
?>