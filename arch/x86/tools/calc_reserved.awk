#!/bin/awk -f
#
# Calculate the amount of space that we have to reserve for .bss and .brk
# sections
#
# Usage:
# objdump -h a.out | awk -f calc_reserved.awk

BEGIN {
	sections = "^.bss$|^.brk$"
	size = 0;
}

/^ *[0-9]+ [a-z._]+ *[0-9a-f]+/ {
	if (match($2, sections))
		size += strtonum("0x" $3);
}

END {
	printf("%d\n", size);
}
