#include<algorithm>
#include<iostream>
#include<forward_list>
#include<list>
using namespace std;
int main(){
    //Forward List
    // forward_list<int> head;
    // head.assign({1,2,3,4,5});
    // for(auto x:head){
    //     cout<<x<<"-->";
    // }

    // Doubly List/ List-STL
    list<int> head{1,2,3,10,8,5};
    head.push_back(9);
    head.push_front(0);
    head.reverse();
    head.pop_front();
    head.pop_back();
    head.remove(3);
    auto it = head.begin();
    it++;
    it++;
    head.erase(it);
    it++;
    head.insert(it,20);
    for(auto x:head){
        cout<<x<<"-->";
    }

    return 0;
}