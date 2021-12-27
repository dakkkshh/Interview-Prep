#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int dp[n+1];
    dp[0]=INT_MIN;
    for(int i=1;i<=n;i++){
        dp[i]=INT_MAX;
    }
    //Normal O(N*N)
    // for(int i=0;i<n;i++){
    //     int cur = arr[i];
    //     for(int j=0;j<=i;j++){
    //         if(cur>dp[j] and cur<dp[j+1]){
    //             dp[j+1] = cur;
    //             break;
    //         }    
    //     }
    // }
    //CB WAY
    // for(int i=0;i<n;i++){
    //     int cur = arr[i];
    //     for(int j=0;j<n;j++){
    //         if(dp[j]<cur and cur<dp[j+1]){
    //             dp[j+1]=cur;
    //         }    
    //     }
    // }
    //Optimized Using Binary Search
    for(int i=0;i<n;i++){
        int cur = arr[i];
        //Binary Search Here using in-built Upper Bound Function
        int len = upper_bound(dp,dp+n+1,cur)-dp;
        //Now len is index which is just greater than current value
        if(dp[len-1] < cur and cur<dp[len]){
            //For strictly increasing check for safe condition
            dp[len]=cur;
        }
    }
    int ans = 0;
    for(int i=0;i<=n;i++){
        if(dp[i]!=INT_MAX) ans=i;
    }
    cout<<"Ans: "<<ans<<endl;
    return 0;
}