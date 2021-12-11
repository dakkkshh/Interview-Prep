#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Queue{
    private: 
        int *arr;
        int f,r,cs,ms;
    public:
        Queue(int defaultSize=5){
            arr = new int[defaultSize];
            cs=0;
            ms=defaultSize;
            f=0;
            r=defaultSize-1;
        }
        bool isFull(){
            return cs==ms;
        }
        bool isEmpty(){
            return cs==0;
        }
        void push(int data){
            if(!isFull()){
                r=(r+1)%ms;
                arr[r]=data;
                cs++;
            }
            return;
        }
        void pop(){
            if(!isEmpty()){
                f=(f+1)%ms;
                cs--;
            }
            return;
        }
        int front(){
            if(!isEmpty()){
                return arr[f];
            }
            
        }
        ~Queue(){
            if(arr!=NULL){
                delete [] arr;
                arr=NULL;
            }
        }

};

class QueueLL{
    int cs;
    list<int> l;

    public:
        QueueLL(){
            cs=0;
        }
        bool isEmpty(){
            return cs==0;
        }
        void push(int data){
            l.push_back(data);
            cs=cs+1;
            return;
        }
        int getFront(){
            return l.front();
        }
        void pop(){
            if(!isEmpty()){
                l.pop_front();
                cs--;
                return;
            }
            return;    
        }
};
void transfer(queue<int> &a, queue<int> &b){
    while(!a.empty()){
        int element = a.front();
        b.push(element);
        a.pop();
    }
    return;
}
class Stack{
    private:
        queue<int> q1;
        queue<int> q2;
    public:
        bool isEmpty(){
            return q1.size()==0;
        }
        void push(int d){
            q1.push(d);
            return;
        }
        void pop(){
            if(q1.empty()){
                return;   
            }
            while(q1.size()>1){
                int elem = q1.front();
                q2.push(elem);
                q1.pop();
            }
            //Removes Last element
            q1.pop();
            //swaping q1 and q2
            swap(q1,q2);
            return;
        }
        int top(){
            return q1.back();
        }
};
int main(){
    //Array Implementation
    // Queue q;
    // for(int i=1;i<=6;i++){
    //     q.push(i);
    // }
    // q.pop();
    // q.pop();
    // q.push(7);
    // while(!q.isEmpty()){
    //     cout<<q.front()<<",";
    //     q.pop();
    // }


    //LL Implementation
    // QueueLL q;
    // for(int i=0;i<=6;i++){
    //     q.push(i);
    // }
    // q.push(9);
    // while(!q.isEmpty()){
    //     cout<<q.getFront()<<" ";
    //     q.pop();
    // }


    //STL-Implementation
    // queue<int> q;
    // for(int i=0;i<10;i++){
    //     q.push(i);
    // }
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }


    //First Non Repeating char;
    // queue<char> q;
    // int freq[27]={0};
    //     //Input running stream untill '.'
    // char ch;
    // cin>>ch;
    // while(ch!='.'){
    //     //Logic here
    //     //Insert in the queue
    //     q.push(ch);
    //     freq[ch-'a']++;

    //     //Query
    //     while(!q.empty()){
    //         int index = q.front()-'a';
    //         if(freq[index]>1){
    //             q.pop();
    //         }else{
    //             cout<<q.front()<<endl;
    //             break;
    //         }
    //     }
    //     //q is empty
    //     if(q.empty()){
    //         cout<<"-1"<<endl;
    //     }
    //     cin>>ch;
    // }


    //Stack Using 2 Que
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}