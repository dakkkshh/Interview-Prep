#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[],int n){
    int dp[100]={0};
    // int cSum = 0;
    //Instead of using cSum we are using a dp array
    int maxSoFar = dp[0];
    dp[0]=arr[0]>0?arr[0]:0;
    for(int i=1;i<n;i++){
        dp[i] = dp[i-1] + arr[i];
        if(dp[i]<0){
            dp[i]=0;
        }
        maxSoFar = max(maxSoFar,dp[i]);
    } 
    return maxSoFar;
}
int maxSumOptimized(int arr[],int n){
    //Kaden's Algo
    int cSum = 0;
    int maxSoFar = INT_MIN;

    for(int i=0;i<n;i++){
        cSum+=arr[i];
        if(cSum<0) cSum = 0;
        maxSoFar = max(maxSoFar,cSum);
    }
    return maxSoFar;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    // cout<<"Ans: "<<maxSum(arr,n)<<endl;
    cout<<"Ans: "<<maxSumOptimized(arr,n)<<endl;
    return 0;
}