/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

extern int start_summary;

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][2].syscall_name="sys_getpid";
		summary_tab[currpid][2].frequency+=1;
		
		summary_tab[currpid][2].time+=ctr1000-timer_start_value;
	}
	return(currpid);
}
