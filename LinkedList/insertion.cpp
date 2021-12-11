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
void insertAtTail(node *&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node* tail = head;
    while(tail->next!= NULL){
        tail=tail->next;
    }
    tail->next = new node(d);
    return;
}
void insertAtMiddle(node *&head,int d,int p){
    if(head==NULL or p==0){
        //linked list doen't exsist
        insertAtHead(head,d);
        return;
    }else if(p>length(head)){
        insertAtTail(head,d);
    }else{
        //Taking p-1 jump for start or temp node
        int jump=1;
        node *temp=head;
        while(jump<=(p-1)){
            temp=temp->next;
            jump++;
        }
        //create node
        node *n = new node(d);
        n->next = temp->next;
        temp->next = n;
        return; 
    }

    
}
int main(){
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    insertAtMiddle(head,4,3);

    insertAtTail(head,7);

    print(head);
    
    return 0;
}