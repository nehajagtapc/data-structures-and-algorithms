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

void DeleteFirst(PPNODE Head){
    PNODE temp = *Head;
    
    if(*Head != NULL) { // if LL contains atleast one node 
        *Head = (*Head)->next;
        free(temp);
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
    PNODE First = NULL;
    int iRet=0;

    InsertFirst(&First,51); //InsertFirst(50,51);
    InsertFirst(&First,21); //InsertFirst(50,51);
    InsertFirst(&First,11); //InsertFirst(50,51);
   // InsertFirst(&First,111);

    DeleteFirst(&First); //111 ha delete kryach aah 
    Display(First);
    
    return 0;
}