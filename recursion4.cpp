#include<iostream>
#include<climits>
using namespace std;
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
char alpha[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
void subsequenceGen(char *in,char *out,int i,int j){
    //base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    //either include current char or not
    //if we include
    out[j]=in[i];
    subsequenceGen(in,out,i+1,j+1);

    //excluding
    subsequenceGen(in,out,i+1,j);

}

void generateBrackets(char *out,int n,int index,int open,int close){
    //Base case
    if(index == 2*n){
        out[index]='\0';
        cout<<out<<endl;
        return;
    }
    //rec case
    if(open<n){
        out[index]='(';
        generateBrackets(out,n,index+1,open+1,close);
    }
    if(close<open){
        out[index]=')';
        generateBrackets(out,n,index+1,open,close+1);
    }
    return;

}
int knapSack(int n,int c,int *weight,int *profit){
    //Base Case
    if(n==0 || c==0){
        return 0;
    }
    //rec case
    int ans=0;
    int include,exclude;
    include = exclude = INT_MIN;
    //If I include last item
    if(weight[n-1]<=c){
        include = profit[n-1] + knapSack(n-1,c-(weight[n-1]),weight,profit);
    }
    //If I exlcude them
    exclude = knapSack(n-1,c,weight,profit);

    ans = max(include,exclude);
    return ans;
}

void keypadProblem(char *in,char *out,int i,int j){
    //Base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    // Rec Case
    int digit = in[i] - '0';

    if(digit==0 || digit == 1){
        keypadProblem(in,out,i+1,j);

    }
    for(int k=0;keypad[digit][k]!='\0';k++){
        out[j] = keypad[digit][k];
        //fill the remaining part

        keypadProblem(in,out,i+1,j+1);
    }
    return;
}
void stringGen(char *in,char *out,int i,int j){
    //Base Case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    int digit = in[i] - '0';
    if(digit==0){
        stringGen(in,out,i+1,j);
    }
    out[j] = alpha[digit-1];
    //Rec Case
    stringGen(in,out,i+1,j+1);
    return;

}
int main(){

    /*
    char input[] = "abc";
    char output[10];
    subsequenceGen(input,output,0,0);
    */

    //Bracket Problem
    /* int n;
    cin>>n;
    char output[2*n];
    generateBrackets(output,n,0,0,0); */

    //Knap Sack Problem
    /* int weight[]={1,2,3,5};
    int price[]={40,20,30,100};
    int n=4,c=7;
    cout<<"Ans is:- "<<knapSack(n,c,weight,price)<<endl; */

    //KEYPAD PROBLEM
    /* char in[100];
    cin>>in;

    char out[100];
    keypadProblem(in,out,0,0); */

    //STRING GEN
    char in[10];
    cin>>in;
    char out[15];
    stringGen(in,out,0,0);


    return 0;
}