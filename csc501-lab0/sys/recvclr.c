/* recvclr.c - recvclr */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;

/*------------------------------------------------------------------------
 *  recvclr  --  clear messages, returning waiting message (if any)
 *------------------------------------------------------------------------
 */
SYSCALL	recvclr()
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][7].syscall_name="sys_recvclr";
		summary_tab[currpid][7].frequency+=1;
	}
	
	STATWORD ps;    
	WORD	msg;

	disable(ps);
	if (proctab[currpid].phasmsg) {
		proctab[currpid].phasmsg = 0;
		msg = proctab[currpid].pmsg;
	} else
		msg = OK;
	restore(ps);
	
	summary_tab[currpid][7].time+=ctr1000-timer_start_value;
	return(msg);
}
