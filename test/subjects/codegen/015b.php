<?php
	function main()
	{
		$a = 5;
		$b[1] =& $a;
		var_dump($b);
	}
?>
