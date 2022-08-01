[abc@localhost Desktop]$ vi 2a.c
[abc@localhost Desktop]$ cc -fopenmp 2.c
[abc@localhost Desktop]$ ./a.out
Please Enter the number Range :7

The thread 0  generating random number: 7 
The thread 1  generating random number: 22 
**************** inside critical section*************
The thread 0 printing fib series
The number value is 7:0 	1 	1 	2 	3 	5 	8 	

**************** inside critical section*************
The thread 1 printing fib series
The number value is 22:0 	1 	1 	2 	3 	5 	8 	13 	21 	34 	55 	89 	144 233 	377 	610 	987 	1597 	2584 	4181 	6765 	10946 	

The thread 0  generating random number: 9 
The thread 1  generating random number: 19 
**************** inside critical section*************
The thread 0 printing fib series
The number value is 9:0 	1 	1 	2 	3 	5 	8 	13 	21 	

**************** inside critical section*************
The thread 1 printing fib series
The number value is 19:0 	1 	1 	2 	3 	5 	8 	13 	21 	34 	55 	89 	144 233 	377 	610 	987 	1597 	2584 	

The thread 0  generating random number: 17 
The thread 1  generating random number: 7 
**************** inside critical section*************
The thread 0 printing fib series
The number value is 17:0 	1 	1 	2 	3 	5 	8 	13 	21 	34 	55 	89 	144 233 	377 	610 	987 	

**************** inside critical section*************
The thread 1 printing fib series
The number value is 7:0 	1 	1 	2 	3 	5 	8 	

The thread 0  generating random number: 10 
The thread 1  generating random number: 12 
**************** inside critical section*************
The thread 0 printing fib series
The number value is 10:0 	1 	1 	2 	3 	5 	8 	13 	21 	34 	

**************** inside critical section*************
The thread 1 printing fib series
The number value is 12:0 	1 	1 	2 	3 	5 	8 	13 	21 	34 	55 	89
