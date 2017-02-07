<?php
    //sprawdza czy zmienna jest pusta  
    function isEmpty(&$var){
	return ($var === '' && $var !== 0 || !isset($var) ) ? (TRUE):(FALSE);
    }
    //sprawdza poprawnosc
    function isValid($type, $var){
        $valid=false;
	switch($type){
	      case "login":
	      if(ereg("^[a-zA-Z0-9_]{3,30}$",$var)) $valid=true;
	      break;
	      case "pass":
	      if(ereg("^[a-zA-Z0-9_]{6,30}$",$var)) $valid=true;
	      break;
	      case "email":
	      if(ereg("^[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+.[a-zA-Z]$",$var)&&strlen($var)<40) $valid=true;
              break;
	      case "gg":
              if(ereg("^[0-9]{1,20}$",$var)) $valid=true;
              break;
	      case "db_value":
	      //if(ereg("^[a-zA-Z0-9\n ]{1,200}$", $var)) $valid = true;
	      return true;
	      break;
         }
         return $valid;
    }
    //ustanowienie polaczenia z baza
    function sqlConnect(){
	include('config.php');
	$mysql=mysqli_connect($mhost, $muser, $mpass);
	if(!$mysql) {
	    print 'Brak połączenia z bazą danych.';
	    exit;
	}
	$wybrana=mysqli_select_db($mysql, $mbase);
	if(!$wybrana) {
	    print 'Błąd wyboru bazy danych.';
	    exit;
	}
	return $mysql;
    }
    //zczytywanie pola auto_increment z wybranej tabeli w MySQL
    function GetNextAutoInc($tablename, $mysql){
	$zapytanie="show table status like '$tablename'";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik) {
	    print 'Nie można wykonać zapytania do bazy.';
    	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[10];
    }
    
    function ActiveOfTask($taskID){ //zwraca aktualny active dla zadania
	$mysql=sqlConnect();
	$zapytanie="SELECT `active` FROM `tasks` WHERE `ID`='$taskID'";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik) {
	    print 'Nie można wykonać zapytania do bazy.';
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
	}

    function isActiveTask($taskID){ //zwraca true jesli dostepne dla tego uzytkownika
	$active=ActiveOfTask($taskID);
	if($active=="2") return true;
	if($active=="1"&&$_SESSION[SESSION_PERMISSION]>=ADMIN) return true; 
	return false;
	}

    function idOfTask($submitID) { //zwraca id zadania na podstawie id submita
	$mysql=sqlConnect();
	$zapytanie="SELECT `task ID` FROM `solutions` WHERE `ID`=$submitID";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik){
	    print "Błąd.";
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
	}

    function nameOfTask($taskID) { //zwraca nazwe zadania po ID
	$mysql=sqlConnect();
	$zapytanie="SELECT `name` FROM `tasks` WHERE `ID`=$taskID";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik) {
	    print "Błąd sqlConnect";
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
	}

    function nameOfUser($userID) { //zwraca nazwe usera po ID
	$mysql=sqlConnect();
	$zapytanie="SELECT `login` FROM `users` WHERE `ID`=$userID";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik) {
	    print "Błąd.";
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
	}

	function idOfUser($username) { //zwraca ID po nazwie
	$mysql=sqlConnect();
	$zapytanie="SELECT `id` FROM `users` WHERE `login`='".mysqli_real_escape_string($mysql,$username)."'";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik || mysqli_num_rows($wynik)!=1) return -1;
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
	}

    function ownerOfSolution($submitID){ //zwraca ID wlasciciela
	$mysql=sqlConnect();
	$zapytanie="SELECT `user ID` FROM `solutions` WHERE `ID`=$submitID";
	$wynik=mysqli_query($mysql,$zapytanie);
	if(!$wynik) {
	    print "Blad";
	    exit;
	}
	$wiersz=mysqli_fetch_row($wynik);
	return $wiersz[0];
    }
?>
