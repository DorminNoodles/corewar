.name "Gaspard"
.comment "aya caramba!"
.extend

l2:	 sti r1, %:live, %1
live:	 live %8
		fork %:l2
		fork %:live
		fork %:l2
		fork %:l2
