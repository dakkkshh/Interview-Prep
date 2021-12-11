#include<iostream>
#include<set>
#include<unordered_set>


using namespace std;
class personCompare{
    public:
        bool operator()(pair<string,int> p1,pair<string,int> p2){
            return p1.second < p2.second;
        }
};
int main(){

    //BASICS
    // int arr[]={10,20,11,11,23,25};
    // int n = sizeof(arr)/sizeof(int);

    // set<int> s;
    // for(int i=0;i<n;i++){
    //     s.insert(arr[i]);
    // }
    
    
    // s.erase(20);//Key is passed which we want to erase
    // auto it=s.find(10);
    // s.erase(it);
    // //Print set Elements
    // for(auto x:s){
    //     cout<<x<<" ";
    // }

    //Pair inside SET
    // set<pair<int,int>> s;
    // s.insert(make_pair(1,2));

    //MULTISET
    // int arr[]={10,20,30,20,10,10};
    // int n=sizeof(arr)/sizeof(int);


    // multiset<int> m(arr,arr+n);
    // m.erase(10);
    // m.insert(80);
    // cout<<m.count(30)<<endl; //count of a number in set
    // auto it=m.find(80);
    // //Get all elements which are equal to 10 provides range of iterator from first to second
    // pair<multiset<int>::iterator,multiset<int>::iterator> p = m.equal_range(10);

    
    // for(auto x:m){
    //     cout<<x<<" ";
    // }

    //Multiset of Custom DataType
    multiset<pair<string,int>,personCompare> m;
    //Now comparisong will be based on the class defined
    //Current setting is ascending order

    return 0;
}