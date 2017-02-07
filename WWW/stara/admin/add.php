<?PHP
if(!isset($_COOKIE['krok'])) setcookie("krok",0);
$ile=$_COOKIE['krok'];
$ile++;
setcookie("krok",$ile);
?>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<meta http-equiv="content-language" content="pl" >
<meta name="robots" content="index,follow" >
<meta name="Keywords" content="miql, Miql" >
<meta name="Description" content="Strona Miql'a" >
<meta name="rating" content="general" >
<meta name="author" content="Maciek 'Miql' Szmigiel" >
<meta name="copyright" content="Copyright by Strona Miql'a 2008" >
<title>Strona Miql'a</title>
</head>
<link rel="stylesheet" href="style.css" TYPE="text/css">
<body bgcolor=#2276be>
<center>
<table border=0 width=750>
  <tr height=75>
    <td align=center colspan="2">
      <img src="logo.jpg">
    </td>
  </tr>
  <tr>
    <td width=120 valign=top>
      <a href="index.php"><img src="news.jpg" border="0"></a>
      <a href="omnie.htm"><img src="omnie.jpg" border="0"></a>
      <a href="galeria.htm"><img src="galeria.jpg" border="0"></a>
      <a href="ksiega.php"><img src="ksiega.jpg" border="0"></a>
      <a href="linki.htm"><img src="linki.jpg" border="0"></a>
    </td>
    <td bgcolor=#2276be valign="top">
       <br>
       <table cellpadding="0" cellspacing="0" width=600> 
        <tr>
          <td style="line-height: 1px" width=10 height=10>
            <img src="lg.gif" alt="" />
          </td>
          <td bgcolor="#0cb4f8" style="line-height: 1px">
          </td>
          <td style="line-height: 1px" width=10 height=10>
           <img src="pg.gif" alt="" />
          </td>
        </tr>
        <tr>
          <td bgcolor="#0cb4f8">
          </td>
          <td bgcolor="#0cb4f8">
	  <center>
	  <font color="#C0FFFF" face="Comic Sans MS">
           <table>	
	   
            <tr>
	    
              <td colspan=2>
                <center>	      
<?PHP
if(strlen($_POST['wpis'])>1000) echo "Za bardzo się rozpisałeś.".$_POST['wpis'];
elseif(strlen($_POST['imie'])>30) echo "Za długie imię, czy na prawdę nazywasz się: ".$_POST['imie']." ?";
elseif(strlen($_POST['email'])>30) echo "Zbyt długi email...";
elseif(strlen($_POST['www'])>50) echo "Za długi adres strony www.";
elseif(strlen($_POST['gg'])>20) echo "Nieprawidłowy numer gg.";
elseif(empty($_POST['wpis'])) echo "Napisz coś.";
elseif(empty($_POST['imie'])) echo "Wpisz swoje imię.";
elseif($ile<3)
{
    $sciezka="ksiega.txt";
    $tryb="a+";
    $dane=fopen($sciezka, $tryb);
    @$_POST['wpis']=ereg_replace ("\n","|", $_POST['wpis']);
    @$_POST['wpis']=ereg_replace ("\r","", $_POST['wpis']);
    @$_POST['wpis']=ereg_replace ("`","", $_POST['wpis']);
    @$_POST['imie']=ereg_replace ("\n","", $_POST['imie']);
    @$_POST['email']=ereg_replace ("\n","", $_POST['email']);
    @$_POST['www']=ereg_replace ("\n","", $_POST['www']);
    @$_POST['gg']=ereg_replace ("\n","", $_POST['gg']);
    @$_POST['imie']=ereg_replace ("\r","", $_POST['imie']);
    @$_POST['email']=ereg_replace ("\r","", $_POST['email']);
    @$_POST['www']=ereg_replace ("\r","", $_POST['www']);
    @$_POST['gg']=ereg_replace ("\r","", $_POST['gg']);    
    @$_POST['imie']=ereg_replace ("`","", $_POST['imie']);
    @$_POST['email']=ereg_replace ("`","", $_POST['email']);
    @$_POST['www']=ereg_replace ("`","", $_POST['www']);
    @$_POST['gg']=ereg_replace ("`","", $_POST['gg']);
    $_POST['wpis']=stripcslashes($_POST['wpis']);
    $_POST['www']=stripcslashes($_POST['www']);
    $_POST['gg']=stripcslashes($_POST['gg']);
    $_POST['login']=stripcslashes($_POST['login']);
    $_POST['email']=stripcslashes($_POST['email']);
    flock($dane,2);
    fwrite($dane,htmlspecialchars($_POST['imie']).'`'.htmlspecialchars($_POST['email']).'`'.htmlspecialchars($_POST['www']).'`'.htmlspecialchars($_POST['gg']).'`'.htmlspecialchars($_POST['wpis'])."\n");
    flock($dane,3);
    fclose($dane);
    echo "Twój wpis został dodany.";
}
else
{
    echo "Anti Spam Protection.<br>Proszę wpisać się innym razem.";
}
echo "<br><br><a href=ksiega.php>Powrót</a><br><br>";
?>
</td>
	    </tr>
 </td>
            </tr>            
           </table>
          </td>   
          <td bgcolor="#0cb4f8">
          </td>
        </tr>
        <tr>
          <td style="line-height: 1px">
           <img src="ld.gif" alt="" />
          </td>
          <td bgcolor="#0cb4f8" style="line-height: 1px">
          </td>
          <td style="line-height: 1px">
           <img src="pd.gif" alt="" />
          </td>
        </tr>
       </table>
    </td>
  </tr>
  <tr>
    <td align=center colspan="2">
       <img src="miql.jpg">
    </td>
  </tr>
</table>
</center>
</body>
</html>
