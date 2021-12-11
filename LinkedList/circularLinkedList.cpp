#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    //Constructor
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertAtHead(node *&head,int d){

    if(head==NULL){//we are insering first node
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next=head;//passing address of previous head to new head
    head=n; //setting new head as head

}
//Circular
void circularLinkedList(node *&head,int d){
    //If there is no Node previously create a new node
    if(head==NULL){
        insertAtHead(head,d);
        return;
    }
    node *n= new node(d);
    node *temp = head;
    n->next=head;
    if(temp!=NULL){
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    head=n;
    return;
}
void printCircular(node *head){
    cout<<"In Fxn"<<endl;
    node *tmp=head;
    while(tmp->next != head){
        cout<<tmp->data<<"-->";
        tmp=tmp->next;
    }
    cout<<tmp->data;
    return;
}
int main(){

    //Circular LL
    node *head=NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    circularLinkedList(head,0);
    printCircular(head);

    return 0;
}