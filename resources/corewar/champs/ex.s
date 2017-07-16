.name "zork"
.comment "just a basic living prog"

#l2:	sti	r1,%:live,80000
#	ld %240, r1
	sti	r1,%65535,%90
	and	r1,%0,r1
	fork	%:live
live:	live	%1
	zjmp	%:live
