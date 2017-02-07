<?php
    exit;
    $bool1 = $_SESSION[SESSION_PERMISSION]>=ADMIN;
    $bool2 = $_SESSION[SESSION_PERMISSION]>=HEAD_ADMIN;
    print '<div style=\'background: #8f8;\'><center>ALGORYTMY & SERWISY ALGORYTMICZNE</center><br>';
    get_form_with_links('links', 'LINKS_001', $bool1, $bool2);
    print '</div>';
?>