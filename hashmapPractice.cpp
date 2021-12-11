#include<bits/stdc++.h>
using namespace std;
bool check0SubArray(){
    //At i store sum till i or also known as Cumulative Sum O(n^2)
    
    //if same csum occurs twice (in forward direction) it means that there
    //was a sub array with sum 0
    int n;
    cin>>n;
    vector<int> arr;
    while(n--){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    unordered_map<int,int> mp;
    int cSum=0;
    int i=0;
    for(auto x:arr){
        cSum+=x;
        //Check if prefix sum is 0
        if(cSum==0) return true;
        //Check if this sum was occured or not
        auto it=mp.find(cSum);
        if(it!=mp.end()){
            return true;
        }else{
            mp.insert(make_pair(cSum,i++));

        }        
    }
    return false;
}
int longestSubArr0Sum(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    unordered_map<int,int> mp;
    int cSum=0;
    int len=0;
    for(int i=0;i<n;i++){
        cSum+=arr[i];
        if(cSum==0){
            //current len will be index+1
            len=max(len,i+1);
        }
        if(mp.find(cSum)!=mp.end()){
            //Sub array with 0 sum found
            len=max(len,i-mp[cSum]);
            //mp[csum]= first occurence of csum
        }else{
            //storing first occurence of sum;
            mp[cSum]=i;
        }
    }
    return len;
}
void longestSubArrKSum(){
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int cSum=0,len=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        cSum+=arr[i];
        if(cSum==k){
            //current len will be index+1
            len=max(len,i+1);
        }

        if(mp.find(cSum-k)!=mp.end()){
            //We need to look for cSum-k
            len = max(len,i-mp[cSum-k]);

        }else{
            //storing first occurence of sum;
            mp[cSum]=i;
        }
    }
    cout<<"Ans: "<<len<<endl;
    return;
}
void consecutiveSubSeq(){
    //Failed When Numbers are repeating
    // 6 6 2 3 1 4 1 5 6 2 8 7 4 2 1 3 4 5 9 6 : Like this
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    unordered_map<int,int> mp; //Number,StreakLen
    for(auto x:arr){
        if(mp.find(x-1)==mp.end() and mp.find(x+1)==mp.end()){
            //No streak found
            //Start a new Streak with Len 1
            mp.insert(make_pair(x,1));
        }
        else if(mp.find(x-1)!=mp.end() and mp.find(x+1)!=mp.end()){
            //Both left and Right Streak exists
            int len1 = mp[x-1]; //Left Len
            int len2 = mp[x+1]; //Right Len
            int streakLen = len1+1+len2;
            //Update Starting of left Streak 
            mp[x-len1] = streakLen;
            //Update ending of right Streak
            mp[x+len2] = streakLen;
        }else if(mp.find(x-1)!=mp.end() and mp.find(x+1)==mp.end()){
            //Left Streak exists
            int len1 = mp[x-1];
            //Update Starting of left Streak
            mp[x-len1] = len1+1;
            mp[x]=len1+1;
        }else{
            //Update Right Ending of right streak
            int len2 = mp[x+1];
            mp[x+len2] = len2+1;
            mp[x]=len2+1;
        }
    }
    int largest = 0;
    for(auto x:mp){
        largest = max(largest,x.second);
    }
    cout<<"Ans: "<<largest<<endl;
}
void consecutiveSubSeqImproved(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    unordered_set<int> s;
    for(auto x:arr){
        s.insert(x);
    }
    int maxStreak =0;
    for(auto x:arr){
        if(s.find(x-1)==s.end()){
            //No streak found
            //Start a new Streak with Len 1
            int streakLen = 1;
            int curr = x;
            while(s.find(curr+1)!=s.end()){
                streakLen++;
                curr++;
            }
            maxStreak = max(maxStreak,streakLen);
        }

    }
    cout<<"Max Streak"<<maxStreak<<endl;
    return;
}
void smallestWindowProblem(){
    string input="hllloeaeo world";
    string pattern = "eelo";
    string result;
    int sl = input.length();
    int pl = pattern.length();
    if(pl>sl){
        cout<<"Not Applicable"<<endl;
        return;
    }
    //Frequency Map of Pattern and String
    int PMAP[256]={0};
    int SMAP[256]={0};

    //Construct PMAP
    for(int i=0;i<pl;i++){
        PMAP[pattern[i]]++;
    }
    //Count stores total matched characters
    int count=0;
    int start=0; //left pointer for shrinking
    int minLen = INT_MAX;
    int startIndex = -1;
    //Sliding Window Tech (Expansion and Constraction)
    for(int i=0;i<sl;i++){
        char ch = input[i];
        SMAP[ch]++;

        //Maintain count of chars
        if(PMAP[ch]!=0 and SMAP[ch]<=PMAP[ch]){
            //First condition check whether char is present or not in pattern
            //Second condition check whether SMAP is sufficient for pattern or not
            count++;
        }
        //Check whether count of chars is equal to pattern len
        if(count==pl){
            //Window has required chars
            //Contraction Time from Left
            //Loop to remove unwanted chars
            char temp = input[start];
            while(PMAP[temp]==0 or SMAP[temp]>PMAP[temp]){
                SMAP[temp]--;
                start++;
                temp = input[start];
            }
            //Window size
            //+1 for 0-based indexing
            int windowLen = i-start+1;
            if(windowLen < minLen){
                minLen = windowLen;
                startIndex = start;
            }
        }
    }
    if(startIndex==-1){
        cout<<"No Such Window"<<endl;
    }else{
        result = input.substr(startIndex,minLen);
        cout<<result<<endl;
    }
    return;
}
void hashingTriangle(){
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];
    }
    unordered_map<int, int> xpoints;
    unordered_map<int, int> ypoints;
 
    for (int i = 0; i < n; i++) {
        xpoints[a[i][0]]++;
        ypoints[a[i][1]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (xpoints[a[i][0]] >= 1 && ypoints[a[i][1]] >= 1) {
            count += (xpoints[a[i][0]] - 1)* (ypoints[a[i][1]] - 1);
        }
    } 
    cout<<count<<endl;
    return;
}
int main()
{   

    // if(check0SubArray()) cout<<"True"<<endl;
    // cout<<longestSubArr0Sum()<<endl;
    // longestSubArrKSum();
    // consecutiveSubSeq();
    // consecutiveSubSeqImproved();
    // smallestWindowProblem();
    

    return 0;
}