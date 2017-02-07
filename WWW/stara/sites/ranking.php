<?php
//    include('sites/rankBar.php');
//    print '<hr>';
    if(!isset($_GET['nb'])){
	$mystring = '';
	if($_GET['kind']=='acm')
	    include('sites/ACMrank.php');
	else include('sites/IOrank.php');
	print $mystring;
	if(isCreatorOfRanks($_SESSION[SESSION_USER])){
	    print '<form action="" method="post">';
	    print '<input type="text" name="name" size="20">';
	    print '<input type="submit" value="save" name="createRank">';
	    print '</form>';
	}
	if(isCreatorOfRanks($_SESSION[SESSION_USER])&isset($_POST['createRank'])){
	    if(!file_exists('ranks/'.$_POST['name'])){
		add_to_file('ranks/.names', $_POST['name']."\n");
		make_a_file_with('ranks/'.$_POST['name'], $mystring);
		$n = count(file('ranks/.names'));
		header('Location: index.php?whereAmI=ranking&nb='.($n-1));
		exit();
	    }
	}
    }
    else {
	$rf = file('ranks/.names');
	include('ranks/'.trim($rf[$_GET['nb']]));
    }
?>