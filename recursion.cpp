#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}
int fib(int n){
    //base case
    if(n==0 or n==1){
        return n;
    }
    //rec case
    int fib1 = fib(n-1),fib2 = fib(n-2);
    return fib1+fib2;
}
bool isSorted(int *a,int n){ //or (int a[],int n) a[] denotes there's an array at address a;
    //base Case
    if(n==0 or n==1){
        return true;
    }
    //rec Case
    if(a[0]<a[1] and isSorted(a+1,n-1)){
        return true;
    }
    return false;
    /*
    We can replace a+1 with an array from elements 1 to n-1
    */
}
int powerCalc(int a, int b){
    //base case
    if(b==1){ //or if b==0 return 1;
        return a;
    }
    //rec case
    return a*powerCalc(a,b-1);
}
int fast_power(int a,int b){
    bool check = b%2==0;
    //base case
    if(b==0){
        return 1;
    }
    //rec case
    int small_ans = fast_power(a,b/2);
    small_ans *= small_ans; //is small_ans = fast_power(a,b/2)*fast_power(a,b/2) it will make tree hence will become complicated
    if(!check){
        return a*small_ans;    
    }
    return small_ans;
}
void descPrint(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    descPrint(n-1);
}
void ascPrint(int n){
    if(n==0){
        return;
    }
    ascPrint(n-1);
    cout<<n<<" ";
}
int binarySearch(int arr[], int p, int r, int num) {
   if (p <= r) {
      int mid = (p + r)/2;
      if (arr[mid] == num)
      return mid ;
      if (arr[mid] > num)
      return binarySearch(arr, p, mid-1, num);
      if (arr[mid] < num)
      return binarySearch(arr, mid+1, r, num);
   }
   return -1;
}
int main(){
    int arr[] ={1,2,3,4,5,8,9,12,20};
    int n = sizeof(arr)/sizeof(int);
    int ans,a;
    cin>>a;
    //ans = factorial(n);
    //ans = fib(n);
    //cout<<isSorted(arr,n)<<endl;
    //ans = fast_power(a,b);
    //cout<<ans<<endl;
    //descPrint(a);
    //cout<<endl;
    //ascPrint(a);
    ans = binarySearch(arr,0,n,a);
    cout<<ans<<endl;
    return 0;
}