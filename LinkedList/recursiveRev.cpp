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
int length(node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}
void print(node *head){
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}
//Pass by ref
void insertAtHead(node *&head,int d){

    if(head==NULL){//we are insering first node
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next=head;//passing address of previous head to new head
    head=n; //setting new head as head
}

node* recRev(node*head){
    //smaller linked list 
    if(head->next==NULL or head==NULL){//one node or zero node list
        return head;
    }

    //Rec case
    //Make call on smaller part
    node*shead=recRev(head->next);
    node*temp=shead;  //or temp=head->next
    while(temp->next!=NULL){
        temp=temp->next;
    }
    head->next=NULL;
    temp->next=head;
    return shead;
}

node* recRev2(node*head,node*prev){
    //Base Case
    if(head->next==NULL or head==NULL){
        return head;
    }
    //Rec Case
    node*n;
    //changing pointer direction
    n=head->next;
    head->next=prev;
    //Updating them using recursion
    recRev2(n,head);
    
}
int main(){
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);
    print(head);cout<<endl;
    cout<<"----------"<<endl;
    head=recRev2(head,NULL);
    print(head);



    return 0;
}