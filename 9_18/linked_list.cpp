#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void initNode (struct Node *head ,int n){
    head ->data=n;
    head->next=NULL;
}

void addNode(struct Node *head,int n){
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=NULL;
    Node *cur=head;
    while(cur){
        if(cur->next==NULL){
            cur->next=newNode;
            return;
        }
        cur=cur->next;
    }
}


void insertFront(struct Node **head,int n){
    Node *newNode=new Node;
    newNode->data=n;
    newNode->next=*head;
    *head=newNode;
}

//struct Node *searchNode(struct Node *head ,int n)
//{
//    Node *cur=head;
//    while(cur){
//        if(cur->data==n) return cur;
//        cur=cur->next;
//    }
//    cout << "No Node" << n << "in list.\n";
//
//}

bool deleteNode(struct Node **head,Node *ptrDel){
    Node *cur =*head;
    if(ptrDel==*head){
        *head=cur->next;
        delete ptrDel;
        return true;
    }
    while (cur){
        if(cur->next==ptrDel){
            cur->next=ptrDel->next;
            delete ptrDel;
            return true;
        }
        cur=cur->next;
    }
    return false;
}


void display(struct Node *head){
    Node *list=head;
    while(list){
        cout << list->data << "  ";
        list=list->next;
    }
    cout << endl;
    cout << endl;
}

int main()
{
    struct Node *newHead;
    struct Node *head=new Node;
    initNode(head,10);
    display(head);

}


