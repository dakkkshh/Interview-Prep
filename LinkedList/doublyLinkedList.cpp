#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;

    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}
void insertAtHead(node *&head,int d){
    if(head==NULL){//we are insering first node
        head = new node(d);
        return;
    }
    node *n = new node(d);
    n->next=head;
    head->prev=n;
    n->prev=NULL;//passing address of previous head to new head
    head=n; //setting new head as head
}
void insertAtTail(node *&head,int d){
    if(head==NULL){//First Node
        insertAtHead(head,d);
        return;
    }
    node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    node *n=new node(d);
    tail->next=n;
    n->prev=tail->next;
    return;
}
int main(){
    node *head=NULL;
    insertAtHead(head,7);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtTail(head,4);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    print(head);
    return 0;
}