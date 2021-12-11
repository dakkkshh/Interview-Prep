#include<iostream>
#include<numeric>
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
    //Single or 0 Node in LL
    //Here we are Finding the MidPoint using two pointer Approach or Runner tech
    //More in Runnertech.cpp
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
node *merge(node*a,node*b){
    //Base Case
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    //Take a temp head "c"
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
node *mergeSort(node*head){
    //Base case
    //Single or 0 Node in LL
    if(head==NULL or head->next==NULL){
        return head;
    }
    //Rec case
    //Break using mid point
    node *mid = midPoint(head);
    node *a = head;
    node *b = mid->next;
    mid->next=NULL;
    //Rec sort two lists
    a=mergeSort(a);
    b=mergeSort(b);
    //Merging them
    node *c = merge(a,b);
    return c;
}
node* takeInput(){
    int d;cin>>d;
    node*head=NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;   
}
int main(){
    node *head=takeInput();
    mergeSort(head);
    print(head);
    return 0;
}