#include<iostream>
#include<vector> //as push back op is provided in vector and it is dynamic
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;

    bool compare(int a,int b){
        if(minHeap){
            return a<b; //if true then swap
        }
        return a>b;;
    }
    void heapify(int idx){
        int leftChild = 2*idx;
        int rigthChild = leftChild+1;
        int minIdx=idx;
        int lastIdx=v.size()-1;
        if(leftChild <= lastIdx and compare(v[leftChild],v[idx])){
            //That node exist
            minIdx=leftChild;
        }
        if(rigthChild <= lastIdx and compare(v[rigthChild],v[minIdx])){
            minIdx=rigthChild;
        }
        //now minIdx store index of smallest child of idx node
        if(minIdx!=idx){ //also act as base case as if node is at right position then this condition will not hit
            swap(v[idx],v[minIdx]);
            //Rec Call
            heapify(minIdx);
        }
        return;
    }
    public:
        Heap(int default_size=10,bool isminHeap=true){
            v.reserve(default_size);
            v.push_back(-1);//blocking 0th index
            minHeap=isminHeap;
        }

        void push(int d){
            v.push_back(d);
            int currentIndex= v.size()-1;
            int parent=currentIndex/2;
            
            //keep pushing to top till root node or stop midway because current element is greater than parent

            while(currentIndex>1 and compare(v[currentIndex],v[parent])){
                swap(v[currentIndex],v[parent]);
                currentIndex=parent;
                parent=parent/2;
            }
        }
        int top(){
            //return top element
            return v[1];
        }
        void pop(){
            //pop top element
            int lastIndex=v.size()-1;
            swap(v[1],v[lastIndex]);
            v.pop_back();
            //heapify it
            heapify(1);
            return;
        }
        bool isEmpty(){
            return v.size()==1;
        }
};
void buildHeap(vector<int> &v){
    for(int i=1;i<v.size();i++){
        int idx=i;
        int parent = i/2;
        while(idx>1 and v[idx]>v[parent]){ //for max heap
            swap(v[idx],v[parent]);
            idx=parent;
            parent=parent/2;
        }
    }
    return;
}
void print(vector<int> v){
    for(auto x:v){
        cout<<x<<" ";
    }
    cout<<endl;
    return;
}
//Build Heap O(N) Approach
bool compare(int a, int b)
{   //for max Heap 
    return a > b;
}
void heapify(vector<int> &v,int idx,int size)
{
    int leftChild = 2 * idx;
    int rigthChild = leftChild + 1;
    int minIdx = idx;
    int lastIdx = size - 1;
    if (leftChild <= lastIdx and compare(v[leftChild], v[idx]))
    {
        //That node exist
        minIdx = leftChild;
    }
    if (rigthChild <= lastIdx and compare(v[rigthChild], v[minIdx]))
    {
        minIdx = rigthChild;
    }
    //now minIdx store index of smallest child of idx node
    if (minIdx != idx)
    { //also act as base case as if node is at right position then this condition will not hit
        swap(v[idx], v[minIdx]);
        //Rec Call
        heapify(v,minIdx,size);
    }
    return;
}
void buildHeapOptimized(vector<int> &v){
    for(int i=((v.size()-1)/2);i>=1;i--){
        heapify(v,i,v.size());
    }
}
void heapSort(vector<int> &arr){

    buildHeapOptimized(arr);
    //Max Heap Obtained
    int n = arr.size();
    //remove n-1 elements from heap
    while(n>1){//atleast 2 elements one null and one real
        swap(arr[1],arr[n-1]);
        n--;
        heapify(arr,1,n);
    }
    return;
}
int main(){

    //Give some initial size of heap and give type of heap min or max
    //True for min and false for max
    // int n;
    // cin>>n;
    // Heap h(n,false); //maxheap
    // for(int i=0;i<n;i++){
    //     int no;
    //     cin>>no;
    //     h.push(no);
    // }
    //Remove elements from heap
    // while(!h.isEmpty()){
    //     cout<<h.top()<<endl;
    //     h.pop();
    // }

    //Vector to Heap
    // vector<int> v={-1,10,20,5,6,1,8,9,4};
    // print(v);
    // buildHeapOptimized(v);
    // print(v);

    //HeapSort
    // vector<int> v={-1,2,1,0,4,3};
    // print(v);
    // heapSort(v);
    // print(v);

    return 0;
}