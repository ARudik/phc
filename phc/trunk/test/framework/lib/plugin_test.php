<?php
/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 */

class PluginTest extends Test
{
	function __construct ($plugin_name)
	{
		$this->plugin_name = $plugin_name;
		parent::__construct();
	}

	function get_test_subjects ()
	{
		return get_non_erroneous_scripts();
	}

	function check_prerequisites ()
	{
		return check_for_plugin ($this->plugin_name);
	}

	function get_name ()
	{
		return $this->plugin_name;
	}

	function get_command_line ($subject)
	{
		global $phc, $plugin_dir;
		$plugin = $this->plugin_name;
		return "$phc --run $plugin_dir/$plugin.la $subject 2>&1";
	}

	function run_test ($subject)
	{
		$command = $this->get_command_line ($subject);
		list ($output, $return_value) = complete_exec($command);
# TODO check return value aswell
		if ($output == "Success\n")
		{
			$this->mark_success ($subject);
		}
		elseif ($output == "Skipped\n")
		{
			$this->mark_skipped ($subject);
		}
		else
		{
			$this->mark_failure ($subject, $command, $return_value, $output);
		}
	}

}

?>
