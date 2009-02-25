<?php

	include ("common.php");

	function run_main ()
	{
		global $DB;

		$order = array (
			"revision",
			"branch",
			"author",
			"pass",
			"fail",
			"skip",
			"timeout",
			"benchmark",
			"test_date",
			"test_revision",
			"redo");

		foreach ($order as $header)
		{
			$headers[$header] = ucfirst (str_replace ("_", " ", $header));
		}
		$headers["revision"] = "Rev";
		$headers["test_revision"] = "Test rev";
		$headers["benchmark"] = "Bench";
		$headers["timeout"] = "T/O";

		$abbreviations = array ("branches/dataflow" => "df", "paul.biggar" => "pb", "edskodevries" => "edv");


		print "<table class=info>\n";
		print "<tr>\n";
		foreach (array_values ($headers) as $header)
			print "<th>$header</th>\n";

		// Completed tests
		$query = $DB->query ("
				SELECT	revision, author, test_date, test_revision, benchmark, branch, failed, redo
				FROM		complete
				");
		$completes = $query->fetchAll(PDO::FETCH_ASSOC);

		foreach ($completes as $complete)
		{
			$rev = (int)$complete["revision"];
			foreach ($complete as $key => $column)
			{
				// abbreviate long words
				if (isset ($abbreviations[$column]))
					$column = $abbreviations[$column];


				$revisions[$rev][$key] = $column;
			}
		}


		// Test results
		$query = $DB->query ("
				SELECT	revision, pass, fail, skip, timeout
				FROM		tests
				WHERE		testname == 'Total'
				");
		$tests = $query->fetchAll(PDO::FETCH_ASSOC);

		foreach ($tests as $test)
		{
			$rev = (int)$test["revision"];
			foreach ($test as $key => $column)
				$revisions[$rev][$key] = $column;
		}


		ksort ($revisions);

		# process data
		foreach ($revisions as $rev => &$data)
		{
			// Always use the correct branch for relative data
			$branch = $data["branch"];

			$data["difference"] = add_difference ("pass", $data, $revisions[$prev[$branch]]);
			add_difference ("fail", $data, $revisions[$prev[$branch]]);
//			add_difference ("skip", $data, $revisions[$prev[$branch]]);
//			add_difference ("timeout", $data, $revisions[$prev[$branch]]);

			$prev[$branch] = $rev;
			$data["test_date"] = date_from_timestamp ($data["test_date"]);
			unset ($data["failed"]);
		}

		$revisions = array_reverse ($revisions, true);


		# print out rows
		foreach ($revisions as $rev => $data)
		{
			print "<tr>\n";

			# pick a color
			$color = "";
			if ($data["difference"] > 0)
				$color = get_good_color ();
			elseif ($data["difference"] < 0)
				$color = get_bad_color ();
			unset ($data["difference"]);

			# add a link to revision
			$data["revision"] = "<a href=\"details.php?rev=$rev\">$rev</a>";

			foreach ($order as $header)
			{
				$value = $data[$header];
				print "<td$color>$value</td>\n";
			}
			print "<a/></tr>\n";
		}

	}
?>
