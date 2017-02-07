<?php
    if(isset($_POST['send'])){
	$login = trim($_POST['login']);
	$passwd = trim($_POST['haslo']);
	$admin = $_POST['admin']-1;
	$email = trim($_POST['email']);
	if(empty($login)||empty($passwd)||empty($email)||strlen($passwd)<7)
	    exit("Puste pola lub hasło krótsze niż 7 znaków.");
	add_to_file('data/users', $login."\n");
	mkdir('kat/'.$login, 0700);
	$rf = file('kat/.nr');
	$rf = $rf[0]+1;
	make_a_file_with('kat/.nr', $rf);
	add_to_file('kat/'.$login.'/id', $rf);
	add_to_file('kat/'.$login.'/user', md5($passwd)."\n".$admin."\n-\n".$email);
	header('Location: index.php?whereAmI=apanel&me=users');
    }
    else{
	print '
	    <form action="" method="post">
	    <table>
	    <tr><td>Login: (\'a\' .. \'z\'; \'A\' .. \'Z\'; \'0\' .. \'9\'; \'_\')</td><td><input type="text" name="login" size="30"></td></tr>
	    <tr><td>Hasło: </td><td><input type="password" size="30" name="haslo"></td></tr>
	    <tr><td colspan="2">
	    <select name="admin">
	    <option value="1">Zwykły user</option>
	    <option value="2">Admin (Dodaj zadanie, Dodaj test)</option>
	    </select></td></tr>
	    <tr><td>E-mail: </td><td><input type="text" name="email" size="30"></td></tr>
	    </table>
	    <input type="submit" name="send" value="Zarejestruj użytkownika.">
	    </form>
	';
    }
?>