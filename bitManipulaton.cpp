#include<iostream>
#include<cstring>
using namespace std;
void basciBit(){
    int a=7,b=5;
    cout<<(a&b)<<endl; 
    cout<<(a|b)<<endl; 
    cout<<(a^b)<<endl; 
    cout<<(a<<b)<<endl; 
    cout<<(a>>b)<<endl; 
    cout<<(~a)<<endl; 
}
void uniqueNumber(){
    int ans = 0,n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        ans = ans^a;
    }
    cout<<"Ans:"<<ans<<endl; 
}
void oddEven(){
    int n;
    cin>>n;
    if(n&1){
        cout<<"ODD"<<endl;
    }else{
        cout<<"EVEN"<<endl;
    }
}
void findBit(){
    int n;
    cin>>n;
    /*My Technique
    int temp = 15>>n;
    if(temp&1){
        cout<<"1"<<endl;
    }else{
        cout<<"0"<<endl;
    }*/
    // CB ONE
    int ans = (15&(1<<n));
    int bit = ans>0? 1:0;
    cout<<bit<<endl;
}
void setBit(){
    int n;
    cin>>n;
    int mask = 1<<n;
    cout<<(15|mask)<<endl;
}
void clearBit(){
    int n;
    cin>>n;
    int mask=(~(1<<n));
    int ans = mask&5;
    cout<<ans<<endl;
}
void updateBit(){
    int v,n;
    cin>>v>>n;
    int ans;
    if(v==1){
        ans = 5|(1<<n);
        cout<<ans<<endl;
    }else if(v==0){
        ans = 5^(1<<n);  
        cout<<ans<<endl;
  
    }else{
        cout<<"Enter 1/0"<<endl;     
    }
}
void clearTillLast(){
    int i,ans;
    cin>>i;
    /* My solution
    ans = 730>>i+1;*/
    //CB ONE NOT WORKING
    //Updated by Flipping 0
    int mask = (~0<<i);
    ans = 15&mask;
    cout<<ans<<endl;
}
void clearRange(){
    int i,j;
    cin>>i>>j;
    int a = (~0)<<(j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    int ans = mask & 31;
    cout<<ans<<endl;
}
void countBit(){
    int n;
    cin>>n;
    int count=0;
    /*
    //Basic Approach
    while(n>0){
        count+= n&1;
        n=n>>1;
    }*/
    //Time effecient manner
    //n&n-1 clears last set bit
    //hence O(number of set bits)
    while(n>0){
        n=n&(n-1);
        count++;
    }
    cout<<count<<endl;
}
void deciToBin(){
    int n;
    cin>>n;
    long long int ans=0;
    int power=1;
    while(n>0){
        int bit = n&1;
        ans += bit*power;
        power*=10;
        n=n>>1; 
    }
    cout<<ans<<endl;
}
void uniqueNumber2(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mask=0;
    for (int i = 0; i < n; i++) {
        mask^=a[i];
    }
    int result=mask;
    int count=0;
    if(!(mask&1)){
        //If last bit is "0" or number is even
        count++;
        mask>>=1;
    }
    mask = 1;
    while(count--){
        mask<<=1;
    }
    int num1 =0;
    int num2 = 0;
    for (int i = 0; i < n; i++) {
        if((a[i]&mask)!=0){
            num1^=a[i];
        }
    }
    num2=result^num1;

    if(num1<num2){
        cout << num1<<" "<<num2 <<endl;
    }else{
        cout << num2<<" "<<num1 <<endl; 
    }
}
void uniqueNumber3(){
    int n;
    cin>>n;
    int a[n],bitArr[64]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        int current = a[i];
        int j=0;
        while(current>0){
            int lastBit = (current&1);
            bitArr[j] += lastBit;
            j++;
            current = current>>1;
        }    
    }
    //print array
    int ans=0,power=1;
    for(int i=0;i<64;i++){
        bitArr[i] %= 3;
        ans+=(bitArr[i]*power);
        power*=2; //or p<<=1
    }
    cout<<"Ans:- "<<ans<<endl;
}
void fastExponential(){
    int a,b;
    cin>>a>>b;
    int ans=1;
    while(b>0){
        int lastBit = b&1;
        if(lastBit){
            ans = ans*a;
        }
        a*=a;
        b>>=1;
    }
    cout<<"Ans:"<<ans<<endl;
}
void filterChar(){ //char a[],int n
    int n,size,j=0;
    char *c;
    cin>>n>>size;
    for(int i=0;i<size;i++){
        cin>>c[i];
    }
    while(n>0){
        int lastBit = n&1;
        if(lastBit){
            cout<<c[j]; 
        }
        j++;
        n>>=1;
    }
    cout<<endl;
}
/*void printSubsets(){
    //depends on filterchar
    int size;
    char *c;
    for(int i=0;i<size;i++){
        cin>>c[i];
    }
    for(int i=0;i<(1<<size);i++){
        filterChar(c,i);
    }
}*/
int main(){
    //basciBit();
    //uniqueNumber();
    //oddEven();
    //findBit();
    //setBit();
    //clearBit();
    //updateBit();
    //clearTillLast();
    //clearRange();
    //countBit();
    //deciToBin();
    //uniqueNumber2(); not Working
    //uniqueNumber3();
    //fastExponential();
    filterChar();
    return 0;
}