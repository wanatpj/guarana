<?php
    ob_start();
    session_start();
    unset($_SESSION);
    session_destroy();
    header('Location: index.php');
    exit();
    ob_end_flush();
?>