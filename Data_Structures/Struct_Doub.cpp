//Linear doubly LL
#include<iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE, **PPNODE;

class DoublyLL{
    private:
        PNODE First;
        int size;

    public:
        DoublyLL(){
            First = NULL;
            size = 0;
        }

    void InsertFirst(int no){
        PNODE newn = new NODE;
        newn->data =no;
        newn->next = NULL;
        newn->prev = NULL;

        if(First == NULL){
            First = newn;
        }

        else{
            newn->next= First;
            (First)->prev = newn;
            First = newn;
        }

    }

    void InsertLast(int no){
       // PNODE newn = NULL;
        PNODE temp = First;

        PNODE newn = new NODE;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if(First == NULL){
            First = newn;
        }

        else{
            while(temp->next != NULL){
                temp= temp->next;
            }

            temp->next = newn;
            newn->prev = temp;
        }
    }

    void DeleteFirst(){
        PNODE temp = First;
        if(First != NULL){
            First = (First)->next;
            (First)->prev = temp;
            free(temp);
        }
       // size--;
    }

    void DeleteLast(){
        PNODE newn = NULL;
        PNODE temp = First;

        if(First == NULL){
            return;
        }

        else if((First)->next == NULL){
            free(First);
            First = NULL;
        }

        else{
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->prev->next = NULL;
            free(temp);
        }
    }

    void InsertAtPos(int no,int iPos){
        int size = Count();
        int i=0;
        PNODE temp = First;
        PNODE newn = NULL;

        if((iPos<1) || (iPos>size+1)){
            cout<<"Invalid Position";
            return;
        }
        
        if(iPos == 1){
            InsertFirst(no);
        }

        else if(iPos == size+1){
            InsertLast(no);
        }

        else{
            PNODE newn = new NODE;

            newn->data =no;
            newn->next = NULL;
            newn->prev = NULL;

            for(i=1; i<iPos-1; i++){
                temp = temp->next;
                temp->prev= temp;
            }

            newn->next = temp->next;
            temp->next = temp->prev;
            temp->prev = newn;
            
          
        }
    }

    void DeleteAtPos(int iPos){
        int size= Count();
        int i=0;
        PNODE temp = First;

        if((iPos<1) || (iPos>size)){
            cout<<"Invalid position\n";
            return;
        }

        if(iPos == 1){
            DeleteFirst();
        }

        else if(iPos == size){
            DeleteLast();
        }

        else{
            for(i=1; i<iPos-1; i++){
                temp= temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;

        }
    }

    void Display(){
        PNODE temp = First;
        while(temp != NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        printf("NULL\n");
    }

    int Count(){
        int iCnt=0;
        while(First != NULL){
            iCnt++;
            First = First->next;
        }
        return iCnt;
    }
};

int main(){
    DoublyLL obj;
    int iRet=0;
    obj.InsertFirst(51);
    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(1);
    
    obj.InsertLast(101);
    obj.Display();
    
    obj.DeleteFirst();
    obj.Display();

    obj.DeleteLast();
    obj.Display();

    obj.InsertAtPos(46,1);
    obj.Display();

    obj.DeleteAtPos(1);
    obj.Display();


    return 0;
    
}