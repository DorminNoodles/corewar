.name "zork"
.comment "just a basic living prog"

#		ld %300, r10
		ld %-4, r2
		ld %-4, r3
		ldi r2, r3, r5
		sti r5, %20, %20
		live %-1
		live %-1
		live %-1
#		ld %8888, r6
#		fork %10
#		ld %0, r14
#		zjmp %-80
#		live %0
#		st r6, 200
#		ld %50, r5
#		st r5, -521
#		sti r5, %-521, %0
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
