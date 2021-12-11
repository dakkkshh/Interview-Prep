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

ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}
istream& operator>>(istream &os,node*head){
    //takeinput(head); takeInput.cpp
    return os;
}
int main(){
    node*head;
    node*head2; 


    //Default
    //cout<<head<<endl;

    cout<<head<<head2;




    return 0;
}