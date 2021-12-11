#include<iostream>
using namespace std;
void increment(int *a){
    *a+=1;
    cout<<"Inside is:- "<<*a<<endl;
}
int main(){
    int x=10;
    int* ptr = &x;
    int** xxptr = &ptr;
    cout<<&x<<endl;
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<(&ptr)<<endl; //add of ptr
    cout<<xxptr<<endl;  //add of ptr
    cout<<*xxptr<<endl; //ptr
    increment(ptr);
    cout<<"Outside is:- "<<*ptr<<endl; //using pass by value will print 10

    return 0;
}