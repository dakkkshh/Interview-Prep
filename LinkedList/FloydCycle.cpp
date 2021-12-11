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
void insertAtHead(node *&head,int d){

    if(head==NULL){//we are insering first node
        head = new node(d);
        return;
    }

    node *n = new node(d);
    n->next=head;//passing address of previous head to new head
    head=n; //setting new head as head

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
bool detectCycle(node *head){
    node*slow=head;
    node*fast=head;

    while(fast!=NULL and fast->next!=NULL){
        //Taking fast to two steps ahead and slow to one step ahead
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
        
    }
    return false;
}
void floydBreak(node *&head){
    node*slow=head;
    node*fast=head;
    node*startLoop;
    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            node*islow=head;
            node*ifast=slow;
            while(ifast!=NULL){
                islow=islow->next;
                ifast=ifast->next;
                if(ifast==islow){
                    startLoop=ifast;
                    break;
                }
            }
            break;
        }    
    }
    node*temp=startLoop;
    while(temp->next!=startLoop){
        temp=temp->next;
    }
    temp->next=NULL;
    return;    
}

//Circular
void circularLinkedList(node *&head,int d){
    if(head==NULL){
        insertAtHead(head,d);
        return;
    }
    node *n= new node(d);
    node *temp = head;
    n->next=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    head=n;
    return;
}
void printCircular(node *head){
    node *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    return;
}
int main(){
    // Floyd
    // node *head=takeInput();
    // print(head);
    // floydBreak(head);
    // print(head);

    //Circular LL
    node *head=NULL;
    circularLinkedList(head,1);
    circularLinkedList(head,2);
    circularLinkedList(head,3);
    circularLinkedList(head,4);
    circularLinkedList(head,5);
    circularLinkedList(head,6);
    circularLinkedList(head,7);
    printCircular(head);

    return 0;
}