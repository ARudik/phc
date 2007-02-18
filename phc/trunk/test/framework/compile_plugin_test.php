<?php
/*
 * phc -- the open source PHP compiler
 * See license/README.is_license for licensing information
 * Unit test for dot output. Checks for syntax errors
 */

require_once ("lib/no_subject_test.php");
class CompilePluginTest extends NoSubjectTest
{
	function check_prerequisites ()
	{
		global $phc_compile_plugin;
		return check_for_program ($phc_compile_plugin);
	}

	function run_test ($subject)
	{
		phc_assert ($subject == "All", "Shouldnt have test subjects passed here");
		global $phc_compile_plugin;

		$command = "cp plugins/tools/purity_test.cpp plugin.cpp 2>&1";
		list ($output, $return_value) = complete_exec ($command);
		if ($output)
		{
			$this->mark_failure ("All", $command, $return_value, $output);
			return;
		}


		$command = "$phc_compile_plugin plugin.cpp 2>&1";
		list ($output, $return_value) = complete_exec ($command);
		if ($output) $this->mark_failure ("All", $command, $return_value, $output);
		else $this->mark_success ("All");
	}
}


array_push($tests, new CompilePluginTest ());

?>
