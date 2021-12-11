#include<bits/stdc++.h>
using namespace std;

int fibTopDown(int n,int dp[]){
    //Base case
    if(n==0 or n==1){
        return n;
    }
    //Check for memorization
    if(dp[n]!=0){
        return dp[n];
    }
    int ans;
    ans = fibTopDown(n-1,dp)+fibTopDown(n-2,dp);
    return dp[n]=ans;
}
int fibBottomUp(int n){
    int dp[100];
    //Base case
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{      
    int n;
    cin>>n;
    int dp[100]={0};
    // cout<<fibTopDown(n,dp);
    cout<<fibBottomUp(n);

    return 0;
}