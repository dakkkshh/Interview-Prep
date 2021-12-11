#include<iostream>
using namespace std;
int main(){
    int arr[1000],csum=0,msum=0,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        csum += arr[i];
        if(csum<0){
            csum=0;
        }
        msum = max(csum,msum);
    }
    cout<<"Maximum is:- "<<msum<<endl;
    return 0;
}