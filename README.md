# Banker's Algorithm

This program is designed to take input files and use the information provided in them to determine if the system is safe and display the safe sequence for the system.

Limitations: This program only works for a system that has 5 processes and 3 resources.

The program requires 2 .txt files to function, one named "processes.txt" and the other named "available.txt".

"processes.txt" holds a list of numbers from the allocation column and the max column of the chart provided in the homework sheet.

"available.txt" holds the numbers in the available column on the homewrok sheet.

In "processes.txt", the numbers should be arranged just like the chart, but every new line needs a ' ' before the first number, or else the numbers won't be read correctly.


To run the program, enter the following commands in the terminal:

$ g++ bankalgo.cpp -o a.out

$ ./a.out

This should run the program and display the safe sequence for the values entered in "processes.txt" and "available.txt".
