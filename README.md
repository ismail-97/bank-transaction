# bank-transaction


Customers who are waiting to make transactions in a bank located in a residential area with a low population density are in a “queue”. 
The employees who perform the operations are located in a “stack”. 
The Bank is considering using employees as a "stack" to run some of its employees in transactions of its customers to the maximum, 
and some of its employees who are unable to provide service to its customers due to its "stack" structure in some other office work. 
In this way, the employee working at the desk will be less distracted and she/he will complete the work efficiently. 
Suppose you have 6 employees (employee ids are given 1 to 6, employee 6 is at the top of stack)  in the bank. 

 
122 1 2

128 1 1

113 1 2

118 2 3

119 2 5

115 2 9

127 3 1

156 3 4

112 3 5

121 3 7

-1
 
 
 
 
 
Output (for 6 employees) 
 
122 6 1 3 0

128 5 1 2 0

113 4 1 3 0

118 5 2 5 0

119 3 2 7 0

115 2 2 11 0

127 6 3 4 0

156 4 3 7 0

112 1 3 8 0

121 6 4 11 1

 
6 10 ..
5 4 ..
4 6 ..
3 5 ..
2 9 ..
1 5  ..
 
In this given text file, the first customer with the account number 122 comes to the bank in the 1st minute and has 2 minutes processing.
(You can think of “comes in the first minute” as coming at the beginning of the first minute). 
Write a program that process the transactions (given in the text file), that took place from the beginning of the 1st minute until 
the time when no customers are left in the bank. The output will consist of customer number, employee number, time the transaction 
started, time the transaction finished, customer waiting time in queue. Additionally each employee's total serving time will be printed.
Write and use all the necessary methods of "Stack" and "Queue" structures in your program. You can implement stacks and queues using 
either array or link list. 
