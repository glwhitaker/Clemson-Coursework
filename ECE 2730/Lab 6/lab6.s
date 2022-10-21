/*
NAME		Grayson Whitaker
COURSE		ECE 2730
SECTION		004
DATE		4.12.2022
FILE		lab6.s
PURPOSE		Define "Factorial" function in C driver file 
			in order to print the factorial of the number
            input by the user. Demonstrate ability to pass
            arguments/parameters to assembly functions, 
            return values from assembly functions, and implement 
            parameters and returns with recursive functions.

*/

/* begin assembly stub */

/*
FUNCTION	Factorial
PURPOSE		To calculate the factorial of a number input
            by the user.
*/

.globl Factorial
.type Factorial, @function

Factorial:
    /* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp
	subl $4, %esp               /* 4-bytes of memory for local int */
	                            /* -4(%ebp) - local variable (int) */

	movl 12(%ebp), %ecx	        /* %ecx = n */

	cmp $0, %ecx		        /* if(n == 0) OR (n == 1)*/
	je return1            
	cmp $1, %ecx
	je return1
	jmp else

    return1:                      /* return 1*/

        movl $1, %eax
        jmp return

    else:					    /* return n * Factorial(n-1); */
        movl %ecx, -4(%ebp)     /* move n to local variable */
        subl $1, %ecx
        pushl %ecx

        call Factorial

        movl -4(%ebp), %ecx	    /* %ecx = n; */
        mull %ecx			    /* n * Factorial(n-1) */
        jmp return

    return:
        /* epilog */
        movl %ebp, %esp
        popl %ebx
        popl %ebp

ret

/* end assembly stub */