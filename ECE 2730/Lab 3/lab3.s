/*
NAME		Grayson Whitaker
COURSE		ECE 2730
SECTION		004
DATE		2.16.2022
FILE		lab3.s
PURPOSE		Define "classify" function in C driver file 
			in order to classify a triangle by the length
			of each of its sides (entered by the user).
*/
/* begin assembly stub */
/*
FUNCTION	classify
RETURNS		Returns integer "tri_type"
PURPOSE		The purpose of the classify function is to determine
			if a triangle is valid based on its side lenghts.
			If it is a valid triangle, it then classifies it as
			as either isosceles, equilateral, or scalene in the form
			of integer "tri_type".
*/
.globl classify
.type classify,@function
classify:
	/* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp

	movl i, %eax				/* if any of the sides = 0, the shape is not a triangle */
	cmpl $0, %eax
	je nottri
	movl j, %eax
	cmpl $0, %eax
	je nottri
	movl k, %eax
	cmpl $0, %eax
	je nottri

	movl $0, match
	
	matchif1:
		movl i, %eax			/* see if any sides are matching lengths */
		cmpl j, %eax
		jne matchif2
		addl $1, match

	matchif2:
		movl i, %eax
		cmpl k, %eax
		jne matchif3
		addl $2, match

	matchif3:
		movl j, %eax
		cmpl k, %eax
		jne mainif
		addl $3, match

	mainif:
		movl match, %eax		/* outermost if statement */
		cmpl $0, %eax
		je checkif
		cmpl $1, %eax
		jne else1
		movl i, %ebx
		addl j, %ebx
		cmpl k, %ebx
		jg endif
		jmp nottri

	else1:
		cmpl $2, %eax
		je else2
		cmpl $6, %eax
		jne else3
		movl $1, tri_type
		jmp return

	else3:
		movl j, %ecx
		addl k, %ecx
		cmpl i, %ecx
		jg endif
		jmp nottri

	else2:
		movl i, %edx
		addl k, %edx
		cmpl j, %edx
		jg endif
		jmp nottri

	endif:
		movl $2, tri_type
		jmp return

	checkif:
		movl i, %ebx			/* check if shape can be a triangle*/
		addl j, %ebx
		cmpl k, %ebx
		jle nottri
		movl j, %ecx
		addl k, %ecx
		cmpl i, %ecx
		jle nottri
		movl i, %edx
		addl k, %edx
		cmpl j, %edx
		jle nottri
		movl $3, tri_type
		jmp return
		
	nottri:
		movl $0, tri_type		/* shape is not triangle */
		jmp return

	return:
	/* epilog */
	movl %ebp, %esp
	popl %ebx
	popl %ebp
	ret

.comm match, 4

/* end assembly stub */
