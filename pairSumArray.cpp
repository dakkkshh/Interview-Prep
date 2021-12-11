#include<iostream>
using namespace std;
//Given Sorted Array,Find pair of elements that sum to k(Given)
int main(){
    int arr[]={1,3,5,7,10,11,12,13},n;
    int sum=16,i=0,j = (sizeof(arr)/sizeof(int)) -1;

    while(i<j){
        int csum = arr[i]+arr[j];
        if(csum < sum){
            i++;
        }else if(csum > sum){
            j--;
        }else if(csum == sum){
            cout<<"["<<arr[i]<<","<<arr[j]<<"]"<<endl;
            i++;
            j--;
        }
    }
    return 0;
}