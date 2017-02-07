<?PHP
    session_start();
    include('fun.php');
    if(!isset($_SESSION['logi'])) include('logowanie.php');
    else
    {
	include('naglowek.php');
	$poz=used($_SESSION['logi']);
	$tab=file('data.txt');
	$exp=explode('`',$tab[$poz]);
	if(trim($exp[3])!='a') echo "Sorry man, nie masz uprawnień administatora.";
	else
	{
	    echo "
		<font size=4>Panel Admina by Yacek 2008 ver. 0.02</font>
		<br><br><b>Witojcie panie administratorze.</b>
		<br>Pamiętaj, że w nazwach plików i folderów nie można używać białych znaków (spacji, etc) !!!<br>
		";
	    echo "<br><hr>Ścieżka folderu: ";
if(isset($_POST['dirr']))
{
if($_POST['dirr']==".")
{
$f=explode('/',$_SESSION['sdir']);
$nowy="";
for($i=0;$i<count($f)-2;$i++)
{
$nowy=$nowy.$f[$i]."/";
}
$_SESSION['sdir']=$nowy;
}
elseif($_POST['dirr']=="..")
{
$f=explode('/',$_SESSION['sdir']);
$nowy="";
for($i=0;$i<count($f)-3;$i++)
{
$nowy=$nowy.$f[$i]."/";
}
$_SESSION['sdir']=$nowy;
}
else $_SESSION['sdir']=$_SESSION['sdir'].$_POST['dirr']."/";
}
	    $dir=$_SESSION['sdir'];
	    echo $dir;
	    echo "<br>Zawartość folderu: <br><table border=1><tr><td>filename:</td><td>filetype:</td></tr>";
	    if (is_dir($dir)) 
	    {
		if ($dh = opendir($dir)) 
		{
		    for($i=0;($tmp=readdir($dh))!==false;$i++) $file[$i]=$tmp; 
		    sort($file);
		    for($i=0;$i<count($file);$i++) 
		    {
			echo "
			    <tr><td>".$file[$i]."</td><td>".filetype($dir.$file[$i])."
			    </td><td><form method=post action=usun.php>
			    <input type=hidden name=src value=".$file[$i].">
			    <input type=submit value= Usuń ></form></td>
			    ";
			    if(is_file($dir.$file[$i]))
			    {
				echo "
				    <td><form method=post action=edycja.php>
				    <input type=hidden name=src value=".$file[$i].">
				    <input type=submit value= Edytuj ></form></td></tr>
				    ";
			    }
			    else
			    {
				echo "
				    <td><form method=post action=index.php>
				    <input type=hidden name=dirr value=".$file[$i].">
				    <input type=submit value= Wejdź ></form></td></tr>
				    ";
			    
			    }
		    }
		    closedir($dh);
		}
	    }
	    echo "
		</table>
		<hr><form method=post action=edycja.php>
		Nazwa pliku do edycji: <input type=text name=src maxlength=100>
		<input type=submit value= Edytuj ></form>
		<hr><form method=post action=usun.php>
		Nazwa pliku do usunięcia: <input type=text name=src maxlength=100>
		<input type=submit value= Usuń ></form>
		<hr><form method=post action=zmien.php>
		Przenoszenie i zmiana nazwy: <input type=text name=src1 maxlength=100>
		<input type=text name=src2 maxlength=100>
		<input type=submit value= Zmień >
		<a href=zmienhelp.htm target=blank>help</a></form>
		<hr><form action=wyslij.php method=POST ENCTYPE=multipart/form-data>
		Wysyłanie pliku: <input type=file name=plik>
		<input type=submit value=Wyślij plik></form>
		<hr>Dodaj newsa:<br><form method=post action=addnews.php>
		Autor: <input type=text name=autor><br>
		Treść: <textarea name=tresc cols=70 rows=7></textarea><br><br>
		<input type=submit value= Dodaj ></form><hr>
		<form method=post action=editnews.php>
		Edycja newsów: <input type=submit value= Edytuj >
		</form><hr><form method=post action=editbook.php>
		Edycja księgi gości: <input type=submit value= Edytuj ></form>
		";
	}
    }
?>