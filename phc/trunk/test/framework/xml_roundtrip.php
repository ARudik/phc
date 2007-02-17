<?php
/*
 * phc -- the open source PHP compiler
 * See license/README.license for licensing information
 * Compares phc's internal values with the source representations of them
 */

array_push($tests, new XMLRoundtrip());
class XMLRoundtrip extends PluginTest
{
	function __construct ()
	{
		parent::__construct("xml_roundtrip");
	}

	function check_prerequisites ()
	{
		global $xerces_compiled_in;
		return parent::check_prerequisites () and
			$xerces_compiled_in;
	}
	
}


