	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"Hello World !"
.LC1:
	.string	"Today is a great day."
.LC2:
	.string	"       KUSHAGRA.\r"
.LC3:
	.string	"SAXENA"
	.align 8
.LC4:
	.string	"David says , \" Programmming is fun !\""
.LC5:
	.string	"Good bye !\n"
	.align 8
.LC6:
	.string	"David says, \" Programming is fun !\"\nD:/My documents/My file"
	.align 8
.LC7:
	.string	"**Conditions apply, \"Offers valid until tomorrow\""
.LC8:
	.string	"C:\\My computer\\My folder"
	.align 8
.LC9:
	.string	"\\ \\ \\ \\ Today is holiday \\ \\ \\ \\ "
	.align 8
.LC10:
	.string	"This is a triple quoted string \"\"\"This month has 30 days \"\"\""
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %edi
	call	puts
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC3, %edi
	call	puts
	movl	$.LC4, %edi
	call	puts
	movl	$.LC5, %edi
	call	puts
	movl	$.LC6, %edi
	call	puts
	movl	$.LC7, %edi
	call	puts
	movl	$.LC8, %edi
	call	puts
	movl	$.LC9, %edi
	call	puts
	movl	$.LC10, %edi
	call	puts
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 6.5.0-2ubuntu1~14.04.1) 6.5.0 20181026"
	.section	.note.GNU-stack,"",@progbits
