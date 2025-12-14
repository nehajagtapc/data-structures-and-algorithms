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

int SearchLastOcc(PPNODE Head, int no){
    int i=0;
    int size=0;
    BOOL flag = FALSE;
    PNODE temp = *Head;
    //size change kryachi last ocurnce satthi
    if(*Head == NULL){
        printf("List is Empty\n");
    }

    else{
        while(temp != NULL){
            while(temp->data == no){
                temp = temp->next;
                flag = TRUE;
                break; 
            }
            size++;
            temp = temp->next;
        }
        printf("Elements present in the list at position is %d \n",size);
      /*  if(*Head == NULL){ ///if ew remove the falg
            return FALSE;
        }
        else{
            return TRUE;
        }*/
        
    }
}



int main(){
    PNODE First = NULL;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);
    Display(First);

    
   // Display(First);
   SearchLastOcc(&First,30);


    return 0;
}