# include<stdio.h>	
	# include<omp.h>
	# include<stdlib.h>
	int MAX;

	int FibonacciTask(int n)
	{
    		int x, y;
    		if (n < 2)
        	return n;
    		else 
		{
		 x = FibonacciTask(n - 1);
		 y = FibonacciTask(n - 2);
		 return (x + y);
    		}
	}
	/* random number generation upto 24 */
	int random_num()
	{
	    int temp;
		temp = rand();
		temp = temp%24;
		MAX = temp;
		return(MAX);
	}

	int main(int argc, char * argv[])
	{
    	
		int FibNumber[25] = {0};
    		int j, temp,tmp,id,i = 0;
		int n, tid;

		printf("Please Enter the number Range :");
		scanf("%d",&n);
		printf("\n");
		omp_set_num_threads(2);
		
		//Parallel region
		# pragma omp parallel
		{
		   	#pragma omp for private (tid,tmp,FibNumber)	 
		         	 
		for(j = 0;  j<=n; j++)
        	 {	
			# pragma omp critical
			{ 
			/* Get thread number */
			
        		tmp = random_num();
			tid = omp_get_thread_num(); 
    		    	printf("The thread %d  generating random number: %d \n", tid,tmp);
        		}
    		         
        	/* The critical section here will enable, not more than one
        	thread to execute in this section (synchronization) */  
        		
		   # pragma omp critical
		   {
		 	/* Get thread number */
    			 tid = omp_get_thread_num();
			printf("**************** inside critical section*************\n");
    			printf("The thread %d printing fib series\n", tid); 
    			
			for(i = 0; i < tmp; i++)
			FibNumber[i] = FibonacciTask(i);
        	        printf("The number value is %d:",tmp); 
    			
			for(i = 0; i < tmp; i++)
        		printf("%d \t", FibNumber[i]);
			printf("\n\n");
		  }
	      }
	  }	
	}
