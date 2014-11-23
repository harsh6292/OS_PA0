#ifndef _LAB0_H_
#define _LAB0_H_

//#include <conf.h>
//extern NPROC

extern unsigned long ctr1000;
extern int proc_exist[];

struct procsummary	{
	char *syscall_name;	//Name of the System Call
	
	unsigned int frequency;	//count the no of times System call is made
	 
	unsigned long time;//[];	//calculate time required to execute for each execution

//	int Syscall_number;	//identifies a system call
}summary_tab[50][27];

//extern struct procsummary summary_tab[NPROC+1][27];	//summary table


//extern struct procsummary ;
extern long zfunction(long);
extern void printsegaddress();
extern void printprocstks(int);
extern void printtos();
extern void syscallsummary_start();
#endif
