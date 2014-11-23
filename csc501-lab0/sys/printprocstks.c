#include<conf.h>
#include<kernel.h>
#include<proc.h>
#include <stdio.h>

unsigned long *stack_pointer;

void printprocstks(int priority)
{
	int nproc;
	struct pentry *process;
	
	//kprintf("\nNo of processes : %d", NPROC);
	kprintf("\n\nTask 4 (printprocstks)");
	for(nproc=1;nproc<=NPROC;nproc++)
	{
		process = &proctab[nproc];
		//kprintf("\nno of processes : %d", numproc);
		if(process->pprio > priority && (process->pstate!=PRFREE))
		{
			kprintf("\nProcess [%s]", process->pname);
			kprintf("\n\t pid : %d", nproc);
			kprintf("\n\t priority : %d", process->pprio);
			kprintf("\n\t base : 0x%08x", process->pbase);
			kprintf("\n\t limit : 0x%08x", process->plimit);
			kprintf("\n\t len : %d", process->pstklen);
			//kprintf("\n\t pointer : 0x%08x", process->pprio);
			if(process->pstate==PRCURR)		//process is currently running
			{
				asm("movl %esp, stack_pointer");
				kprintf("\n\t pointer : 0x%08x", stack_pointer);
			}
			else
				kprintf("\n\t pointer : 0x%08x", process->pesp);	//process is not currently running, so stack pointer is saved
		}
	}

}




