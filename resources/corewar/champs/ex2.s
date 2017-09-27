.name "zork"
.comment "just a basic living prog"

		ld %3289650, r3
#		ld -100, r1
		sti r3, %-60, %0
		sti r3, %-62, %0
		sti r3, %-64, %0
		sti r3, %-66, %0
		sti r3, %-68, %0
		sti r3, %-70, %0
		sti r3, %-72, %0
		sti r3, %-74, %0
		sti r3, %-76, %0

		ld -55, r4
		sti r4, %10, %0

#		sti r3, %-58, %0
#		sti r3, %-57, %0
#		sti r3, %-56, %0
#		zjmp %-71
#		st r2, -3
#		ld %0, r2
#		sti	r2,%5000,%0
#		sti	r2,%-200,%0
#		sti	r2,%-600,%0
#		sti	r2,%-768,%0
#		sti	r2,%3200,%0
#		st r2, -522
#		st r2, 600
#		st r2, -200
#		st r2, 522
#		st r2, -622
#		ld %1, r5
#		ld %0, r6
#		zjmp %-50
#		ld %1, r5
#		ld %1, r5
#		ld %1, r5
#		fork %0
#		live %-1
#		fork %2
#		ld %-1, r2
#		ld %-1, r2
#		live %-1
#		sti	r2,%400,%0
#		sti	r3,%410,%0
#		live %-3
