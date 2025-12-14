#include<iostream>

using namespace std;
typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE;
 
class Stack{
    private:
    PNODE first;
    int size=0;

    public:
    Stack(){
        first = NULL;
        size =0;
    }
    void Display(){
        PNODE temp = first;
        while(temp != NULL){
            cout<<"|"<<temp->data<<"|"<<"\n";
            temp= temp->next;
        }
        cout<<"\n";
    }    
    
    int Count(){
        int iCnt=0;
        while(first != NULL){
            iCnt++;
            first = first->next;
        }
        return iCnt ;
    }
    void Push(int no){  //InsertFirst
       // PNODE newn = NULL;
        PNODE newn = new NODE;

        newn->data =no;
        newn->next =NULL;

        if(first == NULL){
            first = newn;
        }
        else{
            newn->next = first;
            first = newn;
        }
    }

    void Pop()  //DeleteFirst
    {
        PNODE temp = first;

        if(first != NULL){
          first = first->next;
            delete temp;
        }
    }
};

int main(){
    Stack obj;

    obj.Push(51);
    obj.Push(21);
    obj.Push(10);
    obj.Push(11);
    obj.Display();

    obj.Pop();
    obj.Display();

    
    int iRet=obj.Count();
    cout<<"The size of Stack:"<<iRet;

}