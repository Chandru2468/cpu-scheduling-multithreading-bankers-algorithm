INPUT-OUTPUT:

[a@localhost osnew]$ vi 3a.c
[a@localhost osnew]$ cc 3a.c
[a@localhost osnew]$ ./a.out

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 1

Enter the number of process: 5

Enter the number of shared resource: 3
Ente the Available resources:
For Resource type 0 : 10
For Resource type 1 : 5
For Resource type 2 : 7
Enter Maximum matrix
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

Enter Allocation matrix
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 3
Allocation matrix is
	0	1	0
	2	0	0
	3	0	2
	2	1	1
	0	0	2
Maximum matrix
	7	5	3
	3	2	2
	9	0	2
	2	2	2
	4	3	3
Available matrix is 
	3	3	2
Need matrix
	7	4	3
	1	2	2
	6	0	0
	0	1	1
	4	3	1

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 2
< P1, P3, P4, P0, P2,>
System is in Safestate... :):) 

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 4

Enter process id: 1

 Enter the repuest vector: 1 0 2
< P1, P3, P4, P0, P2,>
System is in Safestate... :):)
 Resources Allocated.. :):)

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 3
Allocation matrix is
	0	1	0
	3	0	2
	3	0	2
	2	1	1
	0	0	2
Maximum matrix
	7	5	3
	3	2	2
	9	0	2
	2	2	2
	4	3	3
Available matrix is 
	2	3	0
Need matrix
	7	4	3
	0	2	0
	6	0	0
	0	1	1
	4	3	1

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 4

Enter process id: 4

 Enter the repuest vector: 3 3 0


	 Lack of Resourcess: Process Satate-Wait
1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 3
Allocation matrix is
	0	1	0
	3	0	2
	3	0	2
	2	1	1
	0	0	2
Maximum matrix
	7	5	3
	3	2	2
	9	0	2
	2	2	2
	4	3	3
Available matrix is 
	2	3	0
Need matrix
	7	4	3
	0	2	0
	6	0	0
	0	1	1
	4	3	1

1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 4

Enter process id: 0

 Enter the repuest vector: 0 2 0

System is in Unsafestate....!!
, Resources cannot be allocated
1.Input data
2.Check Safe or Not
3.print
4.New request
 5.Exit
Enter your choice: 5
