#include <stdio.h>
#ifndef Queue_h 
#define Queue_h
#include "Global.h"


#define s

typedef Customer QueueEntry;

#ifdef s
    typedef struct queuenode{
        QueueEntry entry;
        struct queuenode *next;
    }QueueNode;

    typedef struct queue
    {
        QueueNode *front;
        QueueNode *rear;
        int size;
    }Queue;
    int Append(QueueEntry, Queue*);
#else

    #define MAXQUEUE 6
    typedef struct queue
    {
        int front;
        int rear;
        int size;
        QueueEntry entry[MAXQUEUE];
    }Queue;
    void Append(QueueEntry, Queue*);

#endif

void CreateQueue(Queue*);
void Serve(QueueEntry*, Queue*);
int QueueEmpty(Queue*);
int QueueFull(Queue*);
int QueueSize(Queue*);
void ClearQueue(Queue*);
void TraverseQueue(Queue*, void(*pf)(QueueEntry));
void RetrieveQueue(QueueEntry*, Queue*);
#endif