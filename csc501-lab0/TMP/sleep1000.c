/* sleep1000.c - sleep1000 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;


/*------------------------------------------------------------------------
 * sleep1000 --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
SYSCALL sleep1000(int n)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][21].syscall_name="sys_sleep1000";
		summary_tab[currpid][21].frequency+=1;
	}
	
	STATWORD ps;    

	if (n < 0  || clkruns==0)
	{
		summary_tab[currpid][21].time+=ctr1000-timer_start_value;
	         return(SYSERR);
	}
	
	disable(ps);
	if (n == 0) {		/* sleep1000(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
    
    summary_tab[currpid][21].time+=ctr1000-timer_start_value;
	return(OK);
}
