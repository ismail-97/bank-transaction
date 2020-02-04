#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>

typedef struct customer
{
 int AccNo;
 int ArrTime;
 int Start;
 int Period;
 int Finish;
 int Waiting;
}Customer;

typedef struct employee
{
    int emp_id;
    int Ttime;
    int FinishTime;
    Customer customer;
}Employee;

typedef Employee Entry;



#endif