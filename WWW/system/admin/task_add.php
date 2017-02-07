<?php	
    session_start();
    print "<center><b>Dodawanie Zadania</b><br><br>";
    $mysql=sqlConnect();
    if(!isEmpty($_GET['done']))
    {
    	print "Zadanie dodane!<br><br>";
    }
    else if(isEmpty($_POST['name']))
    {
    	$zapytanie="SELECT * FROM `categories` ORDER BY `name` ASC";
    	$wynik=mysqli_query($mysql,$zapytanie);
    	if(!$wynik)
	{
		print 'Nie można pobrać kategorii.';
		exit;
	}
    	print "<form action='index.php?whereAmI=apanel&me=addtask' method='post'>";
   	print "<table border=1 width=600><tr><td><b>Nazwa: </b></td><td><input type='text' name='name' id='name'></td></tr>
   		<tr><td width=150><b>Dodał:</b> </td><td><input type='text' name='author' id='author' value=".$_SESSION[SESSION_USER]."></td></tr>
   		<tr><td><b>Źródło:</b> </td><td><input type='text' name='from' id='from'></td></tr>
   		<tr><td><b>Pamięć [B] (default):</b> </td><td><input type='text' name='mem' id='mem'></td></tr>
   		<tr><td><b>Czas [ms] (default):</b> </td><td><input type='text' name='time' id='time'></td></tr>
   		<tr><td colspan='2'><b>Kategoria:</b> </td></tr>";
   		while($wiersz=mysqli_fetch_row($wynik)) print "<tr><td colspan='2'><input name='cat".$wiersz[0]."' type='checkbox'> ".$wiersz[1]." (".$wiersz[2].")</td></tr>";
   		print "<tr><td colspan='2'><b>Treść:</b></td></tr>
   		<tr><td colspan='2'><textarea cols='80' rows='8' name='content'></textarea></td></tr>
		<tr><td colspan='2'><b>Komentarz:</b></td></tr>
		<tr><td colspan='2'><textarea cols='80' rows='4' name='comment'></textarea></td></tr>
		<tr><td colspan='2'><center><input value='Wyślij' name='add' type='submit'></td></tr>
   		</table></form><br>";
    }
    else
    {	
    	$zapytanie=" SELECT `id` FROM `users` WHERE `login` = '".$_POST['author']."'";
    	$wynik=mysqli_query($mysql,$zapytanie);
    	if(!$wynik)
	{
		print 'Nie można pobrać ID autora.';
		exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	$author=$wiersz[0];
	$category="";
	$i=1;
	$zapytanie="SELECT COUNT( * ) FROM `categories`";
    	$wynik=mysqli_query($mysql,$zapytanie);
    	if(!$wynik)
	{
		print 'Nie można pobrać kategorii.';
		exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	while($i<=$wiersz[0])
	{
		if($_POST['cat'.$i]=='on') $category=$category." ".$i;
		$i++;
	}
	$timess=time();
    	$zapytanie = "INSERT INTO `guarana`.`tasks` (`ID` ,`name` ,`date` ,`from` ,`author` ,`category` ,`memory` ,`time`) VALUES (NULL , '".$_POST['name']."', '".$timess."', '".$_POST['from']."', '".$author."', '".$category."', '".$_POST['mem']."', '".$_POST['time']."');";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik)
	{
		print 'Nie można wykonać zapytania.';
		exit;
	}
	$zapytanie="SELECT `id` FROM `tasks` WHERE `date` = '".$timess."' AND `author` = '".$author."'";
    	$wynik=mysqli_query($mysql,$zapytanie);
    	if(!$wynik)
	{

		print 'Nie można pobrać ID zadania.';
		exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	$id=$wiersz[0];
	mkdir("tasks/$id", 0700);
	$handle = fopen("tasks/$id/$id.php", "w");
	fwrite($handle, $_POST['content']);
	fclose($handle);
	$handle = fopen("tasks/$id/$id.com", "w");
	fwrite($handle, $_POST['comment']);
	fclose($handle);
	$handle = fopen("tasks/$id/$id.conf", "w");
	fwrite($handle, "0");
	fclose($handle);
	header('Location: index.php?whereAmI=apanel&me=addtask&done=1');
	exit;
    }
?>
