#include<iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

typedef pair<int,pair<int,int>> customPair;
class Fun{
    public:
        void operator()(string s){
            cout<<"Having Fun With "<<s<<" !";
            return;
        }

};
class Person{
    public:
        string name;
        int age;

        Person(){

        }
        Person(string s,int a){
            name=s;
            age=a;
        }
};
class PersonCompare{
    public:
    //If true B will be given Priority
    bool operator()(Person a,Person b){
        return a.age < b.age;
    }
};
//QUESTIONS
int join_ropes(int ropes[],int n){
    priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
    int cost=0;
    while(pq.size()>1){
        int A=pq.top();
        pq.pop();
        int B=pq.top();
        pq.pop();
        
        int newRope=A+B;
        cost+=(A+B);
        pq.push(newRope);
    }
    return cost;

}
void runningStream(){
    priority_queue<int> leftHeap; //MAX HEAP
    priority_queue<int,vector<int>,greater<int>> rightHeap; //MIN HEAP

    int d;
    cin>>d;
    leftHeap.push(d);
    float med = d;
    //First Element in median itself so print it out
    cout<<"Median: "<<med<<endl;
    cin>>d;
    //Input all elements
    while(d!=-1){
        //Logic
        if(leftHeap.size()>rightHeap.size()){
            if(d<med){
                //data is going in leftheap
                //migrate top from left to right to avoid imbalance
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }else{
                rightHeap.push(d);
            }
            //Both heap have now same size
            //Med is avg of two
            med=(leftHeap.top()+rightHeap.top())/2.0;
        }else if(leftHeap.size()==rightHeap.size()){
            if(d<med){
                leftHeap.push(d);
                med=leftHeap.top();
            }else{
                rightHeap.push(d);
                med=rightHeap.top();

            }
        }else{
            if(d>med){
                //Going in right and right is already bigger than left so transfer and push
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }else{
                leftHeap.push(d);
            }
            med=(leftHeap.top()+rightHeap.top())/2.0;
        }

        cout<<"Median: "<<med<<endl;
        cin>>d;
    }
    return;
}
vector<int> mergeKSortedArray(vector<vector<int>> arr){
    vector<int> result;
    priority_queue<customPair,vector<customPair>,greater<customPair>> pq; //min Priority Queue

    //Insert the 0th elem of each array
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    //pop and insert to result 
    while(!pq.empty()){
        customPair current = pq.top();
        pq.pop();
        result.push_back(current.first);
        //Indexes of the array
        int x = current.second.first;//row 
        int y = current.second.second;//column

        //Push next element of the current element
        //next element at x,y+1
        if(y+1 < arr[x].size()){
            //Element left in array
            pq.push({arr[x][y+1],{x,y+1}});
        }     
    }
    return result;

}
int main()
{
    // priority_queue<int,vector<int>,greater<int>> pq;
    // for(int i=1;i<=5;i++){
    //     int no;
    //     cin>>no;
    //     pq.push(no);
    // }

    // //Removing Elements
    // while(!pq.empty()){
    //     //By default is Decending Order
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }


    //FUNCTOR
    //Fun f;//constructor call
    //Functor Below as It is behaving like an obj but acting a fxn
    //f("C++");//overloaded operator() = Function Call where F is an Obj

    //Person Age Priority CUSTOM PRIORITY CLASS
    // int n;
    // cin>>n;
    // priority_queue<Person,vector<Person>,PersonCompare> pq;
    // for(int i=0;i<n;i++){
    //     int age;
    //     string name;
    //     cin>>name>>age;
    //     Person p(name,age);
    //     pq.push(p);
    // }
    // int k=3;
    // for(int i=0;i<k;i++){
    //     Person current = pq.top();
    //     cout<<current.name<<" -> "<<current.age<<endl;
    //     pq.pop();
    // }

    //JOIN ROPES
    // int ropes[]={4,3,2,6};
    // int n=4;
    // cout<<join_ropes(ropes,n)<<endl;

    //Running Stream QS
    //runningStream();

    //Merge K Sorted Arrays
    vector<vector<int>> arr{{2,6,12,15},{1,3,14,20},{3,5,8,10}};
    vector<int> output = mergeKSortedArray(arr);
    for(auto x:output){
        cout<<x<<" ";
    }
    return 0;
}