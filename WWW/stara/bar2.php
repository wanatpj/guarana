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
				<td width="60"><a href=index.php?whereAmI=home><img src="gfx/news.jpg" width="60" height="60"/>'.NEWS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=tasks><img src="gfx/tasks.jpg" width="60" height="60"/>'.TASKS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=submit><img src="gfx/test.jpg" width="60" height="60"/>'.SUBMIT_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=status><img src="gfx/status.jpg" width="60" height="60"/>'.STATUS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=moje><img src="gfx/zgloszenia.jpg" width="60" height="60"/>'.MOJE_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=QNA><img src="gfx/qna.jpg" width="60" height="60"/>Q&A</a></td>
				<td width="60"><a href=index.php?whereAmI=ranking><img src="gfx/ranking.jpg" width="60" height="60"/>'.RANKING_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=tech><img src="gfx/info.jpg" width="60" height="60"/>'.INFO_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=ctsi><img src="gfx/konkurs.jpg" width="60" height="60"/>Konkurs</a></td>
				<td width="60"><a href=index.php?whereAmI=links><img src="gfx/link.png" width="60" height="60"/>'.LINKS_TEXT.'</a></td>
				<td width="60"><a href=index.php?whereAmI=edy><img src="gfx/profil.jpg" width="60" height="60"/>Profil</a></td>
				<td width="60"><a href=logout.php><img src="gfx/wyloguj.png" width="60" height="60"/>'.LOG_OUT_TEXT.'</a></td>
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
