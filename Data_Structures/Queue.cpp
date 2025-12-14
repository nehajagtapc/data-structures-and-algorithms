#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}NODE, *PNODE, **PPNODE;

class Queue{
    private:
    PNODE first;
    int size;

    public:
    Queue(){
        first = NULL;
        size =0;
    }

    void Display(){
        PNODE temp = first;
        while(temp != NULL){
            cout<<"|"<<temp->data<<"|->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    void Enqueue(int no)
    {
        PNODE newn= new NODE;
        newn->data = no;
        newn->next = NULL;

        if(first == NULL){
            first = newn;
        }

        else{
            PNODE temp = first;

            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next  =newn;
        }

    }

    void Dequeue(){
    if(first== NULL){
        return;
    }

    else{
        PNODE temp =  first;
        if(first != NULL){
            first= first->next;
        }
        free(temp);
        //temp->next = NULL;
    }
    }
};

int main(){
    Queue obj;
    obj.Enqueue(51);
    obj.Enqueue(21);
    obj.Enqueue(11);
    obj.Display();

    obj.Dequeue();
    obj.Display();
return 0;
}