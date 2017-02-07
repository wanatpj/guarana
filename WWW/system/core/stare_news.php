<?php
    //tabs td
    function isCorrectChar($my_char){//to do
	return ord($my_char)>=32&&ord($my_char)!=127;
    }
    function isCorrectText($text, $limitation){//to do ograniczenie z góry//e to c//in maths $ogr should be <=102400
	$n = strlen($text);
	if($n>$limitation) return false;
	for($i=0;$i<$n;$i++)
	    if(!isCorrectChar(ord($text[$i])))
		return false;
	return true;
    }//end comment
    function get_form_with_news($this_link, $file, $hash, $length, $add_news_condition, $del_news_condition){//e to ch
	if(!file_exists($file)){
	    make_a_file_with($file, '');
	    chmod($file, 0700);
	}
	if(isset($_POST['delNews'.$hash])){
	    delete_stream_from_file($file, (int)$_GET['def'], 3);
	    header('Location: '.$this_link);
	    exit();
	}
        if(isset($_POST['CNewsB'.$hash])&&$add_news_condition){
	    $news = trim($_POST['news']);
	    $news = stripslashes($news);
	    $news = nl2br($news);
	    if(!isCorrectText($news, $length)){
		header('Location: '.$this_link);
		exit();
	    }
	    while(($tmp=strpos($news, "\n"))!==false)
		$news = substr($news, 0, $tmp).substr($news, $tmp+1);
	    $my_text=$news."\n".time()."\n".$_SESSION[SESSION_USER]."\n";
	    add_to_file($file, $my_text);
	    header('Location: '.$this_link);
	    exit();
	}
	else if($add_news_condition){
	    print '
		<form action="'.$this_link.'" method=post>
		<textarea name="news" rows=4 cols=80></textarea><!--to do-->
		<input type=submit value="'.SUBMIT_NEWS_TEXT.'" name="CNewsB'.$hash.'">
		</form>
	    ';
	}
	$content = file($file);
	$n = count($content);
	$n--;
	$k=$n;
	//to do: sort
	//to do: site explorer
	while($k>0){
	    print '
		<hr/>
		<div style="float: right;">'.date(DATE_FORMAT, $content[$k-1]).'</div>
		<div style="text-align: left; background: #ccf">by '.$content[$k].'</div>
		<div style="text-align: '.NEWS_TEXT_ALIGN.';">'.$content[$k-2].'</div>
	    ';
	    if($del_news_condition)
		print '
		    <form action="'.$this_link.'&def='.($k-2).'" method=post>
		    <input type=submit value="'.NEWS_DELETE_TEXT.'" name="delNews'.$hash.'">
		    </form>
		';//to do form->action
	    $k-=3;
	}
    }
?>