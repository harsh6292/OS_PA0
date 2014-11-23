/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;


/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		summary_tab[currpid][1].syscall_name="sys_chprio";
		summary_tab[currpid][1].frequency+=1;
	}
	
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		summary_tab[currpid][1].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
	
	
	summary_tab[currpid][1].time+=ctr1000-timer_start_value;	
	return(newprio);
}
