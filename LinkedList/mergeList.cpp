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
    n->next=head;//passing address of previous head to new head
    head=n; //setting new head as head

}
node *merge(node*a,node*b){
    //Base Case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //Take a temp head "c"
    //Compare and GO tech like of merging an array
    node*c;
    if(a->data < b->data){
        c=a;
        c->next= merge(a->next,b);
    }else{
        c=b;
        c->next=merge(a,b->next);
    }
    return c;
}

int main(){

    node *head=NULL;
    node *head2=NULL;
    insertAtHead(head,9);
    insertAtHead(head,7);
    insertAtHead(head,5);
    insertAtHead(head,3);
    insertAtHead(head,1);

    insertAtHead(head2,8);
    insertAtHead(head2,6);
    insertAtHead(head2,4);
    insertAtHead(head2,2);
    insertAtHead(head2,0);

    node *merged = merge(head,head2);
    print(merged);
    

    return 0;
}