

/*
NAME		Grayson Whitaker
COURSE		ECE 2730
SECTION		004
DATE		2.1.2022
FILE		lab2.s
PURPOSE		The purpose of this assembly file is to define three functions and initialize seven variables
		so that the driver program may compile and run successfully
*/
/* begin assembly stub */

.globl dodiff
.type dodiff , @function
dodiff :
	/* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp
/*
FUNCTION	dodiff
PURPOSE		square each of the digit variables (digit1, digit2, digit3), and then add digit1^2 and digit2^2,
		and then subtract digit3^2
*/
	movl digit1, %eax
	mull digit1
	movl %eax, %ebx      #completes digit1 * digit1
	
	movl digit2, %eax
	mull digit2
	movl %eax, %ecx      #completes digit2 * digit2

	movl digit3, %eax
	mull digit3          #completes digit3 * digit3

	addl %ebx, %ecx      #completes (digit1 * digit1) + (digit2 * digit2)
	subl %ecx, %eax      #completes (digit1 * digit1) + (digit2 * digit2) - (digit3 * digit3)
	movl %eax, diff      #moves calculation into diff

	/* epilog */
	movl %ebp, %esp
	popl %ebx
	popl %ebp
	ret

.globl dosumprod
.type dosumprod, @function
dosumprod:
	/* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp
/*
FUNCTION	dosumprod
PURPOSE		add all three digit variables and store that value in sum, then multiply all three digit variables
		and store that in product
*/
	movl digit1, %eax	#moves digit1 into register A
	addl digit2, %eax	#completes digit1 + digit2
	addl digit3, %eax	#completes digit1 + digit2 + digit3
	movl %eax, sum		#moves calculation into sum

	movl digit1, %eax	#moves digit1 back into register A
	mull digit2			#completes digit1 * digit2
	mull digit3			#completes digit1 * digit2 * digit3
	movl %eax, product	#moves calculation into product

	/* epilog */
	movl %ebp, %esp
	popl %ebx
	popl %ebp
	ret

.globl doremainder
.type doremainder, @function
doremainder:
	/* prolog */
	pushl %ebp
	pushl %ebx
	movl %esp, %ebp
/*
FUNCTION	doremainder
PURPOSE		find the remainder of product / sum and store it in remainder
*/
	movl $0, %edx		#clears register D
	movl product, %eax	#moves product into register A
	divl sum		#completes product/sum
	movl %edx, remainder	#moves the remainder portion of divl operation into remainder variable

	/* epilog */
	movl %ebp, %esp
	popl %ebx
	popl %ebp
	ret

.comm digit1, 4
.comm digit2, 4
.comm digit3, 4
.comm diff, 4
.comm sum, 4
.comm product, 4
.comm remainder, 4


/* end assembly stub */
/* Do not forget the required blank line here! */
