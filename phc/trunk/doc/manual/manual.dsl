<!DOCTYPE style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN" [
<!ENTITY print-ss PUBLIC "-//Norman Walsh//DOCUMENT DocBook HTML Stylesheet//EN" CDATA DSSSL>
<!ENTITY html-ss PUBLIC "-//Norman Walsh//DOCUMENT DocBook HTML Stylesheet//EN" CDATA DSSSL>
]>

<style-sheet>

<style-specification id="print" use="print-stylesheet">
<style-specification-body>
</style-specification-body>
</style-specification>

<style-specification id="html" use="html-stylesheet">
<style-specification-body>

(define %use-id-as-filename% #t)

(element Application
	(make element gi:"tt" (process-children))
)

</style-specification-body>
</style-specification>

<external-specification id="print-stylesheet" document="print-ss">
<external-specification id="html-stylesheet" document="html-ss">

</style-sheet>
