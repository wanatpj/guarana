<?php
    //const.php must be preincluded//etoc//shift the comment//etoc
    function login_form(){
	print '
	    <div>
	    <form action=logon.php method=post>
	    <table><tr><td>'.LOGIN_TEXT.': </td><td>
	    <input type=text name=user size=20></td></tr><tr><td>
	    '.PASSWORD_TEXT.': </td><td>
	    <input type=password name=passwd></td></tr></table>
	    <input type=submit value="'.LOG_IN_TEXT.'">
	    </table>
	    </form>
	    </div>
	';
    }
?>