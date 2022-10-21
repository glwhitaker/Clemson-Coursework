/*
NAME		Grayson Whitaker
COURSE		ECE 2730
SECTION		004
DATE		3.29.2022
FILE		lab5.s
PURPOSE		Define "Fib" function in C driver file 
			in order to print the Fibonacci sequence up 
            to the number input by the user plus one.
*/

/* begin assembly solution */

/*
FUNCTION	Fib
PURPOSE		To create the Fibonacci sequence up to the 
            number input by the user plus one.
*/

.globl Fib
.type Fib,@function
Fib:
	/* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp
	subl $8, %esp /* 4-bytes of memory for two ints */

    /* put code here */
    movl global_var, %eax
    movl %eax, -4(%ebp)         /* local_var = global_var */
    cmp $0, %eax
    je return                   /* if local_var is 0 */
    cmp $1, %eax
    je return                   /* if local_var is 1 */
    subl $1, %eax
    movl %eax, global_var       /* global_var = local_var - 1 */

    call Fib
    movl global_var, %eax
    movl %eax, -8(%ebp)
    movl -4(%ebp), %eax
    subl $2, %eax           /* subtract 2 from local_var */
    movl %eax, global_var   /* global_var = local_var - 2 */

    call Fib
    movl global_var, %eax   /* eax = global_var */
    movl -8(%ebp), %ebx
    addl %eax, %ebx         /* add eax to ebx */
    movl %ebx, global_var   /* global_var = temp_var */
    jmp return

	return:
	/* epilog */
    movl %ebp, %esp
    popl %ebx
    popl %ebp

	ret

/* end assembly stub */