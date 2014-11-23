/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>


extern int start_summary;


/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][18].syscall_name="sys_sleep";
		summary_tab[currpid][18].frequency+=1;
	}
	
	STATWORD ps;    
	if (n<0 || clkruns==0)
	{
		summary_tab[currpid][18].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		summary_tab[currpid][18].time+=ctr1000-timer_start_value;
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
		
	
	summary_tab[currpid][18].time+=ctr1000-timer_start_value;	
		
	return(OK);
}
