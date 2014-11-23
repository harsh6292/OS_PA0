/* resume.c - resume */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;

/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
SYSCALL resume(int pid)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][9].syscall_name="sys_resume";
		summary_tab[currpid][9].frequency+=1;
	}
	
	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);
		summary_tab[currpid][9].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);
	
	summary_tab[currpid][9].time+=ctr1000-timer_start_value;
	return(prio);
}
