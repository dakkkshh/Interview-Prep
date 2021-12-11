#include<iostream>
#include <iterator>
#include<list>
using namespace std;


//Linear Search
template<typename T>
int linearSearch(T a[],T k,int n){
    for(int i=0;i<n;i++){
        if(a[i]==k){
            return i;
        }
    }
    return -1;
}
template<class ForwardIterator,class T>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T key){
    while(start!=end){
        if(*start == key){
            return start;
        }
        start++;
    }
    return end;

}
//Comparators Example
class Book{
    public:
        string name;
        int price;

    Book(){//Default Constructor

    }
    Book(string name,int age){//Parametrisied Constructor
        this ->name = name;
        this ->price = price;
    }

};
class BookCompare{
    public:
        bool operator()(Book A,Book B){//Override bool Operator
            if(A.name == B.name){ //On Basis of name
                return true;
            }
            return false;
        }

};
template<class ForwardIterator,class T,class Compare>
ForwardIterator bookSearch(ForwardIterator start,ForwardIterator end,T key,Compare cmp){
    while(start!=end){
        if(cmp(*start,key)){
            return start;
        }
        start++;
    }
    
    return end;

}
int main(){
    /*
    int a[]={11,2,5,20,9,4,8};
    int c = sizeof(a)/sizeof(int);
    float b[]={1.1,2.4,9.8,56.9,99.87};
    int d = sizeof(b)/sizeof(float);
    int key = 5;
    float k = 56.9;
    cout<<linearSearch(a,key,c)<<endl;
    cout<<linearSearch(b,k,d)<<endl;
    list<int> l;
    for(int i=0;i<5;i++){
        l.push_back(i);
    }
    auto it = search(l.begin(),l.end(),3);
    cout<<*it<<endl;*/
    Book b1("C++",100); //Old Edition
    Book b2("python",120);
    Book b3("java",130);
    Book b4(b1); //b4 is a copy of b1
    
    list<Book> l;
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    BookCompare cmp;
    Book toFind("C++",110); //New Edition of book
    /*  EXAMPLE
    if(cmp(b1,toFind)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }*/
    auto it = bookSearch(l.begin(),l.end(),toFind,cmp);
    if(it!=l.end()){
        cout<<"Book Found in Library"<<endl;
    }
    return 0;
}