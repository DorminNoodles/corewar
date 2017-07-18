.name "zork"
.comment "just a basic living prog"

		ld	%750,r1
		ld	%2000,r2
		ld	%2000,r3
		add r2,r3,r4
		sti	r1,%1200,%0
		sti	r4,%180,%0
		ld %780, r1
		sti	r1,%300,%30
		sti	r1,%400,%42
		sti	r1,%600,%60
		ld %1003, r2
		sti	r2,%800,%42
		sti	r1,%200,%150
		sti	r1,%800,%200
		sti	r1,%900,%230

#		ld %240, r1
#		fork	%:live
#live:	live	%1
#		zjmp	%:live
#		and	r1,%0,r1
#l2:	sti	r1,%:live,80000
