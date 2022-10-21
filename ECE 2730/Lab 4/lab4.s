/*
NAME		Grayson Whitaker
COURSE		ECE 2730
SECTION		004
DATE		2.16.2022
FILE		lab3.s
PURPOSE		Define "AtoI" function in C driver file 
			in order to convert an ascii value entered by
            the user into an integer value.
*/
/* begin assembly stub */
/*
FUNCTION	AtoI
PURPOSE		The purpose of the AtoI function is to convert an ascii
            ascii value entered by the user into an integer value.
*/
.globl AtoI
.type AtoI,@function
AtoI:
    /* prolog */
    pushl %ebp
    movl %esp, %ebp
    pushl %ebx
    pushl %esi
    pushl %edi

    movl $1, sign
    movl ascii, %ebx

CheckSpace:                 /* Skip over starting spaces */
    cmpb $32, (%ebx)
    jne CheckTab
    addl $1, %ebx
    jmp CheckSpace

CheckTab:                   /* Skip over starting tabs */
    cmpb $9, (%ebx)
    jne CheckPlus
    addl $1, %ebx
    jmp CheckSpace

CheckPlus:                  /* Check for plus sign at start */
    cmpb $43, (%ebx)
    jne CheckMinus
    addl $1, %ebx

CheckMinus:                 /* Check for minus sign at start */
    cmpb $45, (%ebx)
    jne Intptr
    movl $-1, sign
    addl $1, %ebx

Intptr:                     /* Initiate pointer to store addres of integer value */
    movl intptr, %ecx
    movl $0, (%ecx)
    movl $0, i
    movl i, %edi

Ones:                       /* Skip to ones place */
    cmpb $48, (%ebx, %edi, 1)
    js Back
    cmpb $57, (%ebx, %edi, 1)
    jns Back
    addl $1, %edi
    jmp Ones

Back:                       /* Back to ones place */
    addl $-1, %edi
    movl $1, multiplier

OnesMultiplier:             /* Set multiplier for ones place */
    cmpl $0, %edi
    js Sign
    movl $0, %eax
    movb (%ebx, %edi, 1), %al
    subl $48, %eax
    mull multiplier
    addl %eax, (%ecx)
    movl $10, %eax
    mull multiplier
    movl %eax, multiplier
    addl $-1 , %edi
    jmp OnesMultiplier

Sign:                       /* Multiply sign */
    movl (%ecx), %eax
    mull sign
    movl %eax, (%ecx)

return:
    /* epilog */
    popl %edi
    popl %esi
    popl %ebx
    movl %ebp, %esp
    popl %ebp
    ret

/* end assembly stub */