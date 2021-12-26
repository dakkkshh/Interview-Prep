#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int dp[100]={0};
    dp[0] = 1;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        dp[i] = max(dp[i],1);
        cout<<"DP["<<i<<"]"<<dp[i]<<endl;
    }
    cout<<endl;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    cout<<"Ans: "<<ans<<endl;
    return 0;
}