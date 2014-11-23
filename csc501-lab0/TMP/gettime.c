/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <lab0.h>
#include<proc.h>

extern int getutim(unsigned long *);
extern int start_summary;

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    unsigned long timer_start_value=ctr1000;
	if(start_summary==1)
	{
		
		summary_tab[currpid][4].syscall_name="sys_gettime";
		summary_tab[currpid][4].frequency+=1;
	}
	/* long	now; */

	/* FIXME -- no getutim */

	summary_tab[currpid][4].time+=ctr1000-timer_start_value;
    return OK;
}
