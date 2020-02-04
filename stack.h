#include <stdio.h>
#include "Global.h"
#ifndef stack_h
#define stack_h


typedef Entry StackEntry;

//#define LIMITED

#ifdef LIMITED

  typedef struct stacknode{
    StackEntry item;
    struct stacknode *next;
  }StackNode;

  typedef struct 
  {
    StackNode *top;
    int size;
  }Stack;
  int Push         (StackEntry, Stack*);
#else

  #define MAXSTACK 6

  
  typedef struct stack
  {
    int top;
    StackEntry entry[MAXSTACK];
  }Stack;
  void Push       (StackEntry, Stack*);

#endif

void CreateStack  (Stack*);
void Pop          (StackEntry*, Stack*);
int  StackEmpty   (Stack*);
int  StackFull    (Stack*);
void TraverseStack(Stack *, void (*pf)(StackEntry));
void ClearStack   (Stack *);
int  StackSize    (Stack *);
void StackTop     (StackEntry *, Stack *);


#endif