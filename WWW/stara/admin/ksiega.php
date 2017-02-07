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
	  <font color="#C0FFFF" face="Comic Sans MS">
           <table width=100%>	
            <tr>
              <td colspan=2>
                <center><b>Księga Gości</b></center><br><br>
	      </td>
	    </tr>
		<?PHP
		if(!isset($_COOKIE['krok'])||$_COOKIE['krok']<3)
		{
		    echo "
		    <form method=post action=add.php>
		    <input type=hidden name=krok value=1>
		    <tr><td>Imię: </td><td><input type=text name=imie maxlength=30></td></tr>
		    <tr><td>E-mail: </td><td><input type=text name=email maxlength=30></td></tr>
		    <tr><td>Twoja strona WWW: </td><td><input type=text name=www maxlength=50></td></tr>
		    <tr><td>Twój numer gadu-gadu: </td><td><input type=text name=gg maxlength=20></td></tr>
		    <tr><td>Dodaj wpis: </td><td><textarea cols=40 rows=6 name=wpis></textarea></td></tr>
		    <tr><td colspan=2><center><input type=submit value= Wyślij > <input type=reset value= Wyczyść ></td></tr>
		    </form><br><br><tr><td colspan=2><br><hr></td></tr>";
		}
		$sciezka="ksiega.txt";
		if(file_exists($sciezka))
		{
		    $dane=fopen($sciezka,"r");
		    echo "<tr><td colspan=2>";
		    while(true)
		    {
			$linia=fgets($dane);
			if($linia===false) break;
			$exp = explode("`",$linia);
			echo "Imię: ".$exp[0];
			if(!empty($exp[1])) echo "<br>E-mail: ".$exp[1];
			if(!empty($exp[2])) echo "<br>WWW: ".$exp[2];
			if(!empty($exp[3])) echo "<br>GG: ".$exp[3];
			echo "<br>Wpis: ";
			$dl=strlen($exp[4]);
			for($i=0;$i<$dl;$i++) if($exp[4][$i]=='|') echo "<br>"; else echo $exp[4][$i];
			echo "<br><br><hr><br>";
		    }
		    fclose($dane);
		}
		echo "</td></tr>";
		?>
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
