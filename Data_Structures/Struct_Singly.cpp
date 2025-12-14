#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;

}NODE,*PNODE,**PPNODE;

class SinglyLL{
    private:
        PNODE First;
        int size;

    public:
        SinglyLL(){
            First = NULL;
            size=0;
        }

    void InsertFirst(int no){
        PNODE newn = new NODE; //newn = (PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        if(First==NULL){
            First=newn;
        }

        else{
            newn->next=First;
            First=newn;
        }
        size++;
    }

    void InsertLast(int no){
        PNODE newn = new NODE;//Allocate the memory

    //Intailise the node
        newn->data = no;
        newn->next= NULL;

    //Insert the node
        if(First == NULL){
            First = newn;
        }

        else{
            PNODE temp = First;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newn;
            
        }
        size++;
    }

    void InsertAtPos(int no,int iPos){
        int size=0;
        PNODE newn = NULL;
        PNODE temp = First;
        size = Count();
        int i=0;

        if(iPos == 1){
            InsertFirst(no);
        }

        else if(iPos == size+1){
            InsertLast(no);
        }

        else{
            PNODE newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            for(i=1; i<size; i++){
                temp = temp->next;
            }
            newn->next=temp->next;
            temp->next = newn;
        }
    }

    void DeleteFirst(){
        PNODE temp = First;

        if(First != NULL){
            First = First->next;
            delete temp;
        }
        size--;
        
    }


    void DeleteLast(){
        PNODE temp = First;

        if(First == NULL){
            return;
        }

        else if(First->next == NULL){
            delete First;
            First = NULL;
            size--;
        }

        else{
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

    void DeleteAtPos(int iPos){
        int size=0;
        PNODE newn = First;
        PNODE temp = NULL;
        PNODE targated =NULL;
        int i=0;
        size = Count();

        if(iPos == 1){
            DeleteFirst();
        }

        else if(iPos == size){
            DeleteLast();
        }

        else{
            for(i=1; i<iPos-1; i++){
                temp = temp->next;
            }
            targated = temp->next;
            temp->next = targated->next;
            free(targated);
            
        }
    }

    void Display(){
    PNODE temp = First;
     while(temp != NULL){
        cout<<temp->data<<"\t";
        temp= temp->next;
     }
    cout<<"\n";
    }

    int Count(){

        return size;
    }
};


int main(){
    SinglyLL obj;
    int iRet=0;
    cout<<"FIRST & LAST INSERTED NUMBERS ARE:";
    obj.InsertFirst(51);
    obj.InsertFirst(11);
    obj.InsertFirst(21);
     
    obj.InsertLast(101);
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of elements are \n"<<iRet;

    cout<<"\nFIRST DELETEED NUMBER IS: ";
    obj.DeleteFirst();
    obj.Display();

    cout<<"LAST DELETED NUMBER IS:";
    obj.DeleteLast();
    obj.Display();
    
    cout<<"NUMBER INSERTED AT POSITION IS: ";
    obj.InsertAtPos(57,2);
    obj.Display();

    cout<<"NUMBER DELETED AT POSITION IS: ";
    obj.DeleteAtPos(2);
    obj.Display();



   return 0;
}