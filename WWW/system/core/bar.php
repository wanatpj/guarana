<?php
	//include("const.php");
	print '

	<style>
		div[id="menu_glowne"] a:link {color: red}
		div[id="menu_glowne"] img {border: 0px}
	</style>
	<div id="menu_glowne">
		<table align="center" cellspacing="15px">
			<tbody style="font-size: 12px; font-family: \'Arial\';">
			<tr align="center">
				<td width="60"><a href=index.php?whereAmI=home><img src="system/img/news.jpg" width="60" height="60"/>'.NEWS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=tasks><img src="system/img/tasks.jpg" width="60" height="60"/>'.TASKS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=submit><img src="system/img/test.jpg" width="60" height="60"/>'.SUBMIT_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=status><img src="system/img/status.jpg" width="60" height="60"/>'.STATUS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=moje><img src="system/img/zgloszenia.jpg" width="60" height="60"/>'.MOJE_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=QNA><img src="system/img/qna.jpg" width="60" height="60"/>Q&A</a></td>
				<td width="60"><a href=index.php?whereAmI=ranking><img src="system/img/ranking.jpg" width="60" height="60"/>'.RANKING_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=tech><img src="system/img/info.jpg" width="60" height="60"/>'.INFO_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=ctsi><img src="system/img/konkurs.jpg" width="60" height="60"/>Konkurs</a></td>
				<td width="60"><a href=index.php?whereAmI=links><img src="system/img/link.png" width="60" height="60"/>'.LINKS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=edy><img src="system/img/profil.jpg" width="60" height="60"/>Profil</a></td>
				<td width="60"><a href=index.php?whereAmI=logout><img src="system/img/wyloguj.png" width="60" height="60"/>'.LOG_OUT_TEXT.'</a></td>
			</tr>
			</tbody>
		</table>
	</div>
	';
if($_SESSION[SESSION_PERMISSION]>=ADMIN)
		print '
		<a href=index.php?whereAmI=apanel>'.ADMIN_PANEL_TEXT.'</a>
		';
		?>
