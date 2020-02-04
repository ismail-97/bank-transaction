#include <stdio.h>
#include "Global.h"
#ifndef LIST_H
#define LIST_H


//#define LIMITED_MEMORY

typedef Entry ListEntry;

#define MAXLIST 10

#ifdef LIMITED_MEMORY
    typedef struct listnode{
        ListEntry entry;
        struct listnode *next;
    }ListNode;

    typedef struct list{
        ListNode *head;
        int size;
    }List;
    int InsertList(int pos, ListEntry e, List *pl);

#else
    
    typedef struct list{
        ListEntry entry[MAXLIST];
        int size;
    }List;


    void InsertList(int pos, ListEntry e, List *pL);

#endif

void DeleteList(int pos, ListEntry *pe, List *pL);
void CreateList(List *pL);
int ListEmpty(List *pL);
int ListFull(List *pL);
int ListSize(List *pL);
void DestroyList(List *pL);
void RetrieveList(int p, ListEntry *pe, List *pL);
void ReplaceList(int p, ListEntry e, List *pL);
void TraverseList(List *pL, void (*pf)(ListEntry));
void SortList(List *pL, char c );



#endif