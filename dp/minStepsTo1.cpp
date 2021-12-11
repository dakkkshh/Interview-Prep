#include <bits/stdc++.h>
using namespace std;

int stepsTo1TD(int n, int dp[])
{
    // Base case
    if (n == 1)
        return 0;

    // Look Up
    if (dp[n] != 0)
    {
        return dp[n];
    }
    // Rec case
    int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    if (n % 2 == 0) op1 = stepsTo1TD(n / 2, dp);
    if (n % 3 == 0) op2 = stepsTo1TD(n / 3, dp);
    op3 = stepsTo1TD(n - 1, dp);
    // set ans as dp[n];
    int ans = min(min(op1, op2), op3) + 1;
    return dp[n]=ans;
}
int minStepsto1BU(int n){
    int dp[100]={0};
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(i%2==0)op1 = dp[i/2];
        if(i%3==0)op2 = dp[i/3];
        op3 = dp[i-1];
        dp[i]=min(min(op1,op2),op3)+1;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    dp[0] = 0;
    dp[1] = 0;
    // cout << stepsTo1TD(n, dp);
    cout<<minStepsto1BU(n);
    return 0;
}