#include <iostream>
#include<cstring>
using namespace std;

class Car
{
private:
    int price;

public:
    char *name;
    Car(){
        name=NULL;
    }
    Car(int x,char *n){
        price=x;
        name = new char[strlen(n)+1];
        strcpy(name,n);
        
    }
    Car(Car &x){
        price = x.price;
        //name=x.name shallow part

        //DEEP COPY
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }
    void setPrice(int x){
        price=x;
    }
    void print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Price: "<<price<<endl;
    }
    ~Car(){
        cout<<"Destructed"<<name<<endl;
        if(name != NULL){
            delete[] name;
        }
        
    }    
};

int main()
{
    //Creating an Object
    Car c(230,"BMW" );
    Car d(c);
    d.name[0]='A';
    d.setPrice(200);
    c.print();
    cout<<"--------"<<endl;

    d.print();

    
    return 0;
}