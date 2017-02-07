<?php
    $bool1 = $bool2 = isLinksOperator($_SESSION[SESSION_USER]);
    if($bool1==1) print 'Linki muszą byc podawane w postaci: http://...<br/>Dane należy wpisywać bez enter-a.';
    print '<div style=\'background: #8f8;\'><center>ALGORYTMY & SERWISY ALGORYTMICZNE</center><br>';
    get_form_with_links('index.php?whereAmI=links', 'data/linki', 'hash862n163y', 5000, $bool1, $bool2);
    print '</div>';
//    print '<div style=\'background: #00f; color: white;\'><center></center>';
//    get_form_with_links('index.php?whereAmI=links', 'data/linki', 'hash862n163y', 5000, 1, 0);
//    print '</div>';
?>