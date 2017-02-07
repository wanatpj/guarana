<?php
    ob_start();
    session_start();
//    if($_SESSION[SESSION_USER]=='wanat') exit("bye bye!");
    include('STL.php');
    include('const.php');
    include('sites/links.php');
    include('resource.php');
    include('basic_forms.php');
    include('functions.php');
    include('news.php');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>	
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="Description" content="Guarana">
    <meta name="Keywords" content="guarana">
    <meta http-equiv="Content-Language" content="pl">
    <meta name="Author" content="Jacek Szmigiel & Paweł Wanat">
    <meta http-equiv="Reply-To" content="***e-mail***, ***e-mail***">
    <meta http-equiv="Creation-Date" content="Thu, 31 Jul 2008 14:22:17 GMT">
    <meta name="Robots" content="all">
    <link rel="shortcut icon" href="gfx/g.jpg">
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
    function zegar()
    {
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
    if(isset($_SESSION[SESSION_MY_NAME]))
    { 
	print '<table width=100%><tr><td>Czas testerki: <SPAN id="Zegar"></SPAN></td>';
	print '<td align=right><table><tr><td>'.USER_TEXT.': </td><td bgcolor="';
	if($_SESSION[SESSION_PERMISSION]==HEAD_ADMIN)
	    print 'FF0000';
	else if($_SESSION[SESSION_PERMISSION]==ADMIN)
	    print '33dd33';
	print '">'.$_SESSION[SESSION_USER].'</td></tr></table></td></tr></table>';
    }
    print '<center><img src=./gfx/logo2.jpg></center><br>';
    //include('sites/minfo.php');
    if(isset($_GET['whereAmI'])) $wmI=$_GET['whereAmI'];
    else $wmI='home';
    if(isset($_SESSION[SESSION_MY_NAME]))
    {
	print '<center>';
	include('bar2.php');
	print '</center><hr/>';	
	if(!isset($wmI)||$wmI=='home'){
	    $bool1 = $_SESSION[SESSION_PERMISSION]>=ADMIN;//to do for less users//etoc
	    $bool2 = $_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN;//to do for less users//etoc
	    get_form_with_news('index.php?', 'data/news', 'm_news000', 1000, $bool1, $bool2);
	}
	else if($wmI=='tasks'){
	    $_GET['list'.'hashshh32']=true;//td
	    get_resource('index.php?whereAmI=tasks', 'tasks/', 'Zadania', 'hashshh32');
	}
	else if($wmI=='submit'){
	    include('sites/submit.php');   
	}
	else if($wmI=='status')
	{
	    include('sites/status.php');
	}
	else if($wmI=='view')
	{
	    include('sites/show_solution.php');
	}

	else if($wmI=='edy')
	{
	   include('sites/edytuj.php');
	}
	else if($wmI=='show')
	{
	    if($_GET['co']=="pawelek") include('tasks/pawelek.php');
	}
	else if($wmI=='details')
	{
	    include('sites/details.php');
	}
	else if($wmI=='submissions'){
	    include('sites/solutions.php');
	}
	else if($wmI=='tech'){
	    include('sites/info.php');
	}
	else if($wmI=='send')
	{
	    include('sites/submitResult.php');
	}
	else if($wmI=='links'){
	    include('sites/linki.php');
	}
	else if($wmI=='moje'){
	    include('sites/moje.php');
	}
	else if($wmI=='apanel'&&$_SESSION[SESSION_PERMISSION]>=ADMIN){
	    include('sites/apanel.php');
	}
	else if($wmI=='ranking'){
	    include('sites/ranking.php');
	}
	else if($wmI=='ctsi'){
	    include('sites/ctsi.php');
	}
	else if($wmI=='QNA'){
	    include('sites/usrQNA.php');
	}
	else print BUG_WARNING_TEXT;
    }
    else if($wmI=='rej')
    {
	include('sites/rejestracja.php');
    }
    else
    {
	/*print '
	    Nie jestes zalogowany.<br/>
	    Narazie nie istnieją żadne opcje dla uzytkowników niezalogowanych.<br/>
	    <br/>'*/print '<br><Br><center>
	';
	//login_form();//etoc -> basic_forms.php
	include('sites/logowanie.php');
	print '</center><br><br>';
    }
    print '<hr/><center>Powered by: '.ADMINS.' | 2008 - '.date("Y").'</center>';//etoc
?>
</body>
</html>
<?php
    ob_end_flush();
?>
