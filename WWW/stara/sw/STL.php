<?php
    function delete_stream_from_file($file, $skad, $ile){//to check//unstable//e to ch//name to do
	$f2 = file($file);
	$n = count($f2);
	for($i=0;$i<$ile;$i++)
	    $tmp[$i]=$f2[$skad+$i];
	for($i=$skad; $i<$n-$ile; $i++)
	    $f2[$i]=$f2[$i+$ile];
	$wf = fopen($file, 'w');
	if(flock($wf, LOCK_EX))
	    for($i=0;$i<$n-$ile;$i++)
		fwrite($wf, $f2[$i]);
	flock($wf, LOCK_UN);
	fclose($wf);
	return $tmp;
    }
    function add_array_to_file($file, $text){//to check//unstable//e to ch
	$af = fopen($file, 'a');
	$tmp = count($text);
	if(flock($tmp, LOCK_EX)){
	    foreach($text as $value)
		fwrite($af, $value);
	    flock($tmp, LOCK_UN);
	}
	fclose($af);
    }
    //to a file?// e to ch
    function add_to_file($file, $text){//en to do//to do chmod's
	$tmp = fopen($file, 'a');
	if(flock($tmp, LOCK_EX)){
	    fwrite($tmp, $text);
	    flock($tmp, LOCK_UN);
	}
	fclose($tmp);
    }
    //to do: function add_to_files()
    //to do: function make_files_with()
    function make_a_file_with($file, $text){//to check//to do chmod's
	$tmp = fopen($file, 'w');//to do/check
	fwrite($tmp, $text);
	fclose($tmp);
    }
	//unlink - predefined - It deletes file.//e to ch
	//mkdir - predefined - It makes directory.//e to ch
	//rmdir - predefined - It deletes directory.//e to ch
    function convert_e_mail($e_mail){
	for($i=0;$i<strlen($e_mail);$i++)
	    if($e_mail[$i]=='.')
		$e_mail=substr($e_mail, 0, $i).' &lt;kropka&gt; '.substr($e_mail, $i+1);
	    else if($e_mail[$i]=='_')
		$e_mail=substr($e_mail, 0, $i).' &lt;znak podkreslenia;&gt '.substr($e_mail, $i+1);
	    else if($e_mail[$i]=='@')
		$e_mail=substr($e_mail, 0, $i).'&lt;malpa&gt; '.substr($e_mail, $i+1);
	return $e_mail;
    }
//DICTIONARY://e to ch
//	function get_first_line_of_data_file($file){
//	    $rf = file($file);
//	    return trim($rf[0]);
//	}
//	function file_set_insert($file, $text){
//	}
//	function file_
?>