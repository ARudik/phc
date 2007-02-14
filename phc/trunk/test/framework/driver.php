<?php

// when dealing with the manual, we need more space
ini_set("memory_limit","256M");
ini_set("include_path","test/framework/external/:".ini_get("include_path"));
set_time_limit (0); // dont let the script time out

// check version of php
if (substr (phpversion (), 0, 1) < 5)
{
	die("Tests skipped (PHP version 5 required)\n");
}

$support_dir =		"test/support_files";
$log_directory =	"test/logs";
$plugin_dir = "plugins";

require_once ("lib/startup.php");
require_once ("lib/header.php");

$phc = get_phc ();
$php = get_php ();

require_once ("lib/test.php");
require_once ("lib/plugin_test.php");
require_once ("lib/two_command_test.php");
require_once ("lib/regression.php");



if ($opt_installed)
{
	$phc = "$bindir/phc";
	$plugin_dir = "$pkglibdir/plugins";
}

$tests = array ();

require_once ("basic_parse_tests.php");
array_push($tests, new PluginTest ("cloning"));
require_once ("compiled_vs_interpreted.php");
require_once ("compile_time_include.php");
require_once ("interpret_canonical_unparsed.php");
require_once ("interpret_unparsed.php");
array_push($tests, new PluginTest ("linear"));
require_once ("line_numbers.php");
require_once ("parse_ast_dot.php");
array_push($tests, new PluginTest ("pre_vs_post_count"));
require_once ("regression_dump_ast.php");
require_once ("regression_dump_includes.php");
require_once ("regression_dump_php.php");
require_once ("reparse_unparsed.php");
require_once ("source_vs_semantic_values.php"); // dont use plugin_test here
array_push($tests, new PluginTest ("xml_roundtrip"));

if (!$opt_no_delete)
{
	echo "rm -Rf $log_directory/*\n";
	`rm -Rf $log_directory/*`;
}

require_once ("lib/labels.php");
open_skipped_file ();

foreach ($tests as $test)
{
	$test_name = $test->get_name ();

	/* if there are regexes, check them, and skip tests not matching one of them */
	if (count ($arguments) > 0)
	{
		$match = false;
		foreach ($arguments as $regex)
		{
			if (preg_match ("/$regex/", $test_name)) $match = true;
		}

		if (!$match)
		{
//			print "Skipping $test_name\n";
			continue;
		}
	}

	if ($opt_support)
	{ 
		if (method_exists ($test, "generate_support_files"))
		{
			$test->generate_support_files ();
		}
	}
	elseif ($opt_numbered)
	{
		$test->print_numbered ();
	}
	else $test->run ();
}

close_skipped_file ();

?>
