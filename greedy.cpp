#include<bits/stdc++.h>
using namespace std;

void makeChange(){
    int coins[]={1,2,5,10,20,50,100,200,500,2000};
    int money;
    cin>>money;
    int t = sizeof(coins)/sizeof(coins[0]);
    //Index of lowest than 39 is given by
    //Index of greater than 39-1
    int ans=0;
    while(money>0){
        //upper_bound return address
        int idx = upper_bound(coins,coins+t,money)-1-coins;
        cout<<coins[idx]<<"+";
        money-=coins[idx];
        ans++;
    }
    cout<<endl;
    cout<<"Number of Coins: "<<ans<<endl;
    return;
}
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
void busyMan(){
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    //Activity Selection Algo
    //Sort Acc. to end time
    sort(v.begin(),v.end(),compare);
    //Start Picking Activites
    int activites = 1;
    int fin = v[0].second;
    //Iterate over remaining
    for(int i=1;i<n;i++){
        if(v[i].first >= fin){
            fin = v[i].second;
            activites++;
        }
    }
    cout<<"Ans is: "<<activites<<endl;
    
    return;
}
void connectingWires(){
    int n;cin>>n;
    int w[n],b[n];
    for(int i=0;i<n;i++){
        cin>>w[i]>>b[i];
    }
    sort(w,w+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+= abs(w[i]-b[i]);
    }
    cout<<"Ans is: "<<ans<<endl;
    return;
}
void biasedStanding(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Counting Sort : Greedy Approach
    int result[n]={0};
    for(int i=0;i<n;i++){
        result[arr[i]]++;
    }
    int badness = 0;
    int actual_rank = 1;
    for(int i=1;i<=n;i++){
        while(result[i]--){
            badness+=abs(actual_rank-i);
            actual_rank++;
        }   
    }
    cout<<"Ans: "<<badness<<endl;
}
void loadBalancer(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //Base case
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%n!=0){
        cout<<"-1"<<endl;
        return;
    }
    int finalLoad = sum/n;
    int ans = INT_MIN;
    int part1Sum=0;
    int part2Sum=0;
    for(int i=0;i<n-1;i++){
        part1Sum+=arr[i];
        int expectedSum = finalLoad*(i+1);
        int diff = abs(part1Sum-expectedSum);
        ans = max(ans,diff);
    }
    cout<<"Ans: "<<ans<<endl;
    return;   
}
int main()
{
    // makeChange();
    // busyMan();
    // connectingWires();
    // biasedStanding();
    loadBalancer();
    
    return 0;
}