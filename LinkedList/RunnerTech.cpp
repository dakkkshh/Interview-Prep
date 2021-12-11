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
node* midPoint(node*head){
    //single node or 0 node
    if(head->next==NULL or head==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head->next;
    while(fast!=NULL and fast->next!= NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
node* endNode(node*head,int k){
    //single or 0 node in LL
    if(head->next==NULL or head==NULL){
        return head;
    }
    node*slow=head;
    node*fast=head;
    //Taking fast to k nodes ahead
    for(int i=0;i<k;i++){
        fast=fast->next;
    }
    while(fast!= NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
    
}
int main(){

    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    cout<<endl;
    node*mid = midPoint(head);
    cout<<mid->data<<endl;
    node*kNode = endNode(head,1);
    cout<<kNode->data<<endl;

    return 0;
}