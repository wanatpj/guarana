<?php
print md5(1214354590);
	$handle = fopen(".hashes","r");
	$nr_zadania = 0;
	while(!feof($handle)) {
		$hash = fgets($handle);
	}
	fclose($handle);
?>
