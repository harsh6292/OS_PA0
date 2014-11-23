/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include<proc.h>
#include <lab0.h>


extern int start_summary;

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{

	unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][10].syscall_name="sys_scount";
		summary_tab[currpid][10].frequency+=1;
	}
	
	extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
	{
		summary_tab[currpid][10].time+=ctr1000-timer_start_value;
		return(SYSERR);
	}
	
	summary_tab[currpid][10].time+=ctr1000-timer_start_value;
	return(semaph[sem].semcnt);
}
