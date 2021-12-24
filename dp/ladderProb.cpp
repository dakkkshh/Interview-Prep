#include<bits/stdc++.h>
using namespace std;

int ladderProblem(int n,int k,int dp[]){
    if(dp[n]!=0) return dp[n];
    int res = 0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            res+=ladderProblem(n-i,k,dp);
        }
    }
    dp[n]=res;
    return res;
}
int ladderProblemRec(int n,int k){
    if(n==0 or n==1)return 1;
    int res=0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            res+= ladderProblemRec(n-i,k);
        }
    }
    return res;
}
int ladderProblemBU(int n,int k){
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}
int ladderProblemBUOpti(int n,int k){
    int dp[100]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){
        //For first k elemt substraction part is 0
        dp[i] = (2*dp[i-1]);
    }
    for(int i=k+1;i<=n;i++){
        dp[i]= (2*dp[i-1]) - dp[n-k-1];
    }
    return dp[n];
}
int main()
{
    int n,k;
    cin>>n>>k;
    int dp[100]={0};
    dp[0]=1;
    dp[1]=1;
    time_t startTime = time(NULL);
    cout<<ctime(&startTime)<<endl;
    // cout<<"Ans: "<<ladderProblem(n,k,dp)<<endl;
    // cout<<"Ans: "<<ladderProblemBU(n,k)<<endl;
    cout<<"Ans: "<<ladderProblemBUOpti(n,k)<<endl;
    time_t endTime = time(NULL);
    cout<<ctime(&endTime)<<endl;
    return 0;
}