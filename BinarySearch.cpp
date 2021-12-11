#include<iostream>
using namespace std;
void binSearch(int arr[],int key,int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m]==key){
            cout<<"INDEX:"<<m<<endl;
            break;
        }else if(key<arr[m]){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    if(s>e){
        cout<<"Not Found"<<endl;
    }
}
void binSearchRecursion(int arr[],int key,int s,int e){
    int m =(s+e)/2;
    if(arr[m] ==key){
        cout<<"INDEX:"<<m<<endl;
    }else if(key<arr[m]){
        binSearchRecursion(arr,key,s,m-1);
    }else if(key>arr[m]){
        binSearchRecursion(arr,key,m+1,e);
    }
}
int firstOcc(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    int ans = -1;
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m]==key){
            //Don't Stop
            ans = m;
            e=m-1;    
        }else if(key<arr[m]){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    return ans;
}
int lastOcc(int arr[],int key,int n){
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e){
        int m = (s+e)/2;
        if(arr[m]==key){
            ans = m;
            s=m+1;
        }else if(key<arr[m]){
            e = m-1;
        }else{
            s = m+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {1,2,5,8,8,8,8,8,10,12,15,20};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    //binSearch(arr,key,n); //using while loop
    //binSearchRecursion(arr,key,0,n-1);
    //First and Last Occurence
    cout<<lastOcc(arr,key,n)<<endl;
    return 0;
}
