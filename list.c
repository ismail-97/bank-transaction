#include "list.h"
#include <stdlib.h>

#ifdef LIMITED_MEMORY
int InsertList(int pos, ListEntry e, List *pl){
    ListNode *p, *q;
    int i;
    if( (p=(ListNode*)malloc(sizeof(ListNode))) && pos <= pl->size){
        p->next=NULL;
        p->entry=e;
        if(pos==0){
            p->next = pl->head;
            pl->head = p;
              printf("i am here \n");

        }
        else{          
            for(q = pl->head, i=0; i<pos-1; i++)
                q=q->next;
            p->next=q->next;
            q->next=p;
        }
            pl->size++;
            return 1;
        }
        else
            return 0;
}

void DeleteList(int pos, ListEntry *pe, List *pl){
    int i;
    ListNode *q, *tmp;
    if(pos==0){
        *pe=pl->head->entry;
        tmp=pl->head->next;
        free(pl->head);
        pl->head=tmp;
    }
    else{
        for(q=pl->head, i=0; i<pos-1; i++)
            q=q->next;
        *pe=q->next->entry;
        tmp=q->next->next;
        free(q->next);
        q->next=tmp;
    }
    pl->size--;
}

void CreateList(List *pl){
    pl->head = NULL;
    pl->size = 0;
}
int ListEmpty(List *pl){
    return !pl->head;
}
int ListFull(List *pl){
    return 0;
}
int ListSize(List *pl){
    return pl->size;
}
void DestroyList(List *pl){
    ListNode *pn;
    while(pl->head){
        pn=pl->head->next;
        free(pl->head);
        pl->head = pn;
    }
    pl->size=0;
}

void RetrieveList(int p, ListEntry *pe, List *pl){
    int i;
    ListNode *q;
    for(q=pl->head, i=0; i<p; i++)
        q=q->next;
    *pe=q->entry;
}
void ReplaceList(int p, ListEntry e, List *pl){
    int i;
    ListNode *q;
    for(q=pl->head, i=0; i<p; i++)
        q=q->next;
    q->entry=e;
}

void TraverseList(List *pl, void (*pf)(ListEntry)){
    ListNode *pn = pl->head;
    while(pn){
        (*pf)(pn->entry);
        pn = pn->next;
    }
}


#else


void InsertList(int p, ListEntry e, List *pl){
    int i;
    for(i=pl->size-1; i>=p; i--)
        pl->entry[i+1] = pl->entry[i];
    pl->entry[p] = e;
    pl->size++;
}

void DeleteList(int p, ListEntry *pe, List *pl){
    int i ;
    *pe = pl->entry[p];
    for (i=p+1; i<=pl->size-1; i++)
        pl->entry[i-1]=pl->entry[i];
    pl->size--;
}

void CreateList(List *pl){
    pl->size = 0;
}
int ListEmpty(List *pl){
    return !pl->size;
}
int ListFull(List *pl){
    return pl->size == MAXLIST;
}
int ListSize(List *pl){
    return pl->size;
}
void DestroyList(List *pl){
    pl->size = 0;
}

void RetrieveList(int p, ListEntry *pe, List *pl){
    *pe=pl->entry[p];
}
void ReplaceList(int p, ListEntry e, List *pl){
    pl->entry[p]=e;
}

void TraverseList(List *pl, void (*pf)(ListEntry)){
    int i;
    for(i=0; i<pl->size; i++)
        (*pf)(pl->entry[i]);
}

void SortList(List *pL, char c){
    int i, j;
    ListEntry Temp;
    if (c == 'f')
    {
        for(i=0; i<pL->size; i++)
            for (j=0; j<pL->size-i-1; j++)
            {
                if( pL->entry[j].FinishTime < pL->entry[j+1].FinishTime)
                {
                    Temp = pL->entry[j];
                    pL->entry[j] = pL->entry[j+1];
                    pL->entry[j+1] = Temp;
                }
            }
    }
    else
    {
        for(i=0; i<pL->size; i++)
            for (j=0; j<pL->size-i-1; j++)
            {
                if( pL->entry[j].emp_id < pL->entry[j+1].emp_id)
                {
                    Temp = pL->entry[j];
                    pL->entry[j] = pL->entry[j+1];
                    pL->entry[j+1] = Temp;
                }
            }
    }
           
}
#endif