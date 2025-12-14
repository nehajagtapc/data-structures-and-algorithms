#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head,PNODE Tail){
    do{
        printf("|%d|->",Head->data);
        Head= Head->next;
    }while(Head != Tail->next);

    printf("\n");
}

int Count(PNODE Head,PNODE Tail){
    int iCnt = 0;
    do{
        iCnt++;
        Head = Head->next;
    }while(Head != Tail->next);
    return iCnt;
}

void InsertFirst(PPNODE Head,PPNODE Tail,int no){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL)){
        *Head = newn;
        *Tail = newn;
    }

    else{
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}


void InsertLast(PPNODE Head,PPNODE Tail,int no){
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL)){
        *Head = newn;
        *Tail = newn;
    }

    else{
        (*Tail)->next = newn;
        *Tail = newn;
    }
    (*Tail)->next = *Head;
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int iPos){
    PNODE newn= NULL;
    int size=1;
    if((iPos<1) || (iPos> (size+1))){
        return;
    }

    if(iPos == 1){
        InsertFirst(Head,Tail,no);
    }

    else if(iPos == size+1){
        InsertLast(Head,Tail,no);
    }

    else{
        PNODE temp = *Head;

        for(int i=1; i<iPos-1; i++){
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next =newn;
    }

}

void DeleteFirst(PPNODE Head,PPNODE Tail){
    if((*Head == NULL) && (*Tail == NULL)){
        return;
    }

    else if(*Head == *Tail){
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }

    else{
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail){
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL)){
        return;
    }

    else if(*Head == *Tail){
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }

    else{
        while(temp->next != *Tail){
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

/*void DeleteAtPos(PPNODE Head,PPNODE Tail,int iPos){
    PNODE newn= NULL;
    int size=1;
    if((iPos<1) || (iPos> (size))){
        return;
    }

    if(iPos == 1){
        InsertFirst(Head,Tail,iPos);
    }

    else if(iPos == size){
        InsertLast(Head,Tail,iPos);
    }
}*/

int main(){
    PNODE First = NULL;
    PNODE Last = NULL;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,11);
    InsertFirst(&First,&Last,21);
    Display(First,Last);

    InsertLast(&First,&Last,101);
    Display(First,Last);

   // InsertAtPos(&First,&Last,15,2);
   // Display(First,Last);

    DeleteFirst(&First,&Last);
    Display(First,Last);

    DeleteLast(&First,&Last);
    Display(First,Last);

    

    return 0;
}
