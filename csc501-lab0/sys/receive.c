/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;

/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */
SYSCALL	receive()
{
	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][6].syscall_name="sys_receive";
		summary_tab[currpid][6].frequency+=1;
	}
	
	STATWORD ps;    
	struct	pentry	*pptr;
	WORD	msg;

	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);
	
	summary_tab[currpid][6].time+=ctr1000-timer_start_value;
	return(msg);
}
