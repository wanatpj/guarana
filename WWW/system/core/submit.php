<?php
     print '
	    <center>
	    <form enctype="multipart/form-data" action="index.php?whereAmI=send" method="post">
	    <input name="isSend" value="1" type="hidden">
	    <table bgcolor="#f4f4f4" cellpadding="5" cellspacing="0">
	    <tbody><tr><td colspan="3"><center><B>Wysłanie rozwiązania</center></b><br>';
	    $mysql=sqlConnect();
	    $zapytanie="SELECT `name`, `active`, `ID` FROM `tasks`";
	    $wynik=mysqli_query($mysql,$zapytanie);
	    if(!$wynik) {
		print "Nie można wysłać zapytania do bazy - spróbuj później.";
		exit;
	    }
	    $il=0;
	    $realil=0;
	    while($wiersz=mysqli_fetch_row($wynik)) {
		$tabeleczka[$realil]=$wiersz[1];
		$nazwa[$realil]=$wiersz[0];
		$ideki[$realil]=$wiersz[2];
		if($tabeleczka[$realil]=="2") $il++;
		$realil++;
	    }
	    echo "<br>Ilość dostępnych zadań: ".$il;
	    print '</td></tr><tr><td colspan="3" height="7">
	    </td></tr><tr>
	    <td width="60">Zadanie:
	    </td><td width="*">
	    <select name="idOfTask">';
	    for($i=$realil-1;$i>=0;$i--)
			if(($_SESSION[SESSION_PERMISSION]>=1 && $tabeleczka[$i]=="1") || $tabeleczka[$i]=="2")
				echo "<option value=".$ideki[$i].">".$ideki[$i]." - ".$nazwa[$i]."</option>";
	    echo '</td><td width="50">
		  </td></tr><tr>
		  <td>Język programowania:
		  </td><td><select name="lang">
		  <option value="cpp" selected="selected">C++</option>';
		  //<option value="c">C</option>
		  //<option value="pas">Pascal</option>
	    echo '</select></td><td></td></tr><tr>
		  <td>Plik ze źródłem:
		  </td><td><input size="42" name="file" type="file">
		  </td><td valign="bottom"><input value="Wyślij plik" type="submit">    
		  </td></tr><tr>
		  <td valign="top">Kod źródłowy:
		  </td><td><textarea style="width: 464px;" name="source" rows="15" cols="50"></textarea>
		  </td><td valign="bottom"><input value="Wyślij kod" type="submit">
		  </td></tr><tr><td colspan="3" height="4"></td></tr></tbody></table></form>';
?>
