<?php
	$x = array(1 => "a", 2 => "b", 3 => "c", 4 => "d");

	foreach($x as $y)
	{
		echo "$y\n";
		break;
	}
	
	foreach($x as $y => $z)
	{
		echo "$y => $z\n";
	}
	
	foreach($x as &$y)
	{
		echo "$y\n";
	}
	
	foreach($x as $y => &$z)
	{
		echo "$y => $z\n";
	}
?>
