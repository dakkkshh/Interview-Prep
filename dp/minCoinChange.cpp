#include<bits/stdc++.h>
using namespace std;

int minCoinChangeTD(int coins[],int money,int dp[],int coinSize){
    //Base case
    if(money==0)return 0;

    //Check Case
    if(dp[money]!=0){
        return dp[money];
    }
    int ans = INT_MAX;
    for(int i=0;i<coinSize;i++){
        int toFind = money-coins[i];
        if(toFind >= 0){
            int tempCase = minCoinChangeTD(coins,toFind,dp,coinSize);
            ans = min(ans,tempCase+1);
        }
    }
    return dp[money]=ans;
}
int minCoinChangeBU(int coins[],int money,int coinSize){
    
}
int main()
{
    int n,money;
    cin>>n>>money;
    int coins[n],dp[3000]={0};
    for(int i=0;i<n;i++){
        cin>>coins[i];
        dp[coins[i]]=1;
    }
    cout<<minCoinChangeTD(coins,money,dp,n);
    return 0;
}