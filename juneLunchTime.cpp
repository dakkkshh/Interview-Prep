#include<iostream>
#include<math.h>
#include<vector>
using namespace std;


int main(){
    int number;
    cin>>number;
    int count=0;
    vector<int> ans;
    for(int i=1;i<=number;i++){
        if(number%i==0){
            count++;
            ans.push_back(i);
        }
    }
    cout<<count<<endl;
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;

}