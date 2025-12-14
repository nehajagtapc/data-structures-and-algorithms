#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *lchild;
    struct node *rchild;
}NODE, *PNODE, **PPNODE;

void Insert(PPNODE Head, int no){
    PNODE newn = new NODE;

    newn->data = no;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(*Head == NULL){
        *Head = newn;
    }

    else{
        PNODE temp = *Head;
        while(1){ //Unconditional loop   for( ;  ; )
            if(temp->data == no){
                cout<<"Duplicacte node\n";
                delete newn;
                break;
            }

            else if(temp->data > no){   //left  : small number
                if(temp->lchild == NULL){
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;

           }

            else if(temp->data < no){   //right : motaa number
                if(temp->rchild == NULL){
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
        }
    }
}

bool Search(PNODE Head, int no){
    bool flag = false;
    if(Head == NULL){  //if tree is empty
        return false;
    }

    else{      //Tree contain atleast one node
        while(Head != NULL){
            if(Head->data == no){  //node sapdlaa
                    flag = true;
                    break;
            }

            else if(no> (Head->data)){  //large
                Head = Head->rchild;
            }

            else if(no< (Head->data)){  //small
                Head = Head->lchild;
            }

        }
        return flag;
    }
}
int main(){
    int no = 0;
    bool bRet = false;

    PNODE first = NULL;

    Insert(&first,51);
    Insert(&first,21);
    Insert(&first,101);

    cout<<"Enter number to search\n";
    cin>>no;

    bRet = Search(first,no);
    if(bRet == true){
        cout<<"Datais there";
    }

    else{
        cout<<"Data is not there";
    }

    return 0;
}