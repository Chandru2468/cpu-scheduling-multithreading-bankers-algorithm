#include<stdio.h>
#include<stdlib.h>
int alloc[10][10],max[10][10],avail[10];
int need[10][10],request[10];
int nop=0,nor=0;

int safeseq();
void print();
int reqalloc();
void getdata();

main()
{
  int choice;
 do
 {
 printf("\n1.Input data\n2.Check Safe or Not\n3.print\n4.New request\n 5.Exit\n");
 printf("Enter your choice: "); 
 scanf("%d",&choice);
 switch(choice)
 {
  case 1: getdata();
	  break;
  case 2: if(safeseq()==1)
 		printf("\nSystem is in Safestate... :):) \n");
	  else 
		printf("\nSystem is in Unsafestate....!!\n");
	  break;
 case 3: print();
	 break;
 case 4: reqalloc();
	 break;
 case 5: exit(0);
}
}while(choice!=5);
} //end of main()

void getdata()
{
 int i,j;
 printf("\nEnter the number of process: ");
 scanf("%d",&nop);
 printf("\nEnter the number of shared resource: ");
 scanf("%d",&nor);

 printf("Ente the Available resources:\n");
 for(i=0;i<nor;i++)
 { 
   printf("For Resource type %d : ",i);
   scanf("%d",&avail[i]);
 }

 printf("Enter Maximum matrix\n");
 for(i=0;i<nop;i++)
  for(j=0;j<nor;j++)
   scanf("%d",&max[i][j]);

 printf("\nEnter Allocation matrix\n");
 for(i=0;i<nop;i++)
  for(j=0;j<nor;j++)
 {
     scanf("%d",&alloc[i][j]);
     
    if(alloc[i][j]>max[i][j])
	{
 	 printf("\n\n\t Allocation should be less < OR == max (Wrong Inpur..!!)");
	 exit(0);
	}
    else
      {
	avail[j]=avail[j]-alloc[i][j];
	need[i][j]=max[i][j]-alloc[i][j];
      }
 }
}

void print()
{
 int i,j;
 printf("Allocation matrix is\n");
 for(i=0;i<nop;i++)
{
  for(j=0;j<nor;j++)
  printf("\t%d",alloc[i][j]); 
  printf("\n");
}
 printf("Maximum matrix\n");
 for(i=0;i<nop;i++)
 {
  for(j=0;j<nor;j++)
   printf("\t%d",max[i][j]);
   printf("\n");
 }

 printf("Available matrix is \n");
 for(j=0;j<nor;j++)
  printf("\t%d",avail[j]);
  printf("\n");

printf("Need matrix\n");
 for(i=0;i<nop;i++)
 {
  for(j=0;j<nor;j++)
   printf("\t%d",need[i][j]);
  printf("\n");
 }
}

int safeseq()
{
 int flag=0,i,j,k,ss=0,sseq[10];
 int finish[10],work[10],p,s;
 int check,t;
 
 for(j=0;j<nor;j++)
  work[j]=avail[j];
 
 for(j=0;j<nop;j++)
 finish[j]=0;
  
 for(t=0;t<nor;t++)
 {
  for(j=0;j<nop;j++)
  {
   if(finish[j]==0)
   {  
	check=0;
	for(k=0;k<nor;k++)
         if(need[j][k]<=work[k])
 	  check++;
	    if(check==nor)
	    {
	      for(k=0;k<nor;k++)
	      {
	 	work[k]=work[k]+alloc[j][k];
	 	finish[j]=1;
 	      }
	
  sseq[ss]=j;
  ss++;
   }
  }
 }
 }
for(i=0;i<nop;i++)
 if(finish[i]==1)
 flag++;
  
if(flag==nop)
 {
  printf("<");
  for(s=0;s<nop;s++)
  printf(" P%d,",sseq[s]); 
  printf(">");
  return 1;
 }
 else	
  {  return 0;  }
}

int reqalloc()
{
 int i,j,k,p,violationcheck=0,waitcheck=0;
 printf("\nEnter process id: ");
 scanf("%d",&p);
 printf("\n Enter the repuest vector: ");
 
 for(i=0;i<nor;i++)
  { 
	scanf("%d",&request[i]); 
	if(request[i]>need[p][i])
	violationcheck=1;
	if(request[i]>avail[i])
	waitcheck=1;
   }
 
 if(violationcheck==1)
 { printf("The Process Exceeds it's Max Needd: Terminated"); return 1; }
 else if(waitcheck==1)
 { printf("\n\n\t Lack of Resourcess: Process Satate-Wait"); return 2; }
 else 
 {	 
  	for(j=0;j<nor;j++)
  	{
  	 avail[j]=avail[j]-request[j];
	 alloc[p][j]=alloc[p][j]+request[j];
	 need[p][j]=need[p][j]-request[j];
   	}
	 if(safeseq()==1)
 	printf("\nSystem is in Safestate... :):)\n Resources Allocated.. :):)\n");
	  else 
	   {
		printf("\nSystem is in Unsafestate....!!\n, Resources cannot be allocated");
		for(j=0;j<nor;j++)
  		{
	  	 avail[j]=avail[j]+request[j];
		 alloc[p][j]=alloc[p][j]-request[j];
		 need[p][j]=need[p][j]+request[j];
   		}
	   }
    }
}
