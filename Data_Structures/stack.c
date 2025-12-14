#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head){
    while(Head != NULL){
        printf("|%d|->",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}

void Push(PPNODE Head, int no){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*Head == NULL){
        *Head = newn;
    }

    else{
        newn->next = *Head;
        *Head = newn;
    }
}


void Pop(PPNODE Head){
    if(*Head == NULL){
        return;
    }

    else{
        PNODE temp =  *Head;
        if(*Head != NULL){
            *Head= (*Head)->next;
        }
        free(temp);
        //temp->next = NULL;
    }
}


int main(){
    PNODE first = NULL;
    Push(&first,51);
    Push(&first,21);
    Push(&first,11);
    Display(first);

    Pop(&first);
    Display(first);
    return 0;
}