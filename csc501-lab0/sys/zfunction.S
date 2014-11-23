.text
.globl zfunction
.type zfunction,@function

zfunction:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp),%eax

	andl $0xFF803FFF, %eax
	shll $4, %eax

	leave
	ret
	
