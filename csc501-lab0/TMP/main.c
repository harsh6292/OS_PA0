/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

extern int start_summary;
void halt();
//struct procsummary *summary; 

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

void func()
{
	//sleep(5);
	sleep(3);
}

int main()
{
	kprintf("HARSHVARDHAN AGGARWAL - - haggarw");
	kprintf("\n\nHello World, Xinu lives.\n\n");
	
	/*int pi;int prx;
	long x=0xaaffffd;
	//summary=&summary_tab[currpid][0];


	x=zfunction(x);
	kprintf("\nValue of X : %x\n", x);
	
	printsegaddress();*/
	
	printtos();
	
	/*printprocstks(1);
	
	//summary=summary_tab[currpid][0];
	syscallsummary_start();
	
	//pi=getpid();
	
	prx=create(func,1500, 5,"func",0,0);
	resume(prx);
	sleep(7);
	//pi=getpid();
	
	syscallsummary_stop();
	
	printsyscallsummary();
	*/return 0;
}
