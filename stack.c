#include "stack.h"
#include <stdlib.h>

#ifdef LIMITED

int Push(StackEntry item, Stack *ps){

  StackNode *pnode = (StackNode*)malloc(sizeof(StackNode));
  if(pnode){
    pnode->item = item;
    pnode->next = ps->top;
    ps->top = pnode;
    ps->size--;
    return 1;
  }
  else
    return 0;
}

void Pop(StackEntry *item_ptr, Stack *ps){
  StackNode *temp;
  *item_ptr = ps->top->item;
  temp = ps->top;
  ps->top = ps->top->next;
  free(temp);
  ps->size--;

}

int StackEmpty(Stack *ps){
  return  ps->top == NULL ;
}

int StackFull(Stack *ps){
  return 0;
}

void CreateStack(Stack *ps){
  ps->top = NULL ;
  ps->size = 0;

}

void Traverse(Stack *ps, void (*pf)(StackEntry item)){
  for(StackNode *pn = ps->top; pn; pn = pn->next)
      (*pf)(pn->item);
}

void ClearStack(Stack *ps){
  StackNode *pn = ps->top;

  while(pn){
    pn=pn->next;
    free(ps->top);
    ps->top=pn;
  }
}

int StackSize(Stack *ps){
  return ps->size;
}

void StackTop(StackEntry *pitem, Stack *ps){
  *pitem = ps->top->item;

}

#else       // array implementation
void CreateStack(Stack *ps){
  ps->top = 0 ;
}

void Push(StackEntry entry, Stack *ps){
  ps->entry[ps->top++] = entry;
}

void Pop(StackEntry *pe, Stack *ps){
  *pe = ps->entry[--ps->top];
}

int StackEmpty(Stack *ps){
  return  !ps->top ;
}

int StackFull(Stack *ps){
  return ps->top == MAXSTACK;
}

void TraverseStack(Stack *ps, void (*pf)(StackEntry entry)){
  int i;
  for(i=ps->top; i>0; i--)
      (*pf)(ps->entry[i-1]);
}

void ClearStack(Stack *ps){
  ps->top = 0 ;
}

int StackSize(Stack *ps){
  return ps->top;
}

void StackTop(StackEntry *pe, Stack *ps){
  *pe = ps->entry[ps->top-1];
}
#endif