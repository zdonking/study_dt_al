#include <iostream>
using namespace std;

class LinkedList{
    struct Node{
        int x;
        Node *next;
    };
 


public :
    LinkedList(){
        head =NULL;
}

void addValue(int val){
    Node *n=new Node();
    n->x = val;
    n->next = head;
    head=n;
}


int popValue(){
    Node *n=head;
    int ret=n ->x;
    head =head->next;
    delete n;
    return ret;
}

private :
    Node *head;
};

int main(){
    LinkedList list;
    list.addValue(5);
    list.addValue(10);
    list.addValue(20);
    count << list.popValue() << end1;
    count << list.popValue() << endl;
    count << list.popValue() << endl;
    return 0;
}


