<?php
    $n = numberOfTasks();
    $n--;
    if(file_exists($my_dir.$n))
	exit('Hacking jest dobry, jeśli tylko mnie nie atakujesz.');
    mkdir($my_dir.$n, 0700);
    mkdir($my_dir.$n.'/in', 0700);
    mkdir($my_dir.$n.'/out', 0700);
    make_a_file_with($my_dir.$n.'/'.$n.'.conf', '0');
?>