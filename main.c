#include "list.h"
#include "stack.h"
#include "queue.h"
#include "Global.h"

void Display(StackEntry entry){
  printf("%d\t %d\n",entry.emp_id, entry.Ttime);
}

void Push_finished(Queue *pq, Stack *ps, List *pL){
    ListEntry Le;
    int i;
    if(!ListEmpty(pL))
    {
      for(i=pL->size-1; i>0; i--)       
      {                                 
        RetrieveList(i, &Le, pL);
        if((pq->rear->entry.ArrTime >= Le.FinishTime) ||(StackEmpty(ps) && pq->rear->entry.ArrTime < Le.FinishTime))
        {
          DeleteList(i, &Le, pL);
          Push(Le, ps);
        }
      }
    }
}
void AssignToEmployee(Queue *pq, Stack *ps, List *pL){
  Entry se;
  QueueEntry qe;

  Push_finished(pq, ps, pL);
  while ( !QueueEmpty(pq) && !StackEmpty(ps))
  {
    Pop(&se, ps);
    Serve(&qe, pq);
    qe.Start   = qe.Start >se.FinishTime ? qe.ArrTime : se.FinishTime;
    qe.Finish  = qe.Start+qe.Period;
    qe.Waiting = qe.Start-qe.ArrTime;
    se.Ttime  += qe.Period;
    se.FinishTime = qe.Finish;
    se.customer = qe;

    InsertList(pL->size, se, pL);
    SortList(pL, 'f');
    printf("%d\t%d\t%d\t%d\t%d\n",se.customer.AccNo, se.emp_id, se.customer.Start, se.customer.Finish, se.customer.Waiting);
  }
}

int main (){
    int i;
    List L;
    Queue q;
    ListEntry Le;
    Stack st;
    CreateStack(&st);
    CreateQueue(&q);
    CreateList(&L);
    Employee e;
    Customer c;
    QueueEntry qe;

    for(i=0; i<MAXSTACK; i++)
    {
        e.emp_id = i+1;
        e.FinishTime = e.Ttime = 0;
        if(!StackFull(&st))
          Push(e, &st);
    }

    scanf(" %d",&c.AccNo);
    while(c.AccNo != -1){
      scanf(" %d %d",&(c.ArrTime), &c.Period);
      c.Waiting = 0;
      c.Start   = c.ArrTime;
      c.Finish  = c.Start + c.Period;
      if(!QueueFull(&q)){
        Append(c, &q);
        AssignToEmployee(&q, &st, &L);
      }
      scanf(" %d",&c.AccNo);
    }
    SortList(&L, 'q');
    for(i=L.size-1; i>=0; i--)       
    {                                 
      DeleteList(i, &Le, &L);
      Push(Le, &st);
    }
    printf("\n");
    TraverseStack(&st, &Display);
    return 0;
}