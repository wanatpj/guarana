<?PHP
    session_start();
    include('naglowek.php');
    echo "Zostałeś wylogowany";
    include('return2sender.php');
    session_destroy();
?>