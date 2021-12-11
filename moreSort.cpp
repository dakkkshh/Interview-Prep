#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void countSort(){
    int arr[]={88,97,10,12,15,1,5,6,12,5,8};
    int size = sizeof(arr)/sizeof(int);
    int large=INT_MIN;
    for(int i=0;i<size;i++){
        large = max(large,arr[i]);
        
    }
    int countArr[large+1]={0};
    for(int i=0;i<size;i++){
        countArr[arr[i]]++;
    }
    int j=0;
    for(int i=0;i<=large;i++){
        while(countArr[i]>0){
            arr[j]=i;
            countArr[i]--;
            j++;
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
}
class Student{
    public:
        int marks;
        string name;
};
void bucketSort(){
    Student s[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i].marks>>s[i].name;
    }

    //Assuming marks are in the range from 0-100;
    vector<Student> v1[101];
    for(int i=0;i<n;i++){
        int m = s[i].marks;
        v1[m].push_back(s[i]);    
    }
    //Iterate over vector and print
    for(int i=100;i>=0;i--){
        for(auto it = v1[i].begin();it!=v1[i].end();it++){
            cout<<(*it).marks<<"  "<<(*it).name<<endl;
        }
    }
}
void dnfSort(){
    int arr[]={2,1,1,1,1,0,1,1,1,0,0,2,0};
    int n = sizeof(arr)/sizeof(int);

    int lo=0;
    int high = n-1;
    int mid =0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[lo]);
            lo++;
            mid++;
        }
        if(arr[mid]==1){
            mid++;
        }
        if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
            //Will not reduce mid since it is possible that last (n-1)is a 0;
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }
}
void waveSort(){
    int arr[]={1,3,4,2,7,4};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0;i<n;i+=2){
        //one comparison with prev element
        if(i!=0 and arr[i]<arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        //one comparison with next element
        if(i!= n-1 and arr[i]<arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    for(auto x:arr){
        cout<<x<<" ";
    }

}
int main(){

    //countSort();
    //bucketSort();
    //dnfSort();
    waveSort();
    return 0;
}