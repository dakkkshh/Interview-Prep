#include<iostream>
//Converting it to template class
template<typename T>
class Vector{
    //cs= membors present and ts = total size of array
    //Private members
    int cs,ts;
    T *arr;

    public:
        Vector(){
            cs = 0;
            ts = 0;
            arr = new T[ts];
        }

        void push_back(const T d){
            if(cs==ts){
                //Array is full
                T *old = arr;
                arr = new T[2*ts];
                ts = 2*ts;
                for(int i=0;i<cs;i++){
                    arr[i] = old[i];
                }
                //Clear Old memory
                delete [] old;
            }
            arr[cs] = d;
            cs++; 
        }
        void pop_back(){
            cs--;
        }
T front()const{
            return arr[0];
        }
        T back()const{
            return arr[cs-1];
        }

        bool isEmpty()const{
            return cs==0;
        }

        int capacity()const{
            return ts;
        }

        T at(int i){
            return arr[i];
        }
        int size(){
            return cs;
        }
        //operator Overloading

        T operator[](const int i){
            return arr[i];
        }
};