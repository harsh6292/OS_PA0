/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

extern int start_summary;

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][13].syscall_name="sys_setdev";
		summary_tab[currpid][13].frequency+=1;
	}
	
	short	*nxtdev;

	if (isbadpid(pid))
	{
		summary_tab[currpid][13].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	summary_tab[currpid][13].time+=ctr1000-timer_start_value;
	return(OK);
}
