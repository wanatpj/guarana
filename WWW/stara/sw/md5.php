<?php
    print '<form action="md5.php" method=post>
	<input type=password name=md5 size=100>
	<input type=submit value="md5">
	</form>
    ';
    if(isset($_POST['md5']))
	print md5($_POST['md5']);
    print '
	<br><a href="http://users.v-lo.krakow.pl/~infal/maths/md5.php">clear</a>
    ';
?>