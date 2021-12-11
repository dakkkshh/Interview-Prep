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
    int dp[money+10]={0};
    int ans = INT_MAX;
    //Min and Max functions are not good for large input
    //interate over all the numbers from 1 to money
    //Not checking dp[0] since it will be 0
    for(int i=1;i<=money;i++){
        dp[i]=INT_MAX;
        //Iterate over coins array
        for(int j=0;j<coinSize;j++){
            if(i-coins[j]>=0){
                int subProblemAnswer = dp[i-coins[j]];
                dp[i]=min(dp[i],subProblemAnswer+1);
                // cout<<"NowAnser is :"<<dp[i]<<endl;
            }
        }
    }
    return dp[money];
//     49 3
// 3 7 4
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
    // cout<<minCoinChangeTD(coins,money,dp,n);
    cout<<minCoinChangeBU(coins,money,n);
    return 0;
}