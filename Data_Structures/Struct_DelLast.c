#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head,int no){
    PNODE newn = NULL;

    //Step1: Allocate he memory
    newn= (PNODE)malloc(sizeof(NODE));

    //Step2: Initailze the node
    newn->data=no;   //Initialze node
    newn->next=NULL;  //hattt khali kela

    //Step3 : Insert the node
    if(*Head ==NULL){
        *Head = newn;
    }
    else{
        newn->next=*Head;
        *Head = newn;
    }
}

void DeleteLast(PPNODE Head){
    PNODE temp = *Head;

    if(*Head == NULL){
        return;
    }
    if((*Head)->next == NULL){
        free(*Head);
        *Head=NULL;
    }
   else{
        while(temp->next->next!= NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
   }
    
}
void Display(PNODE Head){
    while(Head!=NULL){
        printf("%d\n",Head->data);
        Head=Head->next;
    }
}

/*int Count(PNODE Head){
    int iCnt=0;
    while(Head!=0){
        iCnt++;
        Head = Head->next;
    }
    return 0;
}*/

int main(){
    PNODE First =NULL;
    int iRet=0;

    InsertFirst(&First,51); //InsertFirst(50,51);
    InsertFirst(&First,21); //InsertFirst(50,51);
    InsertFirst(&First,11); //InsertFirst(50,51);
    
    DeleteLast(&First);
    Display(First);
    

    return 0;
}