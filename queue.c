#include "queue.h"
#include <stdlib.h>


#ifdef s

void CreateQueue(Queue *pq){
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int Append(QueueEntry e, Queue *pq){
    QueueNode *nn;
    nn = (QueueNode*)malloc(sizeof(QueueNode));
    if(!nn) return 0;
    else{
        nn->next = NULL;
        nn->entry = e;
        if(!pq->rear)
            pq->front = nn;
        else
            pq->rear->next = nn;
        pq->rear = nn;
        pq->size++;        
    }
}

void Serve(QueueEntry *pe, Queue *pq){
    QueueNode *pn = pq->front;
    *pe = pn->entry;
    pq->front = pn->next;
    free(pn);
    if(!pq->front)
        pq->rear = NULL;
    pq->size--;
}
void RetrieveQueue(QueueEntry *pe, Queue *pq){
    *pe = pq->front->entry;
}

int QueueEmpty(Queue* pq){
    return !pq->size;
}
int QueueFull(Queue *pq){
    return 0;
}
int QueueSize(Queue *pq){
    return pq->size;
}
void ClearQueue(Queue *pq){
    while(pq->front){
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)){
  QueueNode *pn;
  for(pn= pq->front; pn; pn=pn->next)
    (*pf)(pn->entry);
}
#else  // array implementation

void CreateQueue(Queue *pq){
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void Append(QueueEntry e, Queue *pq){
    pq->rear = (pq->rear +1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void Serve(QueueEntry *pe, Queue *pq){
    *pe = pq->entry[pq->front];
    pq->front = (pq->front+1) % MAXQUEUE;
    pq->size--;
}

void RetrieveQueue(QueueEntry *pe, Queue *pq){
    *pe = pq->entry[pq->front];
}
int QueueEmpty(Queue* pq){
    return !pq->size;
}
int QueueFull(Queue *pq){
    return (pq->size == MAXQUEUE);
}
int QueueSize(Queue *pq){
    return pq->size;
}
void ClearQueue(Queue *pq){
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
void TraverseQueue(Queue *pq, void(*pf)(QueueEntry)){
    int pos,s;
    for(pos=pq->front, s=0; s<pq->size; s++){
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXQUEUE;
    }
}

#endif