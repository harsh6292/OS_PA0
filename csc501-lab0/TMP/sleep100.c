/* sleep100.c - sleep100 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;


/*------------------------------------------------------------------------
 * sleep100  --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
SYSCALL sleep100(int n)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][20].syscall_name="sys_sleep100";
		summary_tab[currpid][20].frequency+=1;
	}
	
	STATWORD ps;    

	if (n < 0  || clkruns==0)
	{
		summary_tab[currpid][20].time+=ctr1000-timer_start_value;
	         return(SYSERR);
	}
	
	disable(ps);
	if (n == 0) {		/* sleep100(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*10);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
    summary_tab[currpid][20].time+=ctr1000-timer_start_value;
	return(OK);
}
