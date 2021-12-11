#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
class carClass{
    public:
    string carName;
    int x,y;
    carClass(){ }
    carClass(string n,int x,int y){
        carName = n;
        this->x = x;
        this->y = y;
    }
    int distance(){

        return x*x + y*y;
    }
};
bool compare(pair<int,int> p1,pair<int,int> p2){
    int d1 = (p1.first*p1.first) + (p1.second*p1.second);
    int d2 = (p2.first*p2.first) + (p2.second*p2.second);
    if(d1==d2){
        return p1.first<p2.first;
    }
    return d1<d2;
}
bool compareClass(carClass a,carClass b){
    int d1 = a.distance();
    int d2 = b.distance();
    if(d1==d2){
        return a.x < b.x;
    }
    return d1<d2;
}
void distanceProblem(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    v.reserve(500);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end(),compare);
    for(auto x:v){
        cout<<"Car "<<x.first<<","<<x.second<<endl;
    }
}
void distanceProblemClass(){
    int n;
    cin>>n;
    vector<carClass> v;
    v.reserve(500);
    for(int i=0;i<n;i++){
        string name;
        int x,y;
        cin>>name>>x>>y;
        carClass temp(name,x,y);
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compareClass);
    for(auto x:v){
        cout<<"Car:"<<x.carName<<","<<x.distance()<<endl;
    }
}

int main(){
/*
    vector<int> b(5,10);
    vector<int> c(b.begin(),b.end());

    for(auto it = c.begin();it!=c.end();it++){ //auto = vector<int>::iterator
        cout<<*it<<" ";
    }
    cout<<endl;
    for(int x:c){ //easy way can replace int with auto
        cout<<x<<" "; 
    }


    cout<<c.size()<<endl;
    cout<<c.capacity()<<endl;
    cout<<c.max_size()<<endl;

    vector<int> d{1,2,3,4,5};
    d.push_back(16);
    //Add at index
    d.insert(d.begin()+3,2,100);
    //Erase at index
    d.erase(d.begin()+1,d.begin()+3);
    for(auto x:d){
        cout<<x<<" ";
    }
    cout<<endl;
*/
    //distanceProblem();
    //Same Problem but using Class Method
    //distanceProblemClass();
    return 0;
}