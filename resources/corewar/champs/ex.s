.name "zork"
.comment "just a basic living prog"

#l2:	sti	r1,%:live,80000
	sti	%25,r1,r1
	and	r1,%0,r1
	fork	%:live
live:	live	%1
	zjmp	%:live
