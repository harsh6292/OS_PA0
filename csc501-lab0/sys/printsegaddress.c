#include <stdio.h>

extern int etext, edata, end;

void printsegaddress()
{
	kprintf("\n\nTask 2 (printsegaddress)");
	//sleep(10);
	kprintf("\nCurrent:\tetext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", &etext,etext,&edata,edata,&end,end);
	kprintf("\nPreceding:\tetext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", (&etext-1),*(&etext-1) ,&edata-1,*(&edata-1),&end-1,*(&end-1));	//The text, data and bss segment are stored in lower part of memory, hence address value is subtracted from them instead of adding to them. 
	kprintf("\nAfter:\t\tetext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", (&etext+1),*(&etext+1) ,&edata+1,*(&edata+1),&end+1,*(&end+1));
}
