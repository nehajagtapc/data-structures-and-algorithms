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

void Maximum(PPNODE Head){
    if(*Head == NULL){
        printf("invalid");
        return;
    }

    else{
        int max = (*Head)->data;
        while(*Head != NULL){
            if((*Head)->data >max){
            max = (*Head)->data;
            }
            *Head = (*Head)->next;
        
        }
        printf("Maximun node is :%d\n",max);
    
  // return max;
    }

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

    Maximum(&First);
   // Display(First);
    

    return 0;
}