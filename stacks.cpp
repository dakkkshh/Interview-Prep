#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

template<typename T>
class Stack{
    private:
        vector<T> v;
    public:
        void push(T data){
            v.push_back(data);
        }
        bool empty(){
            return v.size()==0;
        }
        void pop(){
            if(!empty()){
                v.pop_back();
            }    
        }
        T top(){
            return v[v.size()-1];
        }
        void reverseStack(){
            reverse(v.begin(),v.end());
            return;
        }
};
Stack<int> reverseStackFxn(Stack<int> s){
    Stack<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    return temp;
}
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
    cout<<endl;
    return;
}

//CB Approac to Rev a Stack
void transfer(stack<int> &s1,stack<int> &s2,int n){
    for(int i=0;i<n;i++){
        s2.push(s1.top());
        s1.pop();
    }
    return;
}
void reverseStackCB(stack<int> &s){
    //helper stack;
    stack<int> s2;
    int n=s.size();
    for(int i=0;i<n;i++){
        //pick top and insert to bottom
        int x=s.top();
        s.pop();

        //Transfer n-i-1 from s to helper
        transfer(s,s2,n-i-1);
        //Insert x to s
        s.push(x);
        //Transfer n-i-1 from helper to s
        transfer(s2,s,n-i-1);
    }
    return;
}
void insertAtBottom(stack<int> &s,int x){
    //Base case
    if(s.empty()){
        s.push(x);
        return;
    }
    //Otherwise pop data and call fxn on small stack
    int data=s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
    return;
}
void recRevStack(stack<int> &s){
    //Base case
    //if s is empty
    if(s.empty()){
        return;
    }
    //Otherwise, pop top element and insert it at bottom of revered smaller stack
    int x=s.top();
    s.pop();
    //rec rev small stack
    recRevStack(s);
    insertAtBottom(s,x);
    return;
}
bool isValidExp(char *s){
    //Store opeing bracket
    //If closing is on top then pop else return false
    stack<char> s1;
    for(int i=0;s[i]!='\0';i++){
        char ch = s[i];
        if(ch=='('){
            s1.push(ch);
        }else if(ch==')'){
            //if it is not a match
            if(s1.empty() or s1.top()!='('){
                return false;
            }
            //if it is a match
            s1.pop();
        }
    }
    return s1.empty();

}
void stockSpan(int prices[],int n,int span[]){
    stack<int> s;//Indices of day
    s.push(0);
    span[0]=1;

    //loop on rest of days
    for(int i=1;i<n;i++){
        //get current price
        int current = prices[i];
        //Get topmost element which is higher than current price
        while(!s.empty() and prices[s.top()]<=current){
            s.pop();
        }
        if(!s.empty()){
            int leftHighest=s.top();
            span[i]=i-leftHighest;
        }else{
            span[i]=i+1;
        }
        //push this element into the stack
        s.push(i);
    }
    return;
}
int main(){
    //Custom STack Class
    // Stack<int> s;
    // for(int i=1;i<=10;i++){
    //     s.push(i*2);
    // }


    //STL-stack
    // stack<int> s2;


    //Reversing Stack by Transfer
    // Stack<int> c=reverseStackFxn(s);
    // print(c);


    //CB ONE to Rev
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // reverseStackCB(s);
    // print(s);


    //Rec Rev Stack
    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // recRevStack(s);
    // print(s);


    //Check Brackets
    // char c[100]="((a+b)+(c-d+f))";    
    // if(isValidExp(c)){
    //     cout<<"T";
    // }else{
    //     cout<<"F";
    // }


    //Stock Span Problem
    int prices[]={100,80,60,70,70,75,85};
    int n=sizeof(prices)/sizeof(int);
    int span[10]={0};
    stockSpan(prices,n,span);
    for(auto x:span){
        cout<<x<<" ";
    }
    return 0;
}