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

void Mininum(PPNODE Head){
    if(*Head == NULL){
        printf("invalid");
        return;
    }

    else{
        int min = (*Head)->data;
        while(*Head != NULL){
            if((*Head)->data < min){
            min = (*Head)->data;
            }
            *Head = (*Head)->next;
        
        }
        printf("Minimum node is :%d\n",min);
    
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

    Mininum(&First);
   // Display(First);
    

    return 0;
}