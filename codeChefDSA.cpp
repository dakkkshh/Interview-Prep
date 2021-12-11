#include<iostream>
#include <cmath>
using namespace std;
void binConvert(int n,int tempBin[],int bin[]){
    int i = 0;
    while (n > 0) {
        tempBin[i] = n % 2;
        n = n / 2;
        i++;
    }
    for(int j=0;j<i;j++){
        bin[j]+=tempBin[j];
    }
    return;
}
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int arr[n],binary[32]={0};
        for(int i=0;i<n;i++){
            int tempBin[32]={0};
            cin>>arr[i];
            binConvert(arr[i],tempBin,binary);    
        }
        int answer=0;
        for(int i=0;i<32;i++){
            if(binary[i]==0){
                continue;
            }
            answer+= ceil(binary[i]/float(k));
        }
        cout<<answer<<endl;    
    }
    return 0;
}