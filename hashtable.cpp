#include<iostream>
using namespace std;

template<typename T>
class Node{
    
    public:
    string key;
    T value;
    Node<T>* next;

    Node(string key,T val){
        this->key = key;
        this->value=val;
        next=NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class Hashtable{
    Node<T>** table;
    int currentSize;
    int tableSize;
    int HashFxn(string key){
        int idx = 0;
        int p = 1; //p is power
        for(int j=0;j<key.length();j++){
            idx+=(key[j]*p)%tableSize;
            idx%=tableSize;
            p=(p*27)%tableSize;
        }
        return idx;
    }
    void rehash(){
        
        Node<T>** oldTable = table; //old pointer pointing to prev table
        int oldTableSize = tableSize;
        tableSize*=2;
        table = new Node<T>*[tableSize];
        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
        currentSize=0;
        //shift elem from old table to new table
        for(int i=0;i<oldTableSize;i++){

            Node<T>* currentBucket = oldTable[i];//head of LL or Bucket of table
            while(currentBucket!=NULL){
                insert(currentBucket->key,currentBucket->value);
                currentBucket = currentBucket->next;
            }
            //Deletion of LL
            if(oldTable[i]!=NULL){
                //Going to be deleted recursively due to if statement in the destructor of the NODE class
                delete oldTable[i]; //Deleted Head of LL
            }
        }
        delete [] oldTable;

        return;
    }

    public:
    Hashtable(int ts=7){ //ts = table size
        tableSize=ts;
        table = new Node<T>*[tableSize];
        currentSize=0;
        for(int i=0;i<tableSize;i++){
            table[i]=NULL;
        }
    }
    void insert(string key, T value){
        int idx=HashFxn(key);
        //Create a LL now

        Node<T>* n = new Node<T>(key,value);
        //Insert at head with id=idx
        n->next=table[idx];
        table[idx]=n;
        currentSize++;

        //Rehash
        float loadFactor = currentSize/(1.0 * tableSize);
        if(loadFactor > 0.7){
            //LF Croses threshhold
            rehash();
        }
    }
    void print(){
        for(int i=0;i<tableSize;i++){
            cout<<"Bucket "<<i<<" --> ";
            Node<T>* temp = table[i];
            //While loop print each bucket
            while(temp!=NULL){
                cout<<temp->key<<" -> ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    T* search(string key){
        //Return Address of Value
        int idx=HashFxn(key); 
        Node<T>* temp=table[idx];
        while(temp!=NULL){
            if(temp->key==key){
                return &temp->value;
            }
            temp=temp->next;
        }
        //Can not find value mapped to key
        return NULL;

    }
    void erase(string key){
        int idx=HashFxn(key);
        Node<T>* temp=table[idx];
        //If head is the key
        if(temp->key==key){
            table[idx]=temp->next;
            delete temp;
            currentSize--;
            return;
        }
        //if key lies in mid or end
        while(temp!=NULL){
            if(temp->next->key==key){
                Node<T>* toDelete = temp->next;
                temp->next=toDelete->next;
                delete toDelete;
                currentSize--;
                return;
            }
            temp=temp->next;
        }
        return;
    }
    //Operator Overloading
    T& operator[](string key){
        //If key is present or not
        T* f = search(key);
        if(f==NULL){
            //Insert the key with garbage value
            T garbage;
            insert(key,garbage);
            f=search(key);
        }
        return *f;
    }


};
int main()
{
    Hashtable<int> price_menu;
    price_menu.insert("Burger",100);
    price_menu.insert("Pepsi",20);
    price_menu.insert("Noodles",90);
    price_menu.insert("Pasta",120);
    price_menu.insert("Maggi",40);

    price_menu.print();   
    
    //SEARCH
    // int *price = price_menu.search("Noodles");
    // if(price!=NULL){
    //     cout<<"Price is: "<<*price<<endl;
    // } 

    //DELETE
    // price_menu.erase("Noodles");
    // cout<<"Updated Table"<<endl;
    // price_menu.print();

    //Operator Overloading
        //Insert
        price_menu["Dosa"]=60;
        //Update
        price_menu["Dosa"]+=10;
        //Search
        cout<<price_menu["Dosa"]<<endl;


    return 0;
}