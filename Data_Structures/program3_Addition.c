#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE Head, int no){
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data =no;
    newn->next = NULL;

    if(*Head == NULL){
        *Head = newn;
    }

    else{
        newn->next = *Head;
        *Head = newn;
    }
}

void Display(PNODE Head){        
    while(Head != NULL){
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Addition(PPNODE Head){
    int iSum =0;
    while(*Head != NULL){
        iSum += (*Head)->data;
        *Head = (*Head)->next;
    }
    printf("Sum of node are : %d\n" ,iSum);
    return iSum;
}

int main(){
    PNODE First = NULL;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);
    Display(First);

    Addition(&First);
   // Display(First);


    return 0;
}