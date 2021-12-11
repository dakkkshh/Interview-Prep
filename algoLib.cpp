#include<iostream>
#include<algorithm>
using namespace std;
//Comparator function of sort
bool sortCompare(int a,int b){
    //ASC
    //return a<b;
    //DESC
    return a>b;
}
void moneyPrblm(int a){
    int coins[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(coins)/sizeof(int);
    int i=n-1;
    while(a!=0){
        if(coins[i]<=a){
            cout<<coins[i]<<"+";
            a-= coins[i];
        }
        i--;
        if(i<0){
            i=n-1;
        }
    }
}
int main(){
    int arr[] = {100,1,99,10,4,8,9,10,9,20,31};
    int n = sizeof(arr)/sizeof(int);
    /* FIND
    int key = 12;
    auto it = find(arr,arr+n,key);
    int index = it-arr;
    cout<<index<<endl;
    if(index == n){
        cout<<"NOT FOUND"<<endl;
    } */

    /* Binary Search
    int key = 40;
    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"FOUND"<<endl;
    }else{
        cout<<"NOT FOUND"<<endl;
    }
    auto it = lower_bound(arr,arr+n,key);
    auto it = upper_bound(arr,arr+n,key);
    cout<<it-arr<<endl; */ //Return Index

    /* SORT
    sort(arr,arr+n,sortCompare);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    } */

    //moneyPrblm(a);

    /* ROTATE
    int b = n/2;
    rotate(arr,arr+b,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }*/

    /*NEXT PERMUTATION
    next_permutation(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    } */

    /* REVERSE
    reverse(arr,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    } */

    //PAIR
    pair<int,char> p;
    p.first = 10;
    p.second = 'B';
    cout<<p.first<<"    "<<p.second<<endl;

    return 0;
}