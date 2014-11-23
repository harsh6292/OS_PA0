#include<conf.h>
#include<stdio.h>
#include<lab0.h>

int start_summary=0;

void syscallsummary_start()
{
	start_summary=1;

}

void syscallsummary_stop() 
{
	start_summary=0;
}

void printsyscallsummary()
{
	int num_proc;	//loop variable for all processes
	int sum_sys;	//loop variable for all sys calls
	int num_calls;	//loop variable to get actual number of calls made
	//unsigned long total_time;
	
	
	kprintf("\nTask 5: (printsyscallsummary)");
	for(num_proc=1;num_proc<NPROC; num_proc++)
	{
		if(proc_exist[num_proc]==1)
		{
		kprintf("\nProcess [pid:%d]", num_proc);
		
		for(sum_sys=0;sum_sys<27;sum_sys++)
		{
			//summary = &summary_tab[num_proc][sum_sys];
			if(summary_tab[num_proc][sum_sys].frequency > 0)
			{
				/*total_time=0;
				for(num_calls=1; num_calls<=summary->frequency; num_calls++)
				{
					total_time+=summary->time[num_calls];
				}*/
				
				kprintf("\n\tSyscall: %s, count: %d, average execution time: %lu (ms)", summary_tab[num_proc][sum_sys].syscall_name, summary_tab[num_proc][sum_sys].frequency, (summary_tab[num_proc][sum_sys].time/summary_tab[num_proc][sum_sys].frequency));
			}
		}
		}
	}
}
