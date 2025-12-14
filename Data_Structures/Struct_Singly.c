//Program : Linear Singly LinkedList
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int no){
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));//Allocate the memory

    //Step 2: Intialise the node
    newn->data =no;
    newn->next=NULL;

    //Insert the node
    if(*Head == NULL){
        *Head = newn;
    }
    else{
        newn->next=*Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head,int no){
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data= no;
    newn ->next =NULL;

    if(*Head == NULL){
        *Head = newn;
    }

    else{
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next=newn;
    }
}

void InsertAtPos(PPNODE Head,int no,int iPos){
    int size=0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    size = Count(*Head);

    if((iPos>1) || (iPos>size+1)){

    }
    if(iPos == 1){
        InsertFirst(Head,no);
    }

    else if(iPos == size+1){
        InsertLast(Head,no);
    }

    else{
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data=no;
        newn->next=NULL;

        for(int i=1 ;i<size ; i++){
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next = newn;
    }

}

void DeleteAtPos(PPNODE Head,int iPos){
    int size=0;
    PNODE newn = NULL;
    PNODE temp = *Head;
    size=Count(*Head);
    PNODE targated = NULL;

    if((iPos>1) || (iPos>size)){

    }

    if(iPos == 1){
        DeleteFirst(Head);
    }

    else if(iPos == size){
        DeleteLast(Head);
    }

    else{
        for(int i=1; i<iPos -1 ;i++){
            temp = temp->next;
        }
        targated = temp->next;
        temp->next = targated->next;
        free(targated);
    }

}
void DeleteFirst(PPNODE Head){
    PNODE temp = NULL;
    if(*Head != NULL){
        *Head= (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head){
    PNODE temp = *Head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;    
}

void Display(PNODE Head){
    while(Head != NULL){
        printf("|%d|->",Head->data);
        Head = Head ->next;
    }
}

int Count(PNODE Head){
    int iCnt=0;
    while(Head!=NULL){
        iCnt++;
        Head=Head->next;
    }
    return iCnt;
}
int main(){
    PNODE First= NULL;
    int iRet=0 , iPos=0 , iValue=0, iDis=0;

    InsertFirst(&First,10);
    InsertFirst(&First,51);
    InsertFirst(&First,11);

    InsertLast(&First,101);
    Display(First);
    printf("Number of Inserted elememnts\n ");
    iRet = Count(First);

    DeleteFirst(&First);
    printf("Delete first elements\n");
    Display(First);


    DeleteLast(&First);
    printf("Delete last elements\n");
    Display(First);

    InsertAtPos(&First,67,3);
    printf("Insert at posiotion elements are \n");
    Display(First);

    DeleteAtPos(&First,3);
    printf("Delete at position elemetes are\n");
    Display(First);

return 0;
}