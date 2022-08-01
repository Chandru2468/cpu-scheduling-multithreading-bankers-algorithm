#include<stdio.h>
#include<stdlib.h>
 struct process
 {
	int id;
	int at;
	int bt;
	int wt;
	int st;
	int tat;
 };  

 struct process p[10];
 struct process temp;
 int apc;  // arrived_process_count

 int nextprocess();
 void srtf(int);
 void roundrobin(int,int);
 void execute(int,int);

 main()
 {
 int choice,n,tq;
 for(;;)
 {
 printf("\n1.Round Robin\n2.SRTF\n3.Exit\n");
 printf("Enter the choice: ");
 scanf("%d",&choice);
 switch(choice)
  {
   case 1: printf("\nRound Robin scheduling algorithm");
  	   printf("\n********************************");
	   printf("\nEnter Number of processes : ");
	   scanf("%d",&n);
	   printf("Enter the time quantam :");
	   scanf("%d",&tq);
	   roundrobin(n,tq);
	   break;

   case 2: printf("\nShortest Remaining Time First(SRTF) scheduling algorithm");
	   printf("\n********************************************************");
	   printf("\nEnter Number of processes : ");
	   scanf("%d",&n);
	   srtf(n);
	   break;
   case 3:exit(0);
  } //end of switch
 } //end of for
} //end of main()

void execute(i,tq)
 {
	if(p[i].bt < tq)
	{
	 p[i].st=p[i].st + p[i].bt;
	 p[i].bt=p[i].bt - p[i].bt;
	}
	else
	{
 	 p[i].bt=p[i].bt-tq;
	 p[i].st=p[i].st+tq;
	}
}

void roundrobin(int n,int tq)
{
 int i,j,flag,swt=0,stat=0;
 float atat,awt;
	
for(i=0;i<=n;i++)
{ p[i].id=0, p[i].at=0,p[i].bt=0, p[i].wt=0, p[i].st=0, p[i].tat=0;}

 for(i=1;i<=n;i++)
	{
		printf("Enter burst time of process%d: ",i);
		scanf("%d",&p[i].bt);
	}
	printf("\nprocess_no   Burst_time  waiting_time   turn_around_time\n");

	do
	{
	for(i=1,flag=0;i<=n;i++)
	   {
		if(p[i].bt==0)
		{ flag++; }
		else
		{
		for(j=1;j<=n;j++)
		   {
 			if(i!=j &&p[j].bt!=0)
			{
				if(p[i].bt<tq)
				{ p[j].wt=p[j].wt+p[i].bt; }
				else 
				{ p[j].wt=p[j].wt+tq; }
			}
		    
	       	    }
 			execute(i,tq);
		    //printf("%d\t\t%d\t\t%d\t\t%d\n",i,p[i].st,p[i].wt,(p[i].wt+p[i].st));
		   }
	 }
	}while(n!=flag);

 	for(i=1;i<=n;i++)
 	{ 
	 p[i].tat=p[i].wt+p[i].st;
   	 swt+=p[i].wt;
   	 stat+=p[i].tat;
   	 printf("%d\t\t%d\t\t%d\t\t%d\n",i, p[i].st,p[i].wt,p[i].tat); 
  	} 
	atat=(float)stat/n;
	awt=(float)swt/n;
  	printf("\nAvg wait time is : %f",awt);
 	printf("\nAvg turn_around_time is :%f",atat);
} 

int nextprocess()       
{
	int min, l, i;
	min = 9999;   
	for(i = 1; i <= apc; i++)
	{
		if( p[i].bt!=0 && p[i].bt < min)
		{
			min = p[i].bt;
			l = i;
		}
	}
	return l;
}  // end of nextprocess
void srtf(int n)
{
 int i,j,time=0,flag;
 float atat,awt;

 for(i=0;i<=n;i++)
 { p[i].id=0, p[i].at=0, p[i].bt=0, p[i].wt=0, p[i].st=0, p[i].tat=0; }

 for(i=1; i<=n; i++)
  {
 	p[i].id = i;
 	printf("\n\nEnter the arrival time for process %d: ", i);
 	scanf("%d", &(p[i].at));
	printf("Enter the burst time for process %d: ", i);
	scanf("%d", &(p[i].bt));
  }
	
	for(i=1; i<=n; i++)
	{
	  for(j=i+1; j<=n; j++)
	  {
	    if(p[i].at > p[j].at)   
	    {
	     temp = p[i];
	     p[i] = p[j];
	     p[j] = temp;
	    }
	  }
	}
	
	apc = 0; //arrived_process_count
	j = 1;
       while(flag != n)
	{
		if(p[apc+1].at==time)
		{	apc++;
			j = nextprocess(); 
		}

		if(p[j].bt != 0)       // to calculate the waiting time of  a process
		{
		   p[j].bt--;
		   p[j].st++;
		   time++;
		
		   for(i = 1; i <= apc; i++)
		   {
		    if(i != j && p[i].bt != 0)
		    p[i].wt++;             
		   }
		 }
             	else
		{ j=nextprocess(); }
		
	 for(i = 1,flag=0; i <= n; i++)
	  {
		if(p[i].bt == 0)
		 flag++;
	  }
	}
	printf("\n\t\tSHORTEST REMAINING TIME FIRST");
	printf("\n\t\t*****************************");
	printf("\n\n Process_id  Arrival_time  Burst_time   Waiting_time   turnaround_time\n");
	
	for(i = 1; i <= n; i++)
	 {
          p[i].tat = p[i].wt + p[i].st; 
     printf("\n\t%d \t%d \t\t%d \t\t%d\t\t%d",p[i].id,p[i].at,p[i].st, p[i].wt,p[i].tat);
	  atat=atat+ p[i].tat;   
	  awt=awt+p[i].wt;             
         }

	atat=atat/n;       
	awt=awt/n;     
        printf("\ntavg=%f\t wavg=%f\n",atat,awt);
   } // end of srtf
