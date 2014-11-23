#include<stdio.h>

unsigned long	*esp;
unsigned long	*ebp;

void printtos()
{
	asm("movl %esp,esp");
	asm("movl %ebp,ebp");
	int moreElements=0;
	kprintf("\n\nTask 3 (printtos)");
	kprintf("\nBefore [0x%08x]: 0x%08x",(ebp+2),*(ebp+2));	//current base pointer -2 is the same as stack pointer of calling process.

	kprintf("\nAfter ebp[0x%08x]: 0x%08x",(ebp),*(ebp)); 	//prints the stack pointer right after entering printtos() i.e. after "movl %esp, %ebp" after this esi, edi and ebx registers are also saved, hence 12 bytes difference on stack
	
	//kprintf("\ncurrent stack pointer  : %08x, [%08x]",(esp),*(esp));
		
	while(moreElements<4 && ebp>esp)
	{
		kprintf("\n\tElement[0x%08x]: 0x%08x",(esp+moreElements),*(esp+moreElements));
		moreElements++;
	}
	
}
