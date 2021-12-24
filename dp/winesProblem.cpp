#include<bits/stdc++.h>
using namespace std;

int profitTD(int wines[],int i,int j,int y,int dp[100][100]){
    //Base case
    if(i>j)return 0; //No bottles left
    //Look Up
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    //Rec Case
    int left = wines[i]*y + profitTD(wines,i+1,j,y+1,dp);
    int right = wines[j]*y +profitTD(wines,i,j-1,y+1,dp);
    int ans = max(left,right);
    dp[i][j]=ans;
    return ans;
}
int profitBU(int wines[],int n){
    int dp[n][n]={0};
    //int year = n-(j-i);
    //Marking Diagonal Values
    for(int i=0;i<n;i++){
        dp[i][i]=wines[i]*n;
    }
    return dp[0][n-1];
}
int main()
{	
    int wines[]={2,3,5,1,4};
    int dp[100][100]={0};
    int n = sizeof(wines)/sizeof(int);
    cout<<"Ans: "<<profitTD(wines,0,n-1,1,dp);
    return 0;
}