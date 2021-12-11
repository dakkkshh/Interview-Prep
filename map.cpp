#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,int> m; 
    // //Inserting Object
    // m.insert(make_pair("Mango",100));
    // pair<string,int> p;
    // p.first="Apple";
    // p.second=120;
    // m.insert(p);
    // m["Banana"]=20;

    // //Search
    // string key;cin>>key;
    // auto it=m.find(key);
    // if(it!=m.end()){
    //     cout<<"Got the key: "<<m[key]<<endl;
    // }else{
    //     cout<<"Key Not Found"<<endl;
    // }

    // if(m.count(key)){
    //     cout<<"Price is: "<<m[key]<<endl;
    // }else{
    //     cout<<"Key Not Found"<<endl;
    // }

    // //Erase
    // //m.erase(key);

    // //Iterate over all K-V
    // for(auto it=m.begin();it!=m.end();it++){
    //     cout<<it->first<<" and "<<it->second<<endl;
    // }
    //     //OR
    // for(auto p:m){
    //     cout<<p.first<<" and "<<p.second<<endl;
    // }


    return 0;
}