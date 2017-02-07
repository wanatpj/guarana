<?php
    ob_start();
    session_start();
    include('system/core/config.php');
    include('system/core/STL.php');
    include('system/core/const.php');
    include('system/core/links.php');
    include('system/core/basic_forms.php');
    include('system/core/functions.php');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>	
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="Description" content="Guarana">
    <meta name="Keywords" content="guarana">
    <meta http-equiv="Content-Language" content="pl">
    <meta name="Author" content="Jakub Adamek & Jacek Szmigiel & Paweł Wanat">
    <meta http-equiv="Reply-To" content="***e-mail***, ***e-mail***">
    <meta http-equiv="Creation-Date" content="Thu, 31 Jul 2008 14:22:17 GMT">
    <meta name="Robots" content="all">
    <link rel="shortcut icon" href="system/img/g.jpg">
    <title>Guarana - testerka</title>
    <style type="text/css">
    <!--

	body
	{
	    color: #000000;
	    background-color: #FFFFFF;
	    margin-left: 5px; margin-right: 5px;
	    margin-top: 5px; margin-bottom: 5px;
	}
	a:link { color: #003300 }
	a:visited { color: #003300 }
	a:active { color: #000000 }
	a:hover { color: #f00; }
    -->
    </style>
    <script type="text/javascript">
    var s = <?php $time=gettimeofday(); echo ($time['sec']+7200);?>;
    function zegar() {
	var sek = s%60; if (sek <= 9) {sek = "0"+sek;}
	var min = ((s-sek)/60)%60; if (min <= 9) {min = "0"+min;}    
	var godzina = ((s-sek-min*60)/3600)%24; if (godzina <= 9) {godzina = "0"+godzina;}
	document.getElementById("Zegar").innerHTML = ""+godzina+":"+min+":"+sek;
	s++;
    }  
    setInterval("zegar()", 1000);
    </script>
    </head>
<?php
    if(isset($_SESSION[SESSION_MY_NAME])) { 
	print '<table width=100%><tr><td>Czas testerki: <SPAN id="Zegar"></SPAN></td>';
	print '<td align=right><table><tr><td>'.USER_TEXT.': </td><td bgcolor="';
	if($_SESSION[SESSION_PERMISSION]==HEAD_ADMIN) print 'FF0000';
	else if($_SESSION[SESSION_PERMISSION]==ADMIN) print '33dd33';
	print '">'.$_SESSION[SESSION_USER].'</td></tr></table></td></tr></table>';
    }
    print '<center><img src=./system/img/logo.jpg></center><br>';
    if(isset($_GET['whereAmI'])) $wmI=$_GET['whereAmI'];
    else $wmI='home';
    if(isset($_SESSION[SESSION_MY_NAME])) {
	print '<center>';
	include('system/core/bar.php');
	print '</center><hr/>';	
	if(!isset($wmI)||$wmI=='home'){
		include('system/core/news.php');
	}
	else if($wmI=='tasks'){
	    include('system/core/tasks.php');
	}
	else if($wmI=='submit'){
	    include('system/core/submit.php');   
	}
	else if($wmI=='status'){
	    include('system/core/status.php');
	}
	else if($wmI=='view'){
	    include('system/core/show_solution.php');
	}
	else if($wmI=='edy'){
		include('system/core/edytuj.php');
	}
	else if($wmI=='details'){
	    include('system/core/details.php');
	}
	else if($wmI=='submissions'){
	    include('system/core/solutions.php');
	}
	else if($wmI=='tech'){
	    include('system/core/info.php');
	}
	else if($wmI=='send'){
	    include('system/core/submitResult.php');
	}
	else if($wmI=='links'){
	    include('system/core/linki.php');
	}
	else if($wmI=='moje'){
	    include('system/core/moje.php');
	}
	else if($wmI=='showusthecode'){
	    include('system/core/showusthecode.php');
	}
	else if($wmI=='apanel'&&$_SESSION[SESSION_PERMISSION]>=ADMIN){
	    include('system/admin/panel.php');
	}
	else if($wmI=='ranking'){
	    include('system/core/ranking.php');
	}
	else if($wmI=='ctsi'){
	    include('system/core/ctsi.php');
	}
	else if($wmI=='QNA'){
	    include('system/core/QNA.php');
	}
	else if($wmI=='logout'){
	    include('system/core/logout.php');
	}	
	else print BUG_WARNING_TEXT;
    }
    else if($wmI=='rej'){
	include('system/core/rejestracja.php');
    }
    else{
	print '<br><Br><center>';
	include('system/core/logowanie.php');
	print '</center><br><br>';
    }
    print '<hr/><center>Powered by: '.ADMINS.' | 2008 - '.date("Y").'</center>';//etoc
?>
</body>
</html>
<?php
    ob_end_flush();
?>
