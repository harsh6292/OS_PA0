/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;


/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][3].syscall_name="sys_getprio";
		summary_tab[currpid][3].frequency+=1;
	}
	
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		summary_tab[currpid][3].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	restore(ps);
	
	
	summary_tab[currpid][3].time+=ctr1000-timer_start_value;
	return(pptr->pprio);
}
