<?php
    print '
	<a href="index.php?whereAmI=apanel">Home</a> |
	<a href="index.php?whereAmI=apanel&me=addtask">'.ADD_TASK_TEXT.'</a> |
	<a href="index.php?whereAmI=apanel&me=maketest">'.MAKE_TEST_TEXT.'</a> |
	<a href="index.php?whereAmI=apanel&me=cts">Panel konkursów</a> |
	<a href="index.php?whereAmI=apanel&me=rejudge">'.REJUDGE_TEXT.'</a> |
	<a href="index.php?whereAmI=apanel&me=tests">'.TESTS_TEXT.'</a> |
	<a href="index.php?whereAmI=apanel&me=aQNA">Q&A</a> |
	<a href="index.php?whereAmI=apanel&me=queue">Kolejka</a> |';
    if($_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN)
	print '|
	    <a href="index.php?whereAmI=apanel&me=edytor">Edytor zadań</a> |    
	    <a href="index.php?whereAmI=apanel&me=users">Użytkownicy</a> |
	    <a href="index.php?whereAmI=apanel&me=demon">Demon</a> |
	    <a href="index.php?whereAmI=apanel&me=stan">Stan serwera</a> |
	    <a href="admin/index.php" target="_blank">Command Center</a>
	';
?>