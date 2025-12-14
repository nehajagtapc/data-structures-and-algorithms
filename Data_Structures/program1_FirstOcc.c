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

int SearchFirstOcc(PPNODE Head, int no){
    int size=1;
    BOOL flag = FALSE;
    PNODE temp = *Head;
    
    if(*Head == NULL){
        printf("List is Empty\n");
    }

    else{
        while(temp != NULL){
            if(temp->data == no){                             
                flag = TRUE;
                break;              
            }
            size++;
            temp = temp->next;       
        }
        printf("Elements present in the list at position is %d \n",size);
        
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

    SearchFirstOcc(&First,30);
   // Display(First);


    return 0;
}