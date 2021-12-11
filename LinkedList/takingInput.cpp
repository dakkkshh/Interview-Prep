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
void input(node*&head){

}
node* takeInput(){
    int d;cin>>d;
    node*head=NULL;
    while(d!=-1){
        //Call whatever function you want head,tail or mid;
        cin>>d;
    }
}
int main(){
    node *head=NULL;
    
    print(head);
    
    return 0;
}