#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head){
    while(Head!= NULL){
        printf("%d\n",Head->data);
        Head=Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head){
    int iCnt=0;
    while(Head!=NULL){
        iCnt++;
        Head=Head->next;
    }
    return iCnt;
}

void InsertFirst(PPNODE Head,int no){
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*Head == NULL){
        *Head = newn;
    }
    else{
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head,int no){
    PNODE newn = NULL;
    PNODE temp = *Head;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if(*Head == NULL){
        *Head = newn;
    }
    else{
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE Head){
    PNODE temp = *Head;
    if(*Head!=NULL){
        *Head=(*Head)->next;
        free(temp);
    }    
}

void DeleteLast(PPNODE Head){
    PNODE temp= *Head;
    if(*Head == NULL){
        return;
    }
    else if((*Head)->next == NULL){
        free(*Head);
        *Head = NULL;
    }
    else{
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head,int no,int iPos){
    int size=0;
    PNODE newn=NULL;
    PNODE temp = *Head;
 
    int i=0;
    size = Count(*Head);

    if((iPos>1)||(iPos>size+1)){      ///filter aah
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1){
        InsertFirst(Head,no);
    }
    else if(iPos == size+1){
        InsertLast(Head,no);
    }

    else{
        newn = (PNODE)malloc(sizeof(NODE));

        newn ->data = no;
        newn->next=NULL;

        for(i=1;i<iPos;i++){
            temp=temp->next;
        }

        newn->next = temp->next;
        temp->next= newn;
    }
}

void DeleteAtPos(PPNODE Head,int iPos){
    int size=0;
    PNODE temp = *Head;
    int i=0;
    size = Count(*Head);
    PNODE targated = NULL;

    if((iPos<1) || (iPos>size)){
        printf("Invalid Position\n");
        return;
    }

    if(iPos == 1){
        DeleteFirst(Head);
    }

    else if(iPos == size){
        DeleteLast(Head);
    }

    else{

        for(i=1;i<iPos-1;i++){
            temp = temp->next;
        }

        targated = temp->next;
        temp->next = targated->next;
        free(targated);
    }

}

int main(){
    PNODE First = NULL;
    int iChoice=1, value=0,iRet=0, iPos=0;

    while(iChoice!=0){
        printf("\n__________________________\n");
        printf("Enter the derised opration that you bwant to perform to LinkedList\n");
        printf("1: Insert the node at first position\n");
        printf("2: Insert the node at last position\n");
        printf("3: Insert the pos at desired position\n");
        printf("4: Delete the first node\n");
        printf("5: Delete the last node\n");
        printf("6: Delete the desried node\n");
        printf("7: Display the content at linked list\n");
        printf("8: Count the number f nodes from linked list\n");
        printf("0: Terminate the application\n");
        printf("\n________________________\n");
        scanf("%d",&iChoice);

        switch(iChoice){
            case 1:
                printf("Enter the data to insert\n");
                scanf("%d\n",&value);
                InsertFirst(&First,value);
                break;

            case 2:
                printf("Enter the data to insert\n");
                scanf("%d\n",&value);
                InsertLast(&First,value);
                break;

            case 3:
                printf("Enter the data to insert\n");
                scanf("%d\n",&value);
                printf("Enter the position\n");
                scanf("%d",&iPos);
                InsertAtPos(&First,value,iPos);
                break;

            case 4:
                DeleteFirst(&First);
                break;
            
            case 5:
                DeleteLast(&First);
                break;

            case 6:
                printf("Enter the position\n");
                scanf("%d\n",&iPos);
                DeleteAtPos(&First,iPos);
                break;

            case 7:
                printf("Elements of linked list are\n");
                Display(First);
                break;

            case 8:
                iRet = Count(First);
                printf("Number of elements are : %d\n",iRet);
                break;
                
            case 0:
                printf("Thank for using Marvellous Linked List\n");
                break;
                
            default:
                printf("Please enter proper choice\n");
                break;           
        }

    }
    return 0;
}