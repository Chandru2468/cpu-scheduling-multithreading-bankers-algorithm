INPUT-OUTPUT:

[a@localhost osnew]$ vi 10a.c
[a@localhost osnew]$ cc 10a.c
[a@localhost osnew]$ ./a.out

1.Round Robin
2.SRTF
3.Exit
Enter the choice: 1

Round Robin scheduling algorithm
********************************
Enter Number of processes : 3
Enter the time quantam :4
Enter burst time of process1: 24
Enter burst time of process2: 3
Enter burst time of process3: 3

process_no   Burst_time  waiting_time   turn_around_time
1		24		6		30
2		3		4		7
3		3		7		10

Avg wait time is : 5.666667
Avg turn_around_time is :15.666667
1.Round Robin
2.SRTF
3.Exit
Enter the choice: 2

Shortest Remaining Time First(SRTF) scheduling algorithm
********************************************************
Enter Number of processes : 4


Enter the arrival time for process 1: 0
Enter the burst time for process 1: 8


Enter the arrival time for process 2: 1
Enter the burst time for process 2: 4


Enter the arrival time for process 3: 2
Enter the burst time for process 3: 9


Enter the arrival time for process 4: 3
Enter the burst time for process 4: 5

		SHORTEST REMAINING TIME FIRST
		*****************************

 Process_id  Arrival_time  Burst_time   Waiting_time   turnaround_time

	1 	0 		8 		9		17
	2 	1 		4 		0		4
	3 	2 		9 		15		24
	4 	3 		5 		2		7
tavg=13.000000	 wavg=6.500000

1.Round Robin
2.SRTF
3.Exit
Enter the choice: 3
