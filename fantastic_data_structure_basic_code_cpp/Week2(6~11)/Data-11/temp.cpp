#include "singlyLinkedlist.h"
#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>

BOOL createList(List* lp)
{
    if(lp==NULL)
        return FALSE;

    lp->head = (Node*)malloc(sizeof(Node));
    if(lp->head=NULL)
        return FALSE;

    lp->tail = (Node*)malloc(sizeof(Node));
    if(lp->tail==NULL){
        free(lp->head);
        return FALSE;
    }

    lp->head->next = lp->tail;

    return TRUE;
}

BOOL addFirst(List* lp,char* data)
{
    Node* newp;

    if(lp=NULL)
    {
        return FALSE;
    }       

    newp = (Node*)malloc(sizeof(Node));
    if( newp != NULL )
    {
        strcpy( newp->data, data );
        newp->next = lp->head->next;
        lp->head->next = newp;
        lp->size++;
    }
    else
    {
        return FALSE;
    }
    
}

BOOL addLast(List* lp, char* data)
{
    Node* newp;
    Node* btp;

    if( lp == NULL )
    {
        return FALSE;
    }

    newp = (Node*)malloc(sizeof(Node));
    if( newp != NULL)
    {
        //
        strcpy( newp->data, data );
        newp->next = lp->tail;

        btp = lp->head;
        while( btp->next != lp->tail)
        {
            btp = btp->next;
        }

        btp->next = newp;
        ++lp->size;
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}

void displayList(List* lp)
{
    //
    Node* curp;
    if( lp == NULL )
        return ;

    curp = lp->head->next;
    while( curp != lp->tail )
    {
        printf("%s\n",curp->data);
        curp = curp->next;
    }
    printf("\n");
}