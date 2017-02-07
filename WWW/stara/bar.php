<?php
    print '
	<a href=index.php?whereAmI=home>'.NEWS_TEXT.'</a> |
	<a href=index.php?whereAmI=tasks>'.TASKS_TEXT.'</a> |
	<a href=index.php?whereAmI=submit>'.SUBMIT_TEXT.'</a> |
	<a href=index.php?whereAmI=status>'.STATUS_TEXT.'</a> |
	<a href=index.php?whereAmI=moje>'.MOJE_TEXT.'</a> |
	<a href=index.php?whereAmI=QNA>Q&A</a> |
	<a href=index.php?whereAmI=ranking>'.RANKING_TEXT.'</a> |
	<a href=index.php?whereAmI=tech>'.INFO_TEXT.'</a> |
	<a href=index.php?whereAmI=ctsi>Informacje o konkursie</a> |
	<a href=index.php?whereAmI=links>'.LINKS_TEXT.'</a> |
	<a href=index.php?whereAmI=edy>Profil</a> |
<!--//php td-->
	<a href=logout.php>'.LOG_OUT_TEXT.'</a><br>';
    if($_SESSION[SESSION_PERMISSION]>=ADMIN)
	print '
	    <a href=index.php?whereAmI=apanel>'.ADMIN_PANEL_TEXT.'</a>
	';
?>