<html>
<head>
<title>Strona Miql'a</title>
</head>
<body bgcolor=#2276be>
<center>
<table border=0 width=750>
  <tr height=75>
    <td align=center colspan="2">
      <img src="logo.jpg">
    </td>
  </tr>
  <tr>
    <td width=120 valign="top">
      <a href="index.htm"><img src="news.jpg" border="0"></a>
      <a href="omnie.htm"><img src="omnie.jpg" border="0"></a>
      <a href="galeria.htm"><img src="galeria.jpg" border="0"></a>
      <a href="ksiega.php"><img src="ksiega.jpg" border="0"></a>
      <a href="linki.htm"><img src="linki.jpg" border="0"></a>
    </td>
    <td bgcolor=#2276be valign="top">
       <br>
       <table cellpadding="0" cellspacing="0" width=600> 
        <tr>
          <td style="line-height: 1px">
            <img src="lg.gif" alt="" />
          </td>
          <td bgcolor="#0cb4f8" style="line-height: 1px">
          </td>
          <td style="line-height: 1px">
           <img src="pg.gif" alt="" />
          </td>
        </tr>
        <tr>
          <td bgcolor="#0cb4f8">
          </td>
          <td bgcolor="#0cb4f8">
           <table width=100%>	
            <?PHP
            $tab=file('news.txt');
            for($i=0;$i<sizeof($tab);$i++)
            {
             $exp=explode('`',$tab[$i]);
            echo "<tr>
              <td colspan=2><font color=#C0FFFF face='Comic Sans MS'>
                ".$exp[2]."
              </td>
            </tr>
            <tr>
              <td><font color=#C0FFFF face='Comic Sans MS'><b>Dodał: ".$exp[1]."</b>
              </td>
              <td  align=right><font color=#C0FFFF face='Comic Sans MS'><b>Data: ".$exp[0]."
              </td></tr>
              <tr><td colspan=2><hr><br></td>
            </tr>";
              }
             ?>            
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