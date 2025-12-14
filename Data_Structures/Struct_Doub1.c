1//Program : Linear Doubly Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head,int no){
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*Head == NULL){
        *Head = newn;
    }

    else{
        newn ->next = *Head;
        (*Head) ->prev = newn;
        *Head = newn;
    }
}



void InsertLast(PPNODE Head,int no){
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

        if(*Head == NULL){
            *Head = newn;
        }

        else{
            while(temp -> next != NULL){
                temp = temp->next;
            }

            temp->next = newn;
            newn->prev = temp;
        }
}

void DeleteFirst(PPNODE Head){
    PNODE temp = *Head;

    if(*Head !=NULL){
        *Head= (*Head) ->next;
        free(temp);

        if(*Head !=NULL){
            (*Head)->prev = NULL;
        }
    }
}

void DeleteLast(PPNODE Head){
    PNODE temp = *Head;
    PNODE newn = NULL;

    if(*Head == NULL){
        return;
    }

    else if((*Head) ->next == NULL){
        free(*Head);
        *Head = NULL;

    }

    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

void InsertAtPos(PPNODE Head, int no, int pos){
    int size = Count(*Head);
    int i=0;
    PNODE temp = *Head;
    PNODE newn = NULL;

    if((pos < 1) || (pos > size +1)){
        printf("Invalid position");
        return;
    }

    if(pos == 1){
        InsertFirst(Head,no);
    }

    else if( pos == size+1){
        InsertLast(Head,no);
    }

    else{
        newn = (PNODE)malloc(sizeof(NODE));

        newn->next = NULL;
        newn->data = no;
        newn->prev =NULL;

        for(i=1 ; i <pos-1; i++){
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteAtPos(PPNODE Head, int pos){
    int size = Count(*Head);
    int i=0;
    PNODE temp = *Head;

    if((pos < 1) || (pos > size)){
        printf("Invalide position");
        return;
    }

    if(pos == 1){
        DeleteFirst(Head);
    }

    else if(pos == size){
        DeleteLast(Head);
    }

    else{
        for(i=1; i<pos-1; i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }
}

void Display(PNODE Head){
    while(Head != NULL){
        printf("|%d| ->",Head->data);
        Head = Head-> next;
    }
    printf("NULL\n");
}

int Count(PNODE Head){

    int iCnt=0;
    while(Head != NULL){
        iCnt++;
        Head = Head->next;
    }

    return iCnt;
}


int main(){
    PNODE first = NULL;
    int iRet=0;

    printf("Inserted elements are:");
    InsertFirst(&first,45);
    InsertFirst(&first,48);
    InsertFirst(&first,56);

    InsertLast(&first,78);
    
    Display(first);

    iRet = Count(first);
    printf("Number of elements count are: %d\n" , iRet);

    printf("THE FIRST DELETE NUMBER IS :");
    DeleteFirst(&first);
    Display(first);

    printf("THE LAST DELETED NUMBER IS :");
    DeleteLast(&first);
    Display(first);

    printf("THE INSERTED NUMBER IIN POISITION ARE:");
    InsertAtPos(&first,15,2);
    Display(first);

    printf("THE DELETED NUMBER FOOM POSITION");
    DeleteAtPos(&first,2);
    Display(first);

return 0;
    
}