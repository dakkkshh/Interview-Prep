#include<iostream>
#include<unordered_map>
using namespace std;


class Student{
    public:
    string firstName;
    string lastName;
    string rollNo;

    Student(string f,string l,string r){
        firstName=f;
        lastName=l;
        rollNo=r;
    }
    bool operator==(const Student &s)const{
        return rollNo==s.rollNo?true:false;
    }
};
class HashFxn{
    public:
    //defining how to computer hash value of a student obj
    size_t operator()(const Student &s)const{
        return s.firstName.length() + s.lastName.length();
    }

};
int main()
{
    
    //Methods same as MAP
    unordered_map<Student,int,HashFxn> studentMap;
    Student s1("Prateek","Narang","010");
    Student s2("Rahul","Kumar","023");
    Student s3("Daksh","Rao","030");
    Student s4("Rahul","Kumar","120");

    //Add student and Marks to HashMap
    studentMap[s1]=100;
    studentMap[s2]=120;
    studentMap[s3]=97;
    studentMap[s4]=45;

    //Output
    for(auto x:studentMap){
        cout<<x.first.firstName<<" Got Marks: "<<x.second<<endl;
    }


    return 0;
}